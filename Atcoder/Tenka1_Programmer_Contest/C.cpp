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

int main(){
    int n;
    cin >> n;
    rep(i,1,3501) rep(j,1,3501){
        ll down = ll(n) * i * j;
        ll up = 4ll * i * j - 1ll * n * j - 1ll * n * i;
        if(up < 0) continue;
        if(up && down % up == 0) {
            ll k = down / up;
            cout << i << " " << j << " " << k << endl;
            return 0;
        }
    }
    return 0;
}
