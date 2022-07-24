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
const int N = 1e5 + 7;
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

struct dsu
{
public:
    dsu() : _n(0) {}
    explicit dsu(int n) : _n(n), parent_or_size(n, -1) {}

    int merge(int a, int b)
    {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y)
            return x;
        if (-parent_or_size[x] < -parent_or_size[y])
            std::swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return x;
    }

    bool same(int a, int b)
    {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }

    int leader(int a)
    {
        assert(0 <= a && a < _n);
        if (parent_or_size[a] < 0)
            return a;
        return parent_or_size[a] = leader(parent_or_size[a]);
    }

    int size(int a)
    {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
    }

    std::vector<std::vector<int>> groups()
    {
        std::vector<int> leader_buf(_n), group_size(_n);
        for (int i = 0; i < _n; i++)
        {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<int>> result(_n);
        for (int i = 0; i < _n; i++)
        {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < _n; i++)
        {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(
            std::remove_if(result.begin(), result.end(),
                           [&](const std::vector<int> &v)
                           { return v.empty(); }),
            result.end());
        return result;
    }

private:
    int _n;
    // root node: -1 * component size
    // otherwise: parent
    std::vector<int> parent_or_size;
};

void solve()
{
    int n, m;
    cin >> n >> m;
    VI c(n);
    dsu d(n);
    rep(i, 0, n)
    {
        cin >> c[i];
    }
    rep(i, 0, m)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        d.merge(x, y);
    }
    ll ans = 0;
    VVI g = d.groups();
    rep(i, 0, SZ(g))
    {
        int mmin = INT_MAX;
        rep(j, 0, SZ(g[i]))
        {
            mmin = min(mmin, c[g[i][j]]);
        }
        ans += mmin;
    }
    cout << ans << endl;
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