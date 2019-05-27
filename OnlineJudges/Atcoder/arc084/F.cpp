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

const int P = 998244353;
const int L = 4001;
int n;
using Bit = bitset<L>;
typedef pair<Bit,int> num;
num X , A[6];
char s[10000];
void output(num x){
    per(i,0,10) putchar(x.fi[i]+'0');puts("");
}
void read(num&b){
    scanf("%s",s);
    b.fi.reset();
    int len = strlen(s);
    rep(i,0,len) b.fi[i]=s[len-1-i]-'0';
    b.se=len-1;
}
num gcd(num x,num y){
    if(x.se<y.se) swap(x,y);
    if(y.se==-1) return x;
    num z(x.fi^(y.fi<<(x.se-y.se)),x.se);
    while(z.se>=0&&z.fi[z.se]==0) z.se--;
    return gcd(z,y);
}

int main(){
    scanf("%d",&n);
    read(X);
    rep(i,0,n) read(A[i]);
    rep(i,1,n) A[0]=gcd(A[0],A[i]);
    int ans = 0;
    for(int i=X.se;i>=A[0].se;--i){
        ans = (ans + ans) % P;
        if(X.fi[i] == 1) ans = (ans + 1) % P;
    }
    num Y = X;
    rep(i,0,A[0].se) Y.fi[i]=0;
    for(int i=Y.se;i>=A[0].se;--i)if(Y.fi[i]){
        Y.fi ^= A[0].fi << (i - A[0].se);
    }
    bool ok = true;
    for(int i=A[0].se-1;i>=0;--i) if(X.fi[i]!=Y.fi[i]){
        if(X.fi[i]<Y.fi[i]) ok=false;
        break;
    }
    ans = (ans + ok) % P;
    printf("%d\n",ans);
    return 0;
}
