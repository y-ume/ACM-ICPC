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

const int N = 505;
int n , col[N];
char g[N][N];

int main(){
  scanf("%d",&n);
  rep(i,0,n) scanf("%s",g[i]);
  rep(i,0,n) rep(j,0,n) col[j] += g[i][j] == '#';
  if(*max_element(col,col+n)==0) {
    puts("-1");
    return 0;
  }
  int remaincol = 0;
  rep(i,0,n) remaincol += col[i] != n;
  int mn = N;
  rep(i,0,n) {
    int white = 0;
    rep(j,0,n) white += g[i][j] == '.';
    mn = min(mn , white + (col[i] == 0));
  }
  printf("%d\n",mn + remaincol);
  return 0;
}
