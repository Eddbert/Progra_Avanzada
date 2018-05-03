#include<stdio.h>
#define llu long long unsigned int

long long mult(long long a,long long b,long long mod)
{
    long double ans;
    long long c;
    a=a%mod;
    b=b%mod;
    ans=(long double)a*b;
    a=a*b;
    c=(long long)(ans/mod);
    a=a-c*mod;
    a=a%mod;
    if(a<0)
        a=a+mod;
    return a;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int i;
        llu a,b,c,q=0,j,l[n];
        char s;
        char str[1001]="";
        for(i=0; i<n; i++)
        {
            scanf("%llu",&l[i]);
        }
        scanf("%llu %llu %llu",&a,&b,&c);
        scanf("%s",str);
        for(i=0; i<n; i++)
        {
            s=str[i];
            if(s=='R')
            {
                q=n-1;
                for(j=i; j<=q; j++)
                {
                    llu temp=l[j];
                    l[j]=l[q];

                    l[q]=temp;
                    q--;
                }
            }
            else if(s=='A')
            {
                for(j=i; j<n; j++)
                {
                    l[j]=((l[j]%c)+(a%c))%c;
                }
            }
            else if(s=='M')
            {
                for(j=i; j<n; j++)
                {
                    l[j]=mult(l[j],b,c);
                }
            }
        }
        for(i=0; i<n; i++)
        {
            printf("%llu ",l[i]%c);
        }
        printf("\n");
    }
    return 0;
}
