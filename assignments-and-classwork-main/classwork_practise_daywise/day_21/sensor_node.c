#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int next_id = 1;
int flag = 1;
pthread_mutex_t list_mt = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t cmd_mt = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cmd_cv = PTHREAD_COND_INITIALIZER;
pthread_mutex_t print_mt = PTHREAD_MUTEX_INITIALIZER;
typedef enum
{
    CMD_NONE,
    CMD_ADD_ONE,
    CMD_DELETE_ONE,
    CMD_AVG
} command_type;

typedef struct
{
    command_type type;
    int value;
} command;

command current_cmd = {CMD_NONE, 0};

typedef struct sample
{
    int value;
    struct sample *next;
} sample;

typedef struct sensor
{
    int id;
    int sample_count;
    sample *samples;
    struct sensor *next;
} sensor;
sensor *head = NULL;

sample *create_samples(int c)
{
    sample *head = NULL;
    for (int i = 0; i < c; i++)
    {
        sample *n = malloc(sizeof(sample));
        n->value = i + 1;
        n->next = head;
        head = n;
    }
    return head;
}

void add_nodes(int n)
{
    for (int i = 0; i < n; i++)
    {
        sensor *s = malloc(sizeof(sensor));
        s->id = next_id++;
        s->sample_count = 3;
        s->samples = create_samples(3);

        pthread_mutex_lock(&list_mt);
        s->next = head;
        head = s;

        pthread_mutex_unlock(&list_mt);
    }
}

void *avg_thread(void *arg)
{
    while (flag)
    {
        pthread_mutex_lock(&cmd_mt);

        while (flag && current_cmd.type != CMD_AVG)
        {
            pthread_cond_wait(&cmd_cv, &cmd_mt);
        }

        if (!flag)
        {
            pthread_mutex_unlock(&cmd_mt);
            break;
        }
        current_cmd.type = CMD_NONE;
        pthread_mutex_unlock(&cmd_mt);
        pthread_mutex_lock(&list_mt);
        sensor *temp = head;
        while (temp)
        {
            double sum = 0;
            int count = 0;

            sample *s = temp->samples;

            while (s)
            {
                sum += s->value;
                count++;
                s = s->next;
            }

            if (count != 0)
            {
                double a = sum / count;
                if (pthread_mutex_trylock(&print_mt) == 0)
                {
                    printf("\n sensor %d avg = %.2f \n", temp->id, a);
                    pthread_mutex_unlock(&print_mt);
                }
            }

            temp = temp->next;
        }
        pthread_mutex_unlock(&list_mt);
        // sleep(3);
    }
    return NULL;
}

void *add_sensor(void *arg)
{
    while (flag)
    {
        pthread_mutex_lock(&cmd_mt);

        while (flag && current_cmd.type != CMD_ADD_ONE)
        {
            pthread_cond_wait(&cmd_cv, &cmd_mt);
        }

        if (!flag)
        {
            pthread_mutex_unlock(&cmd_mt);
            break;
        }

        int samples = current_cmd.value;
        current_cmd.type = CMD_NONE;

        pthread_mutex_unlock(&cmd_mt);

        sensor *s = malloc(sizeof(sensor));
        s->id = next_id++;
        s->sample_count = samples;
        s->samples = create_samples(samples);

        pthread_mutex_lock(&list_mt);
        s->next = head;
        head = s;
        pthread_mutex_unlock(&list_mt);
    }
    return NULL;
}

void *del_sensor(void *arg)
{
    while (flag)
    {
        pthread_mutex_lock(&cmd_mt);

        while (current_cmd.type != CMD_DELETE_ONE && flag)
        {
            pthread_cond_wait(&cmd_cv, &cmd_mt);
        }
        if (!flag)
        {
            pthread_mutex_unlock(&cmd_mt);
            break;
        }

        int target = current_cmd.value;
        current_cmd.type = CMD_NONE;

        pthread_mutex_unlock(&cmd_mt);

        pthread_mutex_lock(&list_mt);

        sensor *p = head, *prev = NULL;

        while (p)
        {
            if (p->id == target)
            {
                if (prev)
                {
                    prev->next = p->next;
                }
                else
                    head = p->next;

                sample *s = p->samples;
                while (s)
                {
                    sample *temp = s;
                    s = s->next;
                    free(temp);
                }
                free(p);
                break;
            }
            prev = p;
            p = p->next;
        }
        pthread_mutex_unlock(&list_mt);
    }
    return NULL;
}

int main()
{
    printf("No. of nodes you want to create \n");
    int n;
    scanf("%d", &n);
    add_nodes(n);
    pthread_t avg_t, add_t, del_t;

    pthread_create(&avg_t, NULL, avg_thread, NULL);
    pthread_create(&add_t, NULL, add_sensor, NULL);
    pthread_create(&del_t, NULL, del_sensor, NULL);

    while (flag)
    {
        int choice, value1;
        // pthread_mutex_lock(&print_mt);
        sleep(1);
        printf("\n 1-add\n 2-delete\n 3-calculate avg \n0-exit-> ");
        scanf("%d", &choice);
        // pthread_mutex_unlock(&print_mt);

        pthread_mutex_lock(&cmd_mt);
        if (choice == 1)
        {
            // pthread_mutex_lock(&print_mt);
            printf("Enter Sample count: ");
            scanf("%d", &value1);
            // pthread_mutex_unlock(&print_mt);

            current_cmd.type = CMD_ADD_ONE; // no. of samples
            current_cmd.value = value1;
        }

        else if (choice == 2)
        {
            // pthread_mutex_lock(&print_mt);
            printf("sensor id to delete: ");
            scanf("%d", &value1);

            current_cmd.type = CMD_DELETE_ONE;
            current_cmd.value = value1; // for sensor id
        }
        else if (choice == 3)
        {
            // pthread_mutex_lock(&print_mt);
            // printf("printing avg ");
            current_cmd.type = CMD_AVG;
            current_cmd.value = 0; // for sensor id
        }
        else
        {
            flag = 0;
        }
        pthread_cond_broadcast(&cmd_cv);
        pthread_mutex_unlock(&cmd_mt);
        // pthread_mutex_unlock(&print_mt);
    }

    pthread_cond_broadcast(&cmd_cv);
    pthread_join(avg_t, NULL);
    pthread_join(add_t, NULL);
    pthread_join(del_t, NULL);

    while (head != NULL)
    {
        sensor *temp = head;
        head = head->next;
        free(temp);
    }
}