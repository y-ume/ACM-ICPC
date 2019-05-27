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

const int N = 50;
ll n , a[N] , s;

int main(){
    cin >> n;
    rep(i,0,n) cin >> a[i] , s += a[i];
    ll step = max(0ll , s - n * (n - 1));
    rep(i,0,n) a[i] += step;
    ll l = -1 , r = *max_element(a,a+n);
    while(l + 1 < r){
        ll m = (l + r) >> 1;
        ll round = 0;
        rep(i,0,n) round += max(0ll , (a[i] - m) / (n + 1));
        if(round <= step) r = m;
        else l = m;
    }
    ll round = 0;
    rep(i,0,n) {
        ll t = max(0ll , (a[i] - r) / (n + 1));
        round += t;
        a[i] -= t * (n + 1);
    }
    rep(i,0,n) a[i] -= step - round;
    step = round;
    while(*max_element(a , a + n) >= n) {
        int p=max_element(a , a + n) - a;
        a[p] -= n;
        rep(i,0,n) if(i != p) a[i]++;
        step ++;
    }
    cout << step << endl;
    return 0;
}
