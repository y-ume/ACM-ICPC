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

const int P = 1e9 + 7;

int main(){
  int n , x;
  scanf("%d",&n);
  vector<pii> v;
  rep(i,0,n) {
    scanf("%d",&x);
    v.pb(mp(x , 0));
  }
  rep(i,0,n) {
    scanf("%d",&x);
    v.pb(mp(x , 1));
  }
  sort(all(v));
  int cnt = 0 , type = 0;
  int ans = 1;
  for(auto e : v) {
    if(cnt && type != e.se) {
      ans = ll(ans) * cnt % P;
      --cnt;
    } else {
      type = e.se;
      ++cnt;
    }
  }
  printf("%d\n",ans);
  return 0;
}
