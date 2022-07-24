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
#define MAXM 100007; 
int r;
int d;
int n;
int cnt;
int x;
int y;
int r_i;
int i;
float distance1;
float calculate_distance(){
    return sqrt(x*x+y*y);
}
int judge1(){
    // used to judge if the inner circle is good
    if(distance1-r >= r_i){
        return 1;
    }
    return 0;
}
int judge2(){
    // used to judge if the outter circle is good
    return r+d-distance1 >= r_i ? 1 : 0;
}
int judge(){
    if(judge1()&judge2()){
        return 1;
    }
    else{
        return 0;
    }
}
int main(){
    cin>>r>>d>>n;
    r-=d;
    for(i = 0; i < n; ++i){
        SCD(x);
        SCD(y);
        SCD(r_i);
        distance1 = calculate_distance();
        cnt += judge();
    }
    cout<<cnt;
    return 0;
}