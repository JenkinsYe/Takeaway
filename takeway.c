/*
    ��Ȩ����:��������5033����������֮��
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
/* ���β����ã�����*/
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
	printf("���Ȳ鿴����������������\n������������������\n");
	scanf_s("%d", &num);
    srand(time(0));
	for (int i = 0; i < num; i++)
	{
		printf("����������:\n1.Ҷ�ϰ�\n2.���ϰ�\n3.���ϰ�\n4.���ϰ�\n");
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
	else printf("��Ч������!\n");
}

int Calculate(int key, person array[])
{
	int a;
	for (int i = 1; i <= array[key].key; i++)
	{		
		a = rand() % 9;
            printf("��%d�������   %d\n", i, a);
		    array[key].total += a;
	}
	nameout(key);
	printf("�ܹ������:    %d\n", array[key].total);
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
	printf("��С����");
	nameout(key);
	printf("\n");
	for (int i = 1; i <= 4; i++)
	{
		if (array[i].key != 0)
		{
			nameout(i);
			if (i == key)
			{
				printf("keyֵ�޸�Ϊ%d\n", array[i].key + num - 1);
			}
			else printf("keyֵ�޸�Ϊ%d\n",array[i].key - 1);
		}
	}
	if (key == last)
	{
		nameout(key);
		printf("�Ѿ�������������\n");
		printf("���޸�lastΪ0������¼�´β����õ���\n");
	}
	else if (key != last)
	{
		printf("lastӦ���޸�Ϊ:%d\n",key);
	}
}

void nameout(int key)
{
	if (key == 1) printf("Ҷ�ϰ�");
	else if (key == 2) printf("���ϰ�");
	else if (key == 3) printf("���ϰ�");
	else printf("���ϰ�");
}