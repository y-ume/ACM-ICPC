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
  string s;
  cin >> s;
  int n = sz(s);
  vi pos[26];
  rep(i,0,n) pos[s[i]-'a'].pb(i);
  int odd = 0;
  rep(i,0,26) odd+=sz(pos[i])&1;
  if(odd == 0 || (odd == 1 && (n & 1))) {
    vector<pii> v;
    vi permu(n , 0);
    rep(i,0,26) {
      vi&p=pos[i];
      if(sz(p)&1) {
        int mid = sz(p) / 2;
        permu[p[mid]] = n / 2;
        p.erase(p.begin() + mid);
      }
      rep(i,0,sz(p)/2) v.pb(mp(p[i],p[sz(p)-1-i]));
    }
    sort(all(v));
    rep(i,0,n/2) {
      int j=n-1-i;
      permu[v[i].fi] = i;
      permu[v[i].se] = j;
    }
    vi fen(n + 1 , 0);
    ll ans = 0;
    rep(i,0,n) {
      ans += i;
      for(int j = permu[i] + 1;j >= 1;j &= j - 1)
        ans -= fen[j];
      for(int j = permu[i] + 1;j <= n;j += j & -j)
        fen[j] ++;
    }
    cout << ans << endl;
  } else
    cout << -1 << endl;
  return 0;
}
