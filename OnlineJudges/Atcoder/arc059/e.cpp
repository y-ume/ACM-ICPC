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

const int N = 404 , P = 1e9 + 7;
int n , c , a[N] , b[N] , f[N] , g[N];
int pw[N][N];

int main(){
  cin >> n >> c;
  rep(i,0,n) cin >> a[i];
  rep(i,0,n) cin >> b[i];
  rep(i,0,N) rep(j,0,N)
    pw[i][j]=j?ll(pw[i][j-1])*i%P:1;
  rep(i,1,N) rep(j,0,N)
    (pw[i][j]+=pw[i-1][j])%=P;
  f[0] = 1;
  rep(i,0,n) {
    rep(i,0,c+1) g[i] = 0;
    rep(j,0,c+1) if(f[j]) {
      rep(k,0,c+1) {
        if(j+k>c) break;
        g[j+k]+=ll(f[j])*(((pw[b[i]][k]-pw[a[i]-1][k])%P+P)%P)%P;
        if(g[j+k]>=P) g[j+k]-=P;
      }
    }
    rep(i,0,c+1) f[i] = g[i];
  }
  cout << f[c] << endl;
  return 0;
}
