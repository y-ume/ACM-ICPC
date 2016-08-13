#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
const int N = 101010;
int n;
int a[N];

void main2() {
    scanf("%d",&n);
    int CC;scanf("%d",&CC);
    for(int i=0;i<n;++i){
        int v,x,d;
        scanf("%d%d%d",&v,&x,&d);
        a[i] = v;
    }
    sort(a,a+n);
    int m;scanf("%d",&m);
    for(int i=0;i<m;++i){
        int x,y;scanf("%d%d",&x,&y);
        double tt = 1. * a[y-1] * a[y-1] / 2 / CC;
        tt += 1. *x;
        printf("%.3lf\n",sqrt(tt*2*CC));
    }
}

int main(){
    int T;scanf("%d",&T);
    for(int i=0;i<T;++i) main2();
    return 0;
}
