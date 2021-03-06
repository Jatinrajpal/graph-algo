#include<bits/stdc++.h>
#define int long long int
using namespace std;
template<typename T>
class Graph{
	map<T,list<T>> l;
public:
	Graph()
	{
	}
	void addEdge(T u,T v,bool bidir=true)
	{
		l[u].push_back(v);
		if(bidir){
			l[v].push_back(u);
		}
	}
	void printAdjList(){
		for(auto i:l)
		{
			cout<<i.first<<"->";
			// l[i] is a linkedlist
			for(auto vertex:i.second)
			{
				cout<<vertex<<",";
			}
			cout<<endl;
		}
	}
	int bfs(T src,T dest)
	{
		queue<T> q;
		map<T,int> dist;
		map<T,T> parent; 
		for(auto i:l)
		{
			dist[i]=INT_MAX;
		}
		dist[src]=0;
		q.push(src);
		// visited[src]=true;
		parent[src]=src;
		while(!q.empty())
		{
			T node=q.front();
			// cout<<node<<" ";
			q.pop();
			for(int neigbour:l[node]){
				if(dist[neigbour]==INT_MAX)
				{
					dist[neigbour]=dist[node]+1;
					q.push(neigbour);
					// visited[neigbour]=true;
					parent[neigbour]=node;
				}
			}
		}
		
		// cout<<"\n";
		return dist[dest];
	}
	void dfsHelper(T src,map<T,bool> &visited)
		{
			visited[src]=true;
			cout<<src<<" ";
			for(auto neigbour:l[src])
			{
				if(!visited[neigbour])
				{
					dfsHelper(neigbour,visited);
				}
			}
		}
		void dfs(T src)
		{
			map<T,bool> visited;
			dfsHelper(src,visited);
		}
};
int32_t main()
{
Graph<int> g;
	g.addEdge(0,1,true);
	g.addEdge(0,4);
	g.addEdge(4,3);
	g.addEdge(1,4);
	g.addEdge(1,2);
	g.addEdge(2,3);
	// g.bfs(0,3);
	g.dfs(0);
	return 0;
}
