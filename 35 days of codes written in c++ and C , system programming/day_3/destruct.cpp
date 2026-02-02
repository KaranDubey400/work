#include <iostream>
using namespace std;

class Sample {
    private:
    static int count; //declaration

public:
   Sample(){
    cout<<endl<<" creating object"<<endl;
    ++count;
   }
   ~Sample(){
    cout<<endl<<" destroying object"<<endl;
    count--;
   }

};

int Sample::count = 0;//definition

int main(){
    Sample s1 , s2, s3;
    return 0; 
}