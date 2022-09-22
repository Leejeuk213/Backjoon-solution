#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int compare(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}
int M[99], N;
int main(){
    scanf("%d", &N);
    int arr[N];
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);
    qsort(arr, N, sizeof(int), compare);
	
    int x = arr[1]-arr[0], idx = 0;
    int sq = sqrt(x);
    for (int i = 2; i <= sq; i++)
        if (x%i == 0){
            M[idx++] = i;
            if (x/i != i) M[idx++] = x/i;
        }
    qsort(M, idx, sizeof(int), compare);
    M[idx++] = x;
	
    for (int i = 0, j; i < idx; i++){
        for (j = 1; j < N; j++)
            if (arr[j] % M[i] != arr[0] % M[i]) break;
        if (j == N) printf("%d ", M[i]);	
    }
}