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
int n , m , ok[N] , remain[N];

int main(){
  cin >> n >> m;
  rep(i,1,n+1) remain[i] = 1;
  ok[1] = 1;
  rep(i,0,m) {
    int x,y;
    cin >> x >> y;
    ok[y] |= ok[x];
    remain[y]++;
    if(!--remain[x]) ok[x] = 0;
  }
  int ans = 0;
  rep(i,1,n+1) ans += ok[i];
  cout << ans << endl;
  return 0;
}
