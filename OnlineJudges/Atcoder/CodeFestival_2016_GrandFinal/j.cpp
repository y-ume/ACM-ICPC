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

const int N = 5005 , P = 1e9 + 7;
int Pow(int x,int t) {int r=1;for(;t;t>>=1,x=ll(x)*x%P)if(t&1)r=ll(r)*x%P;return r;}
int fac[N] , ifac[N];

int comb(int a,int b) {
  if(a < b || a < 0 || b < 0)
    return 0;
  return ll(fac[a]) * ifac[b] % P * ifac[a - b] % P;
}

int main(){
  rep(i,0,N) fac[i] = i ? ll(fac[i-1]) * i % P : 1;
  rep(i,0,N) ifac[i] = Pow(fac[i] , P - 2);
  int n , A , B , C;
  cin >> n >> A >> B >> C;
  if(B & 1) {
    cout << 0 << endl;
    return 0;
  }
  int ans = 0;
  for(int cnt13=0;cnt13<=A&&cnt13<=C;cnt13++) {
    for(int cnt333=0;cnt13+cnt333*3<=C;cnt333++) {
      int remainC = C - cnt13 - cnt333 * 3;
      int way = B == 0 ? remainC == 0 : comb(remainC + B / 2  - 1 , remainC);
      way = ll(way) * fac[B / 2 + cnt13 + cnt333 + A - cnt13] % P
        * ifac[B / 2] % P * ifac[cnt13] % P * ifac[cnt333] % P * ifac[A - cnt13] % P;
      ans += way;
      if(ans >= P)
        ans -= P;
    }
  }
  cout << ans << endl;
  return 0;
}
