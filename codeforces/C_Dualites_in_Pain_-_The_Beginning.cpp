// Wrong Answer on Test 3
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
void Possible(){
    printf("YES\n");
}

void ImPossible(){
    printf("NO\n");
}

void solve(){
    int courses;
    priority_queue<int> q;
    SCD(courses);
    REP(i,courses){
        int temp;
        SCD(temp);
        q.push(temp);
    }
    if(q.empty()){
        Possible();
    }
    else{
        int top = q.top();
        q.pop();
        if(q.empty()){
            if(top == 1 || top == 0){
                Possible();
            }
            else{
                ImPossible();
            }
            return;
        }
        int sec = q.top();
        q.pop();
        if(top == sec || top == sec + 1){
            Possible();
        }
        else{
            ImPossible();
        }
        return;
    }
}

int main(){
    int t;
    t=1;
    while(t){
        solve();
        t--;
    }
    return 0;
}