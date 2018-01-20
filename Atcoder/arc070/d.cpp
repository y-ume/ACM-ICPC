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

const int N = 5000 + 10;
typedef bitset<N> B;
B prefix[N] , suffix[N];
int n , K , a[N];

int main(){
  scanf("%d%d",&n,&K);
  int sum=0;
  rep(i,1,n+1) scanf("%d",a+i);
  rep(i,1,n+1) a[i]=min(a[i],K),sum+=a[i];
  prefix[0][0]=1;
  rep(i,1,n+1) {
    prefix[i]=prefix[i-1]|(prefix[i-1]<<a[i]);
  }
  suffix[n+1][0]=1;
  per(i,1,n+1) {
    suffix[i]=suffix[i+1]|(suffix[i+1]<<a[i]);
  }
  int ans=0;
  rep(i,1,n+1) {
    bool ok = true;
    // [K - a[i] , K)
    int cnt = 0;
    rep(j,K-a[i],K) cnt+=suffix[i+1][j];
    rep(j,0,K) {
      if(j) {
        if(K-a[i]-j>=0)
          cnt-=suffix[i+1][K-a[i]-j];
        cnt+=suffix[i+1][K-j];
      }
      if(prefix[i-1].test(j) && cnt){
        ok = false;
        break;
      }
    }
    ans += ok;
  }
  printf("%d\n",ans);
  return 0;
}
