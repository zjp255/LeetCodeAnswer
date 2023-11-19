/*给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。
请你找出并返回这两个正序数组的 中位数 。
算法的时间复杂度应该为 O(log (m+n)) 。
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
using namespace std;
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int index1 = 0, index2 = 0;
        int size1 = nums1.size();
        int size2 = nums2.size();
        vector<int> nums3;
        while (index1 < size1 || index2 < size2)
        {
            if ((index1 < size1 && index2 >= size2) || (index1 < size1 && index2 < size2 && nums1[index1] <= nums2[index2]))
            {
                nums3.push_back(nums1[index1]);
                index1++;
            }
            else if ((index1 >= size1 && index2 < size2) || (index1 < size1 && index2 < size2 && nums1[index1] > nums2[index2]))
            {
                nums3.push_back(nums2[index2]);
                index2++;
            }
        }
        int size3 = nums3.size();
        if (size3 % 2 == 0)
        {
            size3 /= 2;
            double ans = (double)(nums3[size3] + nums3[size3 - 1]) / 2;
            return ans;
        }
        else
        {
            size3 /= 2;
            double ans = nums3[size3];
            return ans;
        }
        return -1;
    }
};

class Solution1//O((m + n）
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int index1 = 0, index2 = 0;
        int size1 = nums1.size();
        int size2 = nums2.size();
        vector<int> nums3;
        while (index1 < size1 || index2 < size2)
        {
            if ((index1 < size1) && ((index2 >= size2) || (index2 < size2 && nums1[index1] <= nums2[index2])))
            {
                nums3.push_back(nums1[index1]);
                index1++;
            }
            else if ((index2 < size2) && ((index1 >= size1) || (index1 < size1 && nums1[index1] > nums2[index2])))
            {
                nums3.push_back(nums2[index2]);
                index2++;
            }
        }
        int size3 = nums3.size();
        if (size3 % 2 == 0)
        {
            size3 /= 2;
            double ans = (double)(nums3[size3] + nums3[size3 - 1]) / 2;
            return ans;
        }
        else
        {
            size3 /= 2;
            double ans = nums3[size3];
            return ans;
        }
        return -1;
    }
};

class Solution2//时间复杂度O((m + n / 2)
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int index1 = 0, index2 = 0;
        int size1 = nums1.size();
        int size2 = nums2.size();
        int info[2];
        int len = size1 + size2;
        int mid = len / 2;
        for (int i = 0; i <= mid; i++)
        {
            if ((index1 < size1) && ((index2 >= size2) || (index2 < size2 && nums1[index1] <= nums2[index2])))
            {
                if (i == mid - 1)
                {
                    info[0] = nums1[index1];
                }
                else if (i == mid)
                {
                    info[1] = nums1[index1];
                }
                index1++;
            }
            else if ((index2 < size2) && ((index1 >= size1) || (index1 < size1 && nums1[index1] > nums2[index2])))
            {
                if (i == mid - 1)
                {
                    info[0] = nums2[index2];
                }
                else if (i == mid)
                {
                    info[1] = nums2[index2];
                }
                index2++;
            }
        }
        if(len % 2 == 0)
        {
            return (double)(info[0] + info[1])/2;
        }
        else{
            return (double)info[1];
        }
        return -1;
    }
};