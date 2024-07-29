//��18��.����֮��
//������Ŀ����(opens new window)
//
//���⣺����һ������ n ������������ nums ��һ��Ŀ��ֵ target���ж� nums ���Ƿ�����ĸ�Ԫ�� a��b��c �� d ��ʹ�� a + b + c + d ��ֵ�� target ��ȣ��ҳ��������������Ҳ��ظ�����Ԫ�顣
//
//ע�⣺
//
//���в����԰����ظ�����Ԫ�顣
//
//ʾ���� �������� nums = [1, 0, -1, 0, -2, 2]���� target = 0�� ����Ҫ�����Ԫ�鼯��Ϊ�� [[-1, 0, 0, 1], [-2, -1, 1, 2], [-2, 0, 0, 2]]



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
		// ��֦����
		if (nums[k] > target && nums[k] >= 0)
		{
			break;
		}

		// �� nums ȥ��
		if (nums[k] == nums[k - 1])
		{
			continue;
		}

		for (int i = k + 1; i < nums_size; i++)
		{
			// 2����֦����
			if (nums[i] + nums[k] > target && nums[i] + nums[k] > 0)
			{
				break;
			}

			// �� nums[i] ȥ��
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