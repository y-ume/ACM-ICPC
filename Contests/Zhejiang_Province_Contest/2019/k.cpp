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

const int N = 2e6 + 10;
char s[N] , t[N];
int pa[N << 1];

// length of pa is two size of str
// pa[i<<1] : odd string
// pa[i<<1|1] : even string
void Manacher(char *s,int n,int *pa){
  pa[0] = 1;
  for(int i=1,j=0;i<(n<<1)-1;++i){
    int p = i >> 1 , q = i - p , r = ((j + 1)>>1) + pa[j] - 1;
    pa[i] = r < q ? 0 : min(r - q + 1 , pa[(j<<1) - i]);
    while(0 <= p - pa[i] && q + pa[i] < n && s[p - pa[i]] == s[q + pa[i]])
      pa[i]++;
    if(q + pa[i] - 1 > r) j = i;
  }
}

int main() {
  int T;
  scanf("%d",&T);
  rep(i,0,T) {
    scanf("%s%s",s,t);
    int n = strlen(s);
    int l = 0 , r = n - 1;
    while(l < n && s[l] == t[l]) ++l;
    while(r >= 0 && s[r] == t[r]) --r;
    if(l == n) {
      Manacher(s , n , pa);
      ll ans = 0;
      rep(i,0,(n<<1)-1) ans += pa[i];
      printf("%lld\n",ans);
    } else {
      bool ck = true;
      // [l , r]
      for(int i=l;i<=r;++i) ck &= s[i] == t[l + r - i];
      if(!ck) printf("0\n");
      else {
        int ans = 1;
        rep(t,0,n) {
          if(r + 1 + t >= n) break;
          if(l - 1 - t < 0) break;
          if(s[l - 1 - t] == s[r + 1 + t]) {
            ans ++;
          } else break;
        }
        printf("%d\n",ans);
      }
    }
  }
  return 0;
}
