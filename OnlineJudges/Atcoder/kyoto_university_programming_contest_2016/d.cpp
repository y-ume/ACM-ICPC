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

int n;
vi v;

bool test() {
  string s , t;
  for(auto e : v) {
    s += char(".#"[e>>1]);
    t += char(".#"[e&1]);
  }
  cout << s << endl;
  cout << t << endl;
  cin >> s;
  if(s == "end")
    exit(0);
  return s[0] == 'T';
}

int main(){
  cin >> n;
  bool rev = false;
  while(true) {
    int i = 0;
    for(;i < 4;++i) {
      if(rev) v.insert(v.begin() , i);
      else v.pb(i);
      if(test()) break;
      if(rev) v.erase(v.begin());
      else v.pop_back();
    }
    if(i == 4) rev = true;
  }
  return 0;
}
