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

ll H , W;

int main(){
    cin >> H >> W;
    ll ans = min(W % 3 == 0 ? 0 : H , H % 3 == 0 ? 0 : W);
    rep(i,1,H) {
        ll Mn = i * W , Mx = i * W;
        Mn = min(Mn , (W >> 1) * (H - i));
        Mx = max(Mx , ((W + 1) >> 1) * (H - i));
        ans = min(Mx - Mn , ans);
    }
    rep(i,1,W) {
        ll Mn = i * H , Mx = i * H;
        Mn = min(Mn , (H >> 1) * (W - i));
        Mx = max(Mx , ((H + 1) >> 1) * (W - i));
        ans = min(Mx - Mn , ans);
    }
    cout << ans << endl;
    return 0;
}
