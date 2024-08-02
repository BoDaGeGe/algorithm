//110.ƽ�������
//������Ŀ����(opens new window)
//
//����һ�����������ж����Ƿ��Ǹ߶�ƽ��Ķ�������
//
//�����У�һ�ø߶�ƽ�����������Ϊ��һ��������ÿ���ڵ� ���������������ĸ߶Ȳ�ľ���ֵ������1��
//
//ʾ�� 1:
//	����������[3, 9, 20, null, null, 15, 7]
//	���� true ��
//
//ʾ�� 2 :
//	����������[1, 2, 2, 3, 3, null, null, 4, 4]
//	���� false ��

using namespace std;

typedef struct TreeNode
{
	int val;
	Node* lChild;
	Node* rChild;
}Node;

class Solution
{
public:
	int getHeight(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}

		int leftHeight = getHeight(root->lChild);
		if (leftHeight == -1)
		{
			return -1;
		}
		int rightHeight = getHeight(root->rChild);
		if (rightHeight == -1)
		{
			return -1;
		}

		return abs(leftHeight - rightHeight) > 1 ? -1 : 1 + max(leftHeight, rightHeight);
	}

	bool isBanlanced(Node* node)
	{
		return getHeight(node) == -1 ? false : true;
	}
};