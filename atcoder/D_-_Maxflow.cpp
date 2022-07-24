#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i, a, n) for (int i = a; i < n; i++)
#define per(i, a, n) for (int i = n - 1; i >= a; i--)
#define mem(a, b) memset(a, (b), sizeof(a))
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define MOD 1000000007
#define INF (int)1e9
#define CYES cout << "YES" << "\n"
#define CNO cout << "NO" << "\n"
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<long long> VLL;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef map<int, int> MPII;
typedef map<char, int> MPCI;
typedef set<int> SETI;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll div_ceil(ll x, ll y) { return x / y + (x % y > 0); }
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
template <typename... Args>
void logger(string vars, Args &&...values) {
    cerr << vars << " = ";
    string delim = "";
    (..., (cerr << delim << values, delim = ", "));
    cerr << endl;
}


void solve() {
    int n,m;
    cin >> n >> m;
    vector<char> a(m*n);
    rep(i,0,m*n) {
        cin >> a[i];
    }
    mf_graph<int> g(n*m+2);

    rep(y,1,n+1){
        rep(x,1,m+1){
            int index=(y-1)*m+(x-1)+1;
            if(a[index-1]=='#') continue;
            if((x+y)%2==0){
                g.add_edge(0, index, 1);
                if(x!=1) g.add_edge(index, index-1, 1);
                if(x!=m) g.add_edge(index, index+1, 1);
                if(y!=1) g.add_edge(index, index-m, 1);
                if(y!=n) g.add_edge(index, index+m, 1);    
            }
            else{
                g.add_edge(index, n*m+1, 1);
            }
        }
    }

    cout<<g.flow(0, n*m+1)<<endl;

    for(auto& e: g.edges()){
        if(e.from == 0 || e.to == n*m+1 || !e.flow) continue;
        int from = e.from-1;
        int to = e.to-1;
        if(from/m==to/m){
            if(from < to){
                a[from] = '>';
                a[to] = '<';
            }
            else{
                a[from] = '<';
                a[to] = '>';
            }
        }
        else{
            if(from < to){
                a[from] = 'v';
                a[to] = '^';
            }
            else{
                a[from] = '^';
                a[to] = 'v';
            }
        }
    }
    rep(i,0,n) {
            rep(j,0,m) cout << a[i*m+j];
            cout << endl;
        }


    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    for (int Task = 1; Task <= T; Task++) {
        //deb(Task);
        solve();
    }

    return 0;
}