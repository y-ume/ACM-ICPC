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

const int N = 1000 * (50 + 10) , M = 26;
int ne[N][M] , sz[N] , _;
int newnode() {
  ++_;
  rep(i,0,M) ne[_][i] = 0;
  sz[_] = 0;
  return _;
}
int ans;

int dfs(int c) {
  int d = 0;
  rep(i,0,M) if(ne[c][i]){
    int del = dfs(ne[c][i]);
    d += del;
  }
  sz[c] -= d;
  if(sz[c] >= 2) {
    d += 2;
    sz[c] -= 2;
    ans += 2;
  }
  return d;
}

int main() {
  int T , n;
  cin >> T;
  rep(i,0,T) {
    _ = 0;
    int rt = newnode();
    cin >> n;
    rep(i,0,n) {
      string s;
      cin >> s;
      reverse(all(s));
      int cur = rt;
      rep(i,0,sz(s)) {
        int t=s[i]-'A';
        if(!ne[cur][t]) {
          ne[cur][t] = newnode();
        }
        cur = ne[cur][t];
        sz[cur]++;
      }
    }
    ans=0;
    dfs(rt);
    cout << "Case #" << i+1 << ": " << ans << endl;
  }
  return 0;
}
