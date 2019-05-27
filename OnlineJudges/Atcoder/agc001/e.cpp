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

const int N = 2e5 + 10 , P = 1e9 + 7 , MAX = 2010 , M = MAX << 1;
int Pow(int x,int t){int r=1;for(;t;t>>=1,x=ll(x)*x%P)if(t&1)r=ll(r)*x%P;return r;}
inline void pp(int &x,int d){if((x+=d)>=P)x-=P;}
int n , a[N] , b[N] , fac[M + M] , ifac[M + M] , f[M];
vector<pii> event[M];

int way(int a,int b) {
  return ll(fac[a+b])*ifac[b]%P*ifac[a]%P;
}

int main(){
  rep(i,0,M + M) fac[i]=i?ll(fac[i-1])*i%P:1;
  rep(i,0,M + M) ifac[i]=Pow(fac[i],P-2);
  cin >> n;
  int del=0;
  rep(i,0,n) {
    cin >> a[i] >> b[i];
    pp(del,way(a[i]+a[i],b[i]+b[i]));
    event[-a[i] + MAX].pb(mp(-b[i] + MAX , 1));
    event[a[i] + MAX].pb(mp(b[i] + MAX , -1));
  }
  int ans=0;
  rep(i,0,M) {
    for(auto e : event[i]) if(e.se==1) pp(f[e.fi],1);
    rep(j,1,M) pp(f[j],f[j-1]);
    for(auto e : event[i]) if(e.se==-1) pp(ans,f[e.fi]);
  }
  pp(ans,P-del);
  ans=ll(ans)*Pow(2,P-2)%P;
  cout << ans << endl;
  return 0;
}
