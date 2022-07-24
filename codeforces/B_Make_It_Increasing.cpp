#include <bits/stdc++.h> 
using namespace std; 
int t;
int n;
int a[37];
int cnt;
void solve(){
    cnt=0;
    cin>>n;
    for(int i = 1; i<=n;++i){
        cin>>a[i];
    }
    if(a[n]<n-1){
        cout<<"-1"<<endl;
        return;
    }
    else{
        for(int i = n-1 ; i>=1; --i){
            while(a[i]>=a[i+1]){
                cnt++;
                a[i]=a[i]/2;
            }
            if(a[i]<i-1 && i != 1){
                cout<<"-1"<<endl;
                return;
            }
        }
        cout<<cnt<<endl;
        return;
    }
}

int main(){
    cin>>t;
    while(t){
        solve();
        t--;
    }
    return 0;
}