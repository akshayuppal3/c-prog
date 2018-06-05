/**************************************************
 A Simple program for LinkList implementation wih insertBeg 
 insertEnd, delBeg, DelEnd and display operation

 @author: Akshay
 system: C++ windows
--------------------------------------------------*/
#include<iostream>
#include<vector>
using namespace std;
/**
 * Class LinkList
 * Implements simple stack (LIFO) with simple operation like Push and Pop 
 */
class LinkedList{
	friend class Graph;
	int data;
	LinkedList* link;
	public:
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

int main(){
	LinkedList *head = new LinkedList;
	head = NULL;
	char character;
	const char EXIT_CODE = 'X';
	int value;
	bool check;
	
	do {
	cout<<"Enter the options for the program \t\n0) Q: Find existance of element \n1) B : insert_beg \n2) E : insert_end \n3) D : delete_beg \n4) T: delete_end \n5) J: delete_middle \n6) Y: display \n"; //
 	cin>>character;
	
	switch(character){
		case 'B': cout<<"Enter the values to enque ";
				cin>>value;
				head = head->addBeg(head, value);
				break;
		case 'E': cout<<"Enter the values to enque ";
				cin>>value;
				head = head->addEnd(head, value);
				break;
		case 'D': head = head->delBeg(head);
				    break;
		case 'T': head = head->delEnd(head);
				    break;
		case 'J': cout<<"Enter the value you want to delete";
				  cin>>value; 
				  head = head->delMiddle(head,value);
				  break;		    
		case 'Y': head->display(head);
				break;
		case 'Q' : cout<<"Enter the value you want to check in the list "; 
				 cin>>value;
				 (head->finder(head,value))? cout<<"True"<<endl : cout<<"False"<<endl;
				 break;
		default: character = 'X';
				break; 
		}
	}while(character != EXIT_CODE);
	return 0;
}
