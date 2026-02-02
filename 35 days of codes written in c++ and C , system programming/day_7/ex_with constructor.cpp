#include <iostream>
using namespace std ; 


class demo 
{
    private :
    int num ;
    public:
     demo(int x)
     {
          try 
    {
         if(x==0)
         {
            throw "zero is invalid"<<endl;
         }
         
         else
         {
            num =x;
            show();
         } 

        

    }
    catch (const char * msg){
        cout<<"Exception caught";
        cout<<endl<<msg<<endl;
    }
}
 void show(){
    cout<<"num is "<<num<<endl;
 }

  
};

int main (){
    demo(0);

    demo(1);
    return 0;

}