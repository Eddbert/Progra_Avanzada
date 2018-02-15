#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int concatenate(int x, int y) {
    if (y != 0)
    {
        int pow = 10;
        while(y >= pow)
            pow *= 10;
        return x * pow + y;        
    }
    return x;
}

int OrderDigits(int number, bool asc)
    {   
        // Extract each digit into an array
        int digits[(int) log10(number) + 1];
        for (int i = 0; i < sizeof(digits)/sizeof(digits[0]); i++)
        {
            digits[i] = number % 10;
            number /= 10;
        }

        // Order the digits
        for (int i = 0; i < sizeof(digits)/sizeof(digits[0]); i++)
        {
            for (int j = i + 1; j < sizeof(digits)/sizeof(digits[0]); j++)
            {               
                if ((!asc && digits[j] > digits[i]) ||
                    (asc && digits[j] < digits[i]))
                {
                    int temp = digits[i];
                    digits[i] = digits[j];
                    digits[j] = temp;
                }
            }
        }

        // Turn the array of digits back into an integer
        int result = 0;
        for (int i = sizeof(digits)/sizeof(digits[0]) - 1; i >= 0; i--)
        {
            result += digits[i] * (int)pow(10, sizeof(digits)/sizeof(digits[0]) - 1 - i);
        }

        return result;
    }

int main() {
    long N = 10;
    long N_Change = 0;
    int Q = 0;
    printf("Enter any number to calculate product of digit: ");
    scanf("%d", &N);
    while (N > 9)
    {
        N_Change = N;
        for (int i = 9; i > 1; i--)
        {
            if (N % i == 0 && N / i != 1)
            {
                if ((N / i) < 10)
                {
                  Q = concatenate(Q, N / i);
                }
                Q = concatenate(Q, i);
                N = N / i;
                break;
            }
        }
        if (N == N_Change)
        {
            Q = -1;
            break;
        }
        
    }
    if (Q != -1)
    {
        Q = OrderDigits(Q, true);
    }
    printf("Product of digits = %i", Q);
	return 0;
}