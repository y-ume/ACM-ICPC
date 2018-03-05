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

const int N = 303;
int n , u[N] , d[N] , l[N] , r[N];
int dir[N][N];

void match() {
  vector<pii> remain;
  rep(i,0,n) {
    int s = u[i] + d[i];
    if(s > n) {
      puts("NO");
      exit(0);
    }
    remain.pb(mp(-(n - s) , i));
  }
  sort(all(remain));
  rep(i,0,n) {
    int s = l[i] + r[i];
    if(s > n) {
      puts("NO");
      exit(0);
    }
    rep(j,0,s) {
      remain[j].fi++;
      if(remain[j].fi > 0) {
        puts("NO");
        exit(0);
      }
      dir[i][remain[j].se] = 1;
    }
    inplace_merge(remain.begin() , remain.begin() + s , remain.end());
  }
  rep(i,0,n) rep(j,0,n) {
    dir[i][j] = dir[i][j] ? (--l[i] >= 0 ? 0 : 2) : (--u[j] >= 0 ? 1 : 3);
  }
  //rep(i,0,n) rep(j,0,n)
    //printf("%d%c",dir[i][j]," \n"[j == n - 1]);
}

int used[N][N] , instack[N][N];
int dx[4] = {0 , -1 , 0 , 1};
int dy[4] = {-1 , 0 , 1 , 0};
bool dfs(int i,int j) {
  if(used[i][j]) return false;
  if(instack[i][j]) {
    instack[i][j] = false;
    return true;
  }
  instack[i][j] = true;
  int d = dir[i][j];
  for(int ni=i+dx[d],nj=j+dy[d];;ni+=dx[d],nj+=dy[d]) {
    if(ni < 0 || ni >= n || nj < 0 || nj >= n)
      break;
    if(dfs(ni , nj)) {
      dir[ni][nj] = d;
      if(instack[i][j]) {
        instack[i][j] = false;
        return true;
      } else {
        return dfs(i , j);
      }
    }
  }
  used[i][j] = true;
  instack[i][j] = false;
  printf("%c%d\n","LURD"[dir[i][j]],(dir[i][j] & 1 ? j : i) + 1);
  return false;
}

int main(){
  scanf("%d",&n);
  rep(i,0,n) scanf("%d",u+i);
  rep(i,0,n) scanf("%d",d+i);
  rep(i,0,n) scanf("%d",l+i);
  rep(i,0,n) scanf("%d",r+i);
  match();
  rep(i,0,n) rep(j,0,n)
    dfs(i,j);
  return 0;
}
