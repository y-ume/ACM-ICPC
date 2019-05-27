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


const int N = 1010;
int T , n , x[N] , y[N];

int main() {
  scanf("%d",&T);
  rep(i,1,T+1) {
    scanf("%d",&n);
    rep(i,0,n) scanf("%d%d",x + i,y + i);
    set<pii> S;
    rep(i,0,n) rep(j,i+1,n) {
      int dx = x[i] - x[j];
      int dy = y[i] - y[j];
      if(dx < 0) dx *= -1 , dy *= -1;
      if(dx > 0 && dy < 0) {
        int g = __gcd(dx , -dy);
        S.insert(mp(dx / g , -dy / g));
      }
    }
    printf("Case #%d: %d\n",i,1 + sz(S));
  }
  return 0;
}
