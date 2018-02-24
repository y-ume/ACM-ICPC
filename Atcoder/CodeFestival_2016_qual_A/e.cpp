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
int n , m , Q , a[N] , v[N] , _;
int vis[N] , cnt[N] , pos[N];

int main(){
  scanf("%d%d%d",&n,&m,&Q);
  rep(i,0,Q) scanf("%d",a + i);
  reverse(a,a+Q);
  rep(i,0,Q) {
    if(!vis[a[i]])
      vis[a[i]]=1,v[++_]=a[i];
  }
  rep(i,1,m+1) if(!vis[i])
    v[++_]=i;
  rep(i,1,m+1) pos[v[i]]=i;
  cnt[0]=n;
  int Max=0;
  rep(i,0,Q) {
    int t=pos[a[i]];
    if(cnt[t-1]) {
      cnt[t-1]--;
      cnt[t]++;
      Max = max(Max , t);
    } else if(Max < t) {
      puts("No");
      return 0;
    }
  }
  int Min=0;
  rep(i,0,m+1) if(cnt[i]) {
    Min=i;
    break;
  }
  int inc=true;
  rep(i,Min+2,m+1) inc&=v[i]>v[i-1];
  puts(inc ? "Yes" : "No");
  return 0;
}
