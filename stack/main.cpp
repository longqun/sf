// stack.cpp : 定义控制台应用程序的入口点。
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

#define N_OPTR 9 //运算符总数
typedef enum { ADD, SUB, MUL, DIV, POW, FAC, L_P, R_P, EOE } Operator; //运算符集合
																	   //加、减、乘、除、乘方、阶乘、左括号、右括号、起始符与终止符

const char pri[N_OPTR][N_OPTR] = { //运算符优先等级 [栈顶] [当前]
								   /*              |-------------------- 当 前 运 算 符 --------------------| */
								   /*              +      -      *      /      ^      !      (      )      \0 */
	/* --  + */    '>',   '>',   '<',   '<',   '<',   '<',   '<',   '>',   '>',
	/* |   - */    '>',   '>',   '<',   '<',   '<',   '<',   '<',   '>',   '>',
	/* 栈  * */    '>',   '>',   '>',   '>',   '<',   '<',   '<',   '>',   '>',
	/* 顶  / */    '>',   '>',   '>',   '>',   '<',   '<',   '<',   '>',   '>',
	/* 运  ^ */    '>',   '>',   '>',   '>',   '>',   '<',   '<',   '>',   '>',
	/* 算  ! */    '>',   '>',   '>',   '>',   '>',   '>',   ' ',   '>',   '>',
	/* 符  ( */    '<',   '<',   '<',   '<',   '<',   '<',   '<',   '=',   ' ',
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

char optr2rank(char op) { //由运算符转译出编号
	switch (op) {
	case '+': return ADD; //加
	case '-': return SUB; //减
	case '*': return MUL; //乘
	case '/': return DIV; //除
	case '^': return POW; //乘方
	case '!': return FAC; //阶乘
	case '(': return L_P; //左括号
	case ')': return R_P; //右括号
	case '\0': return EOE; //起始符与终止符
	default: exit(-1); //未知运算符
	}
}

char orderBetween(char opt, char character)
{
	return pri[optr2rank(opt)][optr2rank(character)];
}


__int64 facI(int n) { __int64 f = 1; while (n > 1) f *= n--; return f; } //阶乘运算（迭代版）

float calcu(char op, float b) { //执行一元运算
	switch (op) {
	case '!': return (float)facI((int)b); //目前仅有阶乘，可照此方式添加
	default: exit(-1);
	}
}

float calcu(char op, float a, float b) { //执行2元运算
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