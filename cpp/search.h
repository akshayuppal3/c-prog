/**************************************************
 A Simple program for Graph implementation wih insertEdge 
 checkEdge, and displayAdjacent operation

 @author: Akshay
 system: C++ windows
--------------------------------------------------*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include"graph.h"
#include"queue.h"
#include"stack.h"

using namespace std;

class Search{
	public:
	static void bfs(Graph g,int source){
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
			sort(list.begin(), list.end());
			for (it = list.begin(); it != list.end(); ++it){
				if (find(visited.begin(),visited.end(),*it) == visited.end()){          //if node not visited
					fringe.enqueu(*it);
					visited.push_back(*it);												//visited updated			
				}
			}
		}
	}
	
	static void dfs(Graph g,int source){
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
			sort(list.begin(), list.end(),greater<int>());
	//		for(int i=0; i<list.size();++i){ cout<<list.at(i)}
			for (it = list.begin(); it != list.end(); ++it){
				if (find(visited.begin(),visited.end(),*it) == visited.end()){          //if node not visited
					fringe.push(*it);
					visited.push_back(*it);												//visited updated			
				}
			}
		}
	}

};

