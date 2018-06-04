/**************************************************
 A Simple program for LinkList implementation wih insertBeg 
 insertEnd, delBeg, DelEnd and display operation

 @author: Akshay
 system: C++ windows
--------------------------------------------------*/
#include<iostream>

using namespace std;
/**
 * Class LinkList
 * Implements simple stack (LIFO) with simple operation like Push and Pop 
 */
class LinkedList{
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
};

int main(){
	LinkedList *head = new LinkedList;
	head = NULL;
	char character;
	const char EXIT_CODE = 'X';
	int value;
	
	do {
	cout<<"Enter the options for the program \t\n1) B : insert_beg \n2) E : insert_end \n3) D : delete_beg \n4) T: delete_end \n5) Y: display \n"; //
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
		case 'Y': head->display(head);
				break;
		default: character = 'X';
				break; 
		}
	}while(character != EXIT_CODE);
	return 0;
}
