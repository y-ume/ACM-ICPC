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
int n , L , a[N];

int main(){
  cin >> n >> L;
  rep(i,1,n+1) cin >> a[i];
  vector<pair<int,ll> > v;
  vi ans;
  rep(i,1,n+1) {
    v.pb(mp(i,a[i]));
    while(sz(v) >= 2 && v[sz(v)-1].se + v[sz(v)-2].se >= L) {
      ans.pb(v[sz(v)-2].fi);
      v[sz(v)-2].se+=v[sz(v)-1].se;
      v[sz(v)-2].fi=v[sz(v)-1].fi;
      v.pop_back();
    }
  }
  if(sz(v) == 1) {
    cout << "Possible" << endl;
    per(i,0,sz(ans)) cout << ans[i] << endl;
  } else
    cout << "Impossible" << endl;
  return 0;
}
