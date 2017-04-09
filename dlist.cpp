#include <stdio.h>


struct Node{
	int value;
	Node* pre;
	Node* next;
};
Node* first;
Node* last;

Node* insert(int value, Node* p){
	if(p == NULL) return;
	Node* q = new Node;
	q->value = value;
	q->left = NULL;
	q->next = NULL;
	if(first == NULL && last == NULL){
		first = q;
		last = q;
	}
	Node* pp = p->pre;
	if(p == first){
		first = q;
	}
	p->next = q;
	p->
}
void readFile(){

}
void insertAfter(int x, Node* p){

}
void printListL2R(){

}
void printListR2L(){
	
}

int main(int argc, char** argv){

}