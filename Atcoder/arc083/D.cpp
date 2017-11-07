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

const int N = 303;
int dis[N][N] , a[N][N] , n;

int main(){
    scanf("%d",&n);
    rep(i,0,n) rep(j,0,n) scanf("%d",a[i] + j) , dis[i][j] = a[i][j];
    rep(k,0,n) rep(i,0,n) rep(j,0,n) dis[i][j] = min(dis[i][j] , dis[i][k] + dis[k][j]);
    rep(i,0,n) rep(j,0,n) if(a[i][j] != dis[i][j]) return printf("-1\n") , 0;
    ll ans = 0;
    rep(i,0,n) rep(j,i+1,n) {
        bool fd = false;
        rep(k,0,n) if(k!=i&&k!=j) fd |= dis[i][k] + dis[k][j] == dis[i][j];
        if(!fd) ans += dis[i][j];
    }
    printf("%lld\n",ans);
    return 0;
}
