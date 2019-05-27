#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <bitset>
#include <vector>
#include <complex>
#include <algorithm>
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
const int P = 1e9 + 7 , N = 101010;
int n , m , a[N] , b[N] , q[N] , in[N] , sum[N];
vi g[N];
inline void pp(int &x,int d){
    x += d;
    if(x >= P) x -= P;
}

int main(){
    while(~scanf("%d%d",&n,&m)){
        rep(i,1,n+1) in[i] = 0 , g[i].clear();
        rep(i,1,n+1) scanf("%d%d",a + i , b + i);
        rep(i,0,m){
            int u , v;
            scanf("%d%d",&u,&v);
            g[u].pb(v);in[v]++;
        }
        int _=0;
        rep(i,1,n+1) if(in[i] == 0) q[_++] = i;
        rep(i,0,_){
            int c = q[i];
            rep(j,0,sz(g[c])) if(!--in[g[c][j]]) q[_++] = g[c][j];
        }
        int ans = 0;
        for(int i=_-1;i>=0;--i){
            int c = q[i];
            sum[c] = 0;
            rep(j,0,sz(g[c])){
                int t = g[c][j];
                pp(sum[c] , sum[t]);
            }
            pp(ans , 1ll * sum[c] * a[c] % P);
            pp(sum[c] , b[c]);
        }
        printf("%d\n",ans);
    }
    return 0;
}
