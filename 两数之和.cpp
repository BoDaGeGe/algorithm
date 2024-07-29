
//1. ����֮��
//������Ŀ����(opens new window)
//
//����һ���������� nums ��һ��Ŀ��ֵ target�������ڸ��������ҳ���ΪĿ��ֵ���� ���� ���������������ǵ������±ꡣ
//
//����Լ���ÿ������ֻ���Ӧһ���𰸡����ǣ�������ͬһ��Ԫ�ز���ʹ�����顣
//
//ʾ�� :
//
//���� nums = [2, 7, 11, 15], target = 9
//
//��Ϊ nums[0] + nums[1] = 2 + 7 = 9
//
//���Է���[0, 1]


#include <vector>
#include <map>
#include <unordered_map>
#include <iterator>

using namespace std;

vector<int> twoSum(vector<int> nums, int target)
{
	unordered_map<int, int> map;
	int numsSize = nums.size();
	for (int i = 0; i < numsSize; i++)
	{
		if (map.find(target - nums[i]) != map.end())
		{
			return { target - nums[i], i };
		}

		map.insert(pair<int, int>(nums[i], i));
	}

	return {};
}