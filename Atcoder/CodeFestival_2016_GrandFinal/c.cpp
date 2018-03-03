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

int n , a , has[32];

int main(){
  scanf("%d",&n);
  int xo = 0;
  rep(i,0,n) {
    scanf("%d",&a);
    xo ^= a;
    has[__builtin_ctz(a)]++;
  }
  int ans = 0;
  per(i,0,31) if(xo >> i & 1) {
    if(has[i]) {
      xo ^= (1 << (i + 1)) - 1;
      ans++;
    }
  }
  if(xo == 0) printf("%d\n",ans);
  else puts("-1");
  return 0;
}
