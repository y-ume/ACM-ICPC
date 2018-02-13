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

const int N = 3000 + 10 , P = 1e9 + 7;
int n , m , l[N] , r[N] , f[N];
char s[N];

int main(){
  scanf("%d%d%s",&n,&m,s+1);
  rep(i,1,m+1) scanf("%d%d",l+i,r+i);
  f[0] = 1;
  int rightmost = -1;
  rep(i,1,m+1) {
    int from = l[i - 1] , to = rightmost;
    while(from <= min(to , l[i] - 1)) {
      int len = to - from + 1;
      rep(j,0,n+1) {
        if(j == len) f[j] = 0;
        f[j] += f[j + 1];
        if(f[j] >= P)
          f[j] -= P;
      }
      from++;
    }
    from = max(rightmost + 1 , l[i]) , to = r[i];
    int cnt1 = 0;
    rep(j,from,to+1) cnt1 += s[j] == '1';
    per(j,0,n+1) {
      if(j - cnt1 < 0) f[j] = 0;
      else f[j] = f[j - cnt1];
    }
    rightmost = max(rightmost , r[i]);
  }
  int from = l[m] , to = rightmost;
  while(from <= to) {
    int len = to - from + 1;
    rep(j,0,n+1) {
      if(j == len) f[j] = 0;
      f[j] += f[j + 1];
      if(f[j] >= P)
        f[j] -= P;
    }
    from++;
  }
  printf("%d\n",f[0]);
  return 0;
}
