#include <iostream>
#include <cstring>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;++i)

void setIO(){
    freopen("B-large.in.txt","r",stdin);
    freopen("out.txt","w",stdout);
}

char s[10000];
int main2(){
    scanf("%s",s);
    int len = strlen(s);
    int cnt = 0;
    for(int i=0,j=0;i<len;++cnt,i=j)
        for(j=i;j<len && s[i] == s[j];++j);
    return cnt - ((cnt%2) == (s[0] == '+'));
}

int T;
int main(){
    setIO();
    scanf("%d",&T);
    rep(cs,1,T+1)
        printf("Case #%d: %d\n",cs,main2());
    return 0;
}
