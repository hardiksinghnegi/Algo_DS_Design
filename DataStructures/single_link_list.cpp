#include<iostream>
using namespace std;

class Node{

   int data;
   Node *next;

public:
	Node(int val){
	  data = val;
	  next = NULL;
	};

	int getValue(){
	  return data;
	};
	
	void setValue(int val){
	  data = val;
	};
	
	void setNext(Node* forw){
	  next = forw;
	};
	
	Node* getNext(){
	  return next;
	};
};

class List{

   Node* head;

public:
	List(){
	 head = NULL;
	};
	
	void insertNode(int val);
	void deleteNode(int val);
	void displayList();
};

void List::insertNode(int val){

  Node *newNode = new Node(val);
  
  if(head==NULL){
	head = newNode;
  }
  else{
	Node* tmp = head;
	while((tmp->getNext())!=NULL){
		tmp = tmp->getNext();
	}
	tmp->setNext(newNode);
 }
}

void List::deleteNode(int val){

  if(head==NULL){
    cout<<"Underflow"<<endl;
  }
  else if((head->getValue())== val){
    Node* tmp = head;
    head = head->getNext();
    tmp->setNext(NULL);
    delete tmp;
  }
  else{
    Node *tmp,*prev;
    tmp = head;
    prev = head;
    while(tmp!=NULL){
	if((tmp->getValue())==val){
	   prev->setNext(tmp->getNext());
           delete tmp;
	   break;
	}
        prev = tmp;
	tmp = tmp->getNext();
    }
    if(tmp==NULL){
	cout<<"Value Not Found"<<endl;
    }	
  }
}

void List::displayList(){
 
  Node* tmp = head;
  if(tmp==NULL){
	cout<<"The List is empty"<<endl;
  }
  else{

    while(tmp!=NULL){
 
	cout<<tmp->getValue()<<endl;
	tmp = tmp->getNext();
    }
  }
}

int main(){

 List chain;
 chain.insertNode(10);
 chain.insertNode(7);
 chain.insertNode(8);

 chain.displayList();
 chain.deleteNode(0);
 chain.displayList();
}
