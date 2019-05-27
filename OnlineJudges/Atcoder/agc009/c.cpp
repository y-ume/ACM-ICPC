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
const ll inf = 2e18;
inline void pp(int &x,int d) {if((x+=d)>=P)x-=P;}
ll A , B , s[N];
int n;

struct Fenwick {
  int n , a[N];
  vector<pii> rec;
  void ini(int _n) {fill_n(a,(n=_n)+1,0);}
  void add(int x,int d) {rec.pb(mp(x,d));for(;x<=n;x+=x&-x)pp(a[x],d);}
  int sum(int x) {int r=0;for(;x>=1;x&=x-1)pp(r,a[x]);return r;}
  void clear() {
    for(auto e : rec)
      for(int x=e.fi;x<=n;x+=x&-x)
        pp(a[x],P-e.se);
    rec.clear();
  }
} f , g;

int main(){
  scanf("%d%lld%lld",&n,&A,&B);
  s[1] = s[2] = -inf;
  rep(i,3,3+n) scanf("%lld",s+i);
  f.ini(3+n);g.ini(3+n);
  f.add(1,1);
  rep(i,3,3+n) {
    // s[t] <= s[i] - B
    int t = upper_bound(s + 1 , s + i , s[i] - B) - s - 1;
    int addg = f.sum(t);
    t = upper_bound(s + 1 , s + i , s[i] - A) - s - 1;
    int addf = g.sum(t);
    if(s[i] - s[i-1] < A)
      f.clear();
    if(s[i] - s[i-1] < B)
      g.clear();
    f.add(i - 1 , addf);
    g.add(i - 1 , addg);
  }
  int ans = (f.sum(3+n)+g.sum(3+n))%P;
  printf("%d\n",ans);
  return 0;
}
