// #include <iostream>
// using namespace std;
// class base1{
//    private:
//    int num; 
//    public:
//    base1(){
//     num= 30 ; 
//    }
//    void show(){
//     cout<<endl<<"base 1 "<<num<<endl; 
//    }
// };

// class base2{
//     private:
//    int num; 
//    public:
//    base2(){
//     num= 40 ; 
//    }
//    void show(){
//     cout<<endl<<"base 2 num  "<<num<<endl; 
//    }

// };

// class child : public base1, public base2{
//   private:
//    int num; 
//    public:
//    child(){
//     num= 40 ; 
//    }
//    void show(){
//     cout<<endl<<"child num "<<num<<endl; 
//    }


// };


// int main (){
//     child c1; 
//     c1.show(); 
//     c1.base1::show(); 
//     c1.base2::show(); 

//     return 0 ; 
// }

#include <iostream>
using namespace std;
class base1{
   private:
   int num; 
   public:
   base1(){
    num= 30 ; 
   }
   void show(){
    cout<<endl<<"base 1 "<<num<<endl; 
   }
};

class base2{
    private:
   int num; 
   public:
   base2(){
    num= 40 ; 
   }
   void show(){
    cout<<endl<<"base 2 num  "<<num<<endl; 
   }

};

class child : public base1, public base2{
  private:
   int num; 
   public:
   child(){
    num= 40 ; 
   }
   void show(){
    cout<<endl<<"child num "<<num<<endl; 
   }


};


int main (){
    child c1; 
    c1.show(); 
    c1.base1::show(); 
    c1.base2::show(); 

    return 0 ; 
}



