#include <iostream>
using namespace std;
int main()
{
	int n,a,b,num[100],i;
	cin>>n;
	for(i = 0;i < n; i++)
	{
		cin>>a>>b;
		num[i] = a + b; 
	}
	for(i = 0;i < n; i++)
	{
		cout<<num[i]<<endl;
	 }
	 return 0;
}
