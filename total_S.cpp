#include <stdio.h>


int S;
int n;
int a[100];
int temp = 0;
void process(){
	if(temp == S){
		for(int i = 1; i <= n; i++){
			printf("%d ", a[i]);
		}
		printf("\n");
	}

}

void TRY(int k){
	/*Kiểm soát a[k - 1] a[k] a[k+1] ... a[n]
	// Tại a[k] giá trị max nhất mà nó có thể đạt được là 
	// S - Tổng t trước đó +(n - k phần tử còn lại min nhất có thể nhận được là đều bằng 1)
	*/

	for(int v = 1; v <= S - temp + n - k; v++){
		a[k] = v;
		temp += a[k];
		if(k == n) process();
		else
			TRY(k+1);
		temp -= a[k];
	}
}
int main(int argc, char** argv){
	S = 10;
	n = 3;
	TRY(1);
}