//
//��454��.�������II
//������Ŀ����(opens new window)
//
//�����ĸ����������������б� A, B, C, D, �����ж��ٸ�Ԫ��(i, j, k, l) ��ʹ�� A[i] + B[j] + C[k] + D[l] = 0��
//
//Ϊ��ʹ����򵥻������е� A, B, C, D ������ͬ�ĳ��� N���� 0 �� N �� 500 �����������ķ�Χ�� - 2 ^ 28 �� 2 ^ 28 - 1 ֮�䣬���ս�����ᳬ�� 2 ^ 31 - 1 ��
//
//���� :
//
//����:
//
//A = [1, 2]
//B = [-2, -1]
//C = [-1, 2]
//D = [0, 2]
//��� :
//
//	2
//
//	���� :
//
//	����Ԫ������ :
//
//	(0, 0, 0, 1)->A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
//	(1, 1, 0, 0)->A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0


#include <vector>
#include <unordered_map>

using namespace std;

int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D)
{
	unordered_map<int, int> umap;
	for (int a : A)
	{
		for (int b : B)
		{
			umap[a + b]++;
		}
	}

	int count = 0;
	for (int c : C)
	{
		for (int d : D)
		{
			if (umap.find(0 - (c + d)) != umap.end())
			{
				count += umap[0 - (c + d)];
			}
		}
	}

	return count;
}


