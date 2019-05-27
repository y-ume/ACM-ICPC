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

int x[3] , y[3];
db d[3];

int main(){
  rep(i,0,3) scanf("%d%d",x+i,y+i);
  rep(i,0,3) {
    db dx=x[i]-x[(i+1)%3];
    db dy=y[i]-y[(i+1)%3];
    d[i] = sqrt(dx*dx+dy*dy);
  }
  db a = d[0] , b = d[1] , c = d[2];
  db p = (a + b + c) / 2;
  db area = sqrt(p * (p - a) * (p - b) * (p - c));
  db r = area / p;
  db D = max(max(a , b) , c);
  // (1 - x / r) * D = 2 * x
  // D = (2 + D / r) * x
  db ans = D / (2 + D / r);
  printf("%.12f\n",ans);
  return 0;
}
