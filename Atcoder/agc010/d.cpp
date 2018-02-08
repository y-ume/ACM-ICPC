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

bool solve() {
  int even = 0;
  rep(i,0,n) even += ~a[i] & 1;
  if(even % 2 == 1) return 1;
  else if(even + 1 != n || *min_element(a,a+n) == 1) return 0;
  else {
    rep(i,0,n) if(a[i] & 1) --a[i];
    int g=a[0];
    rep(i,1,n) g=__gcd(g,a[i]);
    rep(i,0,n) a[i]/=g;
    return 1^solve();
  }
}

int main(){
  cin >> n;
  rep(i,0,n) cin >> a[i];
  cout << (solve() ? "First" : "Second") << endl;
  return 0;
}
