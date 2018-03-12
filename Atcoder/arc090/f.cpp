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

const int P = 1e9 + 7 , N = 23000000;
inline void pp(int &x,int d) {if((x+=d)>=P)x-=P;}
int Pow(int x,int t) {int r(1);for(;t;t>>=1,x=ll(x)*x%P)if(t&1)r=ll(r)*x%P;return r;}
int S;
char num[N];

int main(){
  cin >> S;
  int ans = 0;
  int lim = 1e7;
  int _ = 0;
  rep(i,1,9) {
    int tot = 9 * Pow(10 , i - 1);
    rep(j,0,tot) {
      if(_ + 1 == N) break;
      num[++_] = i;
    }
  }
  for(int l=1,r=1,s=1;l<lim;s-=num[l++]) {
    while(s < S) s+=num[++r];
    if(s == S) ans++;
  }
  pp(ans , S / 8);
  for(int i = 1;i * i <= S;++i) if(S % i == 0) {
    auto add = [&](int x) {
      if(x >= 8) pp(ans , ((9ll * Pow(10 , x - 1) % P - S / x) + P) % P);
    };
    add(i);
    if(i * i != S) add(S / i);
  }
  cout << ans << endl;
  return 0;
}
