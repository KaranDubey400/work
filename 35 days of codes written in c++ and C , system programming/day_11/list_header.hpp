struct student
{
	int rno;
	double cgpa;
	struct student *next;
};

int add();
int del();
int view();
int rview(student *);
