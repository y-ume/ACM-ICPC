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
int n , b[N];
ll A , B;

int main() {
  int T;
  scanf("%d",&T);
  rep(i,0,T) {
    scanf("%d%lld%lld",&n,&A,&B);
    rep(i,1,n+1) scanf("%d",b + i);
    ll sumA = 0 ,sumB = 0;
    rep(i,1,n+1) {
      sumA += ll(b[i]) * i;
      sumB += ll(b[i]) * ll(b[i]) * i;
    }
    ll dA = sumA - A;
    ll dB = sumB - B;
    if(dA == 0) {
      if(dB != 0) printf("%d\n",0);
      else {
        map<int,int> times;
        ll ans = 0;
        rep(i,1,n+1) ans += times[b[i]]++;
        printf("%lld\n",ans);
      }
    } else {
      ll t = dA > 0 ? dA : -dA;
      ll ans = 0;
      rep(d,1,n) if(t % d == 0) {
        ll del = dA / d;
        rep(i,d+1,n+1) ans += (del == (b[i] - b[i - d])) && (dA * (b[i] + b[i - d]) == dB);
      }
      printf("%lld\n",ans);
    }
  }
  return 0;
}
