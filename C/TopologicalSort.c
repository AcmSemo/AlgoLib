#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX 1000

int adj[MAX][MAX];
int n,min,max;
int visited[MAX];

int isFull(int top)
{
	return (top==MAX-1);
}

int isEmpty(int top)
{
	return (top==-1);
}

void push(int stack[], int *top, int item)
{
	if (isFull(*top))
	{
		printf("Stack Overflow!\n");
		return;
	}
	*top=*top+1;
	stack[*top]=item;
}

int pop(int stack[], int *top)
{
	int item;
	if (isEmpty(*top))
	{
		printf("Stack Underflow!\n");
		exit(1);
	}
	item=stack[*top];
	*top=*top-1;
	return item;
}

void toposort(int v, int stack[], int* top)
{
	visited[v]=1;
	int i;
	for (i=max;i>=min;i--)
	{
		if (!visited[i] && adj[v][i]==1)
			toposort(i,stack,top);
	}
	push(stack,top,v);
}

void toposortutil()
{
	int stack[MAX],top=-1;
	int i;
	for (i=0;i<MAX;i++)
		visited[i]=0;
	for (i=max;i>=min;i--)
	{
		if (!visited[i])
			toposort(i,stack,&top);
	}
	char c;
	while (!isEmpty(top))
	{
		printf("%c ", pop(stack, &top));
	}
}

int main() 
{
	int e,f;
	char a,b;
	char str[10];
	scanf("%d%d%d",&n,&e,&f);
	min=1000,max=0;
	while (e--)
	{
		scanf(" %c %s %c",&a,str,&b);
		adj[a][b]=1;
		if (!f)
			adj[b][a]=1;
		if (a<min)
			min=a;
		if (b<min)
			min=b;
		if (a>max)
			max=a;
		if (b>max)
			max=b;
	}
	toposortutil();
    return 0;
}
