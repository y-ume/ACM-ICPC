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
int n , m , K , pre[N] , fa[N];
int F(int x) {return fa[x] == x ? x : fa[x] = F(fa[x]);}

int main(){
  scanf("%d%d",&n,&m);
  memset(pre , -1 , sizeof(fa));
  rep(i,0,n) fa[i] = i;
  rep(i,0,n) {
    int l , x;
    scanf("%d",&l);
    rep(j,0,l) {
      scanf("%d",&x);
      if(pre[x] != -1) {
        fa[F(pre[x])] = F(i);
      }
      pre[x] = i;
    }
  }
  bool ok = true;
  rep(i,0,n) ok &= F(i) == F(0);
  puts(ok ? "YES" : "NO");
  return 0;
}
