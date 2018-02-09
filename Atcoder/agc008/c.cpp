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

ll a[7];

int main(){
  rep(i,0,7) cin >> a[i];
  ll ans = a[0] / 2 * 2 + a[3] / 2 * 2 + a[4] / 2 * 2;
  if(a[0] && a[3] && a[4]) {
    ans = max(ans , 3 + (a[0] - 1) / 2 * 2 +
        (a[3] - 1) / 2 * 2 + (a[4] - 1) / 2 * 2);
  }
  ans += a[1];
  cout << ans << endl;
  return 0;
}
