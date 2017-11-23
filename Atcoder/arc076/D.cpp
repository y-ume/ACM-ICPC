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
int fa[N] , n , x[N] , y[N] , id[N];
vector<pair<int,pii> > edge;
int F(int x){return fa[x]==x?x:fa[x]=F(fa[x]);}

int main(){
    scanf("%d",&n);
    rep(i,0,n) {
        scanf("%d%d",x + i,y + i);
        id[i] = i;
    }
    sort(id,id+n,[&](int a,int b){return x[a]<x[b];});
    rep(i,1,n) edge.pb(mp(x[id[i]]-x[id[i-1]],mp(id[i],id[i-1])));
    sort(id,id+n,[&](int a,int b){return y[a]<y[b];});
    rep(i,1,n) edge.pb(mp(y[id[i]]-y[id[i-1]],mp(id[i],id[i-1])));
    sort(all(edge));
    rep(i,0,n) fa[i]=i;
    ll cost=0;
    rep(i,0,sz(edge)){
        int u=edge[i].se.fi,v=edge[i].se.se;
        u=F(u),v=F(v);
        if(u!=v){
            fa[v]=u;
            cost+=edge[i].fi;
        }
    }
    cout<<cost<<endl;
    return 0;
}
