#include <bits/stdc++.h>
// #include <atcoder/all>
// using namespace atcoder;
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

void solve()
{
    int n;
    cin >> n;
    int arr[n + 1];
    vector<vector<int>> recd(n + 1);
    rep(i, 0, n)
    {
        cin >> arr[i];
        arr[i]--;
        recd[arr[i]].pb(i);
    }
    rep(i, 0, n)
    {
        VI v = recd[i];

        int sz = SZ(v);
        int ans;
        if (sz == 0)
        {
            ans = 0;
        }
        else
        {
            int prev = v[0];
            ans = 1;
            for (int j = 1; j < sz; j++)
            {
                int gapp = v[j] - prev - 1;

                if ((gapp & 1)==0)
                {
                    ans++;
                    prev = v[j];
                }
            }
        }
        cout << ans << ' ';
    }
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    for (int Task = 1; Task <= T; Task++)
    {
        // deb(Task);
        solve();
    }

    return 0;
}