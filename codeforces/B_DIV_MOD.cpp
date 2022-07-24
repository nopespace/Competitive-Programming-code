#include <bits/stdc++.h> 
using namespace std; 
#define SCD(t) scanf("%d", &t) 
#define SCLD(t) scanf("%ld", &t) 
#define SCLLD(t) scanf("%lld", &t) 
#define SCC(t) scanf("%c", &t) 
#define SCS(t) scanf("%s", t) 
#define SCF(t) scanf("%f", &t) 
#define SCLF(t) scanf("%lf", &t) 
#define MEM(a, b) memset(a, (b), sizeof(a)) 
#define FOR(i, j, k, in) for (int i = j; i < k; i += in) 
#define RFOR(i, j, k, in) for (int i = j; i >= k; i -= in) 
#define REP(i, j) FOR(i, 0, j, 1) 
#define RREP(i, j) RFOR(i, j, 0, 1) 
#define all(cont) cont.begin(), cont.end() 
#define rall(cont) cont.end(), cont.begin() 
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++) 
#define IN(A, B, C) assert(B <= A && A <= C) 
#define MP make_pair 
#define PB push_back 
#define INF (int)1e9 
#define EPS 1e-9 
#define PI 3.1415926535897932384626433832795 
#define MOD 1000000007 
#define read(type) readInt<type>() 
typedef pair<int, int> PII; 
typedef vector<int> VI; 
typedef vector<string> VS; 
typedef vector<PII> VII; 
typedef vector<VI> VVI; 
typedef map<int, int> MPII; 
typedef set<int> SETI; 
typedef multiset<int> MSETI; 
typedef long int int32; 
typedef unsigned long int uint32; 
typedef long long int int64; 
typedef unsigned long long int uint64; 
int l,r,a;
void solve(){
    cin>>l>>r>>a;
    if(r==l){
        int ans = r/a + r%a;
        cout<<ans<<endl;
        return;
    }
    if(r-l < a){
        if(r%a==0){
            int ans = r/a-1+a-1;
            cout<<ans<<endl;
            return;
        }
        else{
            // 0 is in the range?
            int t = a*(r/a);
            int ans;
            if(l<t&&r>t){
                ans = r/a-1+a-1;
            }
            else{
                ans = r/a + r%a;
            }
            cout<<ans<<endl;
            return;
        }
    }
    else{
        int ans = r/a + r%a;
        ans = max(ans, r/a-1+a-1);
        cout<<ans<<endl;
        return;
    }
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