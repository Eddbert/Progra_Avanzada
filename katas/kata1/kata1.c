#include <stdio.h>

int main() {
    int a[] = {12, 28, 46, 32, 50};
    int b[] = {50, 12, 32, 46, 28};
    int p[5];
    for (int i = 0; i < sizeof(a)/sizeof(int); i++)
    {
        for (int j = 0; j < sizeof(b)/sizeof(int); j++)
        {
            if(a[i]==b[j])
            {
                p[i] = j;
                break;
            }
        }
    }
    printf("Success %i, %i, %i, %i, %i\n",p[0],p[1],p[2],p[3],p[4]);
	return 0;
}