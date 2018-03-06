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

const int N = 303 , P = 1e9 + 7;
int n , a[N][N] , f[N][N] , pw2[N * N];
int Pow(int x,int t) {int r=1;for(;t;t>>=1,x=ll(x)*x%P)if(t&1)r=ll(r)*x%P;return r;}
inline void pp(int &x,int d) {if((x+=d)>=P)x-=P;}
inline int mul(int a,int b) {return ll(a)*b%P;}

int main(){
  rep(i,0,N*N) pw2[i] = i ? pw2[i-1] * 2 % P : 1;
  scanf("%d",&n);
  rep(i,0,n) rep(j,0,n) scanf("%d",a[i]+j);
  int rank = 0;
  rep(j,0,n) {
    int id = -1;
    rep(i,rank,n) if(a[i][j]) {
      id = i;
      break;
    }
    if(id == -1) continue;
    rep(k,0,n) swap(a[rank][k] , a[id][k]);
    rep(i,rank+1,n) if(a[i][j]) {
      rep(k,0,n) a[i][k] ^= a[rank][k];
    }
    rank++;
  }
  f[0][0] = 1;
  rep(i,0,n) rep(j,0,i+1) if(f[i][j]) {
    pp(f[i+1][j] , mul(f[i][j] , pw2[j]));
    pp(f[i+1][j+1] , mul(f[i][j] , (pw2[n] - pw2[j] + P) % P));
  }
  int ans = 0;
  rep(i,rank,n+1) pp(ans , mul(f[n][i] , mul(f[i][rank] , pw2[n*(n-i)])));
  ans = mul(ans , Pow(f[n][rank] , P - 2));
  printf("%d\n",ans);
  return 0;
}
