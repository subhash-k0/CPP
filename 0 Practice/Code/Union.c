#include <stdio.h>
#include <conio.h>

int main(){

    int a[10], b[10], m, n, i, j;
    int c[20], k = 0, flag = 0;
    int ch;

    printf("Enter the number of elements in first set:\n");
    scanf("%d", &m);
    printf("Enter the elements:\n");

    for (i = 0; i < m; i++){
        scanf("%d", &a[i]);}

    printf("\nEnter the number of elements in second set:\n");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++){
        scanf("%d", &b[i]);}

    printf("\nElement of First set:\n");
    for (i = 0; i < m; i++){
        printf("%d\t", a[i]);}

    printf("\nElement of Second set:\n");
    for (i = 0; i < n; i++){
        printf("%d\t", b[i]); }

    for (i = 0; i < m; i++){
        c[k] = a[i];
        k++;}

    for (i = 0; i < n; i++){
        flag = 0;
        for (j = 0; j < m; j++){
            if (b[i] == c[j]){
                flag = 1;
                break;
            }  }

        if (flag == 0){
            c[k] = b[i];
            k++;  } }

    printf("\nElement of resultant set\n");
    for (i = 0; i < k; i++){
        printf("%d\t", c[i]);
    }}