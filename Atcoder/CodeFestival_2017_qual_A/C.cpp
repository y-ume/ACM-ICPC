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

int H , W , need[3];
string s[110];

int main(){
    cin >> H >> W;
    rep(i,0,H) cin >> s[i];
    map<char,int> cnt;
    rep(i,0,H) rep(j,0,W) cnt[s[i][j]]++;
    need[2] = (H / 2) * (W / 2);
    need[1] = (H % 2) * (W / 2) + (H / 2) * (W % 2);
    need[0] = (H % 2) * (W % 2);
    for(auto e : cnt) {
        int x = e.se;
        need[0] -= x & 1;
        need[1] -= x >> 1 & 1;
        need[2] -= x >> 2;
    }
    bool ok = true;
    per(i,0,3) {
        if(need[i] < 0 && i) need[i - 1] += need[i] * 2 , need[i] = 0;
        ok &= need[i] <= 0;
    }
    puts(ok ? "Yes" : "No");
    return 0;
}
