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
#include <bitset>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vi;
#define de(x) cout << #x << "=" << x << endl
#define rep(i,a,b) for(int i=a;i<(b);++i)
//#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
const int N = 10005;
const int Q = 997;
const int P = 1000000007;
char s[N] , t[N];
int len;
vi g[N];
namespace case10000{
    bitset<10005> A[N],I,X;
    int fail[N] , to[N],p[N];
    long long hash1[N],hash2[N],jc[N];
    void solve(){
        I[0] = A[1][0] = 1;
        A[1][1] = 1;
        A[0][0] = 1;
        for(int i=2,j=0;i<=len;++i){
            while(j&&s[j+1]!=s[i]) j = fail[j];
            if(s[j+1]==s[i]) ++j;
            A[i] = j ? A[j] : I;
            A[i][i] = 1;
            fail[i] = j;
        }
        //for(int i=1;i<=len;++i)
        //cout << i << " " << A[i] << endl;
        for(int i=1,j=0;i<=len;++i){
            while(j&&s[j+1]!=t[i]) j = fail[j];
            if(s[j+1]==t[i]) ++j;
            to[i] = j;
            //cout << i << " " << to[i] << endl;
        }
        for (int i=1;i<=len;i++)
        {
            hash1[i]=(hash1[i-1]*Q+s[i])%P;
            hash2[i]=(hash2[i-1]*Q+t[i])%P;
        }

        jc[0]=1;
        for (int i=1;i<=len;i++) jc[i]=jc[i-1]*Q%P;
        for (int i=1;i<=len;i++)
        {
            int l=i;
            int r=len;
            while (l<=r)
            {
                int m=(l+r)>>1;
                if (hash2[m-i+1]==((hash1[m]-hash1[i-1]*jc[m-i+1])%P+P)%P)
                    l=m+1;
                else
                    r=m-1;
            }
            p[i]=r-i+1;
        }
        //for(int i=1;i<=len;++i) printf("%d%c",p[i]," \n"[i==len]);
        static char ans[10005];
        for(int i=1;i<=len;++i) g[i].clear();
        for(int i=1;i<=len;++i) if(p[i]) g[i].pb(i) , g[i+p[i]].pb(-i);
        X = I;X[0] = 0;
        for(int i=1;i<=len;++i){
            for(auto e : g[i]){
                if(e>=0) X[e-1] = 1;
                else X[-e-1] = 0;
            }
            //cout << A[to[i]] << endl;
            //cout << X << endl;
            if(A[to[i]]==1) ans[i-1]='1';
            if((X&A[to[i]]).count()) ans[i-1] = '1';
            else ans[i-1] = '0';
        }
        ans[len] = 0;
        puts(ans);
    }
}


int main(){
    while(~scanf("%s%s",s+1,t+1)){
        len = strlen(s + 1);
        case10000::solve();
    }
    return 0;
}
