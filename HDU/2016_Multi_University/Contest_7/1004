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
const int N = 1000005;
int pri[N] , vis[N] , cnt[N] , small[N] , _ , n;
vi g[N] , fac;
int q[N] , _q;

int a[N] , b[N];
void dfs(int dep,int c){
    if(dep == _) fac.pb(c);
    else{
        dfs(dep+1,c);
        for(int i=0;i<b[dep];++i)
            dfs(dep+1,c*=a[dep]);
    }
}
void get(int x){
    _ = 0;
    for(int t=x;t>1;){
        int s=small[t];
        int cnt=0;while(t%s==0) t/=s,++cnt;
        a[_]=s,b[_++]=cnt;
    }
    fac.clear();
    dfs(0,1);
}

priority_queue<pii> Q[N];
void I(int x){
    if(!vis[x]){
        q[_q++] = x;
        vis[x] = true;
        get(x);
        for(auto e : fac){
            Q[e].push(mp(-cnt[x/e],x));
        }
    }
}

void D(int x){
    if(vis[x]){
        vis[x] = false;
    }
}

int Query(int x){
    get(x);
    int ret = ~0U>>1;
    for(auto e : fac){
        while(sz(Q[e]) && !vis[Q[e].top().se]) Q[e].pop();
        if(sz(Q[e])) ret = min(ret , -Q[e].top().fi + cnt[x/e]);
    }
    return ret == ~0U>>1 ? -1 : ret;
}

void main2(){
    rep(i,0,_q){
        if(vis[q[i]]){
            vis[q[i]] = false;
            get(q[i]);
            for(auto x : fac){
                while(sz(Q[x])) Q[x].pop();
            }
        }
    }
    _q = 0;
    char s[10];int x;
    rep(i,0,n){
        scanf("%s%d",s,&x);
        if(s[0] == 'I') I(x);
        else if(s[0] == 'Q') printf("%d\n",Query(x));
        else D(x);
    }
}

int main(){
    for(int i=2;i<N;++i){
        if(!vis[i]) pri[_++] = i , cnt[i] = 1 , small[i] = i;
        for(int j=0,o;j<_&&(o=pri[j]*i)<N;++j){
            vis[o]=true;cnt[o]=cnt[i]+1;small[o]=pri[j];
            if(i%pri[j]==0) break;
        }
    }
    //for(int i=1;i<N;++i) for(int j=i;j<N;j+=i) g[j].pb(i);
    int re = 1;
    memset(vis,0,sizeof(vis));
    while(~scanf("%d",&n) && n) printf("Case #%d:\n",re++) , main2();
    return 0;
}
