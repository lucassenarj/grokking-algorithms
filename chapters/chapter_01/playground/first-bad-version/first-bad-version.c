#include <stdio.h>
#include <stdbool.h>

bool isBadVersion(int version);
int firstBadVersion(int n);

int main(void)
{
    unsigned int version = 5;
    printf("The first bad version is: %d\n\n", firstBadVersion(version)); // bad = 4 | expect output 4
}

bool isBadVersion(int version)
{
    return version == 4;
}

int firstBadVersion(int n) {
    int low = 1;
    int high = n;

    while (low < high)
    {
        int mid = low + (high - low) / 2;

        if (isBadVersion(mid)) {
            high = mid;
        } else {
            low = mid + 1;
        }

    }
    return low;
}
