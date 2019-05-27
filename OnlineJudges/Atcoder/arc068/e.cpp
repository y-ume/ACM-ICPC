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

const int N = 3e5 + 10;
int n , m;
pii seg[N];

struct Fenwick {
  int a[N],n;
  void ini(int _n) {fill_n(a,(n=_n)+1,0);}
  void add(int x,int d) {
    for(;x<=n;x+=x&-x) a[x]+=d;
  }
  int sum(int x) {
    int r(0);
    for(;x>=1;x&=x-1) r+=a[x];
    return r;
  }
}fen;

int main(){
  scanf("%d%d",&n,&m);
  rep(i,0,n) scanf("%d%d",&seg[i].fi,&seg[i].se);
  sort(seg , seg + n , [&](pii a,pii b){return a.se-a.fi<b.se-b.fi;});
  fen.ini(m);
  int cur = 0;
  rep(i,1,m+1) {
    while(cur < n && seg[cur].se - seg[cur].fi + 1 < i) {
      fen.add(seg[cur].fi , 1);
      fen.add(seg[cur].se + 1 , -1);
      cur++;
    }
    int ans = n - cur;
    for(int j=i;j<=m;j+=i)
      ans += fen.sum(j);
    printf("%d\n",ans);
  }
  return 0;
}
