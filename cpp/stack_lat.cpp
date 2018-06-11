/**************************************************
 A Simple program for stack implementation with Push
 and Pop operation

 @author: Akshay
 system: C++ windows
--------------------------------------------------*/
#include<iostream>
#include<vector>

using namespace std;

/**
 * Class Stack
 * Implements simple stack (LIFO) with simple operation like Push and Pop 
 */
class Stack{
	vector<int> stack;
	public:
		/**
		 * pushing elements onto the stack.
		 * @param param1 int variable 
		 * @return void
		 */
		void push( int x ){
			stack.push_back(x);
		}
		/**
		 * removes the last element from the stack.
		 * @return void
		 */
		void pop(){
			if (stack.empty()){				//Checing for empty stack
				cout<<"Stack is empty"<<endl;
			}
			else {
			stack.pop_back();
			}
		}
		/**
		 * displays element in the stack in reverse order.
		 * @param param1 class variable  
		 * @return void
		 */ 
		void display() {
			if (stack.empty()){
				cout<<"Stack is empty"<<endl;  //Checking for empty stack
			}
			else{
			vector<int>:: iterator it;	
			for (it = stack.end() -1; it>= stack.begin(); --it ){
				cout<<*it<<"\t";
			}
			cout<<endl;
			}
		}
};

// main method
int main() {
	Stack st;
	char character;
	const char EXIT_CODE = 'X';
	int value;
	
	do {
	cout<<"Enter the options for the program \t\n1) P : push \n2) O : pop \n3) D: display \n";
	cin>>character;
	
	switch(character){
		case 'P': cout<<"Enter the values to push ";
				cin>>value;
				st.push(value);
				break;
		case 'O': st.pop();
				break;
		case 'D': st.display();
				break;
		default: character = 'X';
				break; 
		}
	}while(character != EXIT_CODE);
	return 0;
}
