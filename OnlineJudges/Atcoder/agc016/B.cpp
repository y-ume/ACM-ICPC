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

int n;
map<int,int> times;

int main(){
    cin >> n;
    rep(i,0,n){
        int x;
        cin >> x;
        times[x]++;
    }
    if(sz(times) > 2) puts("No");
    else if(sz(times) == 1) {
        int x = times.begin()->fi;
        if(x == n - 1) puts("Yes");
        else if(1 <= x && x <= n / 2) puts("Yes");
        else puts("No");
    } else if(sz(times) == 2) {
        auto it = times.begin();
        int x = it->fi , xcnt = it->se;
        ++it;
        int y = it->fi , ycnt = it->se;
        if(y != x + 1 || ycnt == 1) puts("No");
        else if(xcnt + 1 <= y && y <= xcnt + ycnt / 2) puts("Yes");
        else puts("No");
    }
    return 0;
}
