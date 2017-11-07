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

const int N = 202 , P = 998244353;
int n,pw[N]={1};
pii p[N];

int main(){
    rep(i,1,N) pw[i]=pw[i-1]*2%P;
    cin >> n;
    rep(i,0,n) cin >> p[i].fi >> p[i].se;
    sort(p , p + n);
    int ans = (pw[n]+P-1)%P , del = 0;
    rep(i,0,n) {
        map<pii,int> vis;
        rep(j,i+1,n){
            int dx=p[j].fi-p[i].fi;
            int dy=p[j].se-p[i].se;
            if(dx==0) dy=1;
            else if(dy==0) dx=1;
            else {
                int g=__gcd(dx,abs(dy));
                dx/=g,dy/=g;
            }
            vis[mp(dx,dy)]++;
        }
        for(auto e : vis) (del += pw[e.se] - 1) %= P;
        (del += 1) %= P;
    }
    (ans += P - del) %= P;
    cout << ans << endl;
    return 0;
}
