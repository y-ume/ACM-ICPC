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

const int P = 1e9 + 7;
int a , b , c , d;
inline void pp(int &a,int b){if((a+=b)>=P)a-=P;}
inline int mul(int a,int b){return ll(a)*b%P;}
inline int ceil(ll a,ll b){return (a+b-1)/b;}

int main(){
    cin >> a >> b >> c >> d;
    int ans=mul(min(a,d+1),mul(min(b,d+1),min(c,d+1)));
    rep(times,0,3){
        int x=1,limx=a-d-1;
        while(x<=limx) {
            int y=ll(x)*b/a;
            int z=ll(x)*c/a;
            int nx=limx+1;
            if(0<=y-d&&y+d<b) nx=min(nx,ceil(ll(b-d)*a,b));
            else nx=min(nx,ceil(ll(y+1)*a,b));
            if(0<=z-d&&z+d<c) nx=min(nx,ceil(ll(c-d)*a,c));
            else nx=min(nx,ceil(ll(z+1)*a,c));
            int ly=min(b-1,y+d)-max(0,y-d)+1;
            int lz=min(c-1,z+d)-max(0,z-d)+1;
            pp(ans,mul(nx-x,mul(ly,lz)));
            x=nx;
        }
        swap(a,b);swap(b,c);
    }
    cout << ans << endl;
    return 0;
}
