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
int n , m , cnt[N] , sum[N] , odd[N];

int main(){
  scanf("%d%d",&n,&m);
  rep(i,0,n) {
    int x;
    scanf("%d",&x);
    cnt[x]++;
  }
  rep(i,0,m) {
    for(int j=i;j<N;j+=m)
      sum[i]+=cnt[j],odd[i]+=cnt[j]&1;
  }
  int ans=0;
  for(int i=0;i+i<=m;++i) {
    int j=(m-i)%m;
    if(i==j) ans+=sum[i]/2;
    else {
      int a=i,b=j;
      if(sum[a]<sum[b]) swap(a,b);
      ans+=sum[b];
      odd[a]-=sum[b];
      if(odd[a]<0) {
        if(odd[a] & 1)
          odd[a] = 1;
        else
          odd[a] = 0;
      }
      ans+=(sum[a]-sum[b]-odd[a])/2;
    }
  }
  printf("%d\n",ans);
  return 0;
}
