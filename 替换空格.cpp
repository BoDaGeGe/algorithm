//题目：剑指Offer 05.替换空格
//力扣题目链接(opens new window)
//
//请实现一个函数，把字符串 s 中的每个空格替换成"%20"。
//
//示例 1： 输入：s = "We are happy."
//输出："We%20are%20happy."


#include <string>

using namespace std;

string replaceSpace(string s)
{
	int count = 0;
	int sOldSize = s.size();
	for (int i = 0; i < s.size(); i++)
	{
		if (' ' == s[i])
		{
			count++;
		}
	}

	// 扩充字符串s的大小  也就是每个字空格替换成"%20"之后的大小
	s.resize(s.size() + count * 2);
	int sNewSize = s.size();
	// 从后向前将空格替换成"%20"
	for (int i = sNewSize - 1, j = sOldSize - 1; j < i; i--, j--)
	{
		if (' ' != s[j])
		{
			s[i] = s[j];
		}
		else
		{
			s[i] = '0';
			s[i - 1] = '2';
			s[i - 2] = '%';
			i -= 2;
		}
	}
	return s;
}