#include <bits/stdc++.h> 
using namespace std; 
#define SCD(t) scanf("%d", &t) 
#define MAXN 57
int n;
int m;
int ans = 1000007;
int curr;
string s[MAXN];

void solve(){
    int ans = 1000007;
    SCD(n);
    SCD(m);
    for(int i = 0; i < n; ++i){
        cin>>s[i]; 
    }
    for(int i = 0; i < n; ++ i){
        for(int j = i + 1; j < n ; ++j){
            curr = 0;
            for(int k = 0; k < m; ++k){
                curr += abs(s[i][k] - s[j][k]);
            }
            ans = ans < curr ? ans : curr;
        }
    }
    printf("%d\n", ans);
}

int main(){
    int t;
    cin >> t;
    while(t){
        solve();
        t--;
    }
    return 0;
}