#include <iostream>
using namespace std;
 int faktorialis(int n)
{
	int eredmeny=1;
	for(int i=1;i<=n;i++)
		eredmeny*=i;
	return eredmeny;
}

int main()
{
int szam;
cout<<"Írj be egy szamor\n";
cin>>szam;
cout<<faktorialis(szam);
}
