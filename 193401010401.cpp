#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;
struct stu
{
	int number;
	char name[10];
	float chengji[4];
	float a[4];
	float jidian;
	float zongce;
}str[50];
int main()
{
	struct stu t;
	int i,n,j,k=0;
	float GPA(struct stu str, int n);//绩点
	float CIT(struct stu str);//综测
	void f3(struct stu str);//输出按照综测成绩由高到低排序的学生成绩
	printf("请输入需要统计的学生数量：");
	cin >> n;
	printf("\n");
	printf("请依次输入学生的学号、姓名、马原、英语、组原与数据结构成绩（空格隔开）\n");
	for (i = 0; i < n; i++)
	{
		cin >> str[i].number >> str[i].name;
		for (j = 0; j < 4; j++)
		{
			cin >> str[i].chengji[j];
		}
		for (j = 0; j < 4; j++)
		{
			str[i].a[j] = 0;
		}
		str[i].jidian = 0;
		str[i].zongce = 0;
	}
	for (i = 0; i < n; i++)//绩点
	{
		str[i].jidian=GPA(str[i], n);
	}
	for (i = 0; i < n; i++)//综测
	{
		str[i].zongce=CIT(str[i]);
	}
	for (i = 0; i < n-1; i++)
	{
		for (j = 1; j < n; j++)
		{
			if (str[i].zongce < str[j].zongce)
			{
				t = str[i];
				str[i] = str[j];
				str[j] = t;
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		f3(str[i]);
	}
	if (str[0].jidian > 5.99)
	{
		k = 1;
		printf("一等奖学金：%d %s %.0f %.0f %.0f %.0f %.2f %.2f", str[0].number, str[0].name, str[0].chengji[0], str[0].chengji[1], str[0].chengji[2], str[0].chengji[3], str[0].jidian, str[0].zongce);
	}
	else
		printf("无");
	printf("\n");
	if (k == 1 && n > 1)
	{
		printf("二等奖学金：");
		for (i = 1; i < 4; i++)
		{
			if (str[i].jidian > 5.99)
			{
				k++;
				printf("二等奖学金：%d %s %.0f %.0f %.0f %.0f %.2f %.2f", str[i].number, str[i].name, str[i].chengji[0], str[i].chengji[1], str[i].chengji[2], str[i].chengji[3], str[i].jidian, str[i].zongce);
			}
		}
		if (k == 1)
			printf("无");
	}
	printf("\n");
	if (k == 4 && n >= 10)
	{
		printf("三等奖学金：");
		for (i = 4; i < 10; i++)
		{
			if (str[i].jidian > 5.99)
			{
				k++;
				printf("三等奖学金：%d %s %.0f %.0f %.0f %.0f %.2f %.2f", str[i].number, str[i].name, str[i].chengji[0], str[i].chengji[1], str[i].chengji[2], str[i].chengji[3], str[i].jidian, str[i].zongce);
			}
		}
		if (k == 4)
			printf("无");
	}
	system("pause");
	return 0;
}
float GPA(struct stu str,int n)
{
	int b[4] = { 5,6,4,3 };
	float sum = 0;
	int i,j;
	for (i = 0; i < 4; i++)
	{
		if (str.chengji[i] < 60)
			str.a[i] = 0;
		else if (str.chengji[i] == 60)
			str.a[i] = 2;
		else
			str.a[i] = (str.chengji[i] - 60) * 0.2;
	}
	for (j = 0; j < 4; j++)
	{
		sum = sum + str.a[j] * b[j];
	}
	str.jidian = sum / 18.0;
	return str.jidian;
}
float CIT(struct stu str)
{
	str.zongce = 100 * 0.25 + (50 + str.jidian * 5) * 0.75;
	return str.zongce;
}
void f3(struct stu str)
{
	int i;
	printf("学号      姓名     马原成绩       英语成绩       组原成绩       数据结构成绩      绩点      综测   \n");
	printf("%d          %s       ", str.number, str.name);
	for (i = 0; i < 4; i++)
	{
		printf("%.0f             ", str.chengji[i]);
	}
	printf("%.2f       ", str.jidian);
	printf("%.2f\n", str.zongce);
}