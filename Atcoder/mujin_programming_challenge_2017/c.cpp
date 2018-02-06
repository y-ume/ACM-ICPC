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

const int N = 5e5 + 10 , C = 26;
char s[N];
int Q , l , r , n , nxt[N][C+1] , jump[N][20];

int main(){
  scanf("%s",s);
  n = strlen(s);
  rep(i,0,C+1) nxt[n+1][i]=n+1;
  nxt[n][C]=n;
  rep(i,0,C) nxt[n][i]=n+1;
  per(i,0,n) {
    int ch=s[i]-'a';
    nxt[i][ch]=i+1;
    rep(j,ch+1,C+1) nxt[i][j]=nxt[nxt[i][j-1]][j-1];
    rep(j,0,ch) nxt[i][j]=nxt[nxt[i][C]][j];
    //rep(j,0,C+1) printf("%d%c",nxt[i][j]," \n"[j==C]);
  }
  rep(i,0,20) jump[n][i]=n,jump[n+1][i]=n+1;
  per(i,0,n) {
    jump[i][0]=nxt[i][C];
    rep(j,1,20) jump[i][j]=jump[jump[i][j-1]][j-1];
  }
  scanf("%d",&Q);
  rep(i,0,Q) {
    scanf("%d%d",&l,&r);
    --l;
    per(i,0,20) if(jump[l][i]<r)
      l=jump[l][i];
    l=jump[l][0];
    puts(l == r ? "Yes" : "No");
  }
  return 0;
}
