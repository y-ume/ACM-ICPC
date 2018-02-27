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

const int N = 1e3 + 10;
const ll inf = 1e9 + 7;
int n , m , a[N][N];
ll times[N];

ll solve(vector<ll> A,vector<ll> B,int sig = 0) {
  if(A >= B) {
    int times = 0;
    while(true) {
      rep(i,1,sz(B)) {
        B[i] += B[i-1];
        B[i] = min(B[i] , inf);
        if(B[i] == inf)
          break;
      }
      times++;
      if(sig == 0) {
        if(A < B) return times;
        if(sz(B) == 2) return times + (A[1] - B[1] + B[0]) / B[0];
        if(B[2] == inf) return times + (A[1] - B[1] + B[0] - 1) / B[0];
      } else {
        if(A <= B) return times;
        if(sz(B) == 2 || B[2] == inf) return times + (A[1] - B[1] + B[0] - 1) / B[0];
      }
    }
  } else return -(solve(B , A , 1) - 1);
}

int main(){
  scanf("%d%d",&n,&m);
  rep(i,0,n) rep(j,0,m) scanf("%d",a[i]+j);
  bool error = false;
  rep(i,1,n) error |= a[i][0] < a[i-1][0];
  if(m == 1) rep(i,1,n) error |= a[i][0] <= a[i-1][0];
  if(error) return printf("-1\n") , 0;
  rep(i,1,n) {
    if(a[i][0] > a[i-1][0]) {
      times[i] = 0;
      continue;
    }
    vector<ll> A , B;
    rep(j,0,m) A.pb(a[i-1][j]) , B.pb(a[i][j]);
    ll del = solve(A,B);
    times[i] = max(0ll , times[i-1] + del);
  }
  ll ans = 0;
  rep(i,0,n) ans += times[i];
  printf("%lld\n",ans);
  return 0;
}
