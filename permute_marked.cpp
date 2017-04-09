#include <stdio.h>
#include <stdlib.h>

#ifndef MAX
#define MAX 1000
#endif
int a[MAX];
bool marked[MAX];
int n;
void process(){
	for(int i = 1; i <= n; i++){
			printf("%d", a[i]);
		}
		printf("\n");
}


void TRY(int k){
	for(int v = 1; v <= n; v++){
		if(!marked[v]){
			a[k] = v;
			marked[v] = true;
			if(k == n)	process();
			else TRY(k+1);
			marked[v] = false;
		}
	}
}

int main(int argc, char const *argv[])
{
	n = atoi(argv[1]);
	for(int i = 0; i <= n; i++){
		marked[i] = false;
	}
	TRY(1);
	return 0;
}