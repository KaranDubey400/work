#include <iostream>
using namespace std;
class Student{
    private:
    int num;
    static int staic_num; //static data memeber declaration

    public:
    void input(){
        cout<<"this is for object number"<<++staic_num;
        cout<<"Enter number-";
        cin>>num;
    }
    void output(){
        cout<<endl<<"number -"<<endl;
    }
    void static show(){
        
        cout<<endl <<"total number of objects created are "<<staic_num<<endl;
    }
};
int Student:: staic_num=10;

int main(){
    Student s1,s2,s3;
    s1.input();
    s1.output();
    s2.input();
    s2.output();
    s3.input();
    s3.output();
    s1.show();//calling using object 
    Student::show();//calling ysing class name
    return 0; 
}