//222.��ȫ�������Ľڵ����
//������Ŀ����(opens new window)
//
//����һ����ȫ����������������Ľڵ������
//
//ʾ�� 1��
//
//���룺root = [1, 2, 3, 4, 5, 6]
//�����6
//ʾ�� 2��
//
//���룺root = []
//�����0
//ʾ�� 3��
//
//���룺root = [1]
//�����1
//��ʾ��
//
//���нڵ����Ŀ��Χ��[0, 5 * 10 ^ 4]
//0 <= Node.val <= 5 * 10 ^ 4
//��Ŀ���ݱ�֤��������� ��ȫ������

#include <queue>

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
	int countNodes(Node* root)
	{
		queue<Node*> que;

		if (nullptr != root)
		{
			que.push(root);
		}

		int result = 0;
		while (!que.empty())
		{
			int size = que.size();
			for (int i = 0; i < size; i++)
			{
				Node* node = que.front();
				que.pop();
				result++;
				if (node->lChild)
				{
					que.push(node);
				}
				if (node->rChild)
				{
					que.push(node);
				}
			}

		}

		return result;
	}
};