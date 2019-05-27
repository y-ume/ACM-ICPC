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

const int N = 2e5 + 10;
char s[N];
int nxt[N],n;
ll l,r,cnt[26],sum[N][26];
vector<ll> len;
vector<vector<ll> > S;

vector<ll> solve(ll x){
    if(x <= n) return vector<ll>(sum[x],sum[x]+26);
    int p = upper_bound(all(len) , x) - len.begin() - 1;
    vector<ll> res = S[p] , gt = solve(x - len[p]);
    rep(i,0,26) res[i] += gt[i];
    return res;
}

int main(){
    scanf("%s%lld%lld",s+1,&l,&r);
    n=strlen(s+1) / 2;
    nxt[1]=0;
    for(int i=2,j=0;i<=n;++i){
        while(j&&s[j+1]!=s[i]) j=nxt[j];
        nxt[i]=s[j+1]==s[i]?++j:j;
    }
    rep(i,1,n+1) rep(j,0,26) sum[i][j]=sum[i-1][j]+(s[i]-'a'==j);
    int period = n - nxt[n];
    if(n % period == 0) {
        rep(i,1,period+1) {
            cnt[s[i] - 'a'] += (r + period - i) / period - (l - 1 + period - i) / period;
        }
    } else {
        vector<ll> A(sum[n],sum[n]+26);
        len.pb(n);S.pb(A);
        rep(i,0,26) A[i]+=sum[period][i];
        len.pb(n+period);S.pb(A);
        while(len[sz(len)-1]<r) {
            len.pb(len[sz(len)-1]+len[sz(len)-2]);
            A=*S.rbegin();
            rep(i,0,26) A[i]+=S[sz(S)-2][i];
            S.pb(A);
        }
        vector<ll> L = solve(l - 1) , R = solve(r);
        rep(i,0,26) cnt[i] = R[i] - L[i];
    }
    rep(i,0,26) printf("%lld%c",cnt[i]," \n"[i==25]);
    return 0;
}
