/**************************************************
 A Simple header for Graph implementation wih insertEdge 
 checkEdge, and displayAdjacent operation

 @author: Akshay
 system: C++ windows
--------------------------------------------------*/
#include<iostream>
#include<map>
#include<vector>
//#include"graph.h"
#include"search.h"

using namespace std;

class UndirectedGraph: public Graph {
	public:
	Graph g;
	void addEdge(int node1,int node2){
		g.add_edge(node1, node2);
		g.add_edge(node2, node1);
	}
};

int main(){
	UndirectedGraph g;
	int deg;
	float cc;
	g.addEdge(1,2);
	g.addEdge(1,7);
	g.addEdge(1,4);
	g.addEdge(1,5);
	g.addEdge(2,3);
	g.addEdge(2,5);
	g.addEdge(3,7);
	g.addEdge(3,4);
	g.addEdge(3,6);
	g.addEdge(4,7);
	g.addEdge(4,5);
	g.addEdge(5,6);
	g.addEdge(6,7);
	
	Search::bfs(g,1);
	g.displayAdj(1);
	return 0;
}
