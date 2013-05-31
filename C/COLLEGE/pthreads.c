#include<pthread.h>
#include<stdio.h>
int a[100];
void *runner(void *param)
{
	int n=atoi(param),i;
	printf("CHILD: generating fibonacci\n");
	a[1]=0,a[2]=1;
	for(i=3;i<=n;i++)
		a[i]=a[i-1]+a[i-2];
}
int main(int argc,char *argv[])
{
	int i;
	if(argc<2 || atoi(argv[1])<2)
	{
		fprintf(stderr,"Usage: ./a.out <number > 1>\n");
		return 0;
	}
	pthread_t tid;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_create(&tid,&attr,runner,argv[1]);
	pthread_join(tid,NULL);
	printf("PARENT: Displaying Fibonacci\n");
	for(i=1;i<=atoi(argv[1]);i++)
		printf("fib(%d)=%d\n",i,a[i]);
	return 0;
}
