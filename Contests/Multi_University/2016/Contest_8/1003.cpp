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
typedef unsigned int ui;
const int N = 18 , P = 233;
int T,n;
char s[N+10][N+10];
bool ok[1<<N];
ui p[1<<N];
int Min[1<<N] , go[1<<N];


void main2(){
    scanf("%d",&n);
    rep(i,0,n) scanf("%s",s[i]);
    rep(i,0,n) go[1<<i] = 0;
    rep(i,0,n) rep(j,0,n) go[1<<i] |= (s[i][j]-'0')<<j;
    ok[0] = true;
    rep(i,1,1<<n){
        #define lb(x) ((x)&(-x))
        ok[i]=false;
        for(int j=i;j;j^=lb(j)){
            int t = lb(j);
            if(ok[i^t] && (go[t]&(i^t))==0) ok[i]=true;
            if(ok[i]) break;
        }
    }
    ui ans=0;
    rep(i,1,1<<n){
        if(ok[i]) Min[i] = 1;
        else{
            Min[i] = 1000;
            for(int j=(i-1)&i;j;j=(j-1)&i){
                if(ok[j]) Min[i] = min(Min[i] , Min[i^j] + 1);
            }
        }
        ans += Min[i] * p[i];
    }
    printf("%u\n",ans);
}

int main(){
    p[0] = 1;
    rep(i,1,1<<N) p[i]=p[i-1]*P;
    scanf("%d",&T);
    rep(i,0,T) main2();
    return 0;
}
