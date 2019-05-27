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
int T , n , m , a[110] , b[110];

int main(){
    scanf("%d",&T);
    rep(re,0,T){
        scanf("%d%d",&n,&m);
        fill(a + 1 , a + n + 1 , -1);
        rep(i,0,m){
            int x , y;scanf("%d%d",&x,&y);
            a[x] = y;
        }
        if(a[1] == -1) a[1] = 100;
        if(a[2] == -1) a[2] = a[1];
        int q = max(0,a[n]);b[n] = a[n];
        for(int i=n-1;i>=1;--i) b[i] = max(b[i+1] , a[i]) , q += max(0,b[i]);
        int p = a[1] + a[2];
        printf("%d/%d\n",p/__gcd(p,q) , q/__gcd(p,q));
    }
    return 0;
}
