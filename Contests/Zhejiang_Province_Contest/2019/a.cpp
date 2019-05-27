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
int T , n , q;
int sz[N] , fa[N];
int components;
ll edgeIn;

int F(int x) {return fa[x] == x ? x : fa[x] = F(fa[x]);}

ll sum[N << 2] , edge[N << 2];
int comp[N << 2];

void modify(int c,int l,int r,int p,int d) {
  if(l == r) {
    sum[c] += 1ll * d * p;
    comp[c] += d;
    edge[c] = 1ll * l * l * comp[c] * (comp[c] - 1) >> 1;
  } else {
    int mid = (l + r) >> 1;
    if(p <= mid) modify(c << 1 , l , mid , p , d);
    else modify(c << 1 | 1 , mid + 1 , r , p , d);
    sum[c] = sum[c << 1] + sum[c << 1 | 1];
    comp[c] = comp[c << 1] + comp[c << 1 | 1];
    edge[c] = edge[c << 1] + edge[c << 1 | 1] + sum[c << 1] * sum[c << 1 | 1];
  }
}

ll ptssum , remain;
bool full;
int query(int c,int l,int r) {
  if(full || remain < 0) return 0;
  if(ptssum * sum[c] + edge[c] <= remain) {
    remain -= ptssum * sum[c] + edge[c];
    ptssum += sum[c];
    return comp[c];
  } else if(l != r){
    int mid = (l + r) >> 1;
    return query(c << 1 | 1 , mid + 1 , r) +
      query(c << 1 , l , mid);
  } else {
    int L = 0 , R = comp[c] + 1;
    while(L + 1 < R) {
      int M = (L + R) >> 1;
      ll edgesum = ptssum * l * M + (1ll * l * l * M * (M - 1) >> 1);
      (edgesum <= remain ? L : R) = M;
    }
    remain -= ptssum * l * L + (1ll * l * l * L * (L - 1) >> 1);
    ptssum += l * L;
    if(L != comp[c]) full = true;
    return L;
  }
}

int main() {
  scanf("%d",&T);
  rep(i,0,T) {
    scanf("%d%d",&n,&q);
    rep(i,1,n+1) sz[i] = 1 , fa[i] = i;
    components = n , edgeIn = 0;
    memset(sum , 0 , (n * 4) * sizeof(sum[0]));
    memset(edge , 0 , (n * 4) * sizeof(edge[0]));
    memset(comp , 0 , (n * 4) * sizeof(comp[0]));
    modify(1 , 1 , n , 1 , n);
    int op , u , v;
    ll K;
    rep(i,0,q) {
      scanf("%d",&op);
      if(op == 1) {
        scanf("%d%d",&u,&v);
        int fu = F(u) , fv = F(v);
        if(fu != fv) {
          modify(1 , 1 , n , sz[fu] , -1);
          modify(1 , 1 , n , sz[fv] , -1);
          edgeIn += 1ll * sz[fu] * sz[fv];
          fa[fv] = fu;
          sz[fu] += sz[fv];
          sz[fv] = 0;
          modify(1 , 1 , n , sz[fu] , 1);
          components--;
        }
        edgeIn--;
      } else {
        scanf("%lld",&K);
        ptssum = 0 , remain = K - edgeIn;
        full = false;
        int B = components - max(1 , query(1 , 1 , n)) + 1;
        B -= remain > 0;
        printf("%lld %d\n",max(1ll , components - K) , B);
      }
    }
  }
  return 0;
}
