#include <bits/stdc++.h>
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

const int MAXN=1e5+7;

void solve() {
    // init
    int n;
    int num[MAXN];
    int index[MAXN];
    cin>>n;
    rep(i, 0, n){
        int a;
        cin>>a;
        num[i] = a;
        index[a] = i;
    }
    // solving
    ll ans = 1;
    int l = index[0];
    int r = index[0];
    rep(i, 1, n){
        if(index[i] > r){
            r = index[i];
        }
        else if(index[i] < l){
            l = index[i];
        }
        else{
            int len = r-l+1;
            ans *= (len-i);
            ans = ans % MOD;
            // deb(i, len, index[i]);
        }
        
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    for (int Task = 1; Task <= T; Task++) {
        // deb(Task);
        solve();
    }

    return 0;
}