#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
	map<int,string>interruptMap = {{1,"PWR"},
				       {2, "VU"},
				       {3, "VD"},
				       {4, "TS"},
				       {5, "PWR"}, // lock-unlock
				       {6, "TS"}, //CAMERA
				       {7, "PWR+VU/VD"},//SCREENSHOT
				       {8, "TS+GYRO"}, //Orientation
				       {9, "TS"}, //FLASH
				       {10, "PWR"}, //Emergency
				       {11, "PWR+FS"}};
	
	int choice = 0;
	while(true)
	{
		//display 
		cout<<"------------------------------\n";
		cout<<"TABLET INTERRUPT MENU\n";
		cout<<"\n1.Power-On \n2.Volume Up \n3.Vol Down \n4.TS-IN/OUT \n5.Screen Lock \n6.Camera \n7.Screenshot \n8.Orientation \n9.Flash-ON/OFF \n10.Emergency Call \n11.Authentication\n";
		cout<<"\nEnter your choice: (Press -1 to exit)  ";
		cin>>choice;
		if(choice == -1)
			break;
		else if(interruptMap.find(choice) != interruptMap.end())
		{
			cout<<"Key pressed: "<<interruptMap[choice]<<endl;
		}
		else
		{
			cout<<"Invalid Choice\n";
		}
	}
	return 0;
}

		
		

	







