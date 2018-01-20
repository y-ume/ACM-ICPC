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

int A , B;

int ask(int a,int b){
  printf("? %d %d\n",a,b);
  fflush(stdout);
  static char ch[3];
  scanf("%s",ch);
  return ch[0] == 'Y';
}

int main(){
  scanf("%d%d",&A,&B);
  if(A <= B) {
    puts("Impossible");
    fflush(stdout);
    return 0;
  }
  int n = A + B;
  vi v;
  rep(i,0,n) {
    if(!sz(v)) v.pb(i);
    else {
      if(ask(v.back(),i))
        v.pb(i);
      else
        v.pop_back();
    }
  }
  static char ans[4040];
  int honest = v.back();
  rep(i,0,n) ans[i]='0'+ask(honest,i);
  printf("! ");
  rep(i,0,n) putchar(ans[i]);
  puts("");
  fflush(stdout);
  return 0;
}
