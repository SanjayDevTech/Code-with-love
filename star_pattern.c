#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void rightAngledPattern(int n){
    for(int i = 1; i <= n; i++){
        for(int j = n - 1; j >= i; j--)
            printf(" ");
        for(int j = 1; j <= i; j++)
            printf("*");
        printf("\n");
    }
}
int main() {
    int t, n;
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        scanf("%d", &n);
        printf("Case #%d:\n", i + 1);
        rightAngledPattern(n);
    }
    return 0;
}

