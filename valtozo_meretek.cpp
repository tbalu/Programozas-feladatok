#include <iostream>
using namespace std;
int main()
{
       typedef struct date { int y,m,d;}date;
	date **datmut;
	int *a;
	int **m;
	/**a=10;
	cout<<a<<endl;
	cout<<*a<<endl;
	cout<<"+++++++++++++++"<<endl;
	//int **m;
	/*m=&a;
	cout<<"m: "<<m<<endl;*/
	
	char **cm;
	char *c;
	
	cout<<"Char mutato"<<endl;
	cout<<&c<<endl;
	enum keyword {ASM,AUTO,BREAK};
	cout<<"char mérete "<<sizeof(char)<<" bájt"<<endl;
	cout<<"short mérete "<<sizeof(short)<<" bájt"<<endl;
	cout<<"int mérete "<<sizeof(int)<<" bájt"<<endl;
	cout<<"long mérete "<<sizeof(long)<<" bájt"<<endl;	
	cout<<"float mérete "<<sizeof(float)<<" bájt"<<endl;
	cout<<"double mérete "<<sizeof(double)<<" bájt"<<endl;
	cout<<"long double mérete "<<sizeof(long double)<<" bájt"<<endl;
	cout<<"unsigned mérete "<<sizeof(unsigned)<<" bájt"<<endl;
	cout<<"int mutato mérete "<<sizeof(&m)<<" bájt"<<endl;
	cout<<"char mutato mérete "<<sizeof(&cm)<<" bájt"<<endl;
	cout<<"datum struktura mérete "<<sizeof(date)<<" bájt"<<endl;
	cout<<"datum struktura mutatojanak mérete "<<sizeof(&datmut)<<" bájt"<<endl;
	cout<<"enum keyword mérete "<<sizeof(keyword)<<" bájt"<<endl;
}
