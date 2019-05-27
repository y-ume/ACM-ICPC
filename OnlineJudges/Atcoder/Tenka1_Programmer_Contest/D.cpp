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

const int N = 1e5 + 10;
int n , K , a[N] , b[N];

int main(){
    cin >> n >> K;
    rep(i,0,n) cin >> a[i] >> b[i];
    ll ans = 0;
    rep(i,0,31) {
        ll tmp = 0;
        rep(j,0,n) {
            int Kl = K >> i;
            int al = a[j] >> i;
            if((al & Kl) == al) {
                if(i == 0 || (K >> (i - 1) & 1) > (a[j] >> (i - 1) & 1))
                    tmp += b[j];
            }
        }
        ans = max(ans , tmp);
    }
    cout << ans << endl;
    return 0;
}
