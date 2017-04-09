#include <iostream>
using namespace std;
int s = 0;
int count = 0;

int main(){
    
    try(1,4);
    cout << count;
}
int try(int k, int n)
{
    for(int v = 0; v <=1; v++){
        s+=v;
        cout << s << endl;
        if(k==n){
            if(s==(n/2)) count++;
        }
        else try(k+1, n);
        s-=v;
    }
}