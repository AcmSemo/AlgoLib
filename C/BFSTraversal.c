#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#define initial 1
#define waiting 2
#define visited 3

void create_graph(int adj[MAX][MAX], int* n)
{
	int i,maxedges,src,dest,tmp;
	printf("Enter number of vertices: ");
	scanf("%d",&tmp);
	*n=tmp;
	maxedges=tmp*(tmp-1);
	for (i=1;i<=maxedges;i++)
	{
		printf("Enter edge %d ((-1,-1) to quit): ",i);
		scanf("%d%d",&src,&dest);
		if (src==-1 && dest==-1)
			break;
		if (src>=tmp||dest>=tmp||src<0||dest<0)
		{
			printf("Invalid edge\n");
			i--;
		}
		else
			adj[src][dest]=1;
	}
}

int isFull(int rear)
{
	return (rear==MAX-1);
}

int isEmpty(int front, int rear)
{
	return (front==-1 || front==rear+1);
}

void enqueue(int queue[], int *front, int *rear, int item)
{
	if (isFull(*rear))
	{
		printf("Queue Overflow!\n");
		return;
	}
	if (*front==-1)
		*front=0;
	*rear=*rear+1;
	queue[*rear]=item;
}

int dequeue(int queue[], int *front, int *rear)
{
	int item;
	if (isEmpty(*front,*rear))
	{
		printf("Queue Underflow!\n");
		exit(1);
	}
	item=queue[*front];
	*front=*front+1;
	return item;
}

void bfs(int v,int adj[MAX][MAX], int n, int state[], int queue[], int front, int rear)
{
	int i;
	enqueue(queue,&front,&rear,v);
	state[v]=waiting;
	while (!isEmpty(front,rear))
	{
		v=dequeue(queue,&front,&rear);
		printf("%d ",v);
		state[v]=visited;
		for (i=0;i<n;i++)
		{
			if (adj[v][i]==1 && state[i]==initial)
			{
				enqueue(queue,&front,&rear,i);
				state[i]=waiting;
			}
		}
	}
	printf("\n");
}

void bftraversal(int adj[MAX][MAX], int n, int state[], int queue[], int front, int rear)
{
	int v;
	for (v=0;v<n;v++)
		state[v]=initial;
	printf("Enter starting vertex for bfs: ");
	scanf("%d",&v);
	bfs(v,adj,n,state,queue,front,rear);
	/* // Add code to print all vertices (unreachable from starting vertex)
	for (v=0;v<n;v++)
	{
		if (state[v]==initial)
			bfs(v,adj,n,state,queue,front,rear);
	}
	*/
}

int main()
{
	int n,adj[MAX][MAX],state[MAX],queue[MAX];
	int front=-1,rear=-1;
	create_graph(adj,&n);
	bftraversal(adj,n,state,queue,front,rear);
	return 0;
}
