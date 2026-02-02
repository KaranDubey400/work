#include <iostream>
#include <cstring>
using namespace std;

class Sample {
    private:
    int rno;
    char name[20];
    double cgpa ;
   

    public:

    void display(){
        cout<<endl<<"rollno"<<" "<<rno<<" "<<name<<" "<<cgpa<<endl;
    }

    Sample(){  //default no arg constructor
      rno = 0; 
      strcpy(name,"None");
      cgpa = 0.0; 
    }
    // //constructor default easy way ... not available in c++11 but in modern c++ available
    // Sample() = default;
    //parameteriezed const
    Sample(int r, const char* n ,double c){
        rno = r;
        strcpy(name,n);
        cgpa = c;
    }

      //parameterized
    Sample(int r,double c){
        rno = r;
        strcpy(name,"None");
        cgpa = c;
    }
    // //copy constructor
    // Sample(Sample &ss ){
    //     rno = ss.rno;
    //     strcpy(name,ss.name);
    //     cgpa = ss.cgpa;
    // }

};

int main(){
    Sample s1; // created using defauly constrcutor
     

    s1.display();

    Sample s2(101,"abc",7.6);
    s2.display();// parameterized const

    Sample s3(109,8.1);
    s3.display();
    
    //copy constructor two syntax
    Sample s4 =s2 ; 
    s4.display(); 
    Sample s5(s3);  //s5.Sample(s3);
    s5.display();

    return 0;


}