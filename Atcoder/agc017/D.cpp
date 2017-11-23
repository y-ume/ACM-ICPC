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
int sg[N],n;
vi g[N];

void dfs(int c,int fa=0){
    for(auto t : g[c]) {
        if(t == fa) continue;
        dfs(t , c);
        sg[c] ^= sg[t] + 1;
    }
}

int main(){
    scanf("%d",&n);
    rep(i,1,n) {
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1);
    puts(sg[1] ? "Alice" : "Bob");
    return 0;
}
