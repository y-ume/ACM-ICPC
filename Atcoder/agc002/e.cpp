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
  cin >> n;
  rep(i,1,n+1) cin >> a[i];
  sort(a + 1 , a + n + 1);
  reverse(a + 1 , a + n + 1);
  int i = 1;
  while(i + 1 <= n && i + 1 <= a[i + 1])
    ++i;
  int hori = a[i] - i + 1;
  int vert = 0;
  for(int j=i;j<=n;++j) {
    if(a[j]<i) break;
    vert++;
  }
  puts(hori % 2 == 1 && vert % 2 == 1 ?
      "Second" : "First");
  return 0;
}
