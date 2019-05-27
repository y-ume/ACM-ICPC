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

const int N = 15 , inf = 2e9;
int n , m;
int g[N][N] , cost[1<<N][N] , f[1<<N][N];
int sum[1<<N] , vis[1<<N] , del[1<<N] , times;

void Update(int &x,int d){
    x = min(x , d);
}

#define lb(x) (x&-(x))
int Cost(int mask){
    if(mask == 0) return 0;
    if(vis[mask] == times) return sum[mask];
    int &ret=sum[mask];
    vis[mask]=times;
    int y=lb(mask);
    return ret = del[y] + Cost(mask^y);
}

int main(){
    cin >> n >> m;
    rep(i,0,m){
        int u,v,c;
        cin>>u>>v>>c;
        --u;--v;
        g[u][v]=g[v][u]=c;
    }
    rep(i,0,1<<n) rep(j,0,n) rep(k,0,n) if(i>>k&1) cost[i][j]+=g[j][k];
    rep(i,0,1<<n) rep(j,0,n) f[i][j]=inf;
    f[1][0]=0;
    rep(i,0,1<<n) rep(j,0,n) if(f[i][j]!=inf){
        rep(k,0,n) if(!(i>>k&1)) del[1<<k] = cost[i^(1<<j)][k];
        rep(k,0,n) if(!(i>>k&1) && g[j][k]) Update(f[i|1<<k][k] , f[i][j] + del[1<<k]);
        int x=((1<<n)-1)^i;
        times++;
        for(int k=x;k;k=(k-1)&x) Update(f[i|k][j] , f[i][j] + Cost(k));
    }
    printf("%d\n",f[(1<<n)-1][n-1]);
    return 0;
}
