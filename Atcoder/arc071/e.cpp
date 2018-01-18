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
char s[N] , t[N];
int sums[N] , sumt[N] , lens , lent;
int q,a,b,c,d;
void prepare(char*s,int*sum,int len){
  len=strlen(s+1);
  rep(i,1,len+1) sum[i]=sum[i-1]+(s[i]=='A'?1:2);
}
int get(int*sum,int l,int r){
  return sum[r]-sum[l-1];
}

int main(){
  scanf("%s%s",s+1,t+1);
  prepare(s,sums,lens);prepare(t,sumt,lent);
  scanf("%d",&q);
  rep(i,0,q) {
    scanf("%d%d%d%d",&a,&b,&c,&d);
    puts((get(sums,a,b)-get(sumt,c,d))%3?"NO":"YES");
  }
  return 0;
}
