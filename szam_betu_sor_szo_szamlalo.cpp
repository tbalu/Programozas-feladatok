#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;


int szavak=0;
int betuk=0;
//int bet=0;
int &bet=betuk;
int szamok=0;
int sorok=0;
int nemtudja=0;
bool szam;
bool szo;
string sor;
//char * token;
char ezszo='w';
char ezszam='n';
char nemtudommi='m';

char miez( char * token)
{
for(int j=0;j<strlen(token);j++)
			{
				if(isalpha(token[j]))
					szo=true;
				else {
					szo=false;
					j=strlen(token);
					}
			}
		if(szo==true & szam==false) return ezszo;
for(int j=0;j<strlen(token);j++)
			{
				if(isdigit(token[j]))
					szam=true;
				else {
					szam=false;
					j=strlen(token);
					}	
			}
		if(szam==true & szo==false) return ezszam;
	if(szam==true & szo==true) return nemtudommi;
	if(szam==false & szo==false) return nemtudommi;
}
void hanybetu(char * token , int& betuk)
{
for(int j=0;j<strlen(token);j++)
	{
if(isalpha(token[j]))
	++betuk;	

}
//return betuk;
	}
int main(int argc, char* argv[])

{
char *fajl = *++argv;
string fajlnev=fajl;
ifstream Fajl(fajlnev);
while (getline(Fajl,sor))
{
	
	char chsor[sor.length()];
	for (int i=0;i<sor.length();i++)
	{
		chsor[i]=sor.at(i);
	}
	//chsor=sor;
	char * token;
	token = strtok(chsor,",. -");
	
	while(token!=NULL)
	{
		cout<<token<<endl;
		//cout<<strlen(token)<<endl;
		/*for(int j=0;j<strlen(token);j++)
			{
				if(isalpha(token[i]))
					szo=true;
				else szo=false;	
			}*/
	if(miez(token)==ezszam)
		++szamok;
	if(miez(token)==ezszo)
		++szavak;
	if(miez(token)==nemtudommi)
		++nemtudja;
		hanybetu(token,betuk);
		token=strtok(NULL,",. -");
	//char v=miez(token);
	//cout<<"besorolas: "<<v<<endl;	
	//void hanybetu(token,&bet);
	

	
}
++sorok;
}
	cout<<"sorok szama:"<<sorok<<endl;
	cout<<"szamok szama:"<<szamok<<endl;
	cout<<"szavak szama:"<<szavak<<endl;
	cout<<"nem tudta eldonteni:"<<nemtudja<<endl;
	cout<<"betuk szama:"<<betuk<<endl;
}


