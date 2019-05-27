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

int n , a , b;
string s;

int main(){
  cin >> n >> a >> b >> s;
  int A = 0 , B = 0;
  for(auto ch : s) {
    if(ch == 'c') {
      puts("No");
    } else if(ch == 'a') {
      if(A + B < a + b) {
        puts("Yes");
        A++;
      } else {
        puts("No");
      }
    } else {
      if(A + B < a + b && B < b) {
        puts("Yes");
        B++;
      } else {
        puts("No");
      }
    }
  }
  return 0;
}
