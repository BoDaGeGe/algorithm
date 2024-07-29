//#��Ŀ����ָOffer58 - II.����ת�ַ���
//������Ŀ����(opens new window)
//
//�ַ���������ת�����ǰ��ַ���ǰ������ɸ��ַ�ת�Ƶ��ַ�����β�����붨��һ������ʵ���ַ�������ת�����Ĺ��ܡ����磬�����ַ���"abcdefg"������2���ú�������������ת��λ�õ��Ľ��"cdefgab"��
//
//ʾ�� 1��
//���� : s = "abcdefg", k = 2
//��� : "cdefgab"
//
//ʾ�� 2��
//���� : s = "lrloseumgh", k = 6
//��� : "umghlrlose"
//
//���ƣ�
//1 <= k < s.length <= 10000





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

	void reverse(string& s, int n)
	{
		reverse(s, s[0], s[n - 1]);
		reverse(s, s[n], s.size() - 1);
		reverse(s, s[0], s.size() - 1);
	}

};