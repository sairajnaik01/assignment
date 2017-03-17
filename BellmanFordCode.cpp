#include <iostream>
#include <limits.h>
#include <time.h>
#include <cmath>

using namespace std;

#define MAX 1000000000
#define ll long long int

//a structure to represent weighted edge in graph 
struct Edge
{
	int src,dest,w;
};

//function to print the the shortest distance
void print(int d[],int n)
{
	cout<<"Vertex   Distance from Source"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<i<<"\t\t"<<d[i]<<endl;
	}
	return;
}

void BellmanFord(int v,int e,Edge *edg)
{
	int d[v];
	d[0]=0;
	for(int i=1;i<v;i++)
	d[i]=MAX;
	for(int i=1;i<v;i++)
	{
		for(int j=0;j<e;j++)
		{
			int u=edg[j].src;
			int v=edg[j].dest;
			int w=edg[j].w;
			if(d[u]!=MAX&&d[u]+w<d[v])
			d[v]=d[u]+w;
		}
	}
	int fire=0;
	for(int i=0;i<e;i++)
	{
		int u=edg[i].src;
		int v=edg[i].dest;
		int w=edg[i].w;
		if(d[u]!=MAX&&d[u]+w<d[v])
		{
			cout<<"Graph contains negative weight cycle"<<endl;
			fire=1;
			break;
		}
	}
	if(fire==0)
	print(d,v);
	return;
}

int main()
{
	std::ios::sync_with_stdio(false);
	clock_t strt=clock();
	int v,e;
	cin>>v>>e;
	//e*=2;//this is for unidirected graph
	Edge *edg=new Edge[e];
	for(int i=0;i<e;i++)
	{
		cin>>edg[i].src>>edg[i].dest>>edg[i].w;
		//cin>>edg[i+1].src>>edg[i+1].dest>>edg[i+1].w;//this is for nidirected graph ones
	}
	BellmanFord(v,e,edg);
	cout<<"Execution Time : "<<(double)(clock() - strt)/CLOCKS_PER_SEC<<endl;
	return 0;
}
