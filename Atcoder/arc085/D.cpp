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

const int N = 2020 , inf = 2e9;
int a[N],n,f[N][N][2],Mx[N],Mn[N];

int main(){
    scanf("%d%d%d",&n,a,a+1);
    rep(i,0,n) scanf("%d",a+2+i);
    n+=2;
    rep(i,0,n) Mx[i]=-inf,Mn[i]=inf;
    per(i,0,n) per(j,i+1,n) rep(k,0,2) {
        int&x=f[i][j][k];
        if(j==n-1) x=abs(a[i]-a[j]);
        else if(k==0) x=Mx[j];
        else x=Mn[j];
        if(k==0) Mn[i]=min(Mn[i],x);
        else Mx[i]=max(Mx[i],x);
    }
    printf("%d\n",f[0][1][0]);
    return 0;
}
