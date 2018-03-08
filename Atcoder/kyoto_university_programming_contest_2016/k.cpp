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

const db pi = acos(-1.);
int T , x[2] , y[2];
db radius[2];
db o[2] , l[2] , r[2];

int main(){
  scanf("%d",&T);
  rep(i,0,T) {
    rep(i,0,2) scanf("%d%d%lf",x+i,y+i,radius+i);
    o[0] = 0;
    o[1] = hypot(x[0] - x[1] , y[0] - y[1]);
    rep(i,0,2) {
      l[i] = o[i] - radius[i];
      r[i] = o[i] + radius[i];
    }
    db A = l[1] + r[1] - l[0] - r[0];
    db B = -2 * (l[1] * r[1] - l[0] * r[0]);
    db C = (l[0] + r[0]) * l[1] * r[1] - (l[1] + r[1]) * l[0] * r[0];
    db x = (-B + sqrt(B * B - 4 * A * C)) / (2 * A);
    rep(i,0,2) {
      radius[i] = fabs(1 / (l[i] - x) - 1 / (r[i] - x)) / 2;
    }
    db ang = asin(fabs(radius[0] - radius[1]) / (radius[0] + radius[1]));
    printf("%d\n",int(pi / ang));
  }
  return 0;
}
