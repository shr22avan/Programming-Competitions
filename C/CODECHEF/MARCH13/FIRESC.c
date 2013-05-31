#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_SIZE 100000
#define MOD 1000000007
#define ull unsigned long long int
typedef int struct_v;
struct object{struct_v v;struct object *next;};
typedef struct object object;
object* new_node(struct_v v)
{
	object *t=(object*)malloc(sizeof(object));
	t->v=v;
	return t;
}
object add(object **head,struct_v v)
{
	object *t=new_node(v);
	t->next=*head;
	*head=t;
}
struct_v top(object **head)
{
	if(*head)
		return (*head)->v;
	else
		printf("Error: The List is empty\n");
}
void pop(object **head)
{
	if(*head)
	{
		object *t=*head;
		(*head)=t->next;
		free(t);
	}
	else
		printf("Error:Cannot delete from empty list\n");
}
void clear(object **head)
{
	while(*head)
	{
		pop(head);
	}
}
object* list[MAX_SIZE];
int component[MAX_SIZE];
ull counter;
void dfs(int i)
{
	component[i]=counter;
	object *t=list[i];
	while(t)
	{	
		if(!component[t->v])
		{
			dfs(t->v);
		}
		t=t->next;
	}
}
int main()
{
	int t,n,m,p,q,i,j,e[MAX_SIZE];
	ull k;
	scanf("%d",&t);
	while(t--)
	{
		memset(list,0,sizeof(list));
		memset(component,0,sizeof(component));
		scanf("%d%d",&n,&m);
		for(i=0;i<m;i++)
		{
			scanf("%d%lld",&j,&k);
			add(&list[j-1],k-1);			
			add(&list[k-1],j-1);
		}
		counter=1;
		for(i=0;i<n;i++)
		{
			if(!component[i])
			{
				dfs(i);
				counter++;
			}
		}
		memset(e,0,sizeof(e));
		for(i=0;i<n;i++)
		{
			e[component[i]-1]++;
		}
		k=1;
		for(i=0;i<counter-1;i++)
		{
			k*=e[i];
			if(k>=MOD)
				k%=MOD;
		}
		printf("%lld %lld\n",counter-1,k);
	}
	return 0;
}
