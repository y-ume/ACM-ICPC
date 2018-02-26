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
int H , W;
char s[N][N];
int cost[N][N] , f[N][N];

int solve(string&s,string&t){
  int n = sz(s);
  rep(i,0,n+1) rep(j,0,n+1) {
    if(i == 0 || j == 0)
      cost[i][j] = f[i][j] = 0;
    else
      cost[i][j] = cost[i-1][j-1] + (s[i-1] == t[j-1]) ,
        f[i][j] = min(f[i-1][j] , f[i][j-1]) + cost[i][j];
  }
  return f[n][n];
}

int main(){
  scanf("%d%d",&H,&W);
  rep(i,0,H) scanf("%s",s[i]);
  int ans = 0;
  rep(i,1,W) {
    string A = "" , B = "";
    rep(j,0,H) A += s[j][i-1] , B += s[j][i];
    ans += solve(A , B);
  }
  printf("%d\n",ans);
  return 0;
}
