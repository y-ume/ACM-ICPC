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

const int N = 101;
int g[N][N] , a[N * N] , n , H , W;

int main(){
    scanf("%d%d",&H,&W);
    scanf("%d",&n);
    rep(i,0,n) scanf("%d",a + i);
    int x=0,y=0;
    rep(i,0,n) {
        rep(j,0,a[i]) {
            g[x][y]=i+1;
            if(~x&1){
                if(y==W-1) x++;
                else y++;
            } else {
                if(y==0) x++;
                else y--;
            }
        }
    }
    rep(i,0,H) rep(j,0,W) printf("%d%c",g[i][j]," \n"[j+1==W]);
    return 0;
}
