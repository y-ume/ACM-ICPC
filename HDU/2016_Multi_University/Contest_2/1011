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
int T , n;

int main(){
    scanf("%d",&T);
    rep(re,0,T){
        scanf("%d",&n);
        int a = 0 , b = 0;
        rep(i,0,n){
            int x;
            scanf("%d",&x);
            if(x&1) a++;
            b += x/2;
        }
        if(a == 0) printf("%d\n",b*2);
        else printf("%d\n",b/a*2+1);
    }
    return 0;
}
