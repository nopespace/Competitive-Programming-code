#include <iostream>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
using namespace std;
long long n;
string a,b;
void solve(){
    long long lenth = a.size();
    long long num = pow(2, lenth);
    printf("%lld\n", num);
}
int main(){
    cin>>n;
    for(int i=0; i<n; ++i){
        cin>>a>>b;
        if( b == "a"){
            printf("1\n");
        }
        else if(b.find("a") != -1){
            printf("-1\n");
        }
        else{
            solve();
        }
    }
}