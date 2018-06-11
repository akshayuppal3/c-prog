/**************************************************
 A Simple program for queue implementation with Enquue
 and Deque and display operation

 @author: Akshay
 system: C++ windows
--------------------------------------------------*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
/**
 * Class Queue
 * Implements simple stack (LIFO) with simple operation like Push and Pop 
 */
template <class T>
class Queue{
	vector<T> queue;
	public:
	/**
		 * pushing elements onto the queue
		 * @param param1 int variable 
		 * @return void
		 */
	void enqueu(T x){
		queue.push_back(x);
	}
	
	/**
		 * removing elements from the queue
		 * @return void
		 */
	T dequeu(){
		T popped;
		if (queue.empty()){
			cout<<"Queue is empty"<<endl;
			return(-1);
		}
		else{
			popped = *queue.begin();
			queue.erase(queue.begin());
			return(popped);
		}
	}
	
	/**
		 * displaying elements in the queue
		 * @return void
		 */
	void display(){
		//vector<T>::iterator it;
		int i;
		if (queue.empty()){
			cout<<"Queue is empty"<<endl;
		}
		else{
			cout<<"Queue"<<endl;
			for (i =0 ; i < queue.size() ; ++i ){
				cout<<queue.at(i);
			}
			cout<<endl;
		}
	 }
	 
	bool isEmpty(){
		if(queue.empty())
			return(true);
		else{
			return(false);
		}
	}
	
	/**
		 * check for elements in the queue
		 * @return bool
		 */
		/**
		 * check for elements in the queue
		 * @param int
		 * @return bool
		 */
	bool inQueue(T x){
		if (find(queue.begin(),queue.end(),x)== queue.end()){
			return (false);
			}
		else{
			return (true);
			}
		}  
};
