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

    vector<string> X(n);

    ll cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> X[i];
        cnt += count(all(X[i]), '#');
    }

    if (cnt == 0) YES;

    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-1; j++)
        {
            ll v = ((X[i][j] == '#') + (X[i][j+1] == '#') + (X[i+1][j] == '#') + (X[i+1][j+1] == '#'));
            if (cnt == v) YES;
        }
    }



    
    for (int i = -n-5; i <= n+5; i++)
    {
        ll v = 0;

        for (int j = 0; j < n; j++)
        {
            ll a = j-i, b = j - i + 1;
            if (a >= 0 && a < n) v += (X[j][a] == '#');
            if (b >= 0 && b < n) v += (X[j][b] == '#');
        }
        
        if (v == cnt) YES;
    }

    for (int i = 0; i < n; i++) reverse(all(X[i]));

    for (int i = -n-5; i <= n+5; i++)
    {
        ll v = 0;

        for (int j = 0; j < n; j++)
        {
            ll a = j-i, b = j - i + 1;
            if (a >= 0 && a < n) v += (X[j][a] == '#');
            if (b >= 0 && b < n) v += (X[j][b] == '#');
        }

        if (v == cnt) YES;
    }
    
    NO;
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
