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
int n , m , col[N] , cnt[2];
vi g[N];

int main(){
    scanf("%d%d",&n,&m);
    rep(i,0,m){
        int u,v;
        scanf("%d%d",&u,&v);
        --u;--v;
        g[u].pb(v);
        g[v].pb(u);
    }
    rep(i,0,n) col[i]=-1;
    vi q;q.pb(0);col[0]=0;
    bool oddcir = false;
    rep(i,0,sz(q)){
        int c=q[i];
        cnt[col[c]]++;
        for(auto t:g[c]) {
            if(col[t]==-1) col[t]=col[c]^1,q.pb(t);
            else if(col[c]==col[t]) {
                oddcir = true;
            }
        }
    }
    if(oddcir) cout << 1ll * n * (n - 1) / 2 - m << endl;
    else cout << 1ll * cnt[0] * cnt[1] - m << endl;
    return 0;
}
