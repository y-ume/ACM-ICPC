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

const int MAXN = 2010 , MAXK = 1e4 + 10;
int n , K;
string s[MAXN];
int z[MAXK * 2];
bitset<MAXK> can[MAXN] , prefix;

void Zalgo(string&s) {
  memset(z,0,sizeof(z));
  for(int i=1,j=0;i<sz(s);++i) {
    if(i < j + z[j]) z[i] = min(z[i - j] , j + z[j] - i);
    while(i + z[i] < sz(s) && s[z[i]] == s[i + z[i]]) z[i]++;
    if(i + z[i] > j + z[j]) j = i;
  }
  z[0] = sz(s);
}

pii best;
string S , ans;
int A;

int compare(pii a,pii b) {
  if(a.fi < b.fi) return -compare(b,a);
  int lcp = b.fi;
  if(b.se) {
    lcp += min(a.fi - b.fi , z[A + 1 + b.fi]);
    if(lcp == a.fi)
      lcp += z[a.fi - b.fi];
  }
  int lena = a.fi + (a.se ? A : 0);
  int lenb = b.fi + (b.se ? A : 0);
  if(lcp == min(lena , lenb))
    return 0;
  char pa = lcp < a.fi ? ans[lcp] : S[lcp-a.fi];
  char pb = lcp < b.fi ? ans[lcp] : S[lcp-b.fi];
  return pa - pb;
}

bool Update(pii t) {
  if(best.fi == -1) {
    best = t;
    return true;
  }
  int cmp = compare(best , t);
  if(cmp > 0) best = t;
  return cmp >= 0;
}

int main(){
  cin >> n >> K;
  rep(i,0,n) cin >> s[i];
  can[n].set(0);
  per(i,0,n) can[i] = can[i + 1] << sz(s[i]) | can[i + 1];
  prefix.set(0);
  rep(i,0,n) {
    S = s[i] + '$' + ans;
    A = sz(s[i]);
    Zalgo(S);
    best=mp(-1,0);
    per(j,0,K+1) {
      bool ok = false;
      if(prefix.test(j) && can[i + 1].test(K - j))
        ok |= Update(mp(j,0));
      if(j >= sz(s[i]) && prefix.test(j - sz(s[i])) && can[i + 1].test(K - j))
        ok |= Update(mp(j-sz(s[i]),1));
      prefix.set(j,ok);
    }
    ans = ans.substr(0 , best.fi);
    if(best.se) ans += s[i];
    rep(j,sz(ans)+1,K+1) prefix.reset(j);
  }
  cout << ans << endl;
  return 0;
}
