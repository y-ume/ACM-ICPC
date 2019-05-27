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
int R , C , n , vis[N + N];
ll a[N + N];
vector<pii> g[N + N];
ll MinR , MinC;

void dfs(int c,ll num) {
  vis[c] = true;
  a[c] = num;
  if(c < R) MinR = min(MinR , num);
  else MinC = min(MinC , num);
  for(auto e : g[c]) {
    int t = e.fi;
    int x = e.se;
    if(vis[t]) {
      if(a[c] + a[t] != x) {
        puts("No");
        exit(0);
      }
    } else {
      dfs(t , x - num);
    }
  }
}

int main(){
  scanf("%d%d%d",&R,&C,&n);
  rep(i,0,n) {
    int r , c , a;
    scanf("%d%d%d",&r,&c,&a);
    --r;--c;
    c += R;
    g[r].pb(mp(c , a));
    g[c].pb(mp(r , a));
  }
  rep(i,0,R+C) if(!vis[i]) {
    MinR=MinC=1ll<<60;
    dfs(i,0);
    if(MinR+MinC<0) {
      puts("No");
      return 0;
    }
  }
  puts("Yes");
  return 0;
}
