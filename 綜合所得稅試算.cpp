#include <iostream>
using namespace std;
 
int main()
{
    int n ,discount ; 
    cin >> n  >> discount;
    double taxrate ;
if (n <=370000)
{    
    taxrate = 0.06;
    discount = 0;
    
}
else if (n <=990000)
{
   taxrate = 0.13;
   discount = 25900;
}	
else if(n <=1980000)
{
	taxrate = 0.21;
	discount = 105100;
}	 
else if (n <=3720000)
{
	taxrate =0.3;
	discount = 283300;
}
else if (n > 3720000)
{
	taxrate =0.4;
	discount = 655300;
}
	cout << "income " << n <<"\n";
	cout <<"tax rate " << taxrate*100 <<"%"<<"\n";
	cout << "tax "<< n*taxrate <<"\n";
	cout << "discount " << discount <<"\n";
	cout << "taxpay " << n*taxrate-discount << "\n";
    return 0;
}
	