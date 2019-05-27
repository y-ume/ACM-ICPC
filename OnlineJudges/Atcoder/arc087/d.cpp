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


bool check(vi v,int x) {
  int sum = 0;
  for(auto e : v)
    sum += e;
  int t = sum + x;
  if(t % 2 == 1 || t < 0)
    return false;
  t /= 2;
  bitset<8001> B;
  B[0] = 1;
  for(auto e : v)
    B |= B << e;
  return B.test(t);
}

int main(){
  string s;
  int x , y;
  cin >> s >> x >> y;
  int i = 0 , n = sz(s);
  while(i < n && s[i] == 'F') {
    --x;++i;
  }
  vi v[2];
  int d = 0 , go = 0;
  for(;i<n;++i) {
    if(s[i] == 'T') {
      if(go) v[d].pb(go);
      d ^= 1;
      go = 0;
    } else
      ++go;
  }
  if(go) v[d].pb(go);
  puts(check(v[0] , x) && check(v[1] , y) ? "Yes" : "No");
  return 0;
}
