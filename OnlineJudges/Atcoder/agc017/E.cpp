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

const int H = 202 << 1;
int fa[H] , out[H] , in[H] , n , h;
vi g[H];
int F(int x){return fa[x]==x?x:fa[x]=F(fa[x]);}
int id(int x){
    return x>0?x-1:h+(-x-1);
}

int main(){
    scanf("%d%d",&n,&h);
    rep(i,0,h+h) fa[i]=i;
    rep(i,0,n) {
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        int l=c?-c:a,r=d?d:-b;
        l=id(l),r=id(r);
        fa[F(r)]=F(l);
        out[l]++;
        in[r]++;
    }
    rep(i,0,h+h) g[F(i)].pb(i);
    rep(i,0,h) if(out[i]<in[i]) return puts("NO") , 0;
    rep(i,h,h+h) if(out[i]>in[i]) return puts("NO") , 0;
    rep(i,0,h+h) if(sz(g[i])) {
        bool end = false , has = false;
        for(auto e : g[i]) {
            has |= in[e] | out[e];
            if(e < h && out[e] > in[e]) end = true;
            if(e >= h && out[e] < in[e]) end = true;
        }
        if(has && !end) return puts("NO") , 0;
    }
    puts("YES");
    return 0;
}
