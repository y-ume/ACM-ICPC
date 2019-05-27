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

const int N = 5e5 + 10 , P = 1e9 + 7;
inline void pp(int &x,int d) {if((x+=d)>=P)x-=P;}
inline int mul(int a,int b) {return ll(a)*b%P;}
int n , p[N] , fac[N] , vis[N];

struct Fenwick{
  int n,a[N];
  void add(int x,int d) {for(;x<=n;x+=x&-x)pp(a[x],d);}
  int sum(int x) {int r=0;for(;x>=1;x&=x-1)pp(r,a[x]);return r;}
}f0,f1;

int main(){
  fac[0]=1;rep(i,1,N) fac[i]=ll(fac[i-1])*i%P;
  scanf("%d",&n);
  int zero = 0;
  f0.n=f1.n=n;
  rep(i,1,n+1) {
    scanf("%d",p+i);
    if(p[i]) vis[p[i]] = true;
    else zero++;
  }
  rep(i,1,n+1) if(!vis[i]) f0.add(i,1);
  int ans = 0 , rightzero = zero , leftzero = 0 , sumfac = 0;
  rep(i,1,n+1) {
    if(!p[i]) {
      rightzero--;
      leftzero++;
      // 0 0
      if(zero >= 2)
        pp(ans , mul(fac[zero - 2] , mul(fac[n - i] , mul(rightzero , ll(zero) * (zero - 1) / 2 % P))));
      pp(sumfac , fac[n - i]);
    } else {
      if(zero >= 1) {
        // 0 x
        pp(ans , mul(fac[zero - 1] , mul(sumfac , zero - f0.sum(p[i]))));
        // x 0
        pp(ans , mul(fac[zero - 1] , mul(fac[n - i] , mul(rightzero , f0.sum(p[i])))));
      }
      // x x
      pp(ans , mul(fac[zero] , (f1.sum(n) - f1.sum(p[i]) + P) % P));
      f1.add(p[i] , fac[n - i]);
    }
  }
  pp(ans , fac[zero]);
  printf("%d\n",ans);
  return 0;
}
