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

const int N = 202020 , inf = 1<<26;
int n , b[N] , Q;
pii seg[N];
int add[N << 2] , Mn[N << 2];
inline void Down(int c){
    if(add[c]) {
        add[c << 1] += add[c];
        Mn[c << 1] += add[c];
        add[c << 1 | 1] += add[c];
        Mn[c << 1 | 1] += add[c];
        add[c] = 0;
    }
}
inline void Up(int c){
    Mn[c] = min(Mn[c << 1] , Mn[c << 1 | 1]);
}
void Update(int c,int l,int r,int p,int x){
    if(l == r) Mn[c] = min(Mn[c] , x);
    else {
        int m = (l + r) >> 1;
        Down(c);
        if(p <= m) Update(c << 1 , l , m , p , x);
        else Update(c << 1 | 1 , m + 1 , r , p , x);
        Up(c);
    }
}
void Add(int c,int l,int r,int L,int R,int x){
    if(L <= l && r <= R) {
        add[c] += x;
        Mn[c] += x;
    } else {
        Down(c);
        int m = (l + r) >> 1;
        if(L <= m) Add(c << 1 , l , m , L , R , x);
        if(R > m) Add(c << 1 | 1 , m + 1 , r , L , R , x);
        Up(c);
    }
}
int query(int c,int l,int r,int L,int R){
    if(L <= l && r <= R) return Mn[c];
    else {
        int m = (l + r) >> 1;
        int res = inf;
        Down(c);
        if(L <= m) res = min(res , query(c << 1 , l , m , L , R));
        if(R > m) res = min(res , query(c << 1 | 1 , m + 1 , r , L , R));
        return res;
    }
}

int main(){
    scanf("%d",&n);
    rep(i,1,n+1) scanf("%d",b+i);
    scanf("%d",&Q);
    rep(i,0,Q) scanf("%d%d",&seg[i].fi,&seg[i].se);
    sort(seg,seg+Q);
    int c=0;
    rep(i,1,n+1) Add(1 , 0 , n , i , i , inf);
    rep(i,1,n+1) {
        while(c < Q && seg[c].fi == i) {
            int t = query(1 , 0 , n , 0 , seg[c].se);
            Update(1 , 0 , n , seg[c].se , t);
            ++c;
        }
        if(b[i] == 0) Add(1 , 0 , n , i , n , 1);
        else Add(1 , 0 , n , 0 , i - 1 , 1);
    }
    printf("%d\n",query(1 , 0 , n , 0 , n));
    return 0;
}
