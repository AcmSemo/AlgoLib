#include <stdio.h>
#include <string.h>

#define MAX 100
#define initial 1
#define visited 2
#define finished 3
int n;
int adj[MAX][MAX];
int state[MAX];

void create_graph()
{
	int i,maxedges,src,dest,tmp;
	printf("Enter number of vertices: ");
	scanf("%d",&n);
	maxedges=n*(n-1);
	for (i=1;i<=maxedges;i++)
	{
		printf("Enter edge %d ((-1,-1) to quit): ",i);
		scanf("%d%d",&src,&dest);
		if (src==-1 && dest==-1)
			break;
		if (src>=n||dest>=n||src<0||dest<0)
		{
			printf("Invalid edge\n");
			i--;
		}
		else
			adj[src][dest]=1;
	}
}

void dfs(int v)
{
	int i;
	printf("%d ",v);
	state[v]=visited;
	for (i=0;i<=n;i++)
	{
		if (adj[v][i]==1 && state[i]==initial)
			dfs(i);
	}
	state[v]=finished;
}

void dftraversal()
{
	int v;
	for (v=0;v<n;v++)
		state[v]=initial;
	printf("Enter starting vertex for dfs.\n");
	scanf("%d",&v);
	dfs(v);
	for (v=0;v<n;v++)
	{
		if (state[v]==initial)
			dfs(v);
	}
	printf("\n");
}

int main()
{
	create_graph();
	dftraversal();
	return 0;
}
