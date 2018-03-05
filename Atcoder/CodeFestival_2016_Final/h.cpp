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

const int N = 2e5 + 10 , M = 1e6 + 10;
int n , m , a[N] , f[M + M] , _;

int main(){
  scanf("%d",&n);
  rep(i,1,n) scanf("%d",a+i);
  int sum = 0;
  rep(i,3,n) sum += a[i];
  per(i,0,M) f[_++] = i;
  rep(i,3,n) {
    int last = _ - 1;
    rep(j,1,a[i]+1)
      f[_++] = f[last - j];
  }
  scanf("%d",&m);
  rep(i,0,m) {
    int x;
    scanf("%d",&x);
    if(x >= sum) {
      printf("%d\n",x - sum + a[1] - a[2]);
    } else {
      printf("%d\n",f[_ - 1 - x] + a[1] - a[2]);
    }
  }
  return 0;
}
