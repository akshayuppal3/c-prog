/**************************************************
 A Simple header for Graph implementation wih insertEdge 
 checkEdge, and displayAdjacent operation

 @author: Akshay
 system: C++ windows
--------------------------------------------------*/
#include<iostream>
#include<map>
#include<vector>
#include"linkedList.h"

using namespace std;

//@graph
class Graph: public LinkedList{
	map<int, LinkedList* > vertex;
	public:
	void add_edge(int node1, int node2){
		//if node1 present in the key
		map<int, LinkedList *>::iterator i = vertex.find(node1);
		if( i != vertex.end() ) {
			LinkedList *temp = i->second;
			if(temp == NULL){
				temp->data = node2;
				temp->link = NULL;
			  }
			else {
				if (temp->finder(temp,node2) == false){          //adding the new node to adjacency list only if node2 not present
					temp = temp->addEnd(temp, node2);
					vertex[node1] = temp;                          //Update the map after inserting the new node to the adjacenccy list
				}
				//else{}                                       //In case edge node1-node2 already present we dont add it in
		     }
	    } //if node1 not present in the key
		else{ //creating a new hash for node1 if not present with one adjacent node (node2)
			LinkedList *temp = new LinkedList;
			temp->data = node2;    
			temp->link = NULL;
			vertex.insert( pair<int, LinkedList *> (node1, temp));
		}	    	     
	}
	
	void displayAdj(int node1){
		map<int, LinkedList *>::iterator it = vertex.find(node1); //= vertex.find(node1);
		if( it  != vertex.end() ) {
			LinkedList *temp = it->second;
			cout<<"Adjacent node ";
			temp->display(temp);
		}
		else{
			cout<<"Adjacent node of "<<node1<<" doesn't exists";
		 }
		
	} 
	/**
		 * return adjacent elements of the vertex
		 * @param param1 LinkList head pointer
		 * @return vector<int>
		 */
	vector<int> getAdj(int node1){
		map<int, LinkedList *>::iterator it =  vertex.find(node1);
		vector<int> list;
		if (it != vertex.end()){
			LinkedList *temp = it->second;
			list = temp->getNodes(temp);
		}
		else{
			return(list);
		}
	}	
	
	
	bool checkEdge(int node1, int node2){
		map<int, LinkedList *>:: iterator i = vertex.find(node1);
		if (i != vertex.end()){
			LinkedList *temp = i->second;
			if(temp->finder(temp,node2)){
				return(true);
			}
			else
			{
				return(false);
			}
		}
		else{
			return(false);
		}
	}	
};
