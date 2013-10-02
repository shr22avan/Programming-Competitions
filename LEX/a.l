%{
#include<stdio.h>
%}

%%
^[^aeiouAEIOU][a-zA-Z0-9]* {int i; for(i = 0; i < strlen(yytext); i++) printf("%c",toupper((char)yytext[i]));}
%%
