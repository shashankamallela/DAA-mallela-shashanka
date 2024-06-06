#include <stdio.h>
#include <limits.h>
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    if (nums1Size > nums2Size)
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);

    int l = 0;
    int r = nums1Size;

    while (l <= r) {
        int partition1 = (l + r) / 2;
        int partition2 = (nums1Size + nums2Size + 1) / 2 - partition1;
        int maxLeft1 = (partition1 == 0) ? INT_MIN : nums1[partition1 - 1];
        int maxLeft2 = (partition2 == 0) ? INT_MIN : nums2[partition2 - 1];
        int minRight1 = (partition1 == nums1Size) ? INT_MAX : nums1[partition1];
        int minRight2 = (partition2 == nums2Size) ? INT_MAX : nums2[partition2];
        
        if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
            if ((nums1Size + nums2Size) % 2 == 0)
                return ((double)(max(maxLeft1, maxLeft2) + min(minRight1, minRight2))) * 0.5;
            else
                return max(maxLeft1, maxLeft2);
        } else if (maxLeft1 > minRight2) {
            r = partition1 - 1;
        } else {
            l = partition1 + 1;
        }
    }
}

int main() {
    int nums1[] = {1, 3};
    int nums1Size = sizeof(nums1) / sizeof(nums1[0]);
    int nums2[] = {2};
    int nums2Size = sizeof(nums2) / sizeof(nums2[0]);

    printf("Median of the two sorted arrays: %f\n", findMedianSortedArrays(nums1, nums1Size, nums2, nums2Size));
    return 0;
}
