#include <stdio.h>

int binsearch(int x, int v[], int n)
{
    int low = 0, high = n - 1, mid;
    while (low < high) {
        mid = low + (high - low) / 2;
        if (v[mid] < x) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    if (v[low] == x) {
        return low;
    }
    return -1;
}

int main(int argc, char *argv[])
{
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    //int x = 11;
    //int x = 0;
    //int x = 9;
    int x = 8;
    int idx;
    if ((idx = binsearch(x, arr, 10)) >= 0) {
        printf("%d is at %d.\n", x, idx);
    } else {
        printf("%d is not in arr.\n", x);
    }

    return 0;
}
