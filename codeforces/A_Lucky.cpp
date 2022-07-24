#include <bits/stdc++.h> 
using namespace std; 

void solve(){
    int n;
    string s;
    cin>>s;
    int l = s.length();
    if(s[0]+s[1]+s[2] == s[l-1] + s[l-2] + s[l-3]){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
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