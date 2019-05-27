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

const int N = 400;
using B = bitset<N>;
int n,m;
B b[N];
bool err[N];

int main(){
    scanf("%d%d",&n,&m);
    rep(i,0,m) {
        int x,y;
        scanf("%d%d",&x,&y);
        --x;--y;
        err[y] |= err[x];
        err[x] |= err[y];
        if(b[x].test(y) || (b[x] & b[y]).count()) err[x] = 1;
        if(b[y].test(x) || (b[x] & b[y]).count()) err[y] = 1;
        b[x] |= b[y];
        b[y] |= b[x];
        b[x][y] = b[y][x] = 1;
    }
    int ans=0;
    rep(i,0,n) rep(j,i+1,n) if(!err[i]&&!err[j]&&!b[i][j]&&!b[j][i])
        ans+=(b[i]&b[j]).count()==0;
    printf("%d\n",ans);
    return 0;
}
