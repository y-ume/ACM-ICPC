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

const int N = 1e5 + 10 , inf = 2e9 + 10;
int n , c , K , a[N];

int main(){
  scanf("%d%d%d",&n,&c,&K);
  rep(i,0,n) scanf("%d",a+i);
  sort(a,a+n);
  int ans=0,sum=0,limit=inf;
  rep(i,0,n) {
    if(sum==c||a[i]>limit) {
      ans++;
      sum=0;
      limit=inf;
    }
    if(sum==0) limit=a[i]+K;
    sum++;
  }
  if(sum) ans++;
  printf("%d\n",ans);
  return 0;
}
