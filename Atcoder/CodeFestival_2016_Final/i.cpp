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

const int P = 1e9 + 7;
inline int mul(int a,int b) {return ll(a) * b % P;}

bool ispalindomic(string s) {
  string t = s;
  reverse(all(t));
  return s == t;
}
const int N = 220;
int h , w , fac[10];
string s[N];
int fa[N];
int F(int x) {return fa[x] == x ? x : fa[x] = F(fa[x]);}

int main(){
  rep(i,0,10) fac[i] = i ? fac[i-1] * i : 1;
  cin >> h >> w;
  rep(i,0,h) cin >> s[i];
  int ans = 1;
  if(h & 1) {
    int mid = h >> 1;
    ans = mul(ans , ispalindomic(s[mid]) ? 1 : 2);
    rep(i,mid,h) s[i] = s[i + 1];
    --h;
  }
  if(w & 1) {
    int mid = w >> 1;
    string t = "";
    rep(i,0,h) t += s[i][mid];
    ans = mul(ans , ispalindomic(t) ? 1 : 2);
    rep(i,0,h) s[i].erase(s[i].begin() + mid);
    --w;
  }
  int half_h = h >> 1;
  int half_w = w >> 1;
  rep(i,0,half_h + half_w) fa[i] = i;
  rep(i,0,half_h) rep(j,0,half_w) {
    map<char,int> times;
    times[s[i][j]]++;
    times[s[h-1-i][j]]++;
    times[s[i][w-1-j]]++;
    times[s[h-1-i][w-1-j]]++;
    if(sz(times) == 4) {
      ans = mul(ans , 12);
      fa[F(j + half_h)] = F(i);
    } else {
      int cof = 24;
      for(auto e : times)
        cof /= fac[e.se];
      ans = mul(ans , cof);
    }
  }
  int cof = half_h + half_w;
  rep(i,0,half_h + half_w) cof -= F(i) == i;
  rep(i,0,cof) ans = mul(ans , 2);
  cout << ans << endl;
  return 0;
}
