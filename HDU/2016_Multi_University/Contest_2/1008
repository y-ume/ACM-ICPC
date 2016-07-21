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
const int N = 1010;
int n , m , T , a[N] , sum[2][N];

inline void in(int &x){
    x = 0;char ch;
    do ch = getchar();while(ch < '0' || ch > '9');
    do x = x * 10 + ch - '0' , ch = getchar();while(ch >= '0' && ch <= '9');
}
template<class T>
struct Fenwick{ // [1,n] , init!!
#define lb(x) ((x)&-(x))
    static const int N = 1010101;
    int n;T a[N];
    void ini(int _n){ n=_n;fill(a+1,a+1+n,0);}
    void add(int x,T d){ for(;x<=n;x+=lb(x)) a[x]+=d;}
    T sum(int x){ T r=0;for(;x>=1;x^=lb(x)) r+=a[x];return r;}
};
Fenwick<int> f;
struct ele{
    int a , b , c , d;
}e[N*N];int _;
struct event{
    int x , y , op;
    event(int _x=0,int _y=0,int _op=0){
        x = _x , y = _y , op = _op;
    }
}eve[N*N*2 + 505050];
int id[N*N*2 + 505050];
int __;
int X[N*N],_x;
#define rk(x) upper_bound(X,X+_x,x) - X

void ins(int a,int b,int c,int d){
    //cout << a << " " << b << " " << c << " " << d << endl;
    eve[__++] = event(a,c,1);
    eve[__++] = event(b,c,2);
    eve[__++] = event(a,d,2);
    eve[__++] = event(b,d,1);
}
char ans[505050];
void Solve(){
    rep(i,0,__) id[i] = i;
    sort(id , id + __ ,[&](const int&a,const int&b){if(eve[a].y==eve[b].y)return eve[a].op>eve[b].op;return eve[a].y<eve[b].y;});
    f.ini(_x);
    for(int i=0;i<__;++i){
        int j = id[i];
        if(eve[j].op > 0)
            f.add(eve[j].x , eve[j].op == 1 ? 1 : -1);
        else
            ans[-eve[j].op] = f.sum(eve[j].x) > 0 ? '1' : '0';
    }
    ans[m] = 0;
    puts(ans);
}

void wk(){
    in(n);in(m);
    rep(i,1,n+1) in(a[i]);
    rep(i,1,n+1){
        rep(j,0,2) sum[j][i] = sum[j][i-1];
        sum[i&1][i] += a[i];
    }
    _x = 0;
    _ = 0;
    rep(i,1,n+1){
        int u = 0 , v = 0;
        int x = 0 , y = 0;
        if(i&1) x += a[i];
        else y += a[i];
        e[_].a = u , e[_].b = u+x+1;
        e[_].c = v , e[_].d = v+y+1;
        X[_x++] = u;
        X[_x++] = u+x+1;
        //cout << u << " " << v << " " << x+1 << " " << y << endl;
        _++;
    }
    rep(i,1,n+1) rep(j,i+1,n+1){
        if((i&1) == (j&1) && i != 1 && j != n) continue;
        int u = sum[1][j-1] - sum[1][i];
        int v = sum[0][j-1] - sum[0][i];
        int x = 0 , y = 0;
        if(i&1) x += a[i];else y += a[i];
        if(j&1) x += a[j];else y += a[j];
        e[_].a = u , e[_].b = u+x+1;
        e[_].c = v , e[_].d = v+y+1;
        X[_x++] = u;
        X[_x++] = u+x+1;
        //cout << u << " " << v << " " << x+1 << " " << y << endl;
        _++;
    }
    //rep(i,0,sz(X)) cout << X[i] << endl;
    __ = 0;
    sort(X,X+_x);_x=unique(X,X+_x)-X;
    rep(i,0,_) ins(rk(e[i].a) , rk(e[i].b) , e[i].c , e[i].d);
    rep(i,0,m){
        int x , y;
        in(x);in(y);
        x = rk(x);
        //cout << x << " " << y << endl;
        eve[__++] = event(x,y,-i);
    }
    Solve();
}

int main(){
    in(T);
    rep(i,0,T) wk();
    return 0;
}
