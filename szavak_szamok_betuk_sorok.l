%{ 
	#include <iostream>
	#include <stdio.h>
	int n_szam=0;
	int n_lines=0;
	int betuk=0;
	int n_szavak=0;
%}

%%

[a-zA-Z] {++betuk;}
\n {++n_lines;}

[[:digit:]]+ ++n_szam;



[[:digit:]]*\.[[:digit:]]* ++n_szam;

[a-zA-Z]+ {
betuk+=yyleng;
++n_szavak;
}
%%
//#include <iostream>
int main()
{
using namespace std;
	yyin=fopen("abc.txt","r");
	yylex();
	cout<<"Sorok száma: "<<n_lines<<endl;
	cout<<"Betűk száma: "<<betuk<<endl;
	cout<<"Szavak száma: "<<n_szavak<<endl;
	cout<<"Számok száma: "<<n_szam<<endl;

}
