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

int n , C;
int l[6];
db f[50*6][50*6][1<<5];

int main(){
  scanf("%d%d",&n,&C);
  rep(i,0,n) scanf("%d",l+i);
  rep(i,0,n) if(l[i] > l[n-1])
    swap(l[n-1] , l[i]);
  vi rk(n - 1);
  rep(i,0,n-1) rk[i] = i;
  db up = 0. , down = 0.;
  do {

    down += 1.;
  } while(next_permutation(all(rk)));
  printf("%.16f\n",up / down);
  return 0;
}
