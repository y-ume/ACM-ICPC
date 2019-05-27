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
  vi cnt(2 , 0);
  for(auto ch : s)
    cnt[ch - '0']++;
  int l = 0 , r = sz(s) - 1;
  int ans = sz(s);
  while(cnt[0] && cnt[1]) {
    cnt[s[l++] - '0']--;
    cnt[s[r--] - '0']--;
    --ans;
  }
  cout << ans << endl;
  return 0;
}
