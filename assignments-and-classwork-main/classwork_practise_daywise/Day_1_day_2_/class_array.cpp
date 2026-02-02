#include <iostream>
using namespace std;

class Student{
    private:
    int rollnumber; 
    int cgpa ; 

    public:
    void input(){
       cout<<"enter roll number and cgpa"; 
       cin>>rollnumber>>cgpa; 
    }
    void output(){
        cout<<endl<<"Roll number is- "<<rollnumber; 
        cout<<endl<<"CgPA is- "<<cgpa; 
    }
    double get_cgpa(){
        return cgpa; 
    }
}; 
inline void show(){
    cout<<endl<<"welcome everyone"<<endl;
}
int main()
{
   Student s[3]; 
   show(); 
  for(int i=0;i<3;i++){
    cout<<"enter data of student "<<i+1<<endl; 
    s[i].input(); 
  }
  double to_cgpa = 0.0;

  for(int i=0;i<3;i++){
    cout<<"data of student "<<i+1<<endl; 
    s[i].output(); 
    to_cgpa = to_cgpa + s[i].get_cgpa(); 
  }

  cout<<endl;
  cout<<"average cgpa for the bathc is "<<to_cgpa/3; 

   return 0; 
}

