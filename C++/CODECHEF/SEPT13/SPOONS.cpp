/*#include<iostream>
#include<cstdio>
using namespace std;*/
#include<stdio.h>
#define getint(a) scanf("%d",&a)
#define getll(a) scanf("%lld",&a)
#define ll unsigned long long
int main() {
	int t;
	ll n,a[100];
	a[1]=1;
	a[2]=2;
	a[3]=3;
	a[4]=6;
	a[5]=10;
	a[6]=20;
	a[7]=35;
	a[8]=70;
	a[9]=126;
	a[10]=252;
	a[11]=462;
	a[12]=924;
	a[13]=1716;
	a[14]=3432;
	a[15]=6435;
	a[16]=12870;
	a[17]=24310;
	a[18]=48620;
	a[19]=92378;
	a[20]=184756;
	a[21]=352716;
	a[22]=705432;
	a[23]=1352078;
	a[24]=2704156;
	a[25]=5200300;
	a[26]=10400600;
	a[27]=20058300;
	a[28]=40116600;
	a[29]=77558760;
	a[30]=155117520;
	a[31]=300540195;
	a[32]=601080390;
	a[33]=1166803110;
	a[34]=2333606220;
	a[35]=4537567650;
	a[36]=9075135300;
	a[37]=17672631900;
	a[38]=35345263800;
	a[39]=68923264410;
	a[40]=137846528820;
	a[41]=269128937220;
	a[42]=538257874440;
	a[43]=1052049481860;
	a[44]=2104098963720;
	a[45]=4116715363800;
	a[46]=8233430727600;
	a[47]=16123801841550;
	a[48]=32247603683100;
	a[49]=63205303218876;
	a[50]=126410606437752;
	a[51]=247959266474052;
	a[52]=495918532948104;
	a[53]=973469712824056;
	a[54]=1946939425648112;
	a[55]=3824345300380220;
	a[56]=7648690600760440;
	a[57]=15033633249770520;
	a[58]=30067266499541040;
	a[59]=59132290782430712;
	a[60]=118264581564861424;
	a[61]=232714176627630544;
	a[62]=465428353255261088;
	a[63]=916312070471295267;
	a[64]=1832624140942590534;
	getint(t);
	int i;
	while(t--) {
		getll(n);
		for(i = 1; i < 65; i++)
		{
			if(a[i] >= n)
			{
				printf("%d\n",i);
				break;
			}
		}
	}
	return 0;
	/**
	  C(k,k/2) = 2 * C(k-1,(k-1)/2) = k-1 * k-2 * . . . . * (k+1)/2 / (k-1)/2 * (k-3)/2 * . . . . 1 = a
	  C(k-1,(k-2)/2) = k-1 * k-2 * k-3 * . . . . . * (k+2/2) / (k-2)/2 * (k-4)/2 * . . . . . . . 1 = b

	  if k is even
	  da = db
	  na = nb * (k+1)/2
	  a=b*(k+1)/2

	  if k is odd
	  da =  db * (k-1)/2
	  na = nb
	  a = b / (k-1)/2

	 **/
}
