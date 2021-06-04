#pragma once
#include<iostream>
#include<string>
// 헤더 파일에 헤더 선언하는건 다른 클래스가 이 클래스를 참조할때 헤더까지 참조하므로 안좋다 ( 느려짐 )
// "" -> 자신이 만든 클래스 <> -> 표준라이브러리 클래스

using namespace std;

class calculator
{
public:
	//생성자를 사용 안할때는 굳이 선언 안해도 된다.
	//생성자 소멸자가 언제 호출되는지 test 출력문
	calculator() { std::cout << "constructor" << std::endl; };
	~calculator() { std::cout << "destructor" << std::endl; };

	int evaluate(const string& exp) const; //평가하다
	//const 함수에 none_const함수는 쓸수없다.
	//call by value, call by reference 구분 잘하기....

private:
	int read_number(const string& expression, int& index) const;
	char read_add_operator(const string& exp, int& index) const;
	char read_mul_operator(const string& exp, int& index) const;
	int pri_exp(const string& exp, int& new_index)		  const;
	int mul_expression(const string& exp, int& new_index) const;
	int add_expression(const string& exp, int& new_index) const;
};

//변수가 있는것은 상태가 바뀐다는것
//함수만 있는 클래스를 인터페이스라 부른다
//
class A
{
	int aa(int b)
	{
		return a += b;
	};

	int a = 0;
};

//calculator1과 calculator2 차이점
//생성자에서 parameter를 받는지 차이
//객체를 생성하자마자 값을 받아 처리하고 한번만 사용
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