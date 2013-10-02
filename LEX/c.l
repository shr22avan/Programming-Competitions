%{
	#include<stdio.h>
%}
%%
^(0*10*(0*10*10*)*)\n printf("Matches:%s\n",yytext);
%%
