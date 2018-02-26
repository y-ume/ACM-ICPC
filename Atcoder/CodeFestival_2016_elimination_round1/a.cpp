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

const int N = 4005 , M = 4e5 + 10;
int n , m , cost[N][N] , a[M] , b[M] , c[M] , id[M];
int Q;
int fa[N];
vi contain[N];
int F(int x) {return fa[x] == x ? x : fa[x] = F(fa[x]);}

int main(){
  scanf("%d%d",&n,&m);
  rep(i,0,m) scanf("%d%d%d",a+i,b+i,c+i),id[i]=i;
  rep(i,1,n+1) fa[i]=i,contain[i].pb(i);
  sort(id,id+m,[&](int x,int y){return c[x]<c[y];});
  ll sum = 0;
  rep(i,0,m) {
    int u=F(a[id[i]]) , v=F(b[id[i]]);
    if(u != v) {
      sum += c[id[i]];
      if(sz(contain[u]) < sz(contain[v]))
        swap(u , v);
      for(auto e : contain[u])
        for(auto f : contain[v])
          cost[e][f] = cost[f][e] = c[id[i]];
      contain[u].insert(contain[u].end(),all(contain[v]));
      contain[v].clear();
      fa[v] = u;
    }
  }
  scanf("%d",&Q);
  rep(i,0,Q) {
    int s,t;
    scanf("%d%d",&s,&t);
    printf("%lld\n",sum-cost[s][t]);
  }
  return 0;
}
