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

const int N = 2e5 + 10 , LG = 19;
int n , V , x[N] , toR[LG][N] , toL[LG][N] , len;
int fL[1<<LG] , fR[1<<LG];

void prepare(int toR[][N] , int *fL , const vi&x) {
  int V = ::V;
  len = 0;
  while(V >= 0) {
    toR[len][n]=toR[len][n+1]=n;
    per(i,1,n) toR[len][i]=abs(x[i]-x[i+1])<=V?toR[len][i+1]:i;
    len++;
    if(V==0) break;
    V >>= 1;
  }
  rep(i,0,1<<len) fL[i]=0;
  rep(i,0,1<<len) {
    rep(j,0,len) if(~i>>j&1)
      fL[i|1<<j]=max(fL[i|1<<j],toR[j][fL[i]+1]);
  }
}

int main(){
  scanf("%d%d",&n,&V);
  rep(i,1,n+1) scanf("%d",x+i);
  vi v(x,x+1+n);
  prepare(toR , fL , v);
  reverse(v.begin()+1,v.begin()+1+n);
  prepare(toL , fR , v);
  vector<pii> seg;
  int full=(1<<len)-1-1;
  rep(i,0,1<<len) if(~i&1) {
    seg.pb(mp(-fR[i],fL[full^i]));
  }
  sort(all(seg));
  int cur=0,leftmost=-1;
  rep(i,1,n+1) {
    int left=n+1-toL[0][n+1-i];
    int right=toR[0][i];
    while(cur<sz(seg)&&-seg[cur].fi+right>=n) {
      leftmost=max(leftmost,seg[cur].se);
      cur++;
    }
    if(leftmost+1>=left) puts("Possible");
    else puts("Impossible");
  }
  return 0;
}
