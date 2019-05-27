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

const int P = 998244353;
inline void pp(int &x,int d) {if((x+=d)>=P)x-=P;}
string s;
map<string,int> res;

int solve(string s) {
  if(sz(s) == 0)
    return 1;
  if(res.count(s))
    return res[s];
  int &r = res[s];
  pp(r , 1ll * (s[0] - '0' + 1) * solve(s.substr(1)) % P);
  for(int len=1;len+len<=sz(s);++len) {
    string left = s.substr(0,len);
    for(int l=len;l+len<=sz(s);l+=len) {
      rep(i,0,len) left[i] = ((left[i] - '0') & (s[l+i] - '0')) + '0';
      pp(r , 1ll * solve(left) * solve(s.substr(l+len)) % P);
    }
  }
  return r;
}

int main(){
  string s;
  cin >> s;
  cout << solve(s) << endl;
  return 0;
}
