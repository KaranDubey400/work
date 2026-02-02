#include <iostream>
#include<cstring>

using namespace std;


class bank{
  private:
  int acno; 
  
  char name[50]; 
  
  char ac_type[3]; 
  
  double balance  ; 
  
  static int nxt_acc_num; 
  
  public:
  bank(){
    
  }
  
    
  bank(char n[]){
    acno = nxt_acc_num++;
    strcpy(name , n); 
    strcpy(ac_type, "SA"); 
    balance = 5000; 
  }
  
  bank(char n[], char type[] ){
    acno = nxt_acc_num++;
    strcpy(name,n);
    strcpy(ac_type,type); 
    
    if(strcmp(ac_type,"SA")==0){
      balance =5000;
    } else{
      balance =8000; 
    }
  }
  
  void input(){
    acno = nxt_acc_num++;
     cout << "user name enter"<<endl;
            cin >> name;
            
           do {
             cout << "enter acc type SAor CA ";
              cin >> ac_type;
          } while (strcmp(ac_type, "SA") != 0 && strcmp(ac_type, "CA") != 0);
        
          
             if (strcmp(ac_type, "SA") == 0)
    {
            do{
              cout << "balance enter min5000 ";
                cin >> balance;
            }while(balance <5000);
        } 
        
        else{
                do  
               { cout << "balance enter min8000 ";
                cin >> balance;
            }  while (balance < 8000);
        }

  }
   
  static  void show(bank b[], int i, int j ){
    cout<<"customer u want to compare enter , 1, 2,3,4,5 anyone"<<endl;
    int k = 0 , p =0;
     cin >>k;  
    cin>>p;
      i=k-1;
    j=p-1;
  
    
    if (b[i].balance > b[j].balance){
            cout << " this account have more balance   "<<endl << b[i].name    << " "  << b[i].balance << endl; 
    }
        else
        {
            cout <<endl <<"this account have more balance  " << b[j].name << " " << b[j].balance << endl;
    }
  }
  
  void display(){
    cout << acno << " " << name << " "   << ac_type << " " << balance << endl;
  }
}; 

 int bank :: nxt_acc_num = 1001; 

int main(){
    bank *b = new bank[5];
     int account_number; 
  
  char name[50] , ac_type[3]; 
  
  double balance ;
  
  cout<<"enter user1 name"<<endl; 
  cin>>name; 
  b[0] = bank(name); 
  
  cout<<"user2 name"<<endl; 
  cin>>name; 
  cout<<" user1 account type"<<endl; 
  cin>>ac_type; 
  
  b[1] = bank(name,ac_type); 
  
  
  for(int i =2 ; i< 5 ; i++){
    cout<<"user info "<<i+1<<endl;
    b[i].input(); 
  }
  
   cout <<endl<< "acno  name  type  balance";
    for (int i = 0; i < 5; i++)
    {
        b[i].display();  
    }
    
    bank:: show(b,2,6); 

}

