﻿// Test1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <cassert>

int add_expression(const char* exp, int& new_index);

int read_number(const char* expression, int& index)
{
    int number = 0;

    for (int i = index; expression[i] != NULL; i++)
    {
        if (isdigit(expression[i]))
        {
            number *= 10;
            number += expression[i] - '0';

            index++;
        }
        else
        {
            return number;
        }
    }

    return number;
}

char read_add_operator(const char* exp, int& index)
{
    switch (exp[index])
    {
    case '+':
    case '-':
        return exp[index++];
    default:
        return ' ';
    }
}

char read_mul_operator(const char* exp, int& index)
{
    switch (exp[index])
    {
    case '*':
    case '/':
        return exp[index++];
    default:
        return ' ';
    }
}

int pri_exp(const char* exp, int& new_index)
{
    if (exp[new_index] == '(')
    {
        int result = add_expression(exp, ++new_index);

        assert(exp[new_index++] == ')');

        return result;
    }
    else
    {
        return read_number(exp, new_index);
    }
}

int mul_expression(const char* exp, int& new_index)
{
    int num1 = 0;
    int num2 = 0;
    char op;

    int tmp_index = new_index;
    num1 = pri_exp(exp, new_index);
    if (tmp_index == new_index)
    {
        printf("syntex error at column : %d \n", new_index);
        return 0;
    }

    tmp_index = new_index;
    op = read_mul_operator(exp, new_index);
    if (tmp_index == new_index)
    {
        return num1;
    }

    
    tmp_index = new_index;
    num2 = mul_expression(exp, new_index);
    if (tmp_index == new_index)
    {
        printf("syntex error at column : %d \n", new_index);
        return 0;
    }


    int result = 0;
    switch (op)
    {
    case '*':
        result = num1 * num2;
        break;
    case '/':
        result = num1 / num2;
        break;
    }

    printf("%d %c %d \n", num1, op, num2);

    return result;
}

int add_expression(const char* exp, int& new_index)
{
    int num1 = 0;
    int num2 = 0;
    char op;

    int tmp_index = new_index;
    num1 = mul_expression(exp, new_index);
    if (tmp_index == new_index)
    {
        printf("syntex error at column : %d \n", new_index);
        return 0;
    }

    tmp_index = new_index;
    op = read_add_operator(exp, new_index);
    if (tmp_index == new_index)
    {
        return num1;
    }


    tmp_index = new_index;
    num2 = add_expression(exp, new_index);
    if (tmp_index == new_index)
    {
        printf("syntex error at column : %d \n", new_index);
        return 0;
    }


    int result = 0;
    switch (op)
    {
    case '+':
        result = num1 + num2;
        break;
    case '-':
        result = num1 - num2;
        break;
    }

    printf("%d %c %d \n", num1, op, num2);

    return result;
}

int main()
{
    std::cout << "Hello World!\n";

    char exp[256];
    int index = 0;

    std::cin >> exp;

    printf("%s \n", exp);

    int result = add_expression(exp, index);

    printf("= %d \n", result);
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
