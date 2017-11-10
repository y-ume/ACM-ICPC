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

const int N = 2e5 + 10 , M = 26;
string s;
int ne[N][M] , dis[N] , n , m;

int main(){
    cin >> s;
    n = sz(s);m = M;
    rep(i,0,m) ne[n+1][i]=n+1;
    dis[n+1]=0;
    per(i,0,n+1) {
        rep(j,0,m) ne[i][j]=ne[i+1][j];
        if(i!=n) ne[i][s[i]-'a']=i+1;
        dis[i]=1<<30;
        rep(j,0,m) dis[i]=min(dis[i],dis[ne[i][j]]+1);
    }
    string ans="";
    for(int i=0;i!=n+1;) {
        int id=0;
        rep(j,0,m) if(dis[ne[i][j]]<dis[ne[i][id]]) id=j;
        ans+=char('a'+id);
        i=ne[i][id];
    }
    cout<<ans<<endl;
    return 0;
}
