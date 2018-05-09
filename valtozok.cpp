#include <iostream>
using namespace std;
char kar='o';
char* karmut=&kar;
int tizegesz[10]={1,2,3,4,5,6,7,8,9,10};
int (&tizegeszref)[10]=tizegesz;
//karakterlancokból álló tömb
char szo[]="alma";
char* sz1=szo;
char szo2[]="dió";
char* sz2=szo2;
char szo3[]="egyeb";
char* sz3=szo3;
char **karlancok[3]={&sz1,&sz2,&sz3};
//karakterre hivatkozó mutatóra hivatkozó mutató
char kar2='4';
char * kar2mut=&kar2;
char ** kar2mutmut=&kar2mut;
//konstans egész
const int egeszkonstans=10;
//konstans egeszre mutató mutató
const int* kegmut=&egeszkonstans;
//egeszre hvatkozó konstans mutató 
int egesz=12;
int *const konstmut=&egesz;
int main()
{
cout<<"karakter: "<<kar<<"mutatója "<<(void*)karmut<<endl;
cout<<"10 egesz tomb"<<endl;
for(int i=0;i<10;i++)
cout<<tizegesz[i]<<endl;
//referencia a tombre
cout<<"10 egesz tomb referenciaja"<<endl;
for(int i=0;i<10;i++)
cout<<tizegeszref[i]<<endl;
//karakterláncokból álló tömb
cout<<*karlancok[0]<<endl;
cout<<*karlancok[1]<<endl;
cout<<*karlancok[2]<<endl;
//karakterre mutató mutató mutatója
cout<<"karakter: "<<kar2<<"mutatója "<<(void*)kar2mut<<" mutatójára mutató mutató "<<(void*)kar2mutmut<<endl;
//konstans egesz es a mutatója
cout<<"konstans egész szám"<<egeszkonstans<< "mutatója "<<kegmut<<endl;
//egeszre hivatkozó mutató
cout<<"egész szám "<<egesz<< " mutatója "<<konstmut<<endl;
}
