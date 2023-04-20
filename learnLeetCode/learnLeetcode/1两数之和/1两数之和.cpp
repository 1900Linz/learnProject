
#include <iostream>
#include <vector>
#include <algorithm>


//基础题解
//力扣中国原题地址：https://leetcode.cn/problems/two-sum/
//小镇做题迦博客传送门：https://blog.csdn.net/wellwillw?type=blog
//本文链接：https://blog.csdn.net/wellwillw/article/details/130223674?spm=1001.2014.3001.5502

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int sum = nums.size();
        int headptr{};
        int endPtr{ sum - 1};
        int num1{};
        int num2{};

        std::sort(nums.begin(), nums.end());

        while (headptr != (sum - 1) || endPtr/* != 0*/) {

            num1 = nums[headptr];
            num2 = nums[endPtr];

            if (num2 > target)
            {
                endPtr--;
            }
            else if (num1 + num2 > target)
            {
                endPtr--;
            }
            else if (num1 + num2 < target)
            {
                headptr++;
            }
            else if (num1 + num2 == target)
            {
                break;
            }

        }

        return vector<int> { headptr, sum - endPtr - 1};
    }
};

int main()
{
    Solution s;
    vector<int> source{2, 7, 11, 15};

    auto result = s.twoSum(source,9);

    for (auto index : result)
    {
        std::cout << index;
    }
}

