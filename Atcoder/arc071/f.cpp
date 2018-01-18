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

const int N = 1e6 + 10 , P = 1e9 + 7;
inline void pp(int &x,int d){if((x+=d)>=P)x-=P;}
int f[N],n;

int main(){
  scanf("%d",&n);
  f[0] = 1;
  f[1] = n;
  int s = 0;
  rep(i,2,n+1) {
    f[i] = f[i-1];
    if(i-3>=0)
      pp(s , f[i-3]);
    pp(f[i] , s);
    pp(f[i] , n-1-(i-2));
    pp(f[i] , ll(n - 1) * (n - 1) % P);
  }
  printf("%d\n",f[n]);
  return 0;
}
