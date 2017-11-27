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

const int N = 5e5 + 10;
int n , L;
int x[N];
db k[N];

int main(){
    scanf("%d%d",&n,&L);
    int l = 0 , r = 0 , v;
    db ysum = 0 , t;
    rep(i,0,n) {
        scanf("%lf%d",&t,&v);
        int vremain = v;
        while(l < r && vremain >= x[l])
            ysum -= x[l] * k[l] , vremain -= x[l++];
        if(vremain && l < r)
            ysum -= vremain * k[l] , x[l] -= vremain;
        while(l < r && t < k[r-1]) {
            --r;
            ysum -= x[r] * k[r];
            t = (t * v + x[r] * k[r]) / (v + x[r]);
            v += x[r];
        }
        x[r] = v , k[r] = t;
        r++;
        ysum += v * t;
        printf("%.8f\n",ysum / L);
    }
    return 0;
}
