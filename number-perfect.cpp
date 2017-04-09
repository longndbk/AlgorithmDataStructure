#include <stdio.h>
#include <math.h>
bool checkIsPerfect(int num){
	int sum = 0;
	for(int i = 1; i < num; i++){
		if(num % i == 0){
			sum += i;
		}
	}
	if(sum == num){
		return true;
	}
	return false;
}
int main(int argc, char** argv){
	for(int i = 1; i < 100000000000; i++){
		if(checkIsPerfect(i)){
			printf("%d is perfect number \n", i);
		}
	}
}
bool checkIsPrime(int num){
	if(num == 2){
		return true;
	}
	else{
		int i = 3;
		int k = 0;
		while(i <= sqrt(num)){
			if(num % i != 0){
				k++;
			}
		}
		if(k == 0){
			return true;
		}
	}
	return false;
}
