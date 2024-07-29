//151.翻转字符串里的单词
//力扣题目链接(opens new window)
//
//给定一个字符串，逐个翻转字符串中的每个单词。
//
//示例 1：
//输入 : "the sky is blue"
//输出 : "blue is sky the"
//
//示例 2：
//输入 : "  hello world!  "
//输出 : "world! hello"
//解释 : 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
//
//示例 3：
//输入 : "a good   example"
//输出 : "example good a"
//解释 : 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。





#include <string>

using namespace std;

class Solution
{
public:
	// 反转字符串
	void reverse(string& s, int start, int end)
	{
		for (int i = start, j = end; i < j; i++, j--)
		{
			swap(s[i], s[j]);
		}
	}

	// 去除多余空格
	void removeExtraSpaces(string& s)
	{
		int slow = 0;
		for (int i = 0; i < s.size(); ++i)
		{
			if (' ' != s[i])     // 空格不处理  直接搞后面的
			{
				if (0 != slow)
				{
					s[slow++] = ' ';
				}

				while (i < s.size() && s[i] != ' ')
				{
					s[slow++] = s[i++];
				}
			}
		}

		s.resize(slow);
	}

	string reverseWord(string s)
	{
		removeExtraSpaces(s);
		reverse(s, 0, s.size() - 1);

		int start = 0;
		for (int i = 0; i < s.size(); ++i)
		{
			if (i == s.size() || s[i] == ' ')
			{
				reverse(s, start, i - 1);
				start = i + 1;
			}
		}

		return s;
	}

};

