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

const int N = 303 , P = 1e9 + 7;
inline void pp(int &x,int d) {if((x+=d)>=P)x-=P;}
inline int mul(int a,int b) {return ll(a)*b%P;}
int f[N][N][N];
int n , m;

int main(){
  cin >> n >> m;
  f[0][1][1] = 1;
  rep(i,0,m) {
    for(int j=1;j<=n&&j<=i+1;++j)
      for(int k=1;k<=j;++k) if(f[i][j][k]){
        pp(f[i+1][j][k] , mul(f[i][j][k] , j - k));
        pp(f[i+1][j][j] , mul(f[i][j][k] , k));
        pp(f[i+1][j+1][k] , mul(f[i][j][k] , n - j));
      }
  }
  cout << f[m][n][n] << endl;
  return 0;
}
