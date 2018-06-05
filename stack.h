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
template <class T>
class Stack{
	vector<T> stack;
	public:
		/**
		 * pushing elements onto the stack.
		 * @param param1 int variable 
		 * @return void
		 */
		void push( T x ){
			stack.push_back(x);
		}
		/**
		 * removes the last element from the stack.
		 * @return void
		 */
		T pop(){
			T popped;
			if (stack.empty()){				//Checing for empty stack
				cout<<"Stack is empty"<<endl;
				return(-1);
			}
			else {
				popped = stack.back();
				stack.pop_back();
				return(popped);
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
//			vector<T>:: iterator it;	
//			for (auto it = stack.end() -1; it>= stack.begin(); --it ){
//				cout<<*it<<"\t";
//			}
//				cout<<endl;
//			}
				for (int i = 0; i < stack.size(); ++i ){
					cout<<stack.at(i);
				}
				cout<<endl;
			}
		}
		
		bool isEmpty(){
			if (stack.empty()){
				return true;
			}
			else{
				return false;
			}
		}
};

