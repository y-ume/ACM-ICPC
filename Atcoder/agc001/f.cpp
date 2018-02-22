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

const int N = 5e5 + 10 , inf = 1e9 + 7;
int n , K , p[N] , a[N << 2];
int Min(int c,int l,int r,int L,int R) {
  if(L > R) return inf;
  if(L <= l && r <= R) return a[c];
  int m = (l + r) >> 1;
  int res = inf;
  if(L <= m) res = min(res , Min(c << 1 , l , m , L , R));
  if(R > m) res = min(res , Min(c << 1 | 1 , m + 1 , r , L , R));
  return res;
}
void Update(int c,int l,int r,int p,int x) {
  if(l == r) a[c] = x;
  else {
    int m = (l + r) >> 1;
    if(p <= m) Update(c << 1 , l , m , p , x);
    else Update(c << 1 | 1 , m + 1 , r , p , x);
    a[c] = min(a[c << 1] , a[c << 1 | 1]);
  }
}

int tot , vis[N] , ans[N];

void solve(int c) {
  while(true) {
    int t = Min(1 , 0 , n - 1 , 0 , p[c] - 1);
    if(t >= c + K) break;
    solve(t);
  }
  ans[c] = ++tot;
  vis[c] = true;
  Update(1 , 0 , n - 1 , p[c] , inf);
}

int main(){
  scanf("%d%d",&n,&K);
  rep(i,0,n) scanf("%d",p+i) , Update(1 , 0 , n - 1 , --p[i] , i);
  rep(i,0,n) if(!vis[i]) solve(i);
  rep(i,0,n) printf("%d\n",ans[i]);
  return 0;
}
