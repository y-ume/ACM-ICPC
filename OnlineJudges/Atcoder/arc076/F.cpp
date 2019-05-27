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

const int N = 2e5 + 10 , inf = 1<<30;
int n , m;
pii seg[N];

int add[N << 2] , mx[N << 2];
void Add(int c,int l,int r,int L,int R,int x){
    if(L<=l&&r<=R) add[c]+=x,mx[c]+=x;
    else {
        int m=(l+r)>>1;
        if(L<=m) Add(c<<1,l,m,L,R,x);
        if(R>m) Add(c<<1|1,m+1,r,L,R,x);
        mx[c]=max(mx[c<<1],mx[c<<1|1])+add[c];
    }
}
int query(int c,int l,int r,int L,int R){
    if(L<=l&&r<=R) return mx[c];
    else {
        int m=(l+r)>>1;
        int res=-inf;
        if(L<=m) res=max(res,query(c<<1,l,m,L,R));
        if(R>m) res=max(res,query(c<<1|1,m+1,r,L,R));
        return res+add[c];
    }
}


int main(){
    scanf("%d%d",&n,&m);
    rep(i,0,n) scanf("%d%d",&seg[i].fi,&seg[i].se);
    sort(seg,seg+n);
    int ans=max(0,n-m);
    int c=0;
    rep(i,0,m+1) Add(1,0,m+1,i,i,-(m+1-i));
    rep(s,0,m+1) {
        while(c<n&&seg[c].fi<=s){
            Add(1,0,m+1,seg[c].fi+1,seg[c].se,1);
            ++c;
        }
        ans=max(ans,query(1,0,m+1,s+1,m+1)-s);
    }
    printf("%d\n",ans);
    return 0;
}
