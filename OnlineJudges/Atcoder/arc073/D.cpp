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

const int N = 110;
int n,W,w[N],v[N],ans;
vi sum[4];

void dfs(int c,int w,int v){
    if(c==3) {
        int remain = (W - w) / (::w[0] + 3);
        v += sum[3][min(remain,sz(sum[3])-1)];
        ans = max(ans , v);
    } else {
        rep(i,0,sz(sum[c])) {
            dfs(c + 1 , w , v + sum[c][i]);
            w += ::w[0] + c;
            if(w > W) break;
        }
    }
}

int main(){
    scanf("%d%d",&n,&W);
    rep(i,0,n) scanf("%d%d",w+i,v+i);
    rep(i,0,n) sum[w[i]-w[0]].pb(v[i]);
    rep(i,0,4) {
        vi&v=sum[i];
        sort(all(v));
        reverse(all(v));
        v.insert(v.begin(),0);
        rep(i,1,sz(v)) v[i]+=v[i-1];
    }
    dfs(0 , 0 , 0);
    printf("%d\n",ans);
    return 0;
}
