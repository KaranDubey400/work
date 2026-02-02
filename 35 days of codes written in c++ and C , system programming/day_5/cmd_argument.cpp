#include <iostream>
#include <cstdlib>
using namespace std;

// int main(int argc , char *argv[]){

// }
int main (int ac, char **av){
    if(ac<3){
        // doing this now will not through exception it will just terminate , invalid , but 
        //dont through exception . do this with every command line arguments 
        cout<<"invalid number of arguments"<<endl;
        return 1;
    }
    int tot = atoi(av[1])+ atoi(av[2]);
    cout<<"total "<<tot<<endl;
    return 0;
}


