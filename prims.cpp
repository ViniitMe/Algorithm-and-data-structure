#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 5   //No.of vertices in the graph

int min_index(int key[], bool set[])
{
	int v;
	int min=INT_MAX;
	int m;
	for(v=0;v<V;v++)
	{
		if(set[v]==false && key[v]<min)
		{
			min=key[v];
			m=v;
		}
	}
	return m;
}


void printmst(int parent[],int graph[V][V])
{
	int i;
	for(i=1;i<V;i++)  //note: we will print from i=1
	{
		printf("Edge:%d-%d  Weight:%d\n",parent[i],i,graph[i][parent[i]]);
	}
}



void prim(int graph[V][V])    //note: we have to bound graph
{
	int key[V];
	int parent[V];
	bool set[V];
	int i;
	for(i=0;i<V;i++)
	{
		key[i]=INT_MAX;
		set[i]=false;
	}
	//printf("max:%d",INT_MAX);  //for viewing max int
	int j;
	key[0]=0;
	parent[0]=-1 ;  //first vertex will not have any parent

	for(j=0;j<V-1;j++)
	{
		int m=min_index(key,set);         //m=index of the vertex with minimum key value
		set[m]=true;
		for(int v=0;v<V;v++)
		{
			if(graph[m][v]!=0 && set[v]==false && graph[m][v]<key[v])
			{
				key[v]=graph[m][v];
				parent[v]=m;
			}
		}
	}
	printmst(parent,graph);
}

int main()
{
	//firstly declaring the graph and then writing the values will throw error
	int graph[V][V]={{0,10,20,0,0},
				 {10,0,30,5,0},
				 {20,30,0,15,6},
				 {0,5,15,0,8},
				 {0,0,6,8,0},
				};
	int i,j;
	printf("Adjacency matrix representation of given graph:\n");
	for(i=0;i<V;i++)
	{
		for(j=0;j<V;j++)
		{
			printf("%d ",graph[i][j]);
		}
		printf("\n");
	}
	prim(graph);
}