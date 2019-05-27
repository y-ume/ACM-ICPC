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

const int N = 2e5 + 10 , P = 1e9 + 7;
int n , x , y , fac[N] , ifac[N];
int c[N] , w[N];
vi col[N] , contain[N];
int fa[N];
int inv(int x) {return x<=1?x:P-ll(P/x)*inv(P%x)%P;}
inline int F(int x){return fa[x]==x?x:fa[x]=F(fa[x]);}
inline void merge(int a,int b){
  a=F(a);b=F(b);
  if(a!=b) fa[b]=a;
}

int main(){
  scanf("%d%d%d",&n,&x,&y);
  rep(i,0,n) scanf("%d%d",c+i,w+i) , col[c[i]].pb(i);
  rep(i,0,n) fa[i]=i;
  fac[0]=1;rep(i,1,n+1) fac[i]=ll(fac[i-1])*i%P;
  ifac[n]=inv(fac[n]);per(i,1,n+1) ifac[i-1]=ll(ifac[i])*i%P;
  vector<pii> Mns;
  rep(i,1,n+1) if(sz(col[i])){
    int Mn=2e9,id=0;
    for(auto j:col[i]) if(w[j]<Mn)
      Mn=w[j],id=j;
    Mns.pb(mp(Mn,id));
    for(auto j:col[i]) if(Mn+w[j]<=x)
      merge(id,j);
  }
  sort(all(Mns));
  rep(d,0,min(2,sz(Mns))) {
    int i=Mns[d].se;
    rep(j,0,n) if(c[j]!=c[i]&&w[j]+w[i]<=y)
      merge(i,j);
  }
  rep(i,0,n) contain[F(i)].pb(i);
  int ans=1;
  rep(i,0,n) if(sz(contain[i])){
    map<int,int> times;
    for(auto e : contain[i])
      times[c[e]]++;
    ans=ll(ans)*fac[sz(contain[i])]%P;
    for(auto e : times)
      ans=ll(ans)*ifac[e.se]%P;
  }
  printf("%d\n",ans);
  return 0;
}
