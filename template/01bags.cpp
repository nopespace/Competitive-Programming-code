#include<bits/stdc++.h>
using namespace std;

#define MAXN 100007
#define MAXV 100007
int n, s;
int w;
int v;
int dp[MAXV];
int main(){
    cin>>n>>s;
    for(int i = 0; i < n; ++i){
        cin>>w>>v;
        for(int j = s; j > w-1; --j){
            dp[j] = max(dp[j], dp[j-w]+v);
        }
    }
    cout<<dp[s];
}