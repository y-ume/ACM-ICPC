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

const int N = 505;
int H , W , h , w;
int a[N][N];

int main(){
    scanf("%d%d%d%d",&H,&W,&h,&w);
    if(H % h == 0 && W % w == 0) puts("No");
    else {
        puts("Yes");
        int remain = H * W - (H / h) * h * (W / w) * w;
        int pos = (H / h) * (W / w) / remain + 1;
        int neg = -(h * w - 1) * pos - 1;
        rep(i,0,H) rep(j,0,W) printf("%d%c",i%h==h-1&&j%w==w-1?neg:pos," \n"[j+1==W]);
    }
    return 0;
}
