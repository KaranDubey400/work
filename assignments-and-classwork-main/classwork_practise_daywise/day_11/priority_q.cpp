#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main()
{
	priority_queue<int,vector<int>,greater<int>> pq;


	pq.push(200);

	pq.push(100);


	pq.push(400);
	pq.push(800);
	pq.push(300);
	
	pq.push(250);

	while(!pq.empty())
	{
		cout<<pq.top()<<" ";
		pq.pop();
	}
	cout<<endl;
}

