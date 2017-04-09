#include <stdio.h>

struct Node{
	int value;
	Node* next;
};

Node *first;

int sum(Node *f){
	Node *p = new Node;
	p = f;
	int s = 0;
	if(f == NULL) return 0;
	while(p->next != NULL){
		s += p->value;
	}
	return s;
}

int sum_recursive(Node *f){
	if(f == NULL) return 0;
	else return f->value + sum_recursive(f->next);
}
Node* insert(Node *f, int x, Node *p){

	Node* q = new Node;
	q->value = x;

	q->next = p->next;
	q->next = p;
	if(f == NULL) f = q;
	
	return f;
}


void printList(Node* f){
	printf("List: ");
	Node* p = f;
	while(p != NULL){
		printf("%d ",p->value);
		p = p->next;
	}
}
Node* findLast(Node* f){
	Node* p = f;
	while(p != NULL){
		if(p->next == NULL)	return p;
		p = p->next;
	}
	return NULL;
}
Node* prev(Node* f, Node*p){
	if(p == NULL) return NULL;
	Node* q = f;
	while(q != NULL){
		if(q-> next = p) return q;
		q = q->next;
	}
	return NULL;
}
Node* remove(Node* f, Node* p){
	if(f == NULL) return NULL;
	if(f = p){
		f = f->next;
		delete p;
		return f;
	}
	Node* q = prev(f, p);
	if(q != NULL){
		q->next = p->next;
		delete p;
	}
	return f;
}
Node* remove_recursive(Node* f, Node* p){
	if(f == NULL) return NULL;
	if(f == p){
		f = f->next;
		delete p;
		return f;
	}
	f->next = remove_recursive(f->next, p);
	return f;
}
Node* reverse(Node* f){
	Node* p1;
	Node* p2;
	Node* p3;
	if(f == NULL) return NULL;
	p3 = f;
	if(f->next == NULL){
		return f;
	}
	p1 = p3->next;
	p2 = p1->next;
	p3->next = NULL;

	while(p1 != NULL){
		p1->next = p3;
		p3 = p1;
		p1 = p2;
		if(p2 != NULL)
			p2 = p2->next;
	}
	return p3;
}
Node* find(Node* f,int x){
	Node* p = f;
	while(p != NULL){
		if(p->value = x)	return p;
		p = p->next;
	}
	return NULL;
}
Node* insert(int x, Node* f){
	Node *p = new Node;
	p->value = x;
	if(f == NULL){
		f = p;
	}
	Node *q = findLast(f);
	q->next = p;
	
	return q;
}
void readData(char* fn){
	FILE *f = fopen(fn, "r");
	first = NULL;
	while(true){
		int x;
		fscanf(f, "%d", &x);
		if(x == -1) break;
		// Write insert
		insert(x, first);
	}
	fclose(f);
}

int main(int argc, char* argv[]){
	readData(argv[1]);
	printList(first);
}