#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#ifdef max
#undef max
#endif
#define max(a, b) (((a) > (b)) ? (a) : (b))


int maxSubarray(int arr[], int n){
    if (n ==0) return 0;
    int count = arr[0];
    int max_so_far = arr[0];
    for (int i =1; i<n;i++){
        count = max(arr[i], count + arr[i]);
        max_so_far = max(max_so_far, count);
    }
    return max_so_far;
}
int main(){
    int arr[] ={-2,1,-3,4,-1,-2,-8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int max_sum = maxSubarray(arr, n);
    printf("Maximum subarray sum is %d", max_sum);
    return 0;
}