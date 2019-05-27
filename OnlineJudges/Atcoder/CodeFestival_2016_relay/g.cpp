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
int n , Q , f[N];

int main(){
  scanf("%d%d",&n,&Q);
  int c = 1;
  f[2] = 1;
  rep(i,0,Q) {
    int a,b;
    scanf("%d%d",&a,&b);
    swap(f[a] , f[b]);
    if(c == a || c == b)
      c ^= a ^ b;
    if(c != 1) f[c - 1] = 1;
    if(c != n) f[c + 1] = 1;
  }
  f[c] = 1;
  int ans = 0;
  rep(i,1,n+1) ans += f[i];
  printf("%d\n",ans);
  return 0;
}
