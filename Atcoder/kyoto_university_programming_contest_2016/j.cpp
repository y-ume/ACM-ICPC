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

const int N = 1e5 + 10 , P = 1e9 + 7;
int Pow(int x,int t) {int r=1;for(;t;t>>=1,x=ll(x)*x%P)if(t&1)r=ll(r)*x%P;return r;}
void pp(int &x,int d) {if((x+=d)>=P)x-=P;}
int myrand() {return (ll(rand())<<32 ^ ll(rand)<<16 ^ rand()) % P;}
int rd[N] , ifac[N];
int n , K , par[N] , in[N];
vi g[N];
int C(int a,int b) {
  int r=1;rep(i,0,b) r=ll(r)*(a-i)%P;
  return ll(r)*ifac[b]%P;
}

int sz[N] , hs[N] , way[N];
void dfs(int c) {
  sz[c]=hs[c]=1;way[c]=K;
  for(auto t : g[c]) dfs(t),sz[c]+=sz[t],hs[c]=ll(hs[c])*(rd[sz[t]]+hs[t])%P;
  sort(all(g[c]),[&](int a,int b){return hs[a]<hs[b];});
  for(int i=0,j=0;i<sz(g[c]);i=j) {
    for(j=i;j<sz(g[c])&&hs[g[c][i]]==hs[g[c][j]];++j);
    way[c]=ll(way[c])*C(j-i+way[g[c][i]]-1,j-i)%P;
  }
}

int ne[N];
int kmp(vi&v) {
  ne[0] = -1;
  int n = sz(v);
  for(int i=1,j=-1;i<n;++i) {
    while(j!=-1&&hs[v[j+1]]!=hs[v[i]]) j=ne[j];
    ne[i]=hs[v[j+1]]==hs[v[i]]?++j:j;
  }
  if(n%(n-1-ne[n-1])==0) return n-1-ne[n-1];
  return n;
}

vi manacher(vector<pii>&s) {
  int n = sz(s);
  vi p(n , 1);
  for(int i=1,j=0,k=1;i<n;++i) {
    if(i<k) p[i] = min(p[2*j-i],k-i);
    while(i-p[i]>=0&&i+p[i]<n&&s[i-p[i]]==s[i+p[i]])
      ++p[i];
    if(k<i+p[i]) k=i+p[i],j=i;
  }
  return p;
}

int main(){
  srand(time(NULL));
  rep(i,0,N) rd[i] = myrand();
  rep(i,0,N) ifac[i] = i < 2 ? 1 : P - ll(P/i)*ifac[P%i]%P;
  rep(i,1,N) ifac[i] = ll(ifac[i - 1]) * ifac[i] % P;
  scanf("%d%d",&n,&K);
  rep(i,0,n) scanf("%d",par+i),--par[i],g[par[i]].pb(i),in[par[i]]++;
  vi pts;rep(i,0,n) if(!in[i]) pts.pb(i);
  rep(i,0,sz(pts)) if(!--in[par[pts[i]]]) pts.pb(par[pts[i]]);
  vi cir;int s=0;while(!in[s]) ++s;
  for(int t=par[s];cir.pb(t),t!=s;t=par[t]);
  for(auto c : cir) {
    rep(i,0,sz(g[c])) if(in[g[c][i]]) {
      g[c].erase(g[c].begin() + i);
      break;
    }
    dfs(c);
    //cout << sz[c] << " " << hs[c] << " " << way[c] << endl;
  }
  int up = 0 , down = 0;
  int L = sz(cir);
  int smallloop = kmp(cir) , block = L / smallloop;
  vi preprod(L , 0);
  rep(i,0,L) preprod[i] = ll(i ? preprod[i - 1] : 1) * way[cir[i]] % P;
  rep(step,1,block+1) {
    int orbit = __gcd(step , block);
    pp(up , preprod[smallloop * orbit - 1]);
    down ++;
  }
  vector<pii> v;
  map<pii,int> times;
  rep(i,0,L) v.pb(mp(hs[cir[i]],way[cir[i]])),v.pb(mp(-1,1));
  for(auto e : v) times[e]++;
  int cof = 1;
  for(auto e : times) {
    int t = e.se / 2;
    rep(i,0,t) cof = ll(cof) * e.fi.se % P;
  }
  v.insert(v.end() , all(v));
  vi length = manacher(v);
  rep(i,0,L) {
    if(length[i+L]>=L+1) {
      pii x = v[i+L] , y = v[i+L+L];
      int newcof = cof;
      if(~(++times[x])&1) newcof = ll(newcof) * x.se % P;
      if(~(++times[y])&1) newcof = ll(newcof) * y.se % P;
      --times[x];
      --times[y];
      pp(up , newcof);
      down++;
    }
  }
  printf("%lld\n",ll(up) * Pow(down , P - 2) % P);
  return 0;
}
