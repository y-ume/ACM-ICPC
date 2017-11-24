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
int n , B , A , a[N];

int main(){
    scanf("%d%d%d",&n,&A,&B);
    rep(i,0,n) scanf("%d",a + i);
    int l = 0 , r = *max_element(a , a + n);
    while(l + 1 < r){
        int m = (l + r) >> 1;
        ll ex = 0;
        rep(i,0,n) ex += max(0ll , ((a[i] - ll(B) * m) + A - B - 1) / (A - B));
        if(ex <= m) r = m;
        else l = m;
    }
    cout << r << endl;
    return 0;
}
