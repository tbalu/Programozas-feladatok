%{ #include <stdio.h>
	int n_char=0;
	int n_lines=0;
%}

%%

\n {++n_lines;}
. ++n_char;
%%

int main(int argc[], char *argv[])
{
	yyin=fopen("abc.txt","r");
	yylex();
	printf("#n of characters: %d",n_char);
	printf("\n");
	printf("#n of lines: %d\n",n_lines);
	printf("karakterek szama sorvege karakterekkel eggyutt: %d",n_char+n_lines);
	return 0;

}
