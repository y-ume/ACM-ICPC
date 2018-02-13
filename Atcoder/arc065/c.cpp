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
int n , ok[N];
char s[N];
string pat[4] = {"dream" , "dreamer" , "erase" , "eraser"};

int main(){
  scanf("%s",s+1);
  n = strlen(s+1);
  ok[0] = 1;
  rep(i,1,n+1) {
    rep(j,0,4) if(i>=sz(pat[j])&&ok[i-sz(pat[j])]&&string(s+i-sz(pat[j])+1,sz(pat[j]))==pat[j]) {
      ok[i] = 1;break;
    }
  }
  printf(ok[n] ? "YES" : "NO");
  return 0;
}
