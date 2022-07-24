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
    int n, q;
    cin >> n >> q;
    fenwick_tree<ll> fw(n);
    rep(i,0,n) {
        int x;
        cin >> x;
        fw.add(i, x);
    }
    rep(i,0,q){
        int t, u, v;
        cin >> t >> u >> v;
        if(t == 0){
            fw.add(u, v);
        }else{
            cout << fw.sum(u, v) << endl;
        }
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