#include <stdio.h>

int main() {
    int a[] = {2, 6, 3};
    int b[] = {4, 8, 7};
    int p[2];
    int t = 7;
    for (int i = 0; i < sizeof(a)/sizeof(int); i++)
    {
        for (int j = 0; j < sizeof(b)/sizeof(int); j++)
        {
            if(a[i]+b[j]==t)
            {
                p[0] = i;
                p[1] = j;
                printf("Success %i, %i\n",i,j);
                break;
            }
        }
    }
	return 0;
}