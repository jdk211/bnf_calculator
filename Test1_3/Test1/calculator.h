#pragma once
#include<iostream>
#include<string>
#include<string_view>

using namespace std;

class ExpressionBuffer
{
public:
	ExpressionBuffer(string_view expression)
		: index(0)
		, exp(expression)
	{
		//������ �ʱ�ȭ ����
		//�� �տ� �ٴ°Ͱ� �ڿ� �ٴ°��� ����
		//����ó���� ����...
		//�ϴ� �տ� ������ �������� �ʱ�ȭ ������ ������ ���� ���ϰ� ����ó�� �߻�
		//���� �ȿ��� �ʱ�ȭ �� ������ ���� ���� �Ŀ� ����ó�� �߻�
	};

	char Peek() const { return exp[index]; }
	char Next() { return exp[index++]; }
	bool IsEnd() const { return index == exp.length(); }

private:
	string exp;
	int index;
};

class calculator
{
public:
	calculator() { std::cout << "constructor" << std::endl; };
	~calculator() { std::cout << "destructor" << std::endl; };

	float evaluate(string_view exp) const; //���ϴ�
	
private:
	float read_number(ExpressionBuffer& exp)		const;
	char  read_add_operator(ExpressionBuffer& exp)	const;
	char  read_mul_operator(ExpressionBuffer& exp)	const;
	float pri_exp(ExpressionBuffer& exp)			const;
	float mul_expression(ExpressionBuffer& exp)		const;
	float add_expression(ExpressionBuffer& exp)		const;
};

class A
{
	int aa(int b)
	{
		return a += b;
	};

	int a = 0;
};
