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
    ll n, x;

    cin >> n >> x;

    deque<ll> X(n);
    for (int i = 0; i < n; i++)
    {
        cin >> X[i];
    }
    sortx(X);

    ll summ = 0;
    ll sol = 0;
    vi res;

    while (!X.empty())
    {
        if (summ + X.back() >= x) {
            summ = (summ + X.back()) % x;
            sol += X.back();
            res.push_back(X.back());
            X.pop_back();
        } else {
            summ = (summ + X.front()) % x;
            res.push_back(X.front());
            X.pop_front();
        }
    }
    

    cout << sol << '\n';
    for (auto a: res) cout << a << ' ';
    cout << '\n';
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
