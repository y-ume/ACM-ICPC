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

const int N = 110;
int n , a[N][N];

int main(){
  scanf("%d",&n);
  if(n == 2) return puts("-1") , 0;
  rep(i,0,n) rep(j,0,n-1)
    a[i][j] = (i + j + 1) % n;
  if(n % 2 == 0) {
    rep(i,0,n/2) for(int j=0;j+1<n-1;j+=2)
      swap(a[i][j] , a[i][j + 1]);
  }
  rep(i,0,n) rep(j,0,n-1)
    printf("%d%c",a[i][j]+1," \n"[j==n-2]);
  return 0;
}
