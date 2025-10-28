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

const int MAXSZ = 1e7 + 1;
int prime[MAXSZ] = {0};
vi primes;
 
void INIT() {
    for (int i = 0; i < MAXSZ; i++) prime[i] = i;
    for (int i = 2; i * i < MAXSZ; ++i) if (prime[i] == i)
        for (int j = i; j < MAXSZ; j += i) prime[j] = i;
    for (int i = 2; i < MAXSZ; i++) if(prime[i] == i) primes.push_back(i);
}

void solve(int tc) {
    ll n, k, x;

    cin >> n >> k >> x;

    vi X(n+2);
    for (int i = 1; i <= n; i++) cin >> X[i];

    X[0] = -1, X[n+1] = x + 1;
    sortx(X);
    
    auto get = [&](ll d) -> vi {
        vi res(k);

        if (d == 0) {
            for (int i = 0; i < k; i++) res[i] = i;
            return res;            
        }

        X[0] = -d;
        X[n+1] = x+d;

        ll took = 0;
        
        for (int i = 0; i <= n; i++)
        {
            ll pos = X[i] + d;
            while (took < k && X[i+1]-d >= pos)
            {
                res[took] = pos;
                took++;
                pos++;
            }
        }
        
        if (took != k) return {};
        return res;
    };

    ll l = 0, r = x;
    while (l < r)
    {
        ll mid = (l + r + 1) / 2;
        auto tm = get(mid);
        if (tm.empty()) r = mid - 1;
        else l = mid;        
    }

    auto res = get(l);
    for (auto a : res) cout << a << ' ';
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    INIT();
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
