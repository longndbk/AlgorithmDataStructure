#include <stdio.h>
#include <stdlib.h>
#include <list>
#include <queue>
#include <stack>
using namespace std;
struct State{
    int x;
    int y;
    char* mgs;//current State
    State *p;//next state
}
Stack<State*> S;//Store State start to finish
Queue<State*> Q;//Store states  
List<State*> L;//Store in order to free memory
bool visited[10000][10000];//mark state 

int main(int argc, char **argv){
    int a = atoi(argc[1]);
    int b = atoi(argc[2]);
    int c = atoi(argc[3]);

    //Init State SS - state start
    State *SS = new State;
    SS->x = 0;
    SS->y = 0;
    SS->mgs = NULL;
    L.push_back(SS);
    Q.push(SS);

    //Init State SF - store state finish
    State *SF = NULL;
    //Loop when Q is empty 
    while(!Q.isEmpty()){
        //Get State in Queue
        State *S = Q.font();
        int x = S->x;
        int y = S->y;
        if(x == c || y == c || x + y = c){
            SF = S;
            break;
        }
        if(!visited[0][y]){
            State* NS = new State;//Neiberhood state
            NS->x = 0;
            NS->y = y;
            NS->mgs = "Do het coc 1 ra ngoai";
            NS->p = S;
            Q.push(NS);
            L.push_back(NS);
            visited[0][y] = true;
        }
        if(!visited[x][0]){
            State* NS = new State;//Neiberhood state
            NS->x = x;
            NS->y = 0;
            NS->mgs = "Do het coc 2 ra ngoai";
            NS->p = S;
            Q.push(NS);
            L.push_back(NS);
            visited[x][0] = true;
        }
        if(!visited[a][y]){
            State* NS = new State;//Neiberhood state
            NS->x = a;
            NS->y = y;
            NS->mgs = "Do day vao coc 1";
            NS->p = S;
            Q.push(NS);
            L.push_back(NS);
            visited[a][y] = true;
        }
        if(!visited[x][b]){
            State* NS = new State;//Neiberhood state
            NS->x = x;
            NS->y = b;
            NS->mgs = "Do day vao coc 2";
            NS->p = S;
            Q.push(NS);
            L.push_back(NS);
            visited[x][b] = true;
        }
        
        if(x + y <= a &&!visited[x+y][0]){
            State* NS = new State;//Neiberhood state
            NS->x = x + y;
            NS->y = 0;
            NS->mgs = "Do tat 2 -> 1";
            NS->p = S;
            Q.push(NS);
            L.push_back(NS);
            visited[x+y][0] = true;
        }
        //
        if(x + y > a &&!visited[x+y-a][0]){
            State* NS = new State;//Neiberhood state
            NS->x = x+y-a;
            NS->y = 0;
            NS->mgs = "Do tu 2 -> 1";
            NS->p = S;
            Q.push(NS);
            L.push_back(NS);
            visited[x+y-a][0] = true;
        }
        if(x + y <= b &&!visited[0][x+y]){
            State* NS = new State;//Neiberhood state
            NS->x = x + y;
            NS->y = 0;
            NS->mgs = "Do tat nuoc 1 -> 2";
            NS->p = S;
            Q.push(NS);
            L.push_back(NS);
            visited[0][x+y] = true;
        }
        //
        if(x + y > b &&!visited[0][x+y-b]){
            State* NS = new State;//Neiberhood state
            NS->x = 0;
            NS->y = x+y-b;
            NS->mgs = "Do tu 1 -> 2";
            NS->p = S;
            Q.push(NS);
            L.push_back(NS);
            visited[0][x+y-b] = true;
        }

    }

    //Use pointer p -> list with iterator to free memory
    list<State*>::iterator p;
    for(p = L.begin(); p!=L.end(); p++){
        State* S = *p;
        delete S;
    }
}