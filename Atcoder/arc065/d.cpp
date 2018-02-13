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

const int N = 2e5 + 10;
int n , K , L , posa[N] , posb[N];
int fa[N];
int F(int x) {return fa[x]==x?x:fa[x]=F(fa[x]);}

void connect(int m,int *pos) {
  rep(i,1,n+1) fa[i]=i;
  rep(i,0,m) {
    int u,v;scanf("%d%d",&u,&v);
    fa[F(v)]=F(u);
  }
  rep(i,1,n+1) pos[i]=F(i);
}

int main(){
  scanf("%d%d%d",&n,&K,&L);
  connect(K , posa);
  connect(L , posb);
  map<pii,int> cnt;
  rep(i,1,n+1) cnt[mp(posa[i],posb[i])]++;
  rep(i,1,n+1) printf("%d%c",cnt[mp(posa[i],posb[i])]," \n"[i==n]);
  return 0;
}
