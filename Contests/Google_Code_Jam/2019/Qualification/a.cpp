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

int main() {
  int T;
  cin >> T;
  rep(i,0,T) {
    string s;
    cin >> s;
    string A , B;
    auto special = [&](string s) {
      if(s[0] != '1') return false;
      rep(i,1,sz(s)) if(s[i] != '0') return false;
      return true;
    };
    if(special(s)) {
      A = string(sz(s) - 1 , '9');
      B = "1";
    } else {
      auto add = [&](string&S,int x) {
        if(x||sz(S)) S += char(x + '0');
      };
      for(auto x : s) {
        int t = x - '0';
        int a = t , b = 0;
        if(a == 0);
        else if(a == 1) {
          if(sz(A)) swap(a , b);
        } else {
          while(!a || !b || a == 4 || b == 4) {
            --a;++b;
          }
        }
        add(A , a);
        add(B , b);
      }
    }
    cout << "Case #" << i + 1 << ": " << A << " " << B << endl;
  }
  return 0;
}
