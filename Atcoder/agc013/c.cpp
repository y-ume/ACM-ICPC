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
int n , L , T , x[N] , w[N] , ed[N] , ans[N];

int main(){
  scanf("%d%d%d",&n,&L,&T);
  int pos = 0;
  rep(i,0,n) {
    scanf("%d%d",x+i,w+i);
    if(w[i] == 1) {
      ed[i] = (x[i] + T) % L;
      pos += (x[i] + T) / L;
      pos %= n;
    } else {
      ed[i] = ((x[i] - T) % L + L) % L;
      pos += (x[i] - T) / L - (x[i] < T && (x[i] - T) % L != 0);
      pos = (pos % n + n) % n;
    }
  }
  sort(ed , ed + n);
  rep(i,0,n) printf("%d\n",ed[(pos+i)%n]);
  return 0;
}
