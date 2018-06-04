/**************************************************
 A Simple program for queue implementation with Enquue
 and Deque and display operation

 @author: Akshay
 system: C++ windows
--------------------------------------------------*/
#include<iostream>
#include<vector>

using namespace std;
/**
 * Class Queue
 * Implements simple stack (LIFO) with simple operation like Push and Pop 
 */
class Queue{
	vector<int> queue;
	public:
	/**
		 * pushing elements onto the queue
		 * @param param1 int variable 
		 * @return void
		 */
	void enqueu(int x){
		queue.push_back(x);
	}
	
	/**
		 * removing elements from the queue
		 * @return void
		 */
	void dequeu(){
		if (queue.empty()){
			cout<<"Queue is empty"<<endl;
		}
	else{
		queue.erase(queue.begin());
		}
	}
	
	/**
		 * displaying elements in the queue
		 * @return void
		 */
	void display(){
		vector<int>::iterator it;
		if (queue.empty()){
			cout<<"Queue is empty"<<endl;
		}
		else{
			cout<<"Queue"<<endl;
			for (it = queue.begin(); it!= queue.end(); ++it){
				cout<<*it<<"\t";
			}
		}
	 } 
};

int main() {
	Queue queue;
	char character;
	const char EXIT_CODE = 'X';
	int value;
	
	do {
	cout<<"Enter the options for the program \t\n1) E : enqueu \n2) O : dequeue \n3) D: display \n";
	cin>>character;
	
	switch(character){
		case 'E': cout<<"Enter the values to enque ";
				cin>>value;
				queue.enqueu(value);
				break;
		case 'O': queue.dequeu();
				break;
		case 'D': queue.display();
				break;
		default: character = 'X';
				break; 
		}
	}while(character != EXIT_CODE);
	return 0;
}
