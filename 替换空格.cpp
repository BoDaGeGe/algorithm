//��Ŀ����ָOffer 05.�滻�ո�
//������Ŀ����(opens new window)
//
//��ʵ��һ�����������ַ��� s �е�ÿ���ո��滻��"%20"��
//
//ʾ�� 1�� ���룺s = "We are happy."
//�����"We%20are%20happy."


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

	// �����ַ���s�Ĵ�С  Ҳ����ÿ���ֿո��滻��"%20"֮��Ĵ�С
	s.resize(s.size() + count * 2);
	int sNewSize = s.size();
	// �Ӻ���ǰ���ո��滻��"%20"
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