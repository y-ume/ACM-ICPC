/*
 * 联想的显示屏校准
 */

#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <string>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vi;
#define de(x) cout << #x << "=" << x << endl
#define rep(i,a,b) for(int i=a;i<b;++i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
const int N = 404040 , P = 1<<30;
int mu[N] , sum[3][N] , T , n , m;
void pp(int &x,int d){
    x += d;
}
int Sum(ll x){
    return (x*(x+1)>>1)%P;
}
int Sum(int x,int i,int j){
    return sum[x][j] - sum[x][i-1];
}
int main(){
    mu[1] = 1;rep(i,1,N) for(int j=i+i;j<N;j+=i) mu[j] -= mu[i];
    rep(i,1,N){
        sum[0][i] = sum[0][i-1] + mu[i];
        sum[1][i] = sum[1][i-1] + mu[i]*i;
        sum[2][i] = sum[2][i-1] + mu[i]*i*i;
    }
    scanf("%d",&T);
    rep(i,0,T){
        scanf("%d%d",&n,&m);
        int A = 0 , B = 0;
        int a = n-1 , b = m-1;
        for(int i=1;i<=min(a,b);++i){ // n - 1 , m - 1
            int t1 = a/i , t2 = b/i;
            int j = min(a/t1 , b/t2);
            pp(A , t1 * t2 * n * m * Sum(0 , i , j));
            pp(A , -t1 * Sum(t2) * n * Sum(1 , i , j));
            pp(A , -t2 * Sum(t1) * m * Sum(1 , i , j));
            pp(A , Sum(t1) * Sum(t2) * Sum(2 , i , j));
            i = j;
        }
        a = min(n-1,n/2) , b = min(m-1,m/2);
        for(int i=1;i<=min(a,b);++i){
            int t1 = a/i , t2 = b/i;
            int j = min(a/t1 , b/t2);
            pp(B , t1 * t2 * n * m * Sum(0 , i , j));
            pp(B , -t1 * Sum(t2) * n * Sum(1 , i , j) * 2);
            pp(B , -t2 * Sum(t1) * m * Sum(1 , i , j) * 2);
            pp(B , Sum(t1) * Sum(t2) * Sum(2 , i , j) * 4);
            i = j;
        }
        pp(A,-B);
        pp(A,A);
        pp(A,n+m);
        A = (A%P+P)%P;
        printf("%d\n",A);
    }
    return 0;
}

