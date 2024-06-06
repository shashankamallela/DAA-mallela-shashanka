#include <stdio.h>
#include <limits.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    if (nums1Size > nums2Size) {
        int* tempNums = nums1;
        nums1 = nums2;
        nums2 = tempNums;
        
        int tempSize = nums1Size;
        nums1Size = nums2Size;
        nums2Size = tempSize;
    }

    int x = nums1Size;
    int y = nums2Size;
    int low = 0;
    int high = x;

    while (low <= high) {
        int partitionX = (low + high) / 2;
        int partitionY = (x + y + 1) / 2 - partitionX;

        int maxX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
        int minX = (partitionX == x) ? INT_MAX : nums1[partitionX];

        int maxY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
        int minY = (partitionY == y) ? INT_MAX : nums2[partitionY];

        if (maxX <= minY && maxY <= minX) {
            if ((x + y) % 2 == 0) {
                int maxLeft = (maxX > maxY) ? maxX : maxY;
                int minRight = (minX < minY) ? minX : minY;
                return (maxLeft + minRight) / 2.0;
            } else {
                return (maxX > maxY) ? maxX : maxY;
            }
        } else if (maxX > minY) {
            high = partitionX - 1;
        } else {
            low = partitionX + 1;
        }
    }
    return 0.0; 
}
int main() {
    int nums1[] = {1, 3};
    int nums1Size = sizeof(nums1) / sizeof(nums1[0]);
    int nums2[] = {2};
    int nums2Size = sizeof(nums2) / sizeof(nums2[0]);
    printf("%f\n", findMedianSortedArrays(nums1, nums1Size, nums2, nums2Size));
    return 0;
}
