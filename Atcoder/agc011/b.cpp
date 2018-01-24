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
int a[N] , n;
ll sum[N];

int main(){
  scanf("%d",&n);
  rep(i,0,n) scanf("%d",a+i);
  sort(a,a+n);
  rep(i,0,n) sum[i]=a[i]+(i?sum[i-1]:0);
  int ans=0;
  per(i,0,n)
    if(sum[i]*2>=a[i+1])
      ans++;
    else break;
  printf("%d\n",ans);
  return 0;
}
