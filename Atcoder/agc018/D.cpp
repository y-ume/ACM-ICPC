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

const int N = 1e5 + 10;
int n,uv[N],c[N],sz[N];
ll ans;
vi g[N],rt;

void dfs(int c,int fa) {
    sz[c] = 1;
    int Maxsz = 0;
    for(auto i : g[c]){
        int t = uv[i] ^ c;
        if(t == fa) continue;
        dfs(t , c);
        ans += 2ll * min(sz[t] , n - sz[t]) * ::c[i];
        Maxsz = max(Maxsz , sz[t]);
        sz[c] += sz[t];
    }
    if(Maxsz <= n / 2 && (n - sz[c]) <= n / 2)
        rt.pb(c);
}

int main(){
    scanf("%d",&n);
    rep(i,1,n) {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        uv[i]=a^b;
        ::c[i]=c;
        g[a].pb(i);
        g[b].pb(i);
    }
    dfs(1 , 0);
    if(sz(rt) == 1) {
        int Mn = 1e9;
        for(auto e : g[rt[0]]) {
            Mn = min(Mn , c[e]);
        }
        ans -= Mn;
    } else if(sz(rt) == 2){
        for(auto e : g[rt[0]]) {
            if(uv[e] == (rt[0] ^ rt[1])){
                ans -= c[e];
                break;
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}
