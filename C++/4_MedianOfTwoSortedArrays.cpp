#include <vector>
#include <climits>
#include <iostream>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // 确保n <= m
        if (nums1.size() > nums2.size()) {
            nums1.swap(nums2);
        }
        int n = nums1.size(), m = nums2.size();
        int left = 0, right = n;
        bool isOdd = (n + m) & 1;
        double res;
        for (;;) {
            int i = (left + right) / 2;
            int j = isOdd ? (n + m + 1) / 2 - i : (n + m) / 2 - i;
            if (i <= 0 || j >= m || nums1[i-1] <= nums2[j]) {
                if ( i >= n || j <= 0 || nums1[i] >= nums2[j-1]) {
                    if (isOdd) {
                        // 奇数情况时，j > 0
                        res = i <= 0 ? nums2[j-1] : max(nums1[i-1],nums2[j-1]);
                    } else {
                        int a = i <= 0 ? INT_MIN : nums1[i-1];
                        int b = j <= 0 ? INT_MIN : nums2[j-1];
                        int c = i >= n ? INT_MAX : nums1[i];
                        int d = j >= m ? INT_MAX : nums2[j];
                        res = (max(a,b) + min(c,d)) / 2.0;
                    }

                    return res;
                } else {
                    left = i + 1;
                }
            } else {
                right = i - 1;
            }
        }
    }
};

int main() {
    vector<int> nums1(10, 1);
    vector<int> nums2(10, 2);
    Solution *s = new Solution();
    cout << s->findMedianSortedArrays(nums1, nums2);
}
