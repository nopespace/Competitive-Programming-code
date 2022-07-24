#include <iostream>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
long long n[2], a, result[2];
int main() {
    cin>>n[0]>>n[1]>>a;
    for(int i = 0; i <= 1; ++i){
        if(!(n[i]%a)){
            result[i] = n[i]/a;
        }
        else{
            result[i] = n[i]/a+1;
        }
    }
    cout<<result[0]*result[1];
    return 0;
}
