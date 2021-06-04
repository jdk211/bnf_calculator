#pragma once
#include<iostream>
#include<string>
// ��� ���Ͽ� ��� �����ϴ°� �ٸ� Ŭ������ �� Ŭ������ �����Ҷ� ������� �����ϹǷ� ������ ( ������ )
// "" -> �ڽ��� ���� Ŭ���� <> -> ǥ�ض��̺귯�� Ŭ����

using namespace std;

class calculator
{
public:
	//�����ڸ� ��� ���Ҷ��� ���� ���� ���ص� �ȴ�.
	//������ �Ҹ��ڰ� ���� ȣ��Ǵ��� test ��¹�
	calculator() { std::cout << "constructor" << std::endl; };
	~calculator() { std::cout << "destructor" << std::endl; };

	int evaluate(const string& exp) const; //���ϴ�
	//const �Լ��� none_const�Լ��� ��������.
	//call by value, call by reference ���� ���ϱ�....

private:
	int read_number(const string& expression, int& index) const;
	char read_add_operator(const string& exp, int& index) const;
	char read_mul_operator(const string& exp, int& index) const;
	int pri_exp(const string& exp, int& new_index)		  const;
	int mul_expression(const string& exp, int& new_index) const;
	int add_expression(const string& exp, int& new_index) const;
};

//������ �ִ°��� ���°� �ٲ�ٴ°�
//�Լ��� �ִ� Ŭ������ �������̽��� �θ���
//
class A
{
	int aa(int b)
	{
		return a += b;
	};

	int a = 0;
};

//calculator1�� calculator2 ������
//�����ڿ��� parameter�� �޴��� ����
//��ü�� �������ڸ��� ���� �޾� ó���ϰ� �ѹ��� ���
class calculator1
{
public:
	calculator1() {};
	~calculator1() {};

	int evaluate(const string& exp) const {};
};

class calculator2
{
public:
	calculator2(const string& exp) {};
	~calculator2() {};

	int evaluate(const string& exp) const {};
};