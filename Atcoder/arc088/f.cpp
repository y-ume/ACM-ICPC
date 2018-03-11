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
int n;
vi g[N];

bool check(vi&f,int B,int skip) {
  for(int i=0,j=sz(f)-1;i<j;++i,--j) {
    if(i == skip) ++i;
    if(j == skip) --j;
    if(i < j && f[i] + f[j] > B)
      return false;
  }
  return true;
}

int dfs(int c,int fa,int B) {
  vi f;
  for(auto t : g[c]) if(t != fa) {
    f.pb(dfs(t , c , B));
  }
  if(~sz(f) & 1) f.pb(0);
  sort(all(f));
  if(!check(f , B , sz(f) - 1))
    throw 1;
  int l = -1 , r = sz(f) - 1;
  while(l + 1 < r) {
    int mid = (l + r) >> 1;
    (check(f , B , mid) ? r : l) = mid;
  }
  return f[r] + 1;
}

bool check(int B,int rt) {
  try {
    int d = dfs(rt , 0 , B);
    if(d > B + 1)
      return false;
    return true;
  } catch(...) {
    return false;
  }
}

int main(){
  scanf("%d",&n);
  rep(i,1,n) {
    int x,y;
    scanf("%d%d",&x,&y);
    g[x].pb(y);
    g[y].pb(x);
  }
  int A = 0;
  rep(i,1,n+1) A += sz(g[i]) & 1;
  int rt = 1;
  while(~sz(g[rt]) & 1) rt++;
  A >>= 1;
  int l = 0 , r = n;
  while(l + 1 < r) {
    int mid = (l + r) >> 1;
    (check(mid , rt) ? r : l) = mid;
  }
  printf("%d %d\n",A,r);
  return 0;
}
