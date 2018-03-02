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

string s;
int p;
int at(int x) {
  return x < sz(s) ? s[x] : -1;
}
pii Min(pii a,pii b) {
  return pii(min(a.fi,b.fi),min(a.se,b.se));
}
pii Max(pii a,pii b) {
  return pii(max(a.fi,b.fi),max(a.se,b.se));
}

pii parse() {
  if(at(p) == '_' || at(p) == '^') {
    int type = at(p) == '_';
    ++p;
    ++p;
    pii a = parse();
    ++p;
    pii b = parse();
    ++p;
    return type ? Min(a , b) : Max(a , b);
  } else if(at(p) >= '0' && at(p) <= '9') {
    ++p;
    if(at(p) >= '0' && at(p) <= '9') {
      int t = at(p) - '0' + (at(p - 1) - '0') * 10;
      ++p;
      return mp(t,t);
    }
    if(at(p - 1) == '0' || at(p) != -1) {
      int t = at(p - 1) - '0';
      return mp(t,t);
    }
    int t = at(p - 1) - '0';
    return mp(t , t * 10 + 9);
  }
  return pii(0,99);
}

int main(){
  int Q;
  cin >> Q;
  rep(i,0,Q) {
    string s;
    cin >> s;
    int l = 0 , r = sz(s);
    while(l + 1 < r) {
      int mid = (l + r) >> 1;
      p = 0;
      ::s = s.substr(0 , mid);
      pii t = parse();
      if(t.fi == t.se) r = mid;
      else l = mid;
    }
    p = 0;
    ::s = s;
    printf("%d %d\n",parse().fi,r);
  }
  return 0;
}
