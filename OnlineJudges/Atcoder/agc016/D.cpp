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
int n , a[N] , b[N] , sz[N] , fa[N];
int F(int x){return fa[x]==x?x:fa[x]=F(fa[x]);}

int main(){
    scanf("%d",&n);
    rep(i,0,n) scanf("%d",a + i) , a[n] ^= a[i];
    rep(i,0,n) scanf("%d",b + i) , b[n] ^= b[i];
    vi A(a , a + n + 1) , B(b , b + n + 1);
    sort(all(A));
    sort(all(B));
    if(A != B) puts("-1");
    else {
        A.erase(unique(all(A)),A.end());
        rep(i,0,n+1) a[i]=lower_bound(all(A),a[i])-A.begin();
        rep(i,0,n+1) b[i]=lower_bound(all(A),b[i])-A.begin();
        int m = sz(A);
        rep(i,0,m) sz[i]=0,fa[i]=i;
        rep(i,0,n+1) if(a[i]!=b[i]){
            int u=F(a[i]),v=F(b[i]);
            if(u==v) sz[u]++;
            else fa[v]=u,sz[u]+=sz[v]+1;
        }
        int special = F(a[n]) , incircle = a[n] != b[n];
        int ans=0;
        rep(i,0,m) if(F(i)==i){
            if(sz[i]) ans+=sz[i]+(i==special?(incircle?-1:0):1);
        }
        printf("%d\n",ans);
    }
    return 0;
}
