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
int n , a[N];

int main(){
  scanf("%d",&n);
  rep(i,0,n) scanf("%d",a+i);
  ll l = 2 , r = 2;
  per(i,0,n) {
    l = (l - 1) / a[i] + 1;
    r = r / a[i];
    if(l > r) {
      puts("-1");
      return 0;
    }
    l = l * a[i];
    r = r * a[i] + a[i] - 1;
  }
  cout << l << " " << r << endl;
  return 0;
}
