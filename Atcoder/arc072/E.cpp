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
int n , Q , D , d[N] , dis[N];
ll ban[N];

int main(){
    scanf("%d%d",&n,&D);
    rep(i,1,n+1) scanf("%d",d + i);
    dis[0] = D;
    rep(i,1,n+1) dis[i] = min(abs(dis[i-1]-d[i]),dis[i-1]);
    ban[n+1]=1;
    per(i,1,n+1) ban[i] = ban[i+1]<=d[i]/2?ban[i+1]:ban[i+1]+d[i];
    scanf("%d",&Q);
    rep(i,0,Q) {
        int q;scanf("%d",&q);
        puts(ban[q+1]<=dis[q-1]?"YES":"NO");
    }
    return 0;
}
