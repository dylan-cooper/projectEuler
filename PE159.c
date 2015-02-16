#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

#define DIGROOT(a) ((a-1)%9)+1
#define MAX(a,b) (a > b ? a : b)
#ifndef LIMIT
#define LIMIT 1000000
#endif
int arr[LIMIT] = {0};


int * twoFactors(int n, int prec){
    static int facs[2] = {0};
    facs[0] = facs[1] = 0;
    int i, count = 0;
    int max = ceil(sqrt((double)n));
    for (i = 2; (i <= max || count == 1) ; i++){
        if (n % i == 0){
            if (prec-- <= 0){
                facs[0] = n/i;
                facs[1] = i;
                return facs;
            }
        }
    }
    return facs;
}

int main(){
    int i;
    int total = 0;
    clock_t t0 = clock();
    for (i = 2; i < LIMIT; i++){
        int temp = i, max = 0;
        while (temp % 9 == 0) {
            max += 9;
            temp /= 9;
        }
        if (temp > 1){
            int localMax = DIGROOT(temp);
            int * factors;
            int j = 0;
            do {
                factors = twoFactors(temp, j++);
                localMax = MAX(localMax, arr[factors[0]] + arr[factors[1]]);
            } while (factors[0] != 0 && j < 9);
            max += MAX(DIGROOT(temp), localMax); 
        }
        arr[i] = max;
        total += max;
    }
    printf("Time: %d\tTotal: %d\n", (clock()-t0)/CLOCKS_PER_SEC, total);
}
