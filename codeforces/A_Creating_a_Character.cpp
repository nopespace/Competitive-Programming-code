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
int strr,intt,expp;
int cnt;
void handle(){
    expp = expp/2;
    cnt += expp;
    printf("%d\n", cnt);
}
void handle2(){
    int t = strr - intt - 1;
    if(t>=expp){
        cnt+=expp;
        printf("%d\n",cnt);
        return;
    }
    cnt += t;
    expp -= t;
    cnt += expp/2;
    printf("%d\n", cnt);
}

void solve(){
    cnt = 0;
    SCD(strr);
    SCD(intt);
    SCD(expp);
    if(strr <= intt){
        int gap = intt - strr;
        gap+=1;
        strr+=gap;
        expp-=gap;
        if(expp < 0){
            printf("0\n");
            return;
        }
        cnt++;
        handle();
    }
    else{
        cnt++;
        if(expp == 0){
            printf("1\n");
            return;
        }
        handle2();
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