#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <bitset>
#include <vector>
#include <complex>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vi;
#define de(x) cout << #x << "=" << x << endl
#define rep(i,a,b) for(int i=a;i<(b);++i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
const int N = 101010;
int n , Q , lg[N];
struct ST{
    int a[20][N];
    void Build(int *v,int n){
        rep(i,0,n) a[0][i] = v[i];
        rep(i,1,lg[n]+1) rep(j,0,n-(1<<i)+1) a[i][j] = min(a[i-1][j] , a[i-1][j+(1<<i>>1)]);
    }
    int rmq(int x,int y){
        if(x>y) swap(x,y);
        int i=lg[y-x+1];
        return min(a[i][x] , a[i][y+1-(1<<i)]);
    }
}st;

char s[N];
int sum[N];

int main(){
    rep(i,2,N) lg[i] = lg[i-1]+(i==(i&-i));
    while(~scanf("%d%d",&n,&Q)){
        scanf("%s",s);
        rep(i,0,n) sum[i] = (i ? sum[i-1] : 0) + (s[i] == '(' ? 1 : -1);
        st.Build(sum , n);
        rep(i,0,Q){
            int u,v;scanf("%d%d",&u,&v);
            --u;--v;if(u > v) swap(u,v);
            if(s[u] == '(' && s[v] == ')'){
                puts(st.rmq(u , v - 1) >= 2 ? "Yes" : "No");
            } else puts("Yes");
        }
    }
    return 0;
}
