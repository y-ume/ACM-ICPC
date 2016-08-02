#include<cstdio>
const int N = 1010101;
long long a,stack[N];
int n,i,top;
int main()
{
    while (scanf("%d",&n)!=EOF)
    {
    top=0;
    for (i=1;i<=n;i++)
    {
        scanf("%I64d",&a);
        while (a<0)
        {
            a=stack[top]+a;
            top--;
        }
        stack[++top]=a;
    }
    printf("%d\n",top);
    }
}
