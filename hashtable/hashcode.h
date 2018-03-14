#pragma once
#include <string.h>
static size_t hashCode(char c) { return (size_t)c; } //�ַ�
static size_t hashCode(int k) { return (size_t)k; } //�����Լ���������
static size_t hashCode(long long i) { return (size_t)((i >> 32) + (int)i); }
static size_t hashCode(char s[]) { //�����ַ�����ѭ����λɢ���루cyclic shift hash code��
	int h = 0; //ɢ����
	for (size_t n = strlen(s), i = 0; i < n; i++) //�������ң��������ÿһ�ַ�
	{
		h = (h << 5) | (h >> 27); h += (int)s[i];
	} //ɢ����ѭ������5λ�����ۼӵ�ǰ�ַ�
	return (size_t)h; //������õ�ɢ���룬ʵ���Ͽ�����Ϊ���Ƶġ�����ʽɢ���롱
} //����Ӣ�ﵥ�ʣ�"ѭ������5λ"��ʵ��ͳ�Ƶó������ֵ