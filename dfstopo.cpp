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
	void dfsHelper(T node,map<T,bool> &visited,list<T> &ordering)
		{
			visited[node]=true;
			// we will call dfs on the unvisited neighbours of the current node
			for(T neigbour:l[node])
			{
				if(!visited[neigbour])
				{
					dfsHelper(neigbour,visited,ordering);
				}
			}
			//add 1 line for TS
			// at this point,all the children of current node have been visited
			//so we can add current node to the list
			ordering.push_front(node);
			 
		}
		void dfsTopologicalSort()
		{
			map<T,bool> visited;
			list<T> ordering;
			// dfsHelper(src,visited);
			for(auto i:l)
			{
				T node=i.first;
				if(!visited[node])
				{
					dfsHelper(node,visited,ordering);
				}
			}
			for(T element:ordering)
			{
				cout<<element<<"-->";
			}
		}
};
int32_t main()
{
Graph<string> g;
	g.addEdge("english","programming logic",false);
	g.addEdge("maths","programming logic",false);
	g.addEdge("programming logic","HTML",false);
	g.addEdge("programming logic","Python",false);
	g.addEdge("programming logic","Java",false);
	g.addEdge("programming logic","JS",false);
	g.addEdge("Python","Web Dev",false);
	g.addEdge("HTML","CSS",false);
	g.addEdge("CSS","JS",false);
	g.addEdge("JS","Web Dev",false);
	g.addEdge("Java","Web Dev",false);
	g.addEdge("Python","Web Dev",false);
	g.dfsTopologicalSort();
	return 0;
}
