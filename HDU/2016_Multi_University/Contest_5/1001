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
typedef complex<db> P;
const int N = 2001;
int K , W , n;
db ans[N][N] , f[N] , g[N]; // i->W , j->K
P p[N];
db get(int i,int j){
    return g[j] * (j+1) + (i-j)*f[i-j-1];
}

const int UP = 2000;
int oo[N];
void Pre(){
    for(int i=1;i<=UP;++i) f[i] = 1000000;
    for(n=1;n<=UP;++n){
        int opt = 0;
        if(n<=10){
            for(int i=1;i<=UP;++i){
                db Min = 1000000;int id = 0;
                for(int j=opt;j<i;++j){
                    db F = g[j]*(j+1) + (i-j)*f[i-j-1];
                    F /= (i+1);F += 1;
                    if(F <= Min+1e-8) Min = F , id = j;
                }
                g[i] = Min;opt=id;
                oo[i] = opt;
            }
        }
        else{
            for(int i=1;i<=UP;++i){
                int j = oo[i];
                db F = g[j]*(j+1) + (i-j)*f[i-j-1];
                F /= (i+1);F += 1;
                g[i] = F;
            }
        }
        copy_n(g,2001,f);
        copy_n(g,2001,ans[n]);
    }
}


int main(){
    Pre();
    while(~scanf("%d%d",&K,&W)) printf("%.6lf\n",ans[W][K]+1e-8);
    return 0;
}
