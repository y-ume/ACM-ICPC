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

const int N = 2e5 + 10;
int n , m , a[N];
int cnt[N] , vis[N] , err;

void add(int x){
    cnt[x]++;
    int t=x-cnt[x]+1;
    if(t>=1&&++vis[t]==1)
        err--;
}
void del(int x){
    int t=x-cnt[x]+1;
    cnt[x]--;
    if(t>=1&&--vis[t]==0)
        err++;
}

int main(){
    scanf("%d%d",&n,&m);
    err = n;
    rep(i,1,n+1) scanf("%d",a + i) , add(a[i]);
    rep(i,0,m){
        int x,y;
        scanf("%d%d",&x,&y);
        del(a[x]);
        add(a[x]=y);
        printf("%d\n",err);
    }
    return 0;
}
