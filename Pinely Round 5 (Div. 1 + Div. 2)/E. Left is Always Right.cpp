// #pragma GCC optimize ("Ofast")
// #pragma GCC target ("avx,avx2")
// #pragma GCC optimize("unroll-loops")

#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

#define ll long long
#define ld long double
#define pl pair<ll, ll>
#define vi vector<ll>
#define vii vector<vi>
#define vc vector<char>
#define vcc vector<vc>
#define vp vector<pl>
#define mi map<ll,ll>
#define mc map<char,int>
#define sortx(X) sort(X.begin(),X.end());
#define all(X) X.begin(),X.end()
#define allr(X) X.rbegin(),X.rend()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}
#define MUN {cout << "-1\n"; return;}

using namespace std;

const int SIZE = 1e6 + 1;
const int MODE = 998244353;
ll fac[SIZE], facinv[SIZE];


// nCr = fac(n)/fac(r)*fac(n-r)
ll nCr(ll n, ll r) {
    if (n < r || n < 0 || r < 0) return 0;
    ll res = fac[n];
    res *= (facinv[r] * facinv[n - r]) % MODE;
    return (res) % MODE;
}

void init() {
    fill(fac, fac+SIZE, 1);
    fill(facinv, facinv+SIZE, 1);
    for (int i = 2; i < SIZE; i++) {
        fac[i] = (i * fac[i - 1]) % MODE;
        facinv[i] = MODE - MODE / i * facinv[MODE%i] % MODE;
    }
    for (int i = 2; i < SIZE; i++)
        facinv[i] = (facinv[i] * facinv[i-1])%MODE;
}


void solve(int tc) {
    ll n, k;

    cin >> n >> k;
    string s;
    cin >> s;

    for (auto &a : s) if (a == '?') a = 2;
    else a -= '0';

    vii C(n+1, vi(3));
    C[0][s[0]]=1;
    for (int i = 1; i < n; i++)
    {
        C[i][0] = C[i-1][0]; // 0
        C[i][1] = C[i-1][1]; // 1
        C[i][2] = C[i-1][2]; // ?
        C[i][s[i]]++;
    }
    

    ll cnt[2]{};
    vi V(k-1, 2);
    vii dp(n, vi(2));
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == (V[i%(k-1)] ^ 1)) break;
        if (s[i] != 2) {
            if ( V[i%(k-1)]==2) cnt[s[i]]++;
            V[i%(k-1)] = s[i];
        }
        
        for (int bt = 0; bt < 2; bt++)
        {

            ll oc = (i-1+k-1) % (k-1);
            
            if (V[oc] == 2) cnt[bt^1]++;
            else if (V[oc] == bt) continue;

            ll re = nCr(k-1 -cnt[0]-cnt[1], k/2-cnt[0]);
            dp[i][bt] = re;
            
            if (V[oc] == 2) cnt[bt^1]--;
        }
    }
    
    
    ll sol = 0;
    for (int i = 0; i <= n-k; i++)
    {
        for (int bt = 0; bt <= 1; bt++)
        {
            if (C[i][bt^1]) continue;

            if (i == 0) sol += dp[i+1][bt^1];


            sol += dp[i+1][bt];
            sol %= MODE;
        }
    }    

    ll a = C[n-1][0] - C[n-k][0];
    ll b = C[n-1][1] - C[n-k][1];
    ll c = C[n-1][2] - C[n-k][2];
    if (C[n-k][0] == 0) {
        for (int i = k/2+1; i < k; i++)
        {
            sol += nCr(c, i-b);
            sol %= MODE;
        }
    }
    if (C[n-k][1] == 0) {
        for (int i = k/2+1; i < k; i++)
        {
            sol += nCr(c, i-a);
            sol %= MODE;
        }
    }

    cout << sol << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    init();
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
