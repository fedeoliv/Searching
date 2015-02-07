#include<stdio.h>

/*  Interpolation search works better than Binary Search for a sorted and uniformly distributed array. */

int interpolation_search(int arr[], int low, int high, int x) {
    while(high >= low) {
        int mid = low + (high-low) * (x - arr[low])/(arr[high] - arr[low]);

        if(arr[mid] == x) return mid;
        else if(arr[mid] > x) high = mid - 1;
        else low = mid + 1;
    }
    return -1;
}

int main() {
    int arr[] = {201,209,232,233,332,399,400};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 332;

    printf("%d\n", interpolation_search(arr, 0, n-1, x));
    return 0;
}
