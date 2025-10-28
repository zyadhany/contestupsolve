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

const int MODE = 1e9 + 7;

using namespace std;

const ll INF = 1e16;

void solve(int tc) {
    ll n;

    cin >> n;
    
    vi X(n), C(n);

    for (int i = 0; i < n; i++) cin >> X[i];
    for (int i = 0; i < n; i++) cin >> C[i];
    
    set<ll> st(all(X));
    mi CO;
    for (auto a : st) CO[a] = CO.size();
    for (auto &a : X) a = CO[a];
    ll m = CO.size();
    
    vi dp(m+1, INF);
    
    dp[0] = C[0];
    dp[X[0]] = 0;

    for (int i = 1; i < n; i++)
    {
        ll mn = *min_element(dp.begin(), dp.begin()+X[i]+1);


        for (int j = 0; j < dp.size(); j++)
        {
            dp[j] += C[i];
        }     
           
        dp[X[i]] = mn;
    }

    ll sol = *min_element(dp.begin(), dp.end());
    cout << sol << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
