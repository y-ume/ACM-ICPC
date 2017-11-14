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
typedef tuple<int,int,int> tr;
priority_queue<tr> Q;
int n,a[N],b[N],Mn[20][N],lg[N];

int getMin(int l,int r){
    int i=lg[r-l+1];
    return min(Mn[i][l],Mn[i][r+1-(1<<i)]);
}
tr get(int l,int r){
    return tr(-getMin(l,r),l,r);
}

int main(){
    scanf("%d",&n);
    rep(i,2,n+1) lg[i]=lg[i>>1]+1;
    rep(i,0,n) scanf("%d",a+i),Mn[1][i]=a[i],b[a[i]]=i;
    rep(i,2,lg[n]+1) rep(j,0,n-(1<<i)+2) Mn[i][j]=min(Mn[i-1][j],Mn[i-1][j+(1<<i>>1)]);
    Q.push(get(0,n-1));
    vi ans;
    while(sz(Q)) {
        int x,l,r;
        tie(x,l,r)=Q.top();Q.pop();
        x=-x;
        int y=getMin(b[x]+1,r+1);
        ans.pb(x);ans.pb(y);
        if(b[x]!=l) Q.push(get(l,b[x]-1));
        if(b[x]+1!=b[y]) Q.push(get(b[x]+1,b[y]-1));
        if(b[y]!=r) Q.push(get(b[y]+1,r));
    }
    rep(i,0,sz(ans)) printf("%d%c",ans[i]," \n"[i+1==sz(ans)]);
    return 0;
}
