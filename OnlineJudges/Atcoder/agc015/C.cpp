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

const int N = 2020;
int n , m , Q;
char s[N];
int a[N][N] , hori[N][N] , vert[N][N];
void prepare(int a[N][N]){
    rep(i,1,n+1) rep(j,1,m+1) a[i][j]+=a[i-1][j];
    rep(i,1,n+1) rep(j,1,m+1) a[i][j]+=a[i][j-1];
}
int query(int s[N][N],int a,int b,int c,int d){
    if(a>c||b>d) return 0;
    --a;--b;
    return s[c][d]+s[a][b]-s[a][d]-s[c][b];
}

int main(){
    scanf("%d%d%d",&n,&m,&Q);
    rep(i,1,n+1) {
        scanf("%s",s + 1);
        rep(j,1,m+1) a[i][j] = s[j] == '1';
    }
    rep(i,1,n+1) rep(j,1,m) hori[i][j] = a[i][j] == 1 && a[i][j+1] == 1;
    rep(i,1,n) rep(j,1,m+1) vert[i][j] = a[i][j] == 1 && a[i+1][j] == 1;
    prepare(a);
    prepare(hori);
    prepare(vert);
    rep(i,0,Q){
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        int p=query(::a,a,b,c,d);
        int l=query(hori,a,b,c,d-1)+query(vert,a,b,c-1,d);
        printf("%d\n",p-l);
    }
    return 0;
}
