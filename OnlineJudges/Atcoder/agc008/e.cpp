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
int n , a[N] , du[N] , in[N] , sz[N];
int circlecnt[N] , f[N];

int main(){
  cin >> n;
  rep(i,1,n+1) cin >> a[i] , in[a[i]]++;
  rep(i,1,n+1) du[i] = in[i] , sz[i] = 1;
  vi q;
  rep(i,1,n+1) if(!du[i]) q.pb(i);
  rep(i,0,sz(q)) {
    int c=q[i];
    sz[a[c]]+=sz[c];
    if(!--du[a[c]]) q.pb(a[c]);
  }
  rep(i,1,n+1) if(in[i]>2||(in[i]==2&&!du[i]))
    return puts("0") , 0;
  int ans = 1;
  rep(i,1,n+1) if(du[i]) {
    vi cir;
    for(int c=i;du[c];c=a[c])
      cir.pb(c),du[c]=0;
    vi branch;
    rep(i,0,sz(cir)) if(sz[cir[i]]!=1)
      branch.pb(i);
    if(sz(branch)) {
      branch.pb(branch[0]);
      rep(i,1,sz(branch)) {
        int from = branch[i - 1] , to = branch[i];
        int dis = to - from;
        if(dis <= 0) dis += sz(cir);
        if(dis < sz[cir[to]] - 1)
          return puts("0") , 0;
        else if(dis > sz[cir[to]] - 1)
          (ans *= 2) %= P;
      }
    } else circlecnt[sz(cir)]++;
  }
  rep(i,1,n+1) if(circlecnt[i]) {
    int x = circlecnt[i];
    f[0] = 1;
    rep(j,1,x+1) {
      f[j] = f[j - 1];
      if(i >= 3 && i % 2 == 1) (f[j] += f[j - 1]) %= P;
      if(j >= 2) (f[j] += ll(f[j - 2]) * (j - 1) % P * i % P) %= P;
    }
    ans = ll(ans) * f[x] % P;
  }
  cout << ans << endl;
  return 0;
}
