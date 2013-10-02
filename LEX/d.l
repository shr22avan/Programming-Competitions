%{
	#include<stdio.h>
%}
%%
^class" "[a-zA-Z][a-zA-Z0-9_]* 	printf("CLASS");
{[\n\t ]	printf("LEFTPARAN");
}	printf("RIGHTPARAN");
