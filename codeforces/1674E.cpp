#include <iostream>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#define MAXN 10000007
using namespace std;
int n;
int arr[MAXN];
int cpy[MAXN];
int main(){
    cin>>n;
    for(int i = 0; i<n; ++i){
        cin>>arr[i];
    }
    memcpy(cpy, arr, n*sizeof(int));
    sort(cpy, cpy+n);
    int ans = (cpy[0]+1)/2 + (cpy[1]+1)/2;
    for(int i=0; i<n-2; ++i){
        if(arr[i] <= arr[i+2]){
            ans = min(ans, arr[i]+(arr[i+2]-arr[i]+1)/2);
        }
        else{
            ans = min(ans, arr[i+2]+(arr[i]-arr[i+2]+1)/2);
        }
        
    }

    for(int i=0; i<n-1; ++i){
        int x1 = max((arr[i]+1)/2, (arr[i+1]+1)/2);
        int x2 = max(x1, (arr[i]+arr[i+1]+2)/3);
        ans = min(ans, x2);
    }
    cout<<ans<<endl;
}