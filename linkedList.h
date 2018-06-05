/**************************************************
 A header file for LinkedList functionalities 
 checkEdge, and displayAdjacent operation

 @author: Akshay
 system: C++ windows
--------------------------------------------------*/
#include<map>
#include<vector>
#include<iostream>

using namespace std;

class LinkedList{
	//friend class Graph;
	public:
	int data;
	LinkedList* link;
	/**
		 * adding element at the beginning of linklist
		 * @param param1 LinkList pointer
		 * @param param2 int variable  
		 * @return void
		 */
	LinkedList * addBeg(LinkedList *p, int x){
		if (p == NULL){
			LinkedList *p = new LinkedList;
			p->link = NULL;
			p->data = x;
			return (p);
		}
		else {
			LinkedList *temp = new LinkedList;	
			temp->link = p;
			temp->data = x;
			return(temp);
		} 
	}
	
	/**
		 * adding element at the end of linklist
		 * @param param1 LinkList pointer
		 * @param param2 int variable  
		 * @return void
		 */
	LinkedList * addEnd(LinkedList *p , int x){
		if (p == NULL){
			LinkedList *p = new LinkedList;
			p->link = NULL;
			p->data = x;
			return(p);
		}
		else {
			LinkedList *temp = new LinkedList;
			temp->data = x;
			temp->link = NULL;
			LinkedList *t = p;
			while(t->link != NULL){
				t = t->link;
			}
			t->link = temp;
			return (p);
		}
	}
	/**
		 * deleting from the beginning of linklist
		 * @param param1 LinkList pointer
		 * @return void
		 */
	LinkedList *delBeg(LinkedList *p){
		if (p == NULL){
			cout<<"Linked list is empty"<<endl;
			return(NULL);
		}
		else if(p->link == NULL){
			p = NULL;
			return(p);
		}
		else{
			p = p->link;
			return(p);
		}
	}
	
	/**
		 * deleting from the end of linklist
		 * @param param1 LinkList head pointer
		 * @return void
		 */
	LinkedList * delEnd(LinkedList *head){
		if (head == NULL){
			cout<<"Linked list is empty"<<endl;
			return(NULL);
		}
		else if(head->link == NULL){
			head = NULL;
			return(head);
		}
		else{
			LinkedList * temp = head;
			while(temp->link->link != NULL){
				temp = temp->link;
			}
			temp->link = NULL;
			return(head);
		}
	}
	
	/**
		 * deleting from the end of linklist
		 * @param param1 LinkList head pointer
		 * @return void
		 */
	LinkedList * delMiddle(LinkedList *head, int data){
		if(head == NULL){
			cout<<"Linked list is empty"<<endl;
			return(head);
		}
		//First element is he element to be deleted
		else if (head->data == data){
			head = head->delBeg(head);
			return(head);
		}
		else{
			LinkedList *temp = head;
			bool flag = false;
			while(temp != NULL){
				if(temp->link->data == data){
					flag = true;
					break;
				}
				temp = temp->link;
			}
			if (flag == true){
				temp->link = temp->link->link;
				return(head);
			}
			else{
				cout<<"data not found in the linked list"<<endl;
				return(head);
			}
		}
	}
	
	/**
		 * get adjacent elements in the linklist
		 * @param param1 LinkList head pointer
		 * @return void
		 */
	vector<int> getNodes(LinkedList *head){
		vector<int> list;
		int temp_data;
		if (head == NULL){
			return(list);
		}
		else{
			LinkedList *temp = head;
			while (temp != NULL){
				list.push_back(temp->data);
				temp = temp->link;
			}
			return(list);
		}
	}
	
	/**
		 * display element in the linklist
		 * @param param1 LinkList head pointer
		 * @return void
		 */	
	void display (LinkedList *head){
		if (head== NULL){
			cout<<"Linked list is empty"<<endl;
		}
		else{
			LinkedList *temp = head;
			while(temp != NULL){
				cout<<temp->data<<"\t";
				temp = temp->link; 
				}
			cout<<endl;	
		}
	}
	
	/**
		 * check if element exists in the linklist
		 * @param param1 LinkList head pointer
		 * @param param2 data
		 * @return void
		 */	
	bool finder(LinkedList * head, int data){
		if (head == NULL){
			return (false);
		}
		else {
			LinkedList * temp = head;
			while(temp != NULL){
				if(temp->data == data){
					return (true);
				}
				temp = temp->link;
			}
			return(false);
		}
	}
	
		
};
