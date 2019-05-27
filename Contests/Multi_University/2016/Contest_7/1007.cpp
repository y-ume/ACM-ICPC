#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <string>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <complex>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vi;
#define de(x) cout << #x << "=" << x << endl
#define rep(i,a,b) for(int i=a;i<(b);++i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
const int N = 1010;
int T , n , m;
vi q[N] , V;
vector<pii> g[N];
ll f[N] , dp[N][N];

void dfs(int c,int fa){
    //cout << c << " " << fa << endl;
    fill_n(dp[c],sz(V),0);
    int j=0;
    if(c != 1)
    rep(i,0,sz(V)){
        while(j<sz(q[c]) && q[c][j] < i) ++j;
        dp[c][i] = 1ll * (sz(q[c]) - j) * V[i];
        //cout << c << " " << i << " " << dp[c][i] << endl;
    }
    for(auto e : g[c]) if(e.fi != fa){
        int t = e.fi;
        dfs(t , c);
        ll tmp = dp[t][sz(V)-1];
        dp[c][sz(V)-1] += tmp;
        for(int i=sz(V)-2;i>=0;--i){
            tmp = max(tmp , dp[t][i]);
            dp[c][i] += tmp;
        }
    }
}
int ans[N];
void dfs2(int c,int fa,int i){
    for(auto e : g[c]) if(e.fi != fa){
        int t = e.fi;
        int j=i;ll Max = -1;
        for(int k=i;k<sz(V);++k) if(dp[t][k] > Max) Max = dp[t][k] , j=k;
        ans[e.se] = V[j] - V[i];
        dfs2(t , c , j);
    }
}

void main2(){
    scanf("%d%d",&n,&m);
    fill_n(g,n+1,vector<pii>());
    fill_n(q,n+1,vi());
    V.clear();
    rep(i,1,n){
        int u,v;scanf("%d%d",&u,&v);
        g[u].pb(mp(v,i));g[v].pb(mp(u,i));
    }
    V.pb(0);
    rep(i,0,m){
        int u,v;
        scanf("%d%d",&u,&v);
        q[u].pb(v);
        V.pb(v);
    }
    sort(all(V));V.erase(unique(all(V)),V.end());
    //rep(i,0,sz(V)) printf("%d%c",V[i]," \n"[i+1==sz(V)]);
    rep(i,1,n+1){
        sort(all(q[i]));
        rep(j,0,sz(q[i]))
            q[i][j] = lower_bound(all(V) , q[i][j]) - V.begin();
    }
    dfs(1,0);
    ll best = -1;int id = 0;
    rep(i,0,sz(V)){
        if(dp[1][i] > best) best = dp[1][i] , id = i;
    }
    dfs2(1,0,id);
    printf("%lld\n",best);
    for(int i=1;i<n;++i) printf("%d%c",ans[i]," \n"[i+1==n]);
}

int main(){
    scanf("%d",&T);
    rep(i,0,T) main2();
    return 0;
}
