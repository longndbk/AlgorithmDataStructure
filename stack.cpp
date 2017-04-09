#include <stdio.h>

struct Stack
{
    char info;
    Stack *next; 
};
Stact top = NULL;


int empty(){
    return top == NULL;
}
void push(char x){
    Stack *p = new Stack;
    p->info = x;
    p->next = top;
    top = p;
}
void pop(){

}
int main(int argc, char** argv){

}