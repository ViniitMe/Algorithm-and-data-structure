#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 9

int min_dist(int dist[], bool set[])
{
	int min=INT_MAX;
	int m;
	int v;
	for(v=0; v<V; v++)
	{
		if(dist[v]<min && set[v]==false)
		{
			min=dist[v];
			m=v;
		}
	}
	return m;
}

void printer(int dist[])
{
	int i;
	printf("Vertex   Distance from source\n");
	for(i=0;i<V;i++)
	{
		printf("%d     %d\n",i,dist[i]);
	}
}

void dijsktras(int graph[V][V],int source)
{
	int dist[V];
	int parent[V];
	bool set[V];

	int i;
	for(i=0;i<V;i++)
	{
		dist[i]=INT_MAX;
		set[i]=false;
	}
	dist[source]=0;
	parent[source]=-1;

	int j;
	for(j=0;j<V-1;j++)
	{
		int m=min_dist(dist,set);
		set[m]=true;
		for(int v=0;v<V;v++)
		{
			if(graph[m][v]!=0 && set[v]==false && dist[v]>graph[m][v]+dist[m])
			{
				dist[v]=graph[m][v]+dist[m];
				parent[v]=m;
			} 
		}
	}
	printer(dist);
}

int main()
{
	int graph[V][V]={{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 14, 10, 0, 2, 0, 0},
                      {0, 0, 0, 0, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };
    dijsktras(graph,0);
}