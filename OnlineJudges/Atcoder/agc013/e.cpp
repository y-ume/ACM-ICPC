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

const int P = 1e9 + 7;
inline void pp(int &x,int d){if((x+=d)>=P)x-=P;}

typedef vector<vi> MM;
MM operator * (const MM a,const MM b){
  int L = sz(a);MM r(L,vi(L,0));
  rep(i,0,L) rep(j,0,L) rep(k,0,L) pp(r[i][j] , ll(a[i][k]) * b[k][j] % P);
  return r;
}
MM operator ^ (MM a,ll t){
  int L = sz(a);MM r(L,vi(L,0));
  rep(i,0,L) r[i][i] = 1;
  for(;t;t>>=1,a=a*a) if(t&1) r=r*a;
  return r;
}
const int N = 1e5 + 10;
int n , m , x[N];

int main(){
  scanf("%d%d",&n,&m);
  rep(i,1,m+1) scanf("%d",x+i);
  MM limit{
    {1,2,1},
    {0,1,1},
    {0,0,1}
  };
  MM nolimit{
    {2,2,1},
    {1,1,1},
    {1,0,1}
  };
  MM A(3,vi(3,0));
  rep(i,0,3) A[i][i]=1;
  rep(i,1,m+1) {
    A = A * (nolimit ^ (x[i] - x[i-1] - 1));
    A = A * limit;
  }
  A = A * (nolimit ^ (n - x[m]));
  printf("%d\n",A[0][2]);
  return 0;
}
