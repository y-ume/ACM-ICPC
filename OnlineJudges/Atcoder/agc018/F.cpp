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

const int N = 2e5 + 10 , M = N * 4;
int n , du[N] , col[N] , odd[N] , h[N] , cur[N];
int ne[M] , to[M] , vis[M] , e;
inline void add(int u,int v){
    to[e] = v;ne[e] = h[u];
    h[u] = e++;
}
inline void link(int u,int v){
    du[u]++;
    du[v]++;
    add(u , v);
    add(v , u);
}

int top;
void dfs(int c){
    for(int &k=cur[c];~k;k=ne[k]){
        if(vis[k >> 1]) continue;
        vis[k >> 1] = true;
        dfs(to[k]);
    }
    if(top != -1) {
        int a = top , b = c , f = 1;
        if(a > b) swap(a , b) , f = -1;
        if(a < n && a + n == b && odd[a]) {
            col[a] = f;
        }
    }
    top = c;
}

int main(){
    scanf("%d",&n);
    int rt = n + n;
    rep(i,0,rt+1) h[i] = -1;
    rep(t,0,2) {
        rep(i,0,n) {
            int a;
            scanf("%d",&a);
            if(a == -1) link(rt , i + t * n);
            else {
                a = a - 1 + t * n;
                link(a , i + t * n);
            }
        }
    }
    rep(i,0,n) {
        if((du[i] + du[i + n]) & 1){
            return puts("IMPOSSIBLE") , 0;
        }
        if(du[i] & 1) {
            link(i , i + n);
            odd[i] = true;
        }
    }
    rep(i,0,rt+1) cur[i]=h[i];
    top = -1;
    dfs(rt);
    puts("POSSIBLE");
    rep(i,0,n) printf("%d%c",col[i]," \n"[i+1==n]);
    return 0;
}
