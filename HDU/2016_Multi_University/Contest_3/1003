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
const int N = 1001;
int T , n , m;
bool k[N][N] , r[N][N] , q[N][N];
int kt[N][N];
bool col[2][N<<1] , row[2][N<<1] , xx[N<<2];

void Pre(){
    int x = 1000;
    col[0][x]=col[1][x]=row[0][x]=row[1][x]=xx[x]=1;
    for(int i=1000;i>=1;--i) for(int j=1000;j>=1;--j){
        if(i == 1000 && j == 1000) continue;
        bool&a=k[i][j];a=0;
        if(i!=1000 && k[i+1][j] == 0) a=1;
        if(j!=1000 && k[i][j+1] == 0) a=1;
        if(i!=1000 && j!=1000 && k[i+1][j+1] == 0) a=1;
        bool&b=r[i][j];b=0;
        if(col[0][j] == 1 || row[0][i] == 1) b=1;
           col[0][j] |= !b;  row[0][i] |= !b;
        int&c=kt[i][j];c=2;bool eq = 0 , lose = 0;
        if(i+1<=1000&&j+2<=1000){
            if(kt[i+1][j+2] == 0) c=1;
            if(kt[i+1][j+2] == 1) lose=1;
            if(kt[i+1][j+2] == 2) eq=1;
        }
        if(i+2<=1000&&j+1<=1000){
            if(kt[i+2][j+1] == 0) c=1;
            if(kt[i+2][j+1] == 1) lose=1;
            if(kt[i+2][j+1] == 2) eq=1;
        }
        if(c == 2){
            if(eq == 0 && lose == 1) c = 0;
        }
        bool&d=q[i][j];d=0;
        if(col[1][j] == 1 || row[1][i] == 1 || xx[i-j+1000] == 1) d=1;
           col[1][j] |= !d , row[1][i] |= !d , xx[i-j+1000] |= !d;
    }
}

int main(){
    Pre();
    scanf("%d",&T);
    rep(i,0,T){
        int type , n , m;
        scanf("%d%d%d",&type,&n,&m);
        if(type == 1) puts(k[1000-n+1][1000-m+1] ? "B":"G");
        if(type == 2) puts(r[1000-n+1][1000-m+1] ? "B":"G");
        if(type == 4) puts(q[1000-n+1][1000-m+1] ? "B":"G");
        if(type == 3) puts(kt[1000-n+1][1000-m+1] == 0 ? "G" : (kt[1001-n][1001-m] == 1 ? "B" : "D"));
    }
    return 0;
}
