/*#include <cstdio>
#include<iostream>
#include <string.h>
using namespace std;
int main() {
	int n, cnt = 0;
	char a[50], b[50];
	double temp=2000, sum = 0.0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%s", a);
		sscanf(a, "%lf", &temp);
		sprintf(b, "%.2lf", temp);
		int flag = 0;
		for (int j = 0; j < strlen(a); j++) {
			if (a[j] != b[j]) flag = 1;
		}
		if (flag || temp < -1000 || temp > 1000) {
			printf("ERROR: %s is not a legal number\n", a);
			continue;
		}
		else {
			sum += temp;
			cnt++;
		}
	}
	if (cnt == 1) {
		printf("The average of 1 number is %.2lf", sum);
	}
	else if (cnt > 1) {
		printf("The average of %d numbers is %.2lf", cnt, sum / cnt);
	}
	else {
		printf("The average of 0 numbers is Undefined");
	}
	return 0;
}*/

#include <stdio.h>
#include <stdlib.h>

int effect(char a[]) // �ж������Ƿ�Ϸ�
{
	int dot = 0, i = 0, n1 = 0, n2 = 0;
	if (a[0] == '-') i = 1; // �����ͷ�и�������
	for (; a[i] != '\0'; i++) {
		if ((a[i] < 48 || 57 < a[i]) && a[i] != '.') return 0; // �������ֺ�'.'������ַ��򲻺Ϸ�
		if (dot == 1 && a[i] == '.') return 0; // dotΪ1��ʾ���ֹ�'.'���ٳ��ֵ�'.'�������ֲ��Ϸ�
		if (dot > 0) n1++; // n1��ʾС������λ��
		if (a[i] == '.') dot = 1; // ������'.'�ͽ�dot�����Ϊ1
		if (dot == 0) n2++; // n2��ʾ��������λ��
	}
	if (n1 > 2) return 0; // С�����ֶ�����λ���Ϸ�
	if (atof(a) < -1000.0 || atof(a) > 1000.0) return 0; // atof���ַ���ת��Ϊ�����������жϷ�Χ�Ƿ�Ϸ�

	return 1;
}

int main()
{
	int n, cnt = 0;
	double sum = 0.0f, v;
	char tmp[101] = { 0 };
	scanf("%d", &n); // �������ݸ���n
	for (int i = 0; i < n; i++) { // ѭ����ȡ���ݵ�ͬʱ���ж��Ƿ�Ϸ��������������Ϣ
		scanf("%s", tmp);
		if (effect(tmp))
			sum += atof(tmp), cnt++;
		else printf("ERROR: %s is not a legal number\n", tmp); // ���������Ϣ
	}
	v = sum / cnt;
	printf("The average of %d number", cnt);
	if (cnt == 0) printf("s is Undefined\n"); // ������Ч���ݸ����������ƽ����
	if (cnt == 1) printf(" is %.2f\n", v);
	if (cnt >= 2) printf("s is %.2f\n", v);

	return 0;
}