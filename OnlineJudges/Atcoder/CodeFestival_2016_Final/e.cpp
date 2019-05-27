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

int main(){
  ll n , a;
  cin >> n >> a;
  ll ans = n;
  rep(k,2,50) {
    for(ll x=2;;++x) {
      ll mul = 1;
      rep(i,0,k) {
        mul *= x;
        if(mul >= n)
          break;
      }
      if(mul >= n) {
        ll need = (x - 1) * k;
        mul = 1;
        rep(i,0,k) mul *= (x - 1);
        while(mul < n) {
          mul /= x - 1;
          mul *= x;
          need++;
        }
        ans = min(ans , need + a * (k - 1));
        break;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
