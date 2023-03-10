#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int main() {
    unsigned int n = 0;
    scanf("%u", &n);
    int a[32], bi[32], op[15], bits[250], i = 0, j = 0,
    dim = 0, N = 0, l = 0, k = 0, nr = 0, suma = 0;
    unsigned int m = n;
        for (int j = 0; j < 32; j++) {
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
            N = N + (bi[j] << l);
            l++;
        }
        for (j = 3; j <= 2+(N*2); j=j+2) {
            if ((bi[j] == 0) & (bi[j+1] == 0))
                op[++k] = 1;
            else if ((bi[j] == 0) & (bi[j+1] == 1))
                op[++k] = 2;
            else if ((bi[j] == 1) & (bi[j+1] == 0))
                op[++k] = 3;
            else if ((bi[j] == 1) & (bi[j+1] == 1))
                op[++k] = 4;
        }
        l = 0; dim = 1;
        for (j = 6 + (N * 2); j >= 3 + (N * 2); j--) {
            dim = dim + (bi[j] << l);
            l++;
        }
        nr = ((N + 1) * dim) / 16;
        nr = nr + (((N + 1) * dim) % 16 != 0);
        for (i = 1; i <= nr; i++) {
            scanf("%u", &m);
            for (j = 15; j >= 0; j--) {
                if (1 << j <= m) {
                    m = m - (1 << j);
                    bits[15 - j + (i - 1) * 16] = 1;
                } else {
                    bits[15 - j + (i - 1) * 16] = 0;
                }
            }
        }
        for (i = 1; i <= N+1; i++) {
            a[i] = 0;
            for (j = 0; j <= dim-1; j++)
                a[i] = a[i] * 2 + bits[j + (i - 1) * dim];
        }
        suma = a[1];
        for (i = 1; i <= N; i++) {
            if (op[i] == 1)
                suma = suma + a[i+1];
            if (op[i] == 2)
                suma = suma - a[i+1];
            if (op[i] == 3)
                suma = suma * a[i+1];
            if (op[i] == 4)
                suma = suma / a[i+1];
        }
        printf("%d\n" , suma);
    return 0;
}
