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

const int P = 1e9 + 7 , N = 2002 , M = N * N;
inline void pp(int &x,int d) {if((x+=d)>=P)x-=P;}
int n , K , fac[M] , ifac[M];
int f[N][N];
inline int comb(int a,int b) {
  return ll(fac[a])*ifac[b]%P*ifac[a-b]%P;
}

int main(){
  cin >> n >> K;
  int tot = n * K;
  if(K == 1) {
    cout << 1 << endl;
    return 0;
  }
  rep(i,0,tot+1) fac[i]=i?ll(fac[i-1])*i%P:1;
  rep(i,0,tot+1) ifac[i]=i<2?1:P-ll(P/i)*ifac[P%i]%P;
  rep(i,1,tot+1) ifac[i]=ll(ifac[i-1])*ifac[i]%P;
  rep(i,0,n+1) rep(j,i,n+1) {
    if(i == 0 && j == 0) {
      f[i][j] = 1;
      continue;
    }
    if(i) f[i][j] = f[i-1][j];
    if(j > i) pp(f[i][j] , ll(f[i][j-1]) *
        comb(i + j * (K - 1) - 1 , K - 2) % P);
  }
  cout << ll(f[n][n]) * fac[n] % P << endl;
  return 0;
}
