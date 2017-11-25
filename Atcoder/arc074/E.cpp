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

const int N = 303 , P = 1e9 + 7;
inline void pp(int &x,int d){if((x+=d)>=P)x-=P;}
int n , m , f[N][N] , g[N][N];
vector<pii> limit[N];

int main(){
    cin >> n >> m;
    rep(i,0,m) {
        int l , r , x;
        cin >> l >> r >> x;
        limit[r].pb(mp(l , x));
    }
    f[0][0] = 1;
    rep(i,1,n+1) {
        rep(j,0,i+1) rep(k,0,i+1) g[j][k] = 0;
        rep(j,0,i) rep(k,0,i) if(f[j][k]) {
            pp(g[j][k] , f[j][k]);
            pp(g[j][i-1] , f[j][k]);
            pp(g[i-1][k] , f[j][k]);
        }
        rep(j,0,i+1) rep(k,0,i+1) {
            f[j][k] = g[j][k];
            for(auto e : limit[i]) {
                int l = e.fi , x = e.se;
                int t = 1 + (l <= j) + (l <= k);
                if(t != x) {
                    f[j][k] = 0;
                    break;
                }
            }
        }
    }
    int ans = 0;
    rep(i,0,n+1) rep(j,0,n+1) pp(ans , f[i][j]);
    cout << ans << endl;
    return 0;
}
