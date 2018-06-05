/**************************************************
 A Simple program for Graph implementation wih insertEdge 
 checkEdge, and displayAdjacent operation

 @author: Akshay
 system: C++ windows
--------------------------------------------------*/
#include<iostream>
#include<vector>
#include<string>
#include"graph.h"
#include"queue.h"
#include"stack.h"


using namespace std;

void bfs(Graph g,int source){
	Queue<int> fringe;
	vector<int> visited;
	vector<int> list;
	vector<int>::iterator it;
	fringe.enqueu((source));
	visited.push_back(source);
	int temp;
	int goal;
	while (fringe.isEmpty() == false){
		temp = fringe.dequeu();
		cout<<temp<<" ";
		//visited.push_back(temp);
		//if (temp == goal){ return (temp);}    //check if temp is goal then return and stop DFS
		list = g.getAdj(temp);
		for (it = list.begin(); it != list.end(); ++it){
			if (find(visited.begin(),visited.end(),*it) == visited.end()){          //if node not visited
				fringe.enqueu(*it);
				visited.push_back(*it);												//visited updated			
			}
		}
	}
}

void dfs(Graph g,int source){
	Stack<int> fringe;
	vector<int> visited;
	vector<int> list;
	vector<int>::iterator it;
	fringe.push((source));
	visited.push_back(source);
	int temp;
	int goal;
	while (fringe.isEmpty() == false){
		temp = fringe.pop();
		cout<<temp<<" ";
		//visited.push_back(temp);
		//if (temp == goal){ return (temp);}    //check if temp is goal then return and stop DFS
		list = g.getAdj(temp);
		for (it = list.begin(); it != list.end(); ++it){
			if (find(visited.begin(),visited.end(),*it) == visited.end()){          //if node not visited
				fringe.push(*it);
				visited.push_back(*it);												//visited updated			
			}
		}
	}
}


int main(){
	Graph g;
	g.add_edge(1,2);
	g.add_edge(1,7);
	g.add_edge(1,4);
	g.add_edge(1,5);
	g.add_edge(2,3);
	g.add_edge(2,5);
	g.add_edge(3,2);
	g.add_edge(3,7);
	g.add_edge(3,4);
	g.add_edge(3,6);
	g.add_edge(4,3);
	g.add_edge(4,1);
	g.add_edge(4,7);
	g.add_edge(4,5);
	g.add_edge(5,4);
	g.add_edge(5,2);
	g.add_edge(5,1);
	g.add_edge(5,6);
	g.add_edge(6,5);
	g.add_edge(6,3);
	g.add_edge(6,7);
	g.add_edge(7,1);
	g.add_edge(7,3);
	g.add_edge(7,4);
	g.add_edge(7,6);
	
	bfs(g,1);
	cout<<endl;
	dfs(g,1);
	return 0;
}



