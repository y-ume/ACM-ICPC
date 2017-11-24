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

const int N = 20;
ll p10[N] = {1} , cof[N];
int D,n;

ll dfs(int c,ll D,ll way) {
    ll Mx=0;
    rep(i,c,n) Mx+=cof[i]*9;
    if(D>Mx||D<-Mx) return 0;
    if(c==n) return way;
    ll res=0;
    for(int x=c==0?0:-9;x<=9;++x)
        res+=dfs(c+1,D-x*cof[c],way*(c==0?9-x:10-abs(x)));
    return res;
}

ll solve(int len){
    rep(i,1,len) p10[i]=p10[i-1]*10;
    n = 0;
    for(int i=len-1,j=0;i>j;--i,++j)
        cof[n++]=p10[i]-p10[j];
    return dfs(0,D,1);
}

int main(){
    cin >> D;
    ll ans = 0;
    rep(len,2,19){
        ll tmp = solve(len);
        if(len & 1) tmp *= 10;
        ans += tmp;
    }
    cout << ans << endl;
    return 0;
}
