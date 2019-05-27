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


int main(){
  int Q;
  cin >> Q;
  rep(i,0,Q) {
    int a , b , c , d;
    cin >> a >> b >> c >> d;
    int mx = max(a , b);
    int mn = min(a , b);
    int K = (mx + mn) / (mn + 1);
    int l = 0 , r = a + 1;
    while(l + 1 < r) {
      int mid = (l + r) >> 1;
      int leftA = mid;
      int leftB = max(0 , (leftA - 1) / K);
      int rightA = a - leftA;
      int rightB = b - leftB;
      if(rightB <= 1ll * (rightA + 1) * K)
        l = mid;
      else
        r = mid;
    }
    string ans;
    int leftA = l , leftB = (leftA - 1) / K;
    rep(i,c,d+1) {
      if(i <= leftA + leftB) {
        ans += i % (K + 1) == 0 ? "B" : "A";
      } else {
        int j = a + b + 1 - i;
        ans += j % (K + 1) == 0 ? "A" : "B";
      }
    }
    cout << ans << endl;
  }
  return 0;
}
