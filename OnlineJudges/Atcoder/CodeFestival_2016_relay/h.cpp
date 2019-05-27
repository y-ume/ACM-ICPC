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

const int D = 86400 , M = 10800;
int n , cnt[D + D];

int main(){
  scanf("%d",&n);
  int c=0;
  rep(i,0,n) {
    int a,b;
    scanf("%d%d",&a,&b);
    c += a;
    c %= D;
    cnt[c]++;
    c += b;
    c %= D;
  }
  rep(i,0,D) cnt[i + D] = cnt[i];
  rep(i,1,D+D) cnt[i] += cnt[i-1];
  int ans=0;
  rep(i,0,D) ans = max(ans , cnt[i + M + 1] - cnt[i]);
  printf("%d\n",ans);
  return 0;
}
