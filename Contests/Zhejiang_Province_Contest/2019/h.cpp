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

const int N = 1e5 + 10;
int n , a[N];

int main() {
  int T;
  scanf("%d",&T);
  rep(i,0,T) {
    scanf("%d",&n);
    rep(i,0,n) scanf("%d",a + i);
    int s = 0;
    rep(i,1,n-1) s += (a[i] > a[i - 1]) && (a[i] > a[i + 1]);
    int ans = s;
    rep(i,0,n) {
      int t = s;
      vi A , B;
      rep(d,-3,4) {
        int j = i + d;
        if(j >= 0 && j < n) {
          if(d != 0) B.pb(a[j]);
          A.pb(a[j]);
        }
      }
      rep(i,1,sz(A)-1) t -= (A[i] > A[i - 1]) && (A[i] > A[i + 1]);
      rep(i,1,sz(B)-1) t += (B[i] > B[i - 1]) && (B[i] > B[i + 1]);
      ans = min(ans , t);
    }
    printf("%d\n",ans);
  }
  return 0;
}
