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
int a[107];

void solve(){
    int n;
    int flag = 0;
    cin>>n;
    int cnt = 0;
    memset(a, 0, sizeof(int) * 107);
    for(int i=0; i<n; ++i){
        int t;
        SCD(t);
        if(t==0){
            flag = 1;
            continue;
        }
        if(a[t] > 0 && flag == 0){
            a[t] = 1;
            flag = 1;
            cnt++;
            continue;
        }
        a[t] += 1;
    }
    if(flag == 1){
         int tmp = 0;
        for(int i = 1; i <= 100; ++i){
            tmp += a[i];
        }
        cnt += tmp;
    }
    else{
        cnt = 1+n;
    }
    printf("%d\n", cnt);
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