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

const int P = 1e9 + 7 , D = 60;
inline void pp(int &x,int d) {if((x+=d)>=P)x-=P;}
ll n;
int dig[D] , f[D][2] , pw3[D] , _;

int dfs(int c,int pre) {
  if(c==-1) return 1;
  if(pre>=2) return pw3[c+1];
  if(~f[c][pre]) return f[c][pre];
  int&res=f[c][pre]=0;
  int s=pre*2+dig[c];
  rep(i,0,3) if(i<=s) pp(res,dfs(c-1,s-i));
  return res;
}

int main() {
  cin >> n;
  while(n) dig[_++]=n&1,n>>=1;
  memset(f,-1,sizeof(f));
  rep(i,0,D) pw3[i]=i?pw3[i-1]*3ll%P:1;
  cout << dfs(_-1,0) << endl;
  return 0;
}
