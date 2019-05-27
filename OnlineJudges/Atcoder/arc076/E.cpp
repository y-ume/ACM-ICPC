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

int r , c , n;
int id(int x,int y){
    if(y == 0) return x;
    if(x == r) return r + y;
    if(y == c) return r + c + r - x;
    if(x == 0) return r + c + r + c - y;
    return -1;
}
vector<pii> pts;

int main(){
    scanf("%d%d%d",&r,&c,&n);
    rep(i,0,n) {
        int x , y , a[2];
        rep(j,0,2) {
            scanf("%d%d",&x,&y);
            a[j] = id(x , y);
        }
        if(a[0] != -1 && a[1] != -1){
            pts.pb(mp(a[0] , i));
            pts.pb(mp(a[1] , i));
        }
    }
    sort(all(pts));
    vi v;
    rep(i,0,sz(pts)) {
        if(sz(v) && v[sz(v)-1] == pts[i].se) v.pop_back();
        else v.pb(pts[i].se);
    }
    puts(sz(v) ? "NO" : "YES");
    return 0;
}
