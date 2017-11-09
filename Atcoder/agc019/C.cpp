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

const db pi = acos(-1.);
const int N = 2e5 + 10;
int sx , sy , tx , ty;
int n , x[N] , y[N];

int main(){
    scanf("%d%d%d%d",&sx,&sy,&tx,&ty);
    scanf("%d",&n);
    rep(i,0,n) scanf("%d%d",x + i,y + i);
    if(sx > tx) {
        sx = -sx , tx = -tx;
        rep(i,0,n) x[i] = -x[i];
    }
    if(sy > ty) {
        sy = -sy , ty = -ty;
        rep(i,0,n) y[i] = -y[i];
    }
    if(tx - sx < ty - sy) {
        swap(sx , sy);swap(tx , ty);
        rep(i,0,n) swap(x[i] , y[i]);
    }
    db ans = 100. * (tx + ty - sx - sy);
    if(sy == ty) {
        bool fd = false;
        rep(i,0,n) fd |= y[i] == sy && sx <= x[i] && x[i] <= tx;
        if(fd) ans += 10 * pi - 20;
    } else {
        vector<pii> pts;
        rep(i,0,n) if(sx <= x[i] && x[i] <= tx && sy <= y[i] && y[i] <= ty)
            pts.pb(mp(x[i] , y[i]));
        sort(all(pts));
        vi best;
        for(auto e : pts) {
            int y = e.se;
            auto it = lower_bound(all(best) , y);
            if(it == best.end()) best.pb(y);
            else *it = y;
        }
        if(sz(best) == ty - sy + 1){
            ans += (5 * pi - 20) * (sz(best) - 1);
            ans += 10 * pi - 20;
        } else {
            ans += (5 * pi - 20) * sz(best);
        }
    }
    printf("%.16f\n",ans);
    return 0;
}
