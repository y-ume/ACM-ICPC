#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <string>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <complex>
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
const int N = 1010 , P = 1e9 + 7;
int n , m , a[N] , b[N];
#define lb(x) (x&(-x))
void pp(int &x,int d){
    x += d;
    if(x >= P) x -= P;
}
struct Fenwick{
    int a[N],n;
    void ini(int _n){
        fill(a,a+(n=_n)+1,0);
    }
    void add(int x,int d){
        for(int i=x;i<=n;i+=lb(i)) pp(a[i],d);
    }
    int sum(int x){
        int r=0;
        for(int i=x;i>=1;i-=lb(i)) pp(r,a[i]);
        return r;
    }
}f;

int main(){
    while(~scanf("%d%d",&n,&m)){
        rep(i,1,n+1) scanf("%d",a + i);
        rep(i,1,m+1) scanf("%d",b + i);
        f.ini(m);
        int ans = 0;
        rep(i,1,n+1) for(int j=m;j>=1;--j) if(a[i] == b[j]){
            int t = f.sum(j-1);
            pp(t,1);
            pp(ans , t);
            f.add(j,t);
        }
        printf("%d\n",ans);
    }
    return 0;
}
