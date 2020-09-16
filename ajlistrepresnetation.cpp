#include<bits/stdc++.h>
// #include<list>
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
};
int32_t main(){
	//graph has 5 vertices numbered from 0 to 4
	Graph<int> g;
	g.addEdge(0,1,true);
	g.addEdge(0,4);
	g.addEdge(4,3);
	g.addEdge(1,4);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.printAdjList();
	return 0;
}