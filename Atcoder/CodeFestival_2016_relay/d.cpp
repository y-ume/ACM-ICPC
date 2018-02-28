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

// A B C
// D E F
// G H I

int main(){
  int A , B , C , D , E , F , G , H , I;
  cin >> A >> B >> E;
  G = A + B - E;
  F = A + G - E;
  C = A + E - F;
  H = A + E - G;
  I = B + E - G;
  D = B + H - F;
  printf("%d %d %d\n",A,B,C);
  printf("%d %d %d\n",D,E,F);
  printf("%d %d %d\n",G,H,I);
  return 0;
}
