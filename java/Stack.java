import java.util.*;
public class Stack{
	private ArrayList<Integer> list;
	Stack (){
		list = new ArrayList<Integer>();
	}
	public void push(int x){
		list.add(x);
	}
	public int pop(int x){
		if (list.isEmpty()){
			System.out.println("list is empty");
			return(-1);
		}
		else{
			int popped = list.get(list.size() -1);
			list.remove(list.size() -1);
			return popped;
		}
	}
	public void display(){
		if (list.isEmpty()){
			System.out.println("list is empty");
		}
		else {
			for (int iterator : list){
				System.out.println(iterator);	
			}
		}
	}
	public static void main(String[] args){
		Stack stack = new Stack();
		stack.push(5);
		stack.push(2);
		stack.push(1);
		stack.display();
	}
}




