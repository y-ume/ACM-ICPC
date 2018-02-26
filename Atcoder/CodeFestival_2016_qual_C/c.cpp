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

const int N = 1e5 + 10 , P = 1e9 + 7;
int l[N] , r[N] , a[N] , b[N] , n;

int main(){
  cin >> n;
  rep(i,1,n+1) cin >> a[i];
  rep(i,1,n+1) cin >> b[i];
  rep(i,1,n+1) l[i] = 1 , r[i] = P;
  rep(i,1,n+1) {
    if(a[i] != a[i-1])
      l[i] = a[i] , r[i] = a[i];
    else
      r[i] = a[i];
  }
  per(i,1,n+1) {
    if(b[i] != b[i+1])
      l[i] = max(l[i] , b[i]) , r[i] = min(r[i] , b[i]);
    else
      r[i] = min(r[i] , b[i]);
  }
  int ans = 1;
  rep(i,1,n+1) {
    if(l[i] <= r[i])
      ans = ll(ans) * (r[i] - l[i]+ 1) % P;
    else
      ans = 0;
  }
  cout << ans << endl;
  return 0;
}
