// 给你一个整数数组 nums，请你将该数组升序排列。


#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

//冒泡排序
//超时

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++)
        {
            bool flag = true;
            for (int j = 0; j < nums.size() - i; j++)
            {
                if(nums[j] > nums[j + 1])
                {
                    int temp = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = temp; 
                    flag = false;
                }
            }
            if(flag)
            {
                break;
            }
        }
        return nums;
    }
};

//选择排序
//将最小的放前面
//超时
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int minIndex = i;
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[minIndex] > nums[j]) {
                    minIndex = j;
                }
            }
            if (minIndex != i) {
                int temp = nums[i];
                nums[i] = nums[minIndex];
                nums[minIndex] = temp;
            }
        }
        return nums;
    }
};

//插入排序
//超时
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++)
        {
            int temp = nums[i];
            for (int j = i - 1; j >= 0; j--)
            {
                if(temp < nums[j])
                {
                    nums[j + 1] = nums[j];
                    nums[j] = temp;
                }
            }
        }
        return nums;
    }
};

//希尔排序
// 103ms 85.52%
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        int gap = n / 2;
        while (gap > 0)
        {
            for (int i = gap; i < n; i++)
            {
                int current = nums[i];
                int pre = i - gap;
                while (pre >= 0 && current < nums[pre])
                {
                    nums[pre + gap] = nums[pre];
                    pre -= gap;
                }
                nums[pre + gap] = current;
            }
            gap /= 2;
        }
        return nums;
    }
};

//归并排序
//126ms 65.78% 69.73MB 26.66%
class Solution {
public:
    vector<int> temp;
    vector<int> sortArray(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums;
        }
        temp = vector(nums.size(), 0);
        merge(nums, 0, nums.size() - 1);
        return nums;
    }

    void merge(vector<int>& nums, int l, int r) {
        if (l >= r)
            return;
        int mid = (l + r) >> 1;
        merge(nums, l, mid);
        merge(nums, mid + 1, r);
        int i = l, j = mid + 1;
        int cnt = 0;
        while (i <= mid && j <= r) {
            if (nums[i] <= nums[j]) {
                temp[cnt++] = nums[i++];
            } else {
                temp[cnt++] = nums[j++];
            }
        }
        if (i <= mid) {
            while (i <= mid) {
                temp[cnt++] = nums[i++];
            }
        } else {
            while (j <= r) {
                temp[cnt++] = nums[j++];
            }
        }
        for (int x = 0; x < cnt; x++) {
            nums[l++] = temp[x];
        }
    }
};

//1714ms 21.65% 67.71MB 55.64%
//快速排序
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }

    static void quickSort(vector<int>& a, int l, int r) {
        if (l < r) {
            int i, j, x;
            i = l;
            j = r;
            x = a[i];
            while (i < j) {
                while (i < j && a[j] > x)
                    j--; // 从右向左找第一个小于x的数
                if (i < j)
                    a[i++] = a[j];
                while (i < j && a[i] < x)
                    i++; // 从左向右找第一个大于x的数
                if (i < j)
                    a[j--] = a[i];
            }
            a[i] = x;
            quickSort(a, l, i - 1);
            quickSort(a, i + 1, r);
        }
    }
};




//快速排序 中间取pivot
//2504ms 5.03% 67.63mb 68.58%
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }

    void quickSort(vector<int>& nums, int l, int r) {
        if (l >= r) {
            return;
        }
        int i = l, j = r;
        int pivot = (i + j) / 2;
        int pNum = nums[pivot];
        nums[pivot] = nums[l];
        while (i < j) {
            while (i < j && nums[j] >= pNum)
                j--;
            if (i < j) {
                nums[i] = nums[j];
                i++;
            }
            while (i < j && nums[i] <= pNum)
                i++;
            if (i < j) {
                nums[j] = nums[i];
                j--;
            }
        }

        nums[i] = pNum;
        quickSort(nums, l, i - 1);
        quickSort(nums, i + 1, r);
    }
};

//堆排序
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {

    }

    void buildMaxHeap(vector<int>& nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            /* code */
        }
        
    }
};