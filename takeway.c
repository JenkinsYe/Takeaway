/*
    版权所有:仅供蓝田5033寝室拿外卖之用
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct {
	int total;
	int key;
}person;

const Ye_key = 19;
const Liu_key = 19;
const Zhang_key = 20;
const Fang_key = 22;

const last = 2;
/* 本次不用拿：暂无*/
void Initialize(int key, person array[]);
int Calculate(int key, person array[]);
void Out(person array[]);
void nameout(int key);

const high = 27;
const low = 14;

int num;
int main(void)
{
	int key;
	person B_5033[5];
	int Compare[5];
	for (int i = 1; i <= 4; i++) {
		Compare[i] = 0;
		B_5033[i].key = 0;
	}
	printf("请先查看本次有无跳过的人\n请输入参与的总人数：\n");
	scanf_s("%d", &num);
    srand(time(0));
	for (int i = 0; i < num; i++)
	{
		printf("请输入数字:\n1.叶老板\n2.刘老板\n3.张老板\n4.方老板\n");
		scanf_s("%d", &key);
		Initialize(key, B_5033);
		Compare[key] = Calculate(key, B_5033);
	}
	Out(B_5033);
	system("pause");
}

void Initialize(int key, person array[])
{
	if (key == 1) {
		array[key].key = Ye_key;
		array[key].total = 0;
	}
	else if (key == 2) {
		array[key].key = Liu_key;
		array[key].total = 0;
	}
	else if (key == 3) {
		array[key].key = Zhang_key;
		array[key].total = 0;
	}
	else if (key == 4)
	{
		array[key].key = Fang_key;
		array[key].total = 0;
	}
	else printf("无效的输入!\n");
}

int Calculate(int key, person array[])
{
	int a;
	for (int i = 1; i <= array[key].key; i++)
	{		
		a = rand() % 9;
            printf("第%d个随机数   %d\n", i, a);
		    array[key].total += a;
	}
	nameout(key);
	printf("总共随机和:    %d\n", array[key].total);
	return array[key].total;
}

void Out(person array[])
{
	int min = 1000000;
	int key;
	for (int i = 1; i <= 4; i++)
	{
		if (array[i].key != 0)
		{
			if (array[i].total < min)
			{
				min = array[i].total;
				key = i;
			}
		}
	}
	printf("最小的是");
	nameout(key);
	printf("\n");
	for (int i = 1; i <= 4; i++)
	{
		if (array[i].key != 0)
		{
			nameout(i);
			if (i == key)
			{
				printf("key值修改为%d\n", array[i].key + num - 1);
			}
			else printf("key值修改为%d\n",array[i].key - 1);
		}
	}
	if (key == last)
	{
		nameout(key);
		printf("已经连续拿了两次\n");
		printf("请修改last为0，并记录下次不用拿的人\n");
	}
	else if (key != last)
	{
		printf("last应当修改为:%d\n",key);
	}
}

void nameout(int key)
{
	if (key == 1) printf("叶老板");
	else if (key == 2) printf("刘老板");
	else if (key == 3) printf("张老板");
	else printf("方老板");
}