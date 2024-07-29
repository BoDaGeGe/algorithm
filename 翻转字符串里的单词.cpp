//151.��ת�ַ�����ĵ���
//������Ŀ����(opens new window)
//
//����һ���ַ����������ת�ַ����е�ÿ�����ʡ�
//
//ʾ�� 1��
//���� : "the sky is blue"
//��� : "blue is sky the"
//
//ʾ�� 2��
//���� : "  hello world!  "
//��� : "world! hello"
//���� : �����ַ���������ǰ����ߺ����������Ŀո񣬵��Ƿ�ת����ַ����ܰ�����
//
//ʾ�� 3��
//���� : "a good   example"
//��� : "example good a"
//���� : ����������ʼ��ж���Ŀո񣬽���ת�󵥴ʼ�Ŀո���ٵ�ֻ��һ����





#include <string>

using namespace std;

class Solution
{
public:
	// ��ת�ַ���
	void reverse(string& s, int start, int end)
	{
		for (int i = start, j = end; i < j; i++, j--)
		{
			swap(s[i], s[j]);
		}
	}

	// ȥ������ո�
	void removeExtraSpaces(string& s)
	{
		int slow = 0;
		for (int i = 0; i < s.size(); ++i)
		{
			if (' ' != s[i])     // �ո񲻴���  ֱ�Ӹ�����
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

