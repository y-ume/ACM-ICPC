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

const int N = 71 , P = 1e9 + 7 , M = 400;
inline void pp(int &x,int d) {if((x+=d)>=P)x-=P;}
inline int mul(int a,int b) {return ll(a)*b%P;}
int n , K , dp[N][N] , fac[M] , ifac[M];
string s;
inline int comb(int a,int b) {
  return mul(fac[a] , mul(ifac[b] , ifac[a-b]));
}

int main() {
  rep(i,0,M) fac[i] = i ? mul(fac[i - 1] , i) : 1;
  rep(i,0,M) ifac[i] = i >= 2 ? P - mul(P / i , ifac[P % i]) : 1;
  rep(i,1,M) ifac[i] = mul(ifac[i - 1] , ifac[i]);
  cin >> n >> K >> s;
  int ans = 0;
  for(int a = 0;a <= K;++a)
    for(int ab = 0;ab * 2 + a <= K;++ab) {
      if(a == 0 && ab == 0) {
        ans++;
        continue;
      }
      int cnt_a = 0 , cnt_ab = 0;
      vi sum(ab);
      for(auto ch : s) {
        if(ch == 'r') {
          if(cnt_a + cnt_ab < a + ab)
            cnt_a ++;
          else if(cnt_ab)
            sum[ab - cnt_ab]++;
        } else {
          if(cnt_ab < ab && cnt_a)
            cnt_a-- , cnt_ab ++;
          else if(cnt_ab)
            sum[ab - cnt_ab]++;
        }
      }
      if(ab != cnt_ab || a != cnt_a)
        break;
      rep(i,1,sz(sum)) sum[i] += sum[i-1];
      memset(dp , 0 , sizeof(dp));
      dp[0][0] = mul(fac[a + ab] , ifac[a]);
      for(int add = 0;add * 2 < n;++add)
        for(int cnt_ab = ab;cnt_ab >= 0;--cnt_ab)
          for(int used = ab ? sum.back() : 0;used >= 0;--used) if(dp[cnt_ab][used]) {
            for(int add_ab = 1;cnt_ab + add_ab <= ab &&
                used + add * add_ab <= sum[cnt_ab + add_ab - 1];++add_ab) {
              pp(dp[cnt_ab + add_ab][used + add * add_ab] , mul(dp[cnt_ab][used] , ifac[add_ab]));
            }
          }
      rep(used,0,(ab ? sum.back() : 0) + 1) {
        int need = (ab + used * 2 + a) + (ab + a - 1);
        int remain = n - need;
        if(remain < 0)
          continue;
        int position = (ab * 3 + used * 2 + a) + (ab + a + 1);
        pp(ans , mul(dp[ab][used] , comb(remain + position - 1 , remain)));
      }
    }
  cout << ans << endl;
  return 0;
}
