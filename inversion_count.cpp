#include <stdio.h>
#include <stdlib.h>
typedef long long LL;

/*  Example: The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).*/

LL interpolate(int x[], int start, int middle, int end) {
    int i, j, k, b[end+1];
    LL c;

    for(i = start; i <= middle; i++) b[i] = x[i];
    for(j = end; i <= end; i++, j--) b[i] = x[j];

    for(c = 0, j = end, i = k = start; k <= end; k++)
        if(b[i] <= b[j]) x[k] = b[i++];
        else {
          x[k] = b[j--];
          c = c + (middle - i + 1);
        }

    return c;
}

LL merge_sort(int x[], int start, int end) {
    int middle;

    if(start >= end) return 0;
    middle = (start + end) / 2;

    return merge_sort(x, start, middle) + merge_sort(x, middle+1, end)
    + interpolate(x, start, middle, end);
}

int main() {
    int t, i;

    scanf("%d", &t);

    while(t--) {
        int n;
        scanf("%d", &n);

        int values[n];
        for(i = 0; i < n; i++) scanf("%d", &values[i]);
        printf("%lld\n", merge_sort(values, 0, n-1));
    }

    return 0;
}
