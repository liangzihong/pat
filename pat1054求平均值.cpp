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

int effect(char a[]) // 判断数字是否合法
{
	int dot = 0, i = 0, n1 = 0, n2 = 0;
	if (a[0] == '-') i = 1; // 如果开头有负号跳过
	for (; a[i] != '\0'; i++) {
		if ((a[i] < 48 || 57 < a[i]) && a[i] != '.') return 0; // 存在数字和'.'以外的字符则不合法
		if (dot == 1 && a[i] == '.') return 0; // dot为1表示出现过'.'，再出现的'.'导致数字不合法
		if (dot > 0) n1++; // n1表示小数部分位数
		if (a[i] == '.') dot = 1; // 出现了'.'就将dot标记置为1
		if (dot == 0) n2++; // n2表示整数部分位数
	}
	if (n1 > 2) return 0; // 小数部分多于两位不合法
	if (atof(a) < -1000.0 || atof(a) > 1000.0) return 0; // atof将字符串转换为浮点数，并判断范围是否合法

	return 1;
}

int main()
{
	int n, cnt = 0;
	double sum = 0.0f, v;
	char tmp[101] = { 0 };
	scanf("%d", &n); // 读入数据个数n
	for (int i = 0; i < n; i++) { // 循环读取数据的同时，判断是否合法，并输出错误信息
		scanf("%s", tmp);
		if (effect(tmp))
			sum += atof(tmp), cnt++;
		else printf("ERROR: %s is not a legal number\n", tmp); // 输出错误信息
	}
	v = sum / cnt;
	printf("The average of %d number", cnt);
	if (cnt == 0) printf("s is Undefined\n"); // 根据有效数据个数分类输出平均数
	if (cnt == 1) printf(" is %.2f\n", v);
	if (cnt >= 2) printf("s is %.2f\n", v);

	return 0;
}