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
		//생성자 초기화 차이
		//블럭 앞에 붙는것과 뒤에 붙는것의 차이
		//예외처리와 관련...
		//일단 앞에 있으면 생성전에 초기화 에러가 있으면 생성 안하고 예외처리 발생
		//정의 안에서 초기화 중 에러가 나면 생성 후에 예외처리 발생
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

	float evaluate(string_view exp) const; //평가하다
	
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
