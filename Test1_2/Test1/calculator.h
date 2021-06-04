#pragma once
#include<iostream>
#include<string>
#include<string_view>

using namespace std;

class calculator
{
public:
	calculator() { std::cout << "constructor" << std::endl; };
	~calculator() { std::cout << "destructor" << std::endl; };

	int evaluate(string_view exp) const; //평가하다
	
private:
	int read_number(string_view expression, int& index) const;
	char read_add_operator(string_view exp, int& index) const;
	char read_mul_operator(string_view exp, int& index) const;
	int pri_exp(string_view exp, int& new_index)		const;
	int mul_expression(string_view exp, int& new_index) const;
	int add_expression(string_view exp, int& new_index) const;
};

class A
{
	int aa(int b)
	{
		return a += b;
	};

	int a = 0;
};
