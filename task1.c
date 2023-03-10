#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int main() {
    unsigned int n = 0;
    scanf("%u", &n);
    int bi[32], i = 0, j = 0, dim = 0, N = 0, l = 0;
    unsigned int m = n;
        for (j = 0; j < 32; j++) {
            bi[j] = 0;
        }
        j = 31;
        while (m > 0) {
            if (m % 2 == 0)
            bi[j] = 0;
            else
            bi[j] = 1;
            j--;
            m = m / 2;
        }
        l = 0; N = 1;
        for (j = 2; j >= 0; j--) {
            N = N + bi[j]*pow(2, l);
            l++;
        }
        printf("%d ", N);
        for (j = 3; j <= 2+(N*2); j=j+2) {
            if ((bi[j] == 0) & (bi[j+1] == 0))
                printf("+ ");
            else if ((bi[j] == 0) & (bi[j+1] == 1))
                printf("- ");
            else if ((bi[j] == 1) & (bi[j+1] == 0))
                printf("* ");
            else if ((bi[j] == 1) & (bi[j+1] == 1))
                printf("/ ");
        }
        l = 0; dim = 1;
        for (j = 6+(N*2); j >=3+(N*2); j--) {
            dim = dim + bi[j]*pow(2, l);
            l++;
        }
        printf("%d\n", dim);
    return 0;
}
