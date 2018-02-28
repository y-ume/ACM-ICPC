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

const int N = 18;
int n , a[1 << N];

int main(){
  scanf("%d",&n);
  rep(i,0,1<<n) scanf("%d",a+i);
  per(i,0,n) {
    rep(j,0,1<<i) {
      int x=a[j<<1],y=a[j<<1|1];
      if(x>y) a[j]=x-y;
      else if(x==y) a[j]=x;
      else a[j]=y-x;
    }
  }
  printf("%d\n",a[0]);
  return 0;
}
