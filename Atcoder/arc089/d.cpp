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

const int N = 4040;
int n , K;
int sum[2][N][N];

int query(int c,int x,int y) {
  --x;--y;
  int xx = x + K;
  int yy = y + K;
  int res = sum[c][xx][yy];
  if(x >= 0 && y >= 0)
    res += sum[c][x][y];
  if(x >= 0)
    res -= sum[c][x][yy];
  if(y >= 0)
    res -= sum[c][xx][y];
  return res;
}

int main(){
  scanf("%d%d",&n,&K);
  int x,y;
  char c[10];
  int KK = K + K;
  rep(i,0,n) {
    scanf("%d%d%s",&x,&y,c);
    x %= KK;
    y %= KK;
    sum[c[0]=='B'][x][y]++;
  }
  rep(t,0,2) rep(i,0,KK) rep(j,0,KK)
    sum[t][i+KK][j] = sum[t][i][j+KK] = sum[t][i+KK][j+KK] = sum[t][i][j];
  int KKK = KK + K;
  rep(t,0,2) rep(i,0,KKK) rep(j,0,KKK) {
    if(i) sum[t][i][j] += sum[t][i-1][j];
    if(j) sum[t][i][j] += sum[t][i][j-1];
    if(i && j) sum[t][i][j] -= sum[t][i-1][j-1];
  }
  int ans = 0;
  rep(c,0,2) rep(i,0,K) rep(j,0,K) {
    int cnt = query(c , i , j) + query(c , i + K , j + K)
      + query(c ^ 1 , i + K , j) + query(c ^ 1 , i , j + K);
    ans = max(ans , cnt);
  }
  printf("%d\n",ans);
  return 0;
}
