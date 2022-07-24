#include <iostream>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
int n;
int x,y;
int main(){
    cin>>n;
    for(int i = 0; i < n; ++i){
    cin >> x >> y;
    if(y%x != 0){
        cout << 0 << ' ' << 0 << endl;

    }else{
    int score = y / x;
    cout<<1<<" "<<score<<endl;}
    }
}