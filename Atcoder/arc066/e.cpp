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
const ll inf = 1e18;
int n , a[N] , op[N];
ll f[N][3];
char s[10];

int main(){
  scanf("%d",&n);
  rep(i,1,n+1) {
    if(i==1) op[i]=0;
    else {
      scanf("%s",s);
      op[i]=s[0]=='-';
    }
    scanf("%d",a+i);
  }
  rep(i,0,n+1) rep(j,0,3) f[i][j]=-inf;
  f[0][0]=0;
  rep(i,0,n+1) per(j,0,3) {
    if(j) f[i][j-1]=max(f[i][j-1],f[i][j]);
    if(i!=n) {
      ll t=f[i][j]+a[i+1]*((j+op[i+1])&1?-1:1);
      f[i+1][j]=max(f[i+1][j],t);
      if(op[i+1]==1&&j!=2)
        f[i+1][j+1]=max(f[i+1][j+1],t);
    }
  }
  printf("%lld\n",f[n][0]);
  return 0;
}
