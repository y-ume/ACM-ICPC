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

const int N = 2020;
int n , m;
char s[N][N];
int a[N][N],up[N],_;
pii st[N];

int main(){
    scanf("%d%d",&n,&m);
    int ans=max(n,m);
    rep(i,0,n) scanf("%s",s[i]);
    rep(i,1,n) rep(j,1,m)
        a[i-1][j-1]=(s[i-1][j-1]^s[i-1][j]^s[i][j-1]^s[i][j])==0;
    rep(i,0,n-1) {
        _=0;
        rep(j,0,m-1) {
            if(a[i][j] == 1) up[j]++;
            else up[j]=0;
            int w=0;
            while(_>0&&up[j]<st[_-1].fi) {
                w+=st[_-1].se;
                ans=max(ans,(st[_-1].fi+1)*(w+1));
                --_;
            }
            st[_++]=mp(up[j],w+1);
        }
        int w=0;
        while(_>0) {
            w+=st[_-1].se;
            ans=max(ans,(st[_-1].fi+1)*(w+1));
            --_;
        }
    }
    printf("%d\n",ans);
    return 0;
}
