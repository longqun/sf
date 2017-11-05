// stack.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "stack.h"
#include "iostream"
#include "string"
using namespace std;
void convert(Stack<char>&, int64_t n, int base);

float evaluate(char * s, string & rpn);

void convertRecurse(Stack<char>&, int64_t n, int base);


static char digit[] = { '0','1','2' ,'3' ,'4' ,'5' ,'6' ,'7' ,'8' ,'9' ,'A' ,'B' ,'C' ,'D' ,'E' ,'F' };
void convertRecurse(Stack<char>&s, int64_t n, int base)
{
	if (n == 0)
	{
		return;
	}
	s.push(digit[n%base]);
	convert(s, n / base, base);
}

void convert(Stack<char>&s, int64_t n, int base)
{
	while (n > 0)
	{
		s.push(digit[n%base]);
		n /= base;
	}
}

#define N_OPTR 9 //���������
typedef enum { ADD, SUB, MUL, DIV, POW, FAC, L_P, R_P, EOE } Operator; //���������
																	   //�ӡ������ˡ������˷����׳ˡ������š������š���ʼ������ֹ��

const char pri[N_OPTR][N_OPTR] = { //��������ȵȼ� [ջ��] [��ǰ]
								   /*              |-------------------- �� ǰ �� �� �� --------------------| */
								   /*              +      -      *      /      ^      !      (      )      \0 */
	/* --  + */    '>',   '>',   '<',   '<',   '<',   '<',   '<',   '>',   '>',
	/* |   - */    '>',   '>',   '<',   '<',   '<',   '<',   '<',   '>',   '>',
	/* ջ  * */    '>',   '>',   '>',   '>',   '<',   '<',   '<',   '>',   '>',
	/* ��  / */    '>',   '>',   '>',   '>',   '<',   '<',   '<',   '>',   '>',
	/* ��  ^ */    '>',   '>',   '>',   '>',   '>',   '<',   '<',   '>',   '>',
	/* ��  ! */    '>',   '>',   '>',   '>',   '>',   '>',   ' ',   '>',   '>',
	/* ��  ( */    '<',   '<',   '<',   '<',   '<',   '<',   '<',   '=',   ' ',
	/* |   ) */    ' ',   ' ',   ' ',   ' ',   ' ',   ' ',   ' ',   ' ',   ' ',
	/* -- \0 */    '<',   '<',   '<',   '<',   '<',   '<',   '<',   ' ',   '='
};

void readNumber(char*&s, Stack<float>&stk)
{
	stk.push((float)(*s - '0'));
	while (isdigit(*(++s)))
	{
		stk.push(stk.pop() * 10 + *s - '0');
	}
	if ('.' != *s)
		return;
	float fraction = 1;
	while (isdigit(*(++s)))
	{
		stk.push(stk.pop() + (*s - '0')*(fraction /= 10));
	}
}

char optr2rank(char op) { //�������ת������
	switch (op) {
	case '+': return ADD; //��
	case '-': return SUB; //��
	case '*': return MUL; //��
	case '/': return DIV; //��
	case '^': return POW; //�˷�
	case '!': return FAC; //�׳�
	case '(': return L_P; //������
	case ')': return R_P; //������
	case '\0': return EOE; //��ʼ������ֹ��
	default: exit(-1); //δ֪�����
	}
}

char orderBetween(char opt, char character)
{
	return pri[optr2rank(opt)][optr2rank(character)];
}


__int64 facI(int n) { __int64 f = 1; while (n > 1) f *= n--; return f; } //�׳����㣨�����棩

float calcu(char op, float b) { //ִ��һԪ����
	switch (op) {
	case '!': return (float)facI((int)b); //Ŀǰ���н׳ˣ����մ˷�ʽ���
	default: exit(-1);
	}
}

float calcu(char op, float a, float b) { //ִ��2Ԫ����
	switch (op)
	{
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a*b;
	case '/':
		return a / b;
	case '^':
		return pow(a, b);
	default:
		exit(-1);
	}
}



float evaluate(char *s, string& rpn)
{
	Stack<float> opnd;
	Stack<char>optr;
	optr.push('\0');
	while (!optr.empty())
	{
		if (isdigit(*s))
		{
			readNumber(s, opnd);
			rpn += to_string((int)opnd.top());//float is not translate well this should be replace;
		}
		else
		{
			switch (orderBetween(optr.top(), *s))
			{
			case '<':
				optr.push(*s);
				s++;
				break;
			case '=':
				optr.pop();
				s++;
				break;
			case '>':
			{

				char op = optr.pop();
				rpn += op;
				if ('!' == op)
				{
					float cac = opnd.pop();
					opnd.push(calcu(op, cac));
				}
				else
				{
					float num1 = opnd.pop();
					float num2 = opnd.pop();
					opnd.push(calcu(op, num1, num2));
				}
			}
			break;
			default:
				exit(-1);
			}
		}
	}
	return opnd.pop();
}

int main()
{
	char *str = "1+2*3+(4+5)*3";
	char *buf = new char[strnlen_s(str, 256) + 1];
	memcpy_s(buf, strnlen_s(str, 256) + 1, str, strnlen_s(str, 256) + 1);
	string rpn;
	cout << evaluate(buf, rpn);
	cout << endl;
	cout << rpn;
	return 0;
}