// #include {{{
#include <iostream>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <ctime>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#include <bitset>
#include <vector>
#include <complex>
#include <algorithm>
using namespace std;
// }}}
// #define {{{
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vi;
#define de(x) cout << #x << "=" << x << endl
#define rep(i,a,b) for(int i=a;i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
// }}}

const int N = 1e3 + 10 , M = 5e3 + 10 , inf = 1<<28;
int n , par[N] , x[N] , q[N] , dp[N][2] , f[M] , g[M];
vi G[N];

void Update(int &x,int d){
    x = min(x , d);
}

int main(){
    cin >> n;
    rep(i,2,n+1) cin >> par[i] , G[par[i]].pb(i);
    rep(i,1,n+1) cin >> x[i];
    int _ = 0;q[_++] = 1;
    rep(i,0,_) for(auto e : G[q[i]]) q[_++] = e;
    per(ii,0,_) {
        int i = q[ii];
        rep(j,0,x[i] + 1) f[j] = inf;
        f[0] = 0;
        for(auto e : G[i]) {
            rep(j,0,x[i] + 1) g[j] = inf;
            per(j,0,x[i] + 1) if(j - x[e] >= 0)
                Update(g[j] , f[j - x[e]] + dp[e][0]);
            per(j,0,x[i] + 1) if(j - dp[e][1] >= 0)
                Update(g[j] , f[j - dp[e][1]] + x[e]);
            rep(j,0,x[i] + 1) f[j] = g[j];
        }
        dp[i][0] = inf;
        rep(j,0,x[i] + 1) Update(dp[i][0] , f[j]);

        rep(j,0,x[i] + 1) f[j] = inf;
        f[0] = 0;
        for(auto e : G[i]) {
            rep(j,0,x[i] + 1) g[j] = inf;
            per(j,0,x[i] + 1) if(j - x[e] >= 0)
                Update(g[j] , f[j - x[e]] + dp[e][1]);
            per(j,0,x[i] + 1) if(j - dp[e][0] >= 0)
                Update(g[j] , f[j - dp[e][0]] + x[e]);
            rep(j,0,x[i] + 1) f[j] = g[j];
        }
        dp[i][1] = inf;
        rep(j,0,x[i] + 1) Update(dp[i][1] , f[j]);
    }
    puts(min(dp[1][0] , dp[1][1]) != inf ? "POSSIBLE" : "IMPOSSIBLE");
    return 0;
}
