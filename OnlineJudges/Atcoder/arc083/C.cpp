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

const int N = 3001;
int A , B , C , D , E , F;
int f[N] , g[N];

void solve(int *a,int x,int y,int n){
    a[0] = 1;
    rep(i,0,n+1) if(a[i]){
        if(i+x<=n) a[i+x]=1;
        if(i+y<=n) a[i+y]=1;
    }
}

int main(){
    cin >> A >> B >> C >> D >> E >> F;
    solve(f , A * 100 , B * 100 , F);
    solve(g , C , D , F);
    pii best(-1,-1);
    g[0] = 0;
    rep(i,1,F+1) g[i] = max(g[i] ? i : 0 , g[i-1]);
    rep(i,1,F+1) if(f[i]){
        int j = min(F - i , i / 100 * E);
        j = g[j];
        if(best.fi == -1 || j * best.fi > (i + j) * best.se)
            best = mp((i + j) , j);
    }
    printf("%d %d\n",best.fi,best.se);
    return 0;
}
