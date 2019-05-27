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

const int N = 2e5 + 10 , P = 1e9 + 7;
int H , W , A , B;
int fac[N] , ifac[N];
int comb(int a,int b) {
  return ll(fac[a])*ifac[b]%P*ifac[a-b]%P;
}
int go(int a,int b,int c,int d) {
  return comb(c + d - a - b , c - a);
}

int main(){
  fac[0] = 1;
  rep(i,1,N) fac[i]=ll(fac[i-1])*i%P;
  ifac[0] = ifac[1] = 1;
  rep(i,2,N) ifac[i]=P-ll(P/i)*ifac[P%i]%P;
  rep(i,1,N) ifac[i]=ll(ifac[i-1])*ifac[i]%P;
  cin >> H >> W >> A >> B;
  int ans = 0;
  rep(i,1,H-A+1) {
    ans += ll(go(1 , 1 , i , B)) * go(i , B + 1 , H , W) % P;
    if(ans >= P)
      ans -= P;
  }
  cout << ans << endl;
  return 0;
}
