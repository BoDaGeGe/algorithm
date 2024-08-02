//110.平衡二叉树
//力扣题目链接(opens new window)
//
//给定一个二叉树，判断它是否是高度平衡的二叉树。
//
//本题中，一棵高度平衡二叉树定义为：一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。
//
//示例 1:
//	给定二叉树[3, 9, 20, null, null, 15, 7]
//	返回 true 。
//
//示例 2 :
//	给定二叉树[1, 2, 2, 3, 3, null, null, 4, 4]
//	返回 false 。

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