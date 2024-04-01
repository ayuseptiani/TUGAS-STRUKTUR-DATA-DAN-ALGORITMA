#include <iostream>
using namespace std;

class Node{
	public:
		char id;
		Node *next;
		
		Node(char id){
			this->id = id;
			this->next = NULL;
		}
};

class LinkedList{
	public:
		Node *head;
		Node *tail;
		
		LinkedList(){
			head = tail = NULL;
		}
		
		void insertToHead(char data){
			Node *node = new Node(data);
			if(head == NULL){
				head = tail = node;
			} else {
				node->next = head;
				head = node;
			}
		}
		
		void insertToTail(char data){
			Node *node = new Node(data);
			if(head == NULL){
				head = tail = node;
			} else {
				tail->next = node;
				tail = node;
			}
		}
		
		void insertAfter(char data, char after){
			Node *current = head;
			while(current != NULL && current->id != after){
				current = current->next;
			}
			
			if(current != NULL){
				Node *node = new Node(data);
				node->next = current->next;
				current->next = node;
				if(current == tail){
					tail = node;
				}
			}
		}
		
		void printALL(){
			Node *tmp = head;
			while(tmp != NULL){
				cout << tmp->id << "->";
				tmp = tmp->next;
			}
			cout << "NULL" << endl;
		}
};

int main(){
	LinkedList link1;
	
	link1.insertToTail('A');
	link1.insertToTail('B');
	link1.insertToTail('C');
	link1.printALL(); 
	
	link1.insertAfter('X', 'B');
	link1.printALL(); // Output: A->B->X->C->NULL
	
	return 0;
}