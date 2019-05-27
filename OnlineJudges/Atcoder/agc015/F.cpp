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

const ll linf = 1e18 , P = 1e9 + 7;
vector<ll> fib;
vector<vector<pair<ll,ll> > > v;

void dfs(int a,ll b,ll c,int d){
    if(b&&c/b==1) v[a].pb(mp(b,c)),v[a].pb(mp(c,b));
    if(d==0){
        ll nb=c,nc=b+c*2;
        if(nb<=linf&&nb<=fib[a+3]&&nc<=linf&&nc<=fib[a+3])
            dfs(a+1,nb,nc,1);
    }
    ll nb=c,nc=b+c;
    if(nb<=linf&&nb<=fib[a+3]&&nc<=linf&&nc<=fib[a+3])
        dfs(a+1,nb,nc,d);
}

int main(){
    fib.pb(1);
    fib.pb(1);
    while(*fib.rbegin()<linf) fib.pb(fib[sz(fib)-1]+fib[sz(fib)-2]);
    v.resize(sz(fib));
    dfs(0 , 1 , 1 , 0);
    int Q;scanf("%d",&Q);
    rep(i,0,Q){
        ll x,y;scanf("%lld%lld",&x,&y);
        if(x>y) swap(x,y);
        int k=1;
        rep(i,1,sz(fib)-1) if(fib[i]<=x&&fib[i+1]<=y)
            k=i;
        ll ans=0;
        if(k == 1) ans=(x%P)*(y%P)%P;
        else {
            for(auto e : v[k]) {
                if(e.fi > x || e.se > y) continue;
                (ans += (y - e.se) / e.fi + 1) %= P;
            }
        }
        printf("%d %lld\n",k,ans);
    }
    return 0;
}
