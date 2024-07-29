//第18题.四数之和
//力扣题目链接(opens new window)
//
//题意：给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。
//
//注意：
//
//答案中不可以包含重复的四元组。
//
//示例： 给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。 满足要求的四元组集合为： [[-1, 0, 0, 1], [-2, -1, 1, 2], [-2, 0, 0, 2]]



#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target)
{
	vector<vector<int>> result;
	int nums_size = nums.size();
	sort(nums.begin(), nums.end());
	for (int k = 0; k < nums_size; k++)
	{
		// 剪枝处理
		if (nums[k] > target && nums[k] >= 0)
		{
			break;
		}

		// 对 nums 去重
		if (nums[k] == nums[k - 1])
		{
			continue;
		}

		for (int i = k + 1; i < nums_size; i++)
		{
			// 2级剪枝处理
			if (nums[i] + nums[k] > target && nums[i] + nums[k] > 0)
			{
				break;
			}

			// 对 nums[i] 去重
			if (i > k + 1 && nums[i] == nums[i - 1])
			{
				continue;
			}

			int left = i + 1;
			int right = nums_size - 1;

			while (left < right)
			{
				if ((long)nums[k] + nums[i] + nums[left] + nums[right] > target)
				{
					right--;
				}
				else if ((long)nums[k] + nums[i] + nums[left] + nums[right] < target)
				{
					left++;
				}
				else
				{
					result.push_back(vector<int>{ nums[k], nums[i], nums[left], nums[right] });
					while (right > left && nums[right - 1] == nums[right])
					{
						right--;
					}
					while (right > left && nums[left + 1] == nums[left])
					{
						left++;
					}
				}

			}
		}
	}

	return result;
}