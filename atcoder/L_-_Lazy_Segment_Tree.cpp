#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
using mint = modint998244353;
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
#define CYES cout << "YES" \
                  << "\n"
#define CNO cout << "NO" \
                 << "\n"
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
void logger(string vars, Args &&...values)
{
    cerr << vars << " = ";
    string delim = "";
    (..., (cerr << delim << values, delim = ", "));
    cerr << endl;
}

struct F
{
    mint a, b;
};

struct S
{
    mint v;
    int size;
};

S op(S a, S b)
{
    return S{a.v + b.v, a.size + b.size};
}

S e()
{
    return S{0, 0};
}

S mapping(F f, S x)
{
    return S{f.a * x.v + f.b * x.size, x.size};
}

F composition(F g, F f)
{
    return F{f.a * g.a, f.b * g.a + g.b};
}

F id()
{
    return F{1, 0};
}

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<S> a(n);
    rep(i, 0, n)
    {
        int x;
        cin >> x;
        a[i] = S{x, 1};
    }
    lazy_segtree<S, op, e, F, mapping, composition, id> seg(a);
    rep(i, 0, q)
    {
        int t, l, r;
        cin >> t >> l >> r;
        if (t == 0)
        {
            int a, b;
            cin >> a >> b;
            seg.apply(l, r, F{a, b});
        }
        else
        {
            cout << seg.prod(l, r).v.val() << endl;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    for (int Task = 1; Task <= T; Task++)
    {
        // deb(Task);
        solve();
    }

    return 0;
}