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
char s[N];
int ne[N][2] , dep[N] , rt , _;
int n;
ll L;

int main(){
  scanf("%d%lld",&n,&L);
  rt = ++_;
  rep(i,0,n) {
    scanf("%s",s);
    int len = strlen(s);
    int c = rt;
    rep(i,0,len) {
      int ch = s[i] - '0';
      if(!ne[c][ch]) {
        int t = ne[c][ch] = ++_;
        dep[t] = dep[c] + 1;
      }
      c = ne[c][ch];
    }
  }
  ll sg = 0;
  rep(i,1,_+1) rep(j,0,2) if(!ne[i][j]){
    ll t = L - dep[i];
    sg ^= t & -t;
  }
  puts(sg ? "Alice" : "Bob");
  return 0;
}
