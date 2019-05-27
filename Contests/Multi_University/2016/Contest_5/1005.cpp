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


const int P = 1e9 + 7 , N = 1000005;
void pp(int &x,int d){
    x += d;
    if(x >= P) x-= P;
}
struct Palindromic_Tree { // [0,p) , 0(even) and 1(odd) is virtual , init!!
    static const int N = 1000005 , M = 26;
    int ne[N][M] , fail[N] , len[N] , last , n , p;
    char S[N];
    int lensum[N] , cnt[N];
    int newnode(int l){
        fill(ne[p] , ne[p] + M , 0);
        len[p] = l;lensum[p] = l;cnt[p] = 1;
        return p++;
    }
    void ini(){
        p = 0;newnode(0);newnode(-1);
        S[n = last = 0] = -1;cnt[0] = cnt[1] = 0;
        fail[0] = 1;
    }
    int get_fail(int x){
        while(S[n - len[x] - 1] != S[n]) x = fail[x];
        return x;
    }
    pii add(int c){
        S[++n] = c;
        int cur = get_fail(last);
        if(!ne[cur][c]){
            int now = newnode(len[cur] + 2);
            fail[now] = ne[get_fail(fail[cur])][c];
            ne[cur][c] = now;
            int ff = fail[now] , cc = now;
            pp(lensum[cc] , lensum[ff]);
            cnt[cc] += cnt[ff];
        }
        last = ne[cur][c];
        return mp(cnt[last] , lensum[last]);
    }
}Pa;
char s[N];
int L[N];

int main(){
    while(~scanf("%s",s+1)){
        int len = strlen(s+1);
        Pa.ini();
        for(int i=1;i<=len;++i){
            pii e = Pa.add(s[i] - 'a');
            L[i] = (1ll * e.fi * (i+1) - e.se)%P;
        }
        Pa.ini();
        int ans = 0;
        for(int i=len;i>=1;--i){
            pii e = Pa.add(s[i] - 'a');
            int x = (1ll * e.fi * (i-1) + e.se)%P;
            if(i > 1){
                int t = 1ll * L[i-1] * x % P;
                pp(ans , t);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
