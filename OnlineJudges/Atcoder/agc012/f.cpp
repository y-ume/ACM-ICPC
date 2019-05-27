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

const int N = 55 , P = 1e9 + 7;
int n , tot , a[N*2];
int f[N*2][N*2] , g[N*2][N*2];
inline void pp(int &x,int d){
  if((x+=d)>=P)x-=P;
}

int main(){
  cin >> n;
  tot = 2 * n - 1;
  rep(i,0,tot) cin >> a[i];
  sort(a , a + tot);
  f[1][1] = 1;
  rep(d,1,n) {
    int m=d*2+1;
    rep(i,0,m+1) rep(j,0,m+1) g[i][j]=0;
    rep(i,0,m+1) rep(j,0,m+1) if(f[i][j]) {
      int ni=i,nj=j;
      int l=n-1-d,r=n-1+d;
      if(a[l]!=a[l+1]) ni++,nj++;
      if(a[r]!=a[r-1]) ni++;
      rep(k,1,nj) pp(g[ni-(nj-k-1)][k] , f[i][j]);
      pp(g[ni][nj] , f[i][j]);
      rep(k,nj+1,ni+1) pp(g[ni-(k-nj-1)][nj+1] , f[i][j]);
    }
    rep(i,0,m+1) rep(j,0,m+1) f[i][j]=g[i][j];
  }
  int ans=0;
  rep(i,0,tot+1) rep(j,0,tot+1) pp(ans,f[i][j]);
  printf("%d\n",ans);
  return 0;
}
