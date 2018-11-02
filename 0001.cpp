/**********************************************/
一位学生（小于40岁）说“我的岁数的三次方是个四位数，四次方是个六位数。
要组成我岁数的三次方和四次方，需要用遍０～９十个数字。”请问他多少岁？
/*********************************************/
#include<iostream>
#include<string>
#include<map>
#include<cmath>
#include<sstream>
#include<vector>
using namespace std;

int main()
{
	char p[50] = { '\0' };
	vector<int> ans;
	for (int i = 1; i < 40; i++)
	{
		string s1, s2;
		int p3 = i * i*i;
		int p4 = p3 * i;
		sprintf(p, "%d", p3);
		s1 = p;
		sprintf(p, "%d", p4);
		s2 = p;
		if (s1.size() == 4 && s2.size() == 6)
		{
			s1 += s2;
			int x = 0x3FF;
			for (int j = 0; j < s1.size(); j++)
			{
				x = x ^ (1 << (s1[j] - '0'));
			}
			if (x == 0) ans.push_back(i);
		}
	}
	cout << ans[0];
	system("pause");
	return 0;
}
