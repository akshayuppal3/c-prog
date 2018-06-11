/**************************************************
 A Simple program for queue implementation with Enquue
 and Deque and display operation

 @author: Akshay
 system: C++ windows
--------------------------------------------------*/
#include<iostream>
#include<utility>
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
//		auto vector< T >::iterator;
//		auto it = queue.begin();
		int i;
		if (queue.empty()){
			cout<<"Queue is empty"<<endl;
		}
		else{
			cout<<"Queue"<<endl;
//			for (auto it = queue.begin(); it!= queue.end(); ++it){
//				cout<<*it<<"\t";
//			}
			for (i =0 ; i < queue.size() ; ++i ){
				cout<<" "<<queue.at(i);
			}
			cout<<endl;
		}
	 }
	
	/**
		 * check if queue empty
		 * @return bool
		 */
	bool isEmpty(){
		if(queue.empty())
			return(true);
		else{
			return(false);
		}
	}
	
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

int main() {
	Queue<string> queue;
	char character;
	const char EXIT_CODE = 'X';
	string value;
//	int popped;
	
	do {
	cout<<"Enter the options for the program \t\n1) E : enqueu \n2) O : dequeue \n3) D: display \n4) I: check in queue \n";
	cin>>character;
	
	switch(character){
		case 'E': cout<<"Enter the values to enque ";
				cin>>value;
				queue.enqueu(value);
				break;
		case 'O': value = queue.dequeu();
				 cout<<value<<endl;
				break;
		case 'D': queue.display();
				break;
		case 'I': cout<<"Enter the element to check in queue ";
				  cin>>value;
				  (queue.inQueue(value))? cout<<"True\n" : cout<<"False\n";
				  break;
		default: character = 'X';
				break; 
		}
	}while(character != EXIT_CODE);
	return 0;
}
