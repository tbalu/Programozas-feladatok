#include <iostream>
using namespace std;
void swap(int *elso,int* masodik)
{
	int temp=*elso;
	*elso=*masodik;
	*masodik=temp;
}

void swap2(int &elso,int& masodik)
{
	int temp=elso;
	elso=masodik;
	masodik=temp;
}

int main()
{
	int elso=0,masodik=0;
	int& refe=elso;
	int& refm=masodik;
	cout<<"Írj be két számot!\n";
	cin>>elso>>masodik;
	swap(elso,masodik);
	cout<<"elso: "<<elso<<" masodik:"<<masodik<<endl;
	swap2(elso,masodik);
	cout<<"elso: "<<elso<<" masodik:"<<masodik<<endl;
	swap2(refe,refm);
	cout<<"elso: "<<elso<<" masodik:"<<masodik<<endl;
}
