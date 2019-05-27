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

int main() {
  int T;
  cin >> T;
  int n , m;
  cin >> n >> m;
  rep(i,0,T) {
    if(n == 365 && m == 100) {
      vi v;
      rep(i,0,18) v.pb(18);
      int mx = 0;
      rep(i,0,n) {
        rep(j,0,sz(v)) {
          cout << v[j];
          if(j + 1 == sz(v)) cout << endl;
          else cout << " ";
        }
        fflush(stdout);
        int sum = 0;
        vi v;
        rep(j,0,18) {
          int x;
          cin >> x;
          v.pb(x);
          sum += x;
        }
        //rep(j,0,18) cerr << v[j] << " \n"[j==17];
        //cerr << sum << endl;
        mx = max(mx , sum);
      }
      //cerr << mx << endl;
      cout << mx << endl;
      fflush(stdout);
      int ok;
      cin >> ok;
      //cerr << ok << endl;
    } else {
      vi v({17 , 15 , 13 , 11 , 8 , 7});
      vi r(6,0);
      rep(i,0,6) {
        rep(j,0,18) {
          cout << v[i];
          if(j + 1 == 18) cout << endl;
          else cout << " ";
        }
        fflush(stdout);
        rep(j,0,18) {
          int x;
          cin >> x;
          r[i] += x;
        }
        r[i] %= v[i];
      }
      int ans=0;
      rep(i,1,1000001) {
        bool ck = true;
        rep(j,0,6) ck &= i % v[j] == r[j];
        if(ck) {
          ans = i;
          break;
        }
      }
      //cerr << ans << endl;
      cout << ans << endl;
      fflush(stdout);
      int ok;
      cin >> ok;
      //cerr << ok << endl;
    }
  }
  return 0;
}
