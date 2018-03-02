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

const int P = 1e9 + 7 , N = 100000 , S = 447;
inline void pp(int &x,int d) {if((x+=d)>=P)x-=P;}
inline void pp(pii&x,pii d) {pp(x.fi,d.fi);pp(x.se,d.se);}
pii dp[2][N + 1];
int len[N];

int main(){
  len[1] = N;
  rep(i,2,S+1) len[i] = len[i-1] - (i-1);
  int c = 0;
  per(i,1,S+1) {
    c ^= 1;
    rep(j,0,len[i]+1) {
      dp[c][j] = mp(0 , 0);
      if(j >= i * 2) {
        pp(dp[c][j] , dp[c][j - i]);
        pp(dp[c][j] , dp[c ^ 1][j - i]);
      } else
        dp[c][j] = mp(1 , j);
    }
  }
  int Q;
  scanf("%d",&Q);
  rep(i,0,Q) {
    int a , b;
    scanf("%d%d",&a,&b);
    pii t = dp[c][a / b];
    int ans = ll(t.fi) * (a % b) % P;
    pp(ans , ll(t.se) * b % P);
    printf("%d\n",ans);
  }
  return 0;
}
