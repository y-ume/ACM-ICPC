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
const int N = 101010 , P = 1e9 + 7;
int n , a[N] , p10[N] = {1} , c[N] , sum[N] , Max[N];
char s[N];
inline void pp(int &x,int d){
    x += d;
    if(x >= P) x -= P;
}

int main(){
    rep(i,1,N) p10[i] = 1ll * p10[i-1] * 10 % P;
    rep(i,2,N) c[i] = c[i-1] , pp(c[i] , i - 1);
    rep(i,1,N) pp(c[i] , i);
    while(~scanf("%d",&n)){
        scanf("%s",s + 1);
        int ans = 0;
        rep(i,1,n+1){
            a[i] = s[i] - '0';
            int left = i - 1, right = n - i;
            Max[i] = min(left + 1 , right + 1);
            pp(ans , 1ll * (c[left] + c[right]) * a[i] % P * p10[n-i] % P);
        }
        int tot = 0;
        rep(i,1,n+1) sum[i] = sum[i-1] + a[i];
        for(int d=1,i=1,j=n;i<=j;++i,--j,++d){
            pp(tot , d * (a[i] + (i == j ? 0 : a[j])));
            pp(ans , 1ll * (p10[n-i] + (i == j ? 0 :p10[n-j])) * tot % P);
            //cout << i << "  " << j << " " << sum[j-1] - sum[i] <<  " " << tot << endl;;
            if(i + 2 <= j) pp(ans , 1ll * (p10[n-i] + (i == j ? 0 : p10[n-j])) * (sum[j-1] - sum[i]) % P * d % P);
        }
        printf("%d\n",ans);
    }
    return 0;
}
