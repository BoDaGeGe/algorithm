//222.完全二叉树的节点个数
//力扣题目链接(opens new window)
//
//给出一个完全二叉树，求出该树的节点个数。
//
//示例 1：
//
//输入：root = [1, 2, 3, 4, 5, 6]
//输出：6
//示例 2：
//
//输入：root = []
//输出：0
//示例 3：
//
//输入：root = [1]
//输出：1
//提示：
//
//树中节点的数目范围是[0, 5 * 10 ^ 4]
//0 <= Node.val <= 5 * 10 ^ 4
//题目数据保证输入的树是 完全二叉树

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