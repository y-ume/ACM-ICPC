#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <string>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <complex>
#include <bitset>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vi;
#define de(x) cout << #x << "=" << x << endl
#define rep(i,a,b) for(int i=a;i<(b);++i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
const int N = 101010 , M = N<<2 , E = N*20 , P=1e9+7;
int A,B,sum,ans;
int rnd() {
    A = (36969 + (sum >> 3)) * (A & ((1<<16)-1)) + (A >> 16);
    B = (18000 + (sum >> 3)) * (B & ((1<<16)-1)) + (B >> 16);
    return ((~(1<<31)) & ((A << 16) + B)) % 1000000000;
}
int T,n,m,a[N],b[N],v[M],lft[M],rgt[M],tag[M],s[E],pl[E],pr[E],_;
#define ls c<<1
#define rs c<<1|1
void Build(int c,int l,int r){
    tag[c] = -1;
    if(l == r){
        lft[c] = _;
        s[_++] = b[l];
        rgt[c] = _;
        v[c] = a[l] >= b[l];
    } else {
        int m=(l+r)>>1;
        Build(ls,l,m);Build(rs,m+1,r);
        v[c] = v[ls] + v[rs];
        int al=lft[ls],ar=rgt[ls],bl=lft[rs],br=rgt[rs];
        merge(s+al,s+ar,s+bl,s+br,s+_);
        lft[c] = _;rgt[c] = _ += r-l+1;
        rep(i,lft[c],rgt[c]){
            while(al<ar&&s[al]<=s[i]) ++al;
            while(bl<br&&s[bl]<=s[i]) ++bl;
            pl[i]=al-1,pr[i]=bl-1;
            if(pl[i]<lft[ls]) pl[i]=0;
            if(pr[i]<lft[rs]) pr[i]=0;
        }
    }
}
void Modify(int c,int x){
    v[c] = max(0,x-lft[c]+1);
    tag[c] = x;
}
void Down(int c){
    if(~tag[c]) Modify(ls,pl[tag[c]]) , Modify(rs,pr[tag[c]]) , tag[c] = -1;
}
void Change(int c,int l,int r,int L,int R,int x){
    if(L<=l&&r<=R){
        Modify(c,x);
    } else {
        int m=(l+r)>>1;
        Down(c);
        if(L<=m) Change(ls,l,m,L,R,pl[x]);
        if(R>m) Change(rs,m+1,r,L,R,pr[x]);
        v[c]=v[ls]+v[rs];
    }
}
void Ask(int c,int l,int r,int L,int R){
    if(L<=l&&r<=R){
        sum += v[c];
    } else {
        int m=(l+r)>>1;
        Down(c);
        if(L<=m) Ask(ls,l,m,L,R);
        if(R>m) Ask(rs,m+1,r,L,R);
    }
}

void main2(){
    scanf("%d%d%d%d",&n,&m,&A,&B);
    rep(i,1,n+1) scanf("%d",a + i);
    rep(i,1,n+1) scanf("%d",b + i);
    ans = sum = 0;
    _=1;
    Build(1,1,n);
    rep(i,0,m){
        int l = rnd()%n+1 , r = rnd()%n+1 , x = rnd()+1;
        if(l > r) swap(l,r);
        if((l+r+x)&1){
            int id=upper_bound(s+lft[1],s+rgt[1],x)-s-1;
            if(id<lft[1]) id=0;
            Change(1,1,n,l,r,id);
        }
        else{
            sum = 0;Ask(1,1,n,l,r);
            ans += ((ll)sum*(i+1)%P);
            if(ans >= P) ans -= P;
        }
    }
    printf("%d\n",ans);
}
int main(){
    scanf("%d",&T);
    rep(i,0,T) main2();
    return 0;
}
