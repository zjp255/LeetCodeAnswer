/*给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。

你可以按任意顺序返回答案。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/two-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
//哈希表
//4ms 92.79% 13.84Mb 20%
class Solution3 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            auto temp = map.find(target - nums[i]);
            if(temp != map.end())
            {
                return {temp->second,i};
            }
            map.insert(pair<int,int>(nums[i],i));
        }
        return {};
    }
};


//哈希表
//3ms 97.75% 13.87MB 14.90%
class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            int temp = target - nums[i];
            if(map.count(temp) != 0)
            {
                return {i,map[temp]};
            }
            map[nums[i]] = i;
        }
        return {};
    }
};
//哈希表
//8ms 74.12% 15.37Mb 5.20%
class Solution1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            map[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            int temp = target - nums[i];
            if(map.count(temp) != 0 && map[temp] != i)
            {
                return {i,map[temp]};
            }
        }
        return {};
    }
};















class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> hashTable;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            auto it = hashTable.find(target - nums[i]);
            if(it != hashTable.end())
            {
                return{it->second,i};
            }
            hashTable[nums[i]] = i;
        }
        return {};

        if (nums.size() > 15)
        {
            int x = 0, y = 0;
            vector<int> tests = nums;
            quickSort(tests, 0, tests.size() - 1);
            for (int i = 0; i < tests.size(); i++)
            {
                int j = search(tests, target - tests[i]);
                if (j >= 0)
                {
                    if (tests[i] + tests[j] == target)
                    {
                        x = tests[i];
                        y = tests[j];
                        break;
                    }
                }
            }
            vector<int> answer;
            for (size_t i = 0; i < nums.size(); i++)
            {
                if (nums[i] == x || nums[i] == y)
                {
                    answer.push_back(i);
                    if (answer.size() == 2)
                    {
                        return answer;
                    }
                }
            }
        }
        else
        {

            for (int i = 0; i < nums.size(); i++)
            {
                for (int j = i + 1; j < nums.size(); j++)
                {
                    if (nums[i] + nums[j] == target)
                    {
                        return {i, j};
                    }
                }
            }
        }
        return {};
    }

    int search(vector<int> &nums, int target)
    {
        int front = 0;
        int last = nums.size() - 1;
        while (front <= last)
        {
            int mid = (front + last) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] > target)
            {
                last = mid - 1;
            }
            else
            {
                front = mid + 1;
            }
        }
        return -1;
    }

    int partition(vector<int> &nums, int low, int high)
    {
        int pivot = nums[high];
        int i = low - 1;
        for (int j = low; j < high; ++j)
        {
            if (nums[j] <= pivot)
            {
                i++;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[i + 1], nums[high]);
        return i + 1;
    }

    void quickSort(vector<int> nums, int low, int high)
    {
        if (low < high)
        {
            int pivot = partition(nums, low, high);

            quickSort(nums, low, pivot - 1);
            quickSort(nums, pivot + 1, high);
        }
    }
};