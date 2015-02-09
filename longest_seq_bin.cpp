#include <stdio.h>

/*  Given an array of 0s and 1s, find the position of 0 to be replaced with 1 to get longest continuous sequence of 1s.
    Input: arr[] =  {1, 1, 0, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1}
    Output: Index 9 */

int maxOnesIndex(bool arr[], int n) {
    int max_count = 0;          /* maximum number of 1 around a zero */
    int max_index;              /* result */
    int prev_zero = -1;         /* index of previous zero */
    int prev_prev_zero = -1;    /* index of previous to previous zero */

    /* Traverse the input array */
    for(int i = 0; i < n; ++i) {
        /*  If current element is 0, then calculate the difference
            between curr and prev_prev_zero */
        if(arr[i] == 0) {
            /* Update result if count of 1s around prev_zero is more */
            if(i - prev_prev_zero > max_count) {
                max_count = i - prev_prev_zero;
                max_index = prev_zero;
            }

            /* Update for next iteration */
            prev_prev_zero = prev_zero;
            prev_zero = i;
        }
    }

    /* Check for the last encountered zero */
    if(n-prev_prev_zero > max_count)
        max_index = prev_zero;

    return max_index;
}

int main() {
    bool arr[] = {1, 1, 0, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("%d\n", maxOnesIndex(arr, n));
    return 0;
}
