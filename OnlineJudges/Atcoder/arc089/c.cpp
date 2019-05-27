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

int main(){
  int n , t , x , y;
  scanf("%d",&n);
  int lastx = 0 , lasty = 0 , lastt = 0;
  rep(i,0,n) {
    scanf("%d%d%d",&t,&x,&y);
    int duration = t - lastt;
    int d = abs(x - lastx) + abs(y - lasty);
    if((d & 1) != (duration & 1) || d > duration) {
      puts("No");
      return 0;
    }
    tie(lastt , lastx , lasty) = tie(t , x , y);
  }
  puts("Yes");
  return 0;
}
