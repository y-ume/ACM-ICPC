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

const int N = 5e5 + 10;
char s[N];
int n;

int main(){
  scanf("%s",s);
  n=strlen(s);
  reverse(s,s+n);
  for(int i=0,carry=0;i<n;++i) {
    int d=int(s[i]-'0')*9+carry;
    s[i]='0'+(d%10);
    carry=d/10;
    if(carry&&i+1==n) {
      s[n++]='0';
    }
  }
  int sum=0;
  rep(i,0,n) sum+=s[i]-'0';
  for(int i=0;;++i) {
    if(sum<=9*i) return printf("%d\n",i),0;
    int carry=9;
    for(int i=0;i<n&&carry;++i){
      int d=s[i]-'0'+carry;
      if(d>=10) d-=10,carry=1;
      else carry=0;
      sum-=s[i]-'0';
      s[i]=d+'0';
      sum+=s[i]-'0';
      if(carry&&i+1==n) {
        s[n++]='0';
      }
    }
  }
  return 0;
}
