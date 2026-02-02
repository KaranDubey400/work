#include <iostream>
using namespace std;

class shape
{
    public:
    virtual void draw() = 0; 

};

class circle : public shape{
    public:
    void draw(){
        cout<<"drawing a circle"<<endl;
    }
};

class rectangle : public shape{
    public:
    void draw(){
        cout<<"drawing a circle"<<endl;
    }
};

int main()
{
   shape * ptr = new circle();
   ptr->draw();
   ptr = new rectangle();
   ptr->draw();

}