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

ll a , b;

int main(){
    cin >> a >> b;
    if(a == b) {
        cout << 1 << endl;
    } else {
        per(i,0,60) if((a >> i & 1) != (b >> i & 1)){
            ll l = (a & ((1ll << i) - 1));
            ll r = (b & ((1ll << i) - 1));
            ll ans = (1ll << i) - l;
            int top=-1;
            rep(j,0,i) if(r >> j & 1) top = j;
            ll R = (1ll << (top + 1)) - 1;
            ll L = l;
            ans += (1ll << i) - max(0ll , L - R - 1);
            cout << ans << endl;
            break;
        }
    }
    return 0;
}
