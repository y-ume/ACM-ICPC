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
int n , m , K , f[N] , g[N];

int main(){
  cin >> n >> m >> K;
  int l = (n + m - 1) / (K - 1);
  f[0] = 1;
  int ans=0 , nmod = n % (K - 1) , mmod = (m - 1) % (K - 1);
  rep(i,1,l+1) {
    rep(j,0,n+1) g[j]=0;
    rep(j,0,n+1) if(f[j]) {
      rep(k,1,K) if(j+k<=n) pp(g[j+k],f[j]);
    }
    rep(j,0,n+1) if(j % (K - 1) == nmod){
      int k = i * (K - 1) - j;
      if(k <= m - 1 && k % (K - 1) == mmod)
        pp(ans , g[j]);
    }
    rep(j,0,n+1) if(f[j]) {
      pp(g[j],f[j]);
    }
    rep(j,0,n+1) f[j]=g[j];
  }
  cout << ans << endl;
  return 0;
}
