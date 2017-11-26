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
vi g[N];
int n,err;

int dfs(int c,int fa){
    int remain = 1;
    for(auto t : g[c]) if(t != fa){
        remain -= dfs(t , c);
    }
    if(remain < 0) err = true;
    return max(0 , remain);
}

int main(){
    scanf("%d",&n);
    rep(i,1,n){
        int a,b;
        scanf("%d%d",&a,&b);
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs(1 , 0);
    puts((n & 1) || err ? "First" : "Second");
    return 0;
}
