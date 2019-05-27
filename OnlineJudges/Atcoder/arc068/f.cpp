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

const int N = 2002 , P = 1e9 + 7;
inline void pp(int &x,int d){if((x+=d)>=P)x-=P;}
int n , K , comb[N][N] , f[N][N] , g[N] , pw2[N];

int main(){
  cin >> n >> K;
  rep(i,0,n+1) rep(j,0,i+1) comb[i][j]=j?(comb[i-1][j-1]+comb[i-1][j])%P:1;
  pw2[0]=1;rep(i,1,n+1) pw2[i]=pw2[i-1]*2%P;
  g[0] = 1;
  rep(i,0,n+1) rep(j,0,n-i+1) f[i][j]=g[i+j],pp(g[i+j+1],f[i][j]);
  if(n == K) cout << f[n-1][0] << endl;
  else {
    int ans = 0;
    rep(m,2,n+1) {
      int sum = m - 2 , choose = n - K - 1;
      if(sum < choose) continue;
      int tmp = ll(comb[sum][choose]) * f[n-m][m-2-choose] % P * pw2[choose] % P;
      pp(ans , tmp);
    }
    cout << ans << endl;
  }
  return 0;
}
