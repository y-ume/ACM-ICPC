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
int n,m,vis[N];
vi g[N];

int main(){
  scanf("%d%d",&n,&m);
  rep(i,0,m){
    int u,v;scanf("%d%d",&u,&v);
    g[u].pb(v);
    g[v].pb(u);
  }
  vi v;
  v.pb(1);vis[1]=true;
  auto append = [&]{
    int x=v.back();
    for(auto e:g[x]) if(!vis[e]){
      v.pb(e);
      vis[e]=true;
      return true;
    }
    return false;
  };
  while(append());
  reverse(all(v));
  while(append());
  printf("%d\n",sz(v));
  rep(i,0,sz(v)) printf("%d%c",v[i]," \n"[i+1==sz(v)]);
  return 0;
}
