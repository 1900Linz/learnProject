
#include <iostream>
#include <vector>
#include <algorithm>

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

