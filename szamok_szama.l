%{ #include <stdio.h>
	int n_szam=0;
	int n_lines=0;
%}

%%

\n {++n_lines;}
[[:digit:]]*\.[[:digit:]]* ++n_szam;
[[:digit:]]+ ++n_szam;

%%

int main(int argc[], char *argv[])
{
	yyin=fopen("abc.txt","r");
	yylex();
	printf("\n");
	printf("számok száma: %d",n_szam);
	printf("\n");
	//printf("#n of lines: %d",n_lines);
	return 0;

}
