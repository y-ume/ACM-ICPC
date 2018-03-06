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

db p[6] , q[6];

int main(){
  rep(i,0,6) cin >> p[i] , p[i] /= 100;
  rep(i,0,6) cin >> q[i] , q[i] /= 100;
  auto get = [&](db x) {
    db res = 0;
    rep(i,0,6) res += max(x * p[i] , (1 - x) * q[i]);
    return res;
  };
  db l = 0 , r = 1;
  rep(i,0,200) {
    db m1 = (2 * l + r) / 3;
    db m2 = (l + r * 2) / 3;
    if(get(m1) < get(m2))
      r = m2;
    else
      l = m1;
  }
  printf("%.12f\n",get((l + r) / 2));
  return 0;
}
