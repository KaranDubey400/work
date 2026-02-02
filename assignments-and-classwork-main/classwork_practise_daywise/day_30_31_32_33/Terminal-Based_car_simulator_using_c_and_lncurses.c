#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <ncurses.h>

/* Car structure */

typedef struct
{
    /* Controls */
    double throttle; // 0..1
    double brake;    // 0 or 1
    double steer;    // -1, 0, +1

    /* State */
    double speed_mps;
    int gear; // -1, 0, 1..5
    double heading_rad;
    double x, y;
    int engine_on;

    /* Limits */
    double max_speed_mps;
    double accel_mps2;
    double brake_mps2;
    double drag;

    /* Fuel */
    double fuel;
    double fuel_burn;
    double idle_fuel_burn;

} Car;

/* Constants */

const double dt = 0.03;
const double steering_rate = 20 * M_PI / 180.0;

const double centering_rate = 33 * M_PI / 180.0;

const double heading_deadzone = 0.5 * M_PI / 180.0;

const double throttle_increase_rate = 1.0;

const double throttle_decay_rate = 0.7;

const double max_reverse_speed = 20;





/* function Declare  */

void initCar(Car *car);

void initNcurses(void);

int processInput(Car *car);

void updateThrottle(Car *car, int up_pressed);

void updateSpeed(Car *car);

void updateFuel(Car *car);

void updateAutomaticGear(Car *car);


void applySpeedLimits(Car *car);



void updateSteering(Car *car);



void updatePosition(Car *car);


void renderDisplay(const Car *car);





/*  function defining*/



void initCar(Car *car)
{
    *car = (Car){0};

    car->max_speed_mps = 100;
    car->accel_mps2 = 4;
    car->brake_mps2 = 7;
    car->drag = 0.12;

    car->fuel = 500;
    car->fuel_burn = 1.0;
    car->idle_fuel_burn = 0.1;
}

void initNcurses(void)
{
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    curs_set(0);

    mvprintw(0, 0,
             "Controls: E=Engine | UP=Throttle | DOWN=Brake/Reverse | LEFT/RIGHT=Steer | Q=Quit");
}

int processInput(Car *car)
{
    int key = getch();
    int up_pressed = 0;

    car->brake = 0;
    car->steer = 0;

    if ((key == 'e' || key == 'E') && car->fuel > 0)
    {
        car->engine_on = !car->engine_on;
        if (!car->engine_on)
        {
            car->throttle = 0;
            car->gear = 0;
        }
    }

    if (key == KEY_UP)
        up_pressed = 1;

    if (key == KEY_DOWN)
    {
        if (car->speed_mps > 0.5)
        {
            car->brake = 1;
        }
        else if (car->engine_on && car->fuel > 0)
        {
            car->gear = -1;
            car->throttle += throttle_increase_rate * dt;
            if (car->throttle > 1.0)
                car->throttle = 1.0;
        }
    }

    if (key == KEY_LEFT)
        car->steer = -1;
    if (key == KEY_RIGHT)
        car->steer = 1;

    if (key == 'q' || key == 'Q')
        return -1;

    updateThrottle(car, up_pressed);
    return 0;
}



void updateThrottle(Car *car, int up_pressed)
{
    if (up_pressed && car->engine_on && car->fuel > 0)
    {
        car->throttle += throttle_increase_rate * dt;
        if (car->throttle > 1.0)
            car->throttle = 1.0;
        if (car->gear <= 0)
            car->gear = 1;
    }
    else
    {
        car->throttle -= throttle_decay_rate * dt;
        if (car->throttle < 0)
            car->throttle = 0;
    }
}



void updateSpeed(Car *car)
{
    if (car->brake && car->speed_mps > 0)
    {
        car->speed_mps -= car->brake_mps2 * dt;
        if (car->speed_mps < 0)
            car->speed_mps = 0;
    }
    else if (car->throttle > 0 && car->engine_on && car->fuel > 0)
    {
        double direction = (car->gear == -1) ? -1 : 1;
        car->speed_mps += car->accel_mps2 * car->throttle * direction * dt;
    }
    else
    {
        car->speed_mps -= car->drag * car->speed_mps * dt;
    }
}



void updateFuel(Car *car)
{
    if (car->engine_on && car->fuel > 0)
    {
        double burn = car->idle_fuel_burn + car->fuel_burn * car->throttle;
        car->fuel -= burn * dt;

        if (car->fuel <= 0)
        {
            car->fuel = 0;
            car->engine_on = 0;
            car->throttle = 0;
        }
    }
}



void updateAutomaticGear(Car *car)
{
    if (car->gear > 0)
    {
        if (car->speed_mps > 90){

            car->gear = 5;
}
        else if (car->speed_mps > 70){

            car->gear = 4;
}

        else if (car->speed_mps > 50){

            car->gear = 3;
}

        else if (car->speed_mps > 30){

            car->gear = 2;
}

        else if (car->speed_mps > 0.1){

            car->gear = 1;
}
    }
}



 void applySpeedLimits(Car *car){
             
             if(car->gear > 0 && car->speed_mps > car->max_speed_mps )
            {
                   car->speed_mps = car->max_speed_mps ; 
                }

                if(car->gear == -1 && car->speed_mps < -max_reverse_speed) {
                    
                     car->speed_mps =  -max_reverse_speed; 

                    }

                 if(fabs(car->speed_mps <0.05)  && car->gear != -1) {
                                 
                           car->speed_mps = 0 ;
                          car->gear =0 ;
                        }
}




void updateSteering(Car *car){

            if( fabs(car->speed_mps) >0.1 ) 
             {
                if(car->steer !=0 ) {
                    
                  car->heading_rad += car->steer * steering_rate * dt ;
                   
                 
                  if(car->heading_rad > M_PI) { 
                        car->heading_rad = M_PI ; 
                        } 
                   
                   if(car->heading_rad < -M_PI) {
                     car->heading_rad  = - M_PI ;
                       }


                       }
              


                   else  {

                       if(fabs(car->heading_rad) > heading_deadzone) {
                          
                             car->heading_rad += (car->heading_rad > 0 ? -1 : 1 ) * centering_rate *dt;

                     }
                         else {
                                    car->heading_rad =0; 
                              }
                           }
}

}



void updatePosition(Car *car)
{
    car->y += car->speed_mps * cos(car->heading_rad) * dt;

    car->x += car->speed_mps * sin(car->heading_rad) * dt;
}




void renderDisplay(const Car *car) {
     
           char gear_str[3]; 
          
          if (car->gear == 0) {

               sprintf(gear_str ,"N");
                 }
             else if (car->gear == -1) {
                
                  sprintf(gear_str, "R"); 
              }
            else {
              sprintf(gear_str ,"%d" ,car->gear ) ;
               } 


               mvprintw(2, 0 , "Engine : %s" , car->engine_on ? "ON" : "OFF");
               
              mvprintw(3 ,0 , "throttle : %5.1f%%" , car->throttle *100 ); 
                 
                mvprintw(4, 0 , "Speed : %7.2f", car->speed_mps) ;

               mvprintw(5,0, "Gear : %s" , gear_str); 

             mvprintw(6,0 , " Heading : %7.2f" , car->heading_rad *180 / M_PI);

            mvprintw(7,0, "Position : X= %.2f Y= %.2f" , car->x , car->y);

             mvprintw(8,0, " Fuel : %.2f " , car->fuel); 

}



int main (void)  {
               
          Car car; 

          initCar( &car) ; 

           initNcurses(); 

           while(1) {

              if(processInput(&car) < 0 ) {
                       break; 
           } 

 updateSpeed(&car);

updateFuel(&car);

 updateAutomaticGear(&car);


applySpeedLimits(&car);



updateSteering(&car);



 updatePosition(&car);


renderDisplay(&car);

       refresh() ;
       
       usleep(30000) ; 

}

      endwin(); 
         
        printf("simulation ends \n" );

       return 0; 
                  
        






}



















