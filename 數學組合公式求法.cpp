#include <iostream>
using namespace std;
int C(int n,int m){
	if(n==m or m==0)
	   return 1;
	if(n>m)
	return C(n-1,m)+C(n-1,m-1);
}
int main()
{
	int n,m;
   cin >> n >> m;
    if(n > m)
	{
    	cout << C(n,m)<< "\n";
    } 
    else
	{
    	cout <<("input error") << "\n";
	}
	return 0;
}