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
#define MAXN 107
int n,r;
int flag = 0;
struct tasks{
    int rep;
    int change;
    bool operator<(tasks o) const
    {
        return rep < o.rep;
    }
    bool operator>(tasks o) const
    {
        return rep > o.rep;
    }
};
struct task_negative{
    int rep;
    int change;
    int value;
    bool operator<(task_negative o) const
    {
        return value < o.value;
    }
    bool operator>(task_negative o) const
    {
        return value > o.value;
    }
};

priority_queue<tasks, vector<tasks>, greater<tasks> > increase;
priority_queue<task_negative> decrease;

void positive(){
    while(!increase.empty()){
        tasks tmp = increase.top();
        increase.pop();
        if(r >= tmp.rep){
            r += tmp.change;
        }
        else{
            flag = 1;
            return;
        }
    }
}
void negative(){
    while(!decrease.empty()){
        task_negative tmp = decrease.top();
        decrease.pop();
        if(r >= tmp.rep){
            r -= tmp.change;
        }
        else{
            flag = 1;
            return;
        }
    }

}

int main(){
    cin >> n >> r;
    for(int i = 0; i < n; ++i){
        int a,b;
        scanf("%d%d", &a, &b);
        if(b>=0){
            tasks tmp;
            tmp.rep = a;
            tmp.change = b;
            increase.push(tmp);
        }
        else{
            task_negative tmp;
            tmp.rep = a;
            tmp.change = -1*b;
            tmp.value = a+b;
            decrease.push(tmp);
        }
    }
    positive();
    if(flag){
        cout<<"NO"<<endl;
        return 0;
    }
    negative();
    if(flag||r<0){
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;

    return 0;
}