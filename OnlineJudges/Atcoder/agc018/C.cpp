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
struct ele{
    int x,y,z;
    bool operator < (const ele&b) const {
        return x+b.y>y+b.x;
    }
    void read(){
        scanf("%d%d%d",&x,&y,&z);
    }
};
int x,y,z,n;
ele p[N];
ll lft[N];

int main(){
    scanf("%d%d%d",&x,&y,&z);
    n=x+y+z;
    rep(i,0,n) p[i].read();
    ll ans=-1e18,sumc=0;
    rep(i,0,n) sumc+=p[i].z,p[i].x-=p[i].z,p[i].y-=p[i].z;
    sort(p,p+n);
    ll tmp=0;
    priority_queue<int> Q;
    //rep(i,0,n) cout << p[i].x << " " << p[i].y << " " << p[i].z << endl;
    rep(i,0,n) {
        Q.push(-p[i].x);tmp+=p[i].x;
        if(sz(Q)>x) tmp+=Q.top(),Q.pop();
        if(sz(Q)==x) lft[i+1]=tmp;
    }
    while(sz(Q)) Q.pop();
    tmp=0;
    per(i,0,n) {
        Q.push(-p[i].y);tmp+=p[i].y;
        if(sz(Q)>y) tmp+=Q.top(),Q.pop();
        if(sz(Q)==y&&i>=x) ans=max(ans,tmp+lft[i]);
    }
    printf("%lld\n",ans+sumc);
    return 0;
}
