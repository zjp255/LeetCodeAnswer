// 给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。请

// 你返回所有和为 0 且不重复的三元组。

// 注意：答案中不可以包含重复的三元组。
#include<iostream>
#include<vector>
#include <unordered_map>
//超时
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    int len = nums.size();
        unordered_map<int,vector<vector<int>>> hashTable;
        vector<vector<int>> ans;
        for(int i = 0; i < len; i++)
        {
            for(int j = i + 1; j < len; j++)
            {
                int key = nums[i] + nums[j];
                vector<vector<int>> temp = hashTable[key];
                if(temp.size() == 0)
                {
                    vector<int> tempt = {nums[i],nums[j]};
                    vector<int> index = {i,j};
                    temp.push_back(tempt);
                    temp.push_back(index);
                }else{
                    for(int x = 0; x < temp.size(); x++)
                    {
                        if((nums[i] == temp[x][0] && nums[j] == temp[x][1]) || (nums[i] == temp[x][1] && nums[j] == temp[x][0]))
                        {
                            break;
                        }
                        else{
                            vector<int> tempt = {nums[i],nums[j]};
                            vector<int> index = {i,j};
                            temp.push_back(tempt);
                            temp.push_back(index);
                        }
                    }
                }
                hashTable[key] = temp;
            }
        }
        for(int i = 0; i < len; i++)
        {
            int key = 0 - nums[i];
            vector<vector<int>> temp = hashTable[key];
            for(int j = 0; j < temp.size(); j += 2)
            {
                if(temp[j + 1][0] != i && temp[j + 1][1] != i)
                {
                    temp[j].push_back(nums[i]);
                    ans.push_back(temp[j]);
                }
            }
        }
        for(int i = 0; i < ans.size(); i++)
        {
            vector<int> temp = ans[i];
            for(int j = 0; j < temp.size() - 1; j++)
            {
                if(temp[j] > temp[j + 1])
                {
                    int tempnum = temp[j];
                    temp[j] = temp[j + 1];
                    temp[j + 1] = tempnum;
                }
            }
            if(temp[0] > temp[1])
            {
                int tempnum = temp[0];
                temp[0] = temp[1];
                temp[1] = tempnum;
            }
            ans[i] = temp;
        }
        int x = 0;
        while(x != ans.size())
        {
            vector<int> temp = ans[x];
            for(int i = x + 1; i < ans.size(); i++)
            {
                if(temp[0] == ans[i][0] && temp[1] == ans[i][1] && temp[2] == ans[i][2])
                {
                    ans.erase(ans.begin() + i);
                    i--;
                }
            }
            x++;
        } 



        return ans;
    }
};





//双指针
//184ms 14.69% 41.84Mb 5.01%
class Solution2 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums);
        int len = nums.size();
        vector<vector<int>> ans;
        if(len < 3)
        {
            return ans;
        }
        int right = 0, left = len - 1;
        for(int i = 0; i < len; i++)
        {
            left = i + 1;
            right = len - 1;
            if(i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            while(left < right)
            {
                int he = nums[right] + nums[left] + nums[i];
                if(he == 0)
                {
                    vector<int> temp = {nums[i],nums[left],nums[right]};
                    ans.push_back(temp);
                     left++;
                    while(nums[left] == nums[left - 1])
                    {
                        left++;
                    }
                }else{
                    if(he >= 0)
                    {
                        right--;
                        while(nums[right] == nums[right + 1])
                        {
                            right--;
                            if(right < 0)
                            {
                                right = 0;
                                break;
                            }
                        }
                    }else{
                        left++;
                        while(nums[left] == nums[left - 1])
                        {
                            left++;
                        }
                    }
                }
            }
        }
        return ans;
    }
    //归并排序
    void sort(vector<int>& nums)
    {
        mergeSort(nums,0,nums.size() - 1);
    }

    void mergeSort(vector<int>& nums, int left, int right)
    {   
        if(left >= right)
        {
            return;
        }

        int mid = (left + right) / 2;
        mergeSort(nums,left,mid);
        mergeSort(nums,mid + 1, right);
        merge(nums, left, mid,right);
    }

    void merge(vector<int>& nums, int left,int mid, int right)
    {
        vector<int> temp;
        int leftdex = left,midex= mid + 1;
        while(leftdex <= mid && midex <= right)
        {
            if(nums[leftdex] <= nums[midex])
            {
                temp.push_back(nums[leftdex]);
                leftdex++;
            }else{
                temp.push_back(nums[midex]);
                midex++;
            }
        }
        if(leftdex <= mid)
        {
            while(leftdex <= mid)
            {
            temp.push_back(nums[leftdex]);
                leftdex++;
            }
        }
        else if(midex <= right)
        {
            while(midex <= right)
            {
            temp.push_back(nums[midex]);
                midex++;
            }
        }
        for(int i = left; i <= right; i++)
        {
            nums[i] = temp[i - left];
        }
    }
};


class Solution3 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //sort(nums.begin(), nums.end());
        int len = nums.size();
        vector<vector<int>> ans;
        if(len < 3)
        {
            return ans;
        }
        int right, left;
        for(int i = 0; i < len; i++)
        {
            left = i + 1;
            right = len - 1;
            if(i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            while(left < right)
            {
                int he = nums[right] + nums[left] + nums[i];
                if(he == 0)
                {
                    vector<int> temp = {nums[i],nums[left],nums[right]};
                    ans.push_back(temp);
                     left++;
                    if(nums[left] == nums[left - 1])
                    {
                        left++;
                    }
                }else{
                    if(he >= 0)
                    {
                        right--;
                        while(nums[right] == nums[right + 1])
                        {
                            right--;
                           if(nums[right] == nums[right + 1])
                    {
                        right--;
                    }
                        }
                    }else{
                        left++;
                        if(nums[left] == nums[left - 1])
                    {
                        left++;
                    }
                    }
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution2 s2;
    vector<int> nums = {0,0,0,0};
    vector<vector<int>> ans = s2.threeSum(nums);
    cout<<"{";
    for(int i = 0; i < ans.size(); i++)
    {
        int num1 = ans[i][0];
        int num2 = ans[i][1];
        int num3 = ans[i][2];
        cout<<"[" << num1 << "," << num2 << "," << num3 << "] ,";
        
    }
    cout<<"}";

    return 0;
}