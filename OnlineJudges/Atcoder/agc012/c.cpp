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

ll n;

int main(){
  cin >> n;
  vi v;
  ++n;
  int len = 63 - __builtin_clzll(n);
  per(i,0,len) {
    v.pb(sz(v) + 1);
    if(n >> i & 1)
      v.insert(v.begin() , sz(v) + 1);
  }
  vi nv;
  rep(i,0,sz(v)) nv.pb(i + 1);
  v.insert(v.end(),all(nv));
  cout << sz(v) << endl;
  rep(i,0,sz(v)) cout << v[i] << " \n"[i+1==sz(v)];
  return 0;
}
