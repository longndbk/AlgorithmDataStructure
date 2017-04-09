#include <stdio.h>

int n;
int x[100];
int a[100];
// If found one result return true
bool found;

bool check(int v, int k){
	for(int j = 1; j <= k - 1; j++){
		if(a[j] == v) return false;
		if(a[j] - j == v - k) return false;
		if(a[j] + j == v + k) return false;
	}
	return true;
}

void process(){
	found = true;
	for(int i = 1; i <= n; i++) x[i] = a[i];
}

void TRY(int k){
	if(found) return;
	for(int v = 1; v <= n; v++){
		if(check(v, k)){
			a[k] = v;
		if(k == n) process();
		else
			TRY(k+1);
		}
		
	}
}
void printHTML(char* file){
	FILE* f = fopen(file, "w");
	fprintf(f, "<table border=1>");
		for(int i = 1; i <= n; i++){
			fprintf(f, "<tr>");
				for (int j = 1; j <= n; j++)
				{
					if(x[i] == j)
						fprintf(f, "<td width=25 height=25 bgcolor='black'>");
					else
						fprintf(f, "<td width=25 height=25 bgcolor='white'>");
					fprintf(f, "</td>");
				}

			fprintf(f, "</tr>");
		}
	fprintf(f, "</table>");
	fclose(f);
}
int main(int argc, char** argv){
	n = 4;
	found = false;
	TRY(1);
	printHTML("queen.html");
}
