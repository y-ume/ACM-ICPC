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
int n , K , a[N];
ll sum[N] , psum[N];

int main(){
  cin >> n >> K;
  rep(i,1,n+1) cin >> a[i];
  rep(i,1,n+1) sum[i] = sum[i-1] + a[i];
  rep(i,1,n+1) psum[i] = psum[i-1] + max(0 , a[i]);
  ll ans = 0;
  rep(i,K,n+1) {
    ll other = psum[n] - psum[i] + psum[i-K];
    ll in = sum[i] - sum[i-K];
    ans = max(ans , max(0ll , in) + other);
  }
  cout << ans << endl;
  return 0;
}
