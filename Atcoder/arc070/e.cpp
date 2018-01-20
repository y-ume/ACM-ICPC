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
int n , l[N] , r[N];
multiset<ll> lpts , rpts;

int main(){
  scanf("%d",&n);
  rep(i,0,n) scanf("%d%d",l+i,r+i);
  lpts.insert(l[0]);
  rpts.insert(l[0]);
  ll dL = 0 , dR = 0;
  ll ans = 0;
  rep(i,1,n) {
    dL -= r[i] - l[i];
    dR += r[i-1] - l[i-1];
    ll L = *lpts.rbegin()+dL;
    ll R = *rpts.begin()+dR;
    if(l[i] < L) {
      auto it=lpts.end();lpts.erase(--it);
      ans += L - l[i];
      lpts.insert(l[i]-dL);
      lpts.insert(l[i]-dL);
      rpts.insert(L-dR);
    } else if(l[i] > R) {
      auto it=rpts.begin();rpts.erase(it);
      ans += l[i] - R;
      rpts.insert(l[i]-dR);
      rpts.insert(l[i]-dR);
      lpts.insert(R-dL);
    } else {
      lpts.insert(l[i]-dL);
      rpts.insert(l[i]-dR);
    }
  }
  printf("%lld\n",ans);
  return 0;
}
