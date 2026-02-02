    #include <iostream>
    #include <cstring>
    using namespace std;

    class Sample {
        private:
        int rno;
        char * name;
        double cgpa ;


        public:

        void display(){
            cout<<endl<<"rollno"<<" "<<rno<<" "<<name<<" "<<cgpa<<endl;
        }

        Sample(){  //default no arg constructor
        rno = 0; 
        name = new char[1];
        cgpa = 0.0; 
        }
    
        //dynamic memory allocation
        Sample(int r, const char* n ,double c){
            rno = r;
            name = new char [strlen(n)+1];
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

        void change(){
            char n[20];
            cin>>n;
            strcpy(name,n);
        }

    };

    int main(){
        Sample s1; // created using defauly constrcutor
        
        s1.display();

        Sample s2(101,"abc",7.6);
        s2.display();// parameterized const

        s2.display();
        
        s2.change();
        s2.display();
        
    

        return 0;


    }