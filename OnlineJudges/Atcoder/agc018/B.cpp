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
int a[N][N],n,m;
int c[N],cnt[N],vis[N];

int main(){
    scanf("%d%d",&n,&m);
    rep(i,0,n) rep(j,0,m) scanf("%d",a[i] + j) , --a[i][j];
    int ans=n+1;
    rep(i,0,m) {
        rep(i,0,n) while(vis[a[i][c[i]]]) ++c[i];
        rep(i,0,m) cnt[i]=0;
        rep(i,0,n) cnt[a[i][c[i]]]++;
        int Mx=0,id=0;
        rep(i,0,m) if(cnt[i]>Mx) Mx=cnt[i],id=i;
        ans=min(ans,Mx);
        vis[id]=true;
    }
    printf("%d\n",ans);
    return 0;
}
