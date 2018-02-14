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

const int N = 5005 , P = 1e9 + 7;
inline void pp(int &x,int d) {if((x+=d)>=P)x-=P;}
int n , m , f[N] , g[N];
string s;

int main(){
  cin >> n >> s;
  f[0] = 1;
  rep(i,0,n) {
    rep(i,0,n+1) g[i] = 0;
    rep(j,0,i+1) if(f[j]) {
      pp(g[j + 1] , f[j]);
      if(j) pp(g[j - 1] , 2 * f[j] % P);
      else pp(g[j] , f[j]);
    }
    rep(i,0,n+1) f[i] = g[i];
  }
  printf("%d\n",f[sz(s)]);
  return 0;
}
