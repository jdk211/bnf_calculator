#include "calculator.h"
#include<iostream>
#include<cassert>

int calculator::evaluate(const string& exp) const
{
    int index = 0;
	return add_expression(exp, index);
}

int calculator::read_number(const string& expression, int& index) const
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

char calculator::read_add_operator(const string& exp, int& index) const
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

char calculator::read_mul_operator(const string& exp, int& index) const
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

int calculator::pri_exp(const string& exp, int& new_index) const
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

int calculator::mul_expression(const string& exp, int& new_index) const
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

int calculator::add_expression(const string& exp, int& new_index) const
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