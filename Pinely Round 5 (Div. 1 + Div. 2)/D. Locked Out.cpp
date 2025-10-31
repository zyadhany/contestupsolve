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

    vi X(n);
    for (int i = 0; i < n; i++)
    {
        cin >> X[i];
    }
    
    vector<deque<ll>> IND(n+2);
    for (int i = 0; i < n; i++) IND[X[i]].push_back(i);
    
    ll sol = 0;
 
    for (int i = 0; i <= n; i++)
    {
        while (!IND[i].empty() && !IND[i+1].empty())
        {
            if (IND[i+1].back() > IND[i].back())
            {
                IND[i+1].pop_back();
                IND[i].pop_back();
                sol++;
            } else {
                IND[i].pop_back();
            }
        }
    }

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