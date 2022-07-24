#include <bits/stdc++.h> 
using namespace std; 
string a;
int flag_1,flag_0,flag_x;
int one,zero,x;
int cnt; //record ? number in between
void solve(){
    cin>>a;
    flag_1=0;
    flag_0=0;
    flag_x=0;
    
    int len = a.size();
    if(len==1||a[len-1]=='1'||a[0]=='0'){
        cout<<1<<endl;
        return;
    }
    for(int i = 0; i<len;++i){
        if(a[i]=='1'){
            flag_1 = 1;
            one = i;
            cnt = 0;
        }
        else if(a[i] == '0'){
            flag_0 = 1;
            if(flag_1){
                cout<<i-one+1<<endl;
                return;
            }
            else{
                cout<<1+i<<endl;
            }
            return;
            
        }
        else{
            //donothing
        }
    }
    if(flag_1){
        cout<<len-one<<endl;
        return;
    }
    cout<<len<<endl;

}

int main(){
    int n;
    cin >> n;
    while(n){
        solve();
        n--;
    }
    return 0;
}