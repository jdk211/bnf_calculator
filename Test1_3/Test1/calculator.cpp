#include "calculator.h"
#include<iostream>
#include<cassert>

float calculator::evaluate(string_view exp_) const
{
    ExpressionBuffer exp(exp_);

	return add_expression(exp);
}

float calculator::read_number(ExpressionBuffer& exp) const
{
    float number = 0;

    while (!exp.IsEnd())
    {
        if (isdigit(exp.Peek()))
        {
            number *= 10;
            number += exp.Next() - '0';
        }
        else
        {
            return number;
        }
    }

    return number;
}

char calculator::read_add_operator(ExpressionBuffer& expression) const
{
    switch (expression.Peek())
    {
    case '+':
    case '-':
        return expression.Next();
    default:
        return ' ';
    }
}

char calculator::read_mul_operator(ExpressionBuffer& expression) const
{
    switch (expression.Peek())
    {
    case '*':
    case '/':
        return expression.Next();
    default:
        return ' ';
    }
}

float calculator::pri_exp(ExpressionBuffer& expression) const
{
    if (expression.Peek() == '(')
    {
        expression.Next();

        float result = add_expression(expression);

        assert(expression.Next() == ')');

        return result;
    }
    else
    {
        return read_number(expression);
    }
}

float calculator::mul_expression(ExpressionBuffer& expression) const
{
    float num1 = 0;
    float num2 = 0;
    char op;

    num1 = pri_exp(expression);
    op = read_mul_operator(expression);
    if (op == ' ') return num1;
    num2 = mul_expression(expression);

    float result = 0;
    switch (op)
    {
    case '*':
        result = num1 * num2;
        break;
    case '/':
        result = num1 / num2;
        break;
    }

    printf("%f %c %f \n", num1, op, num2);

    return result;
}

float calculator::add_expression(ExpressionBuffer& expression) const
{
    float num1 = 0;
    float num2 = 0;
    char op;

    num1 = mul_expression(expression);
    op = read_add_operator(expression);
    if (op == ' ') return num1;
    num2 = add_expression(expression);

    float result = 0;
    switch (op)
    {
    case '+':
        result = num1 + num2;
        break;
    case '-':
        result = num1 - num2;
        break;
    }

    printf("%f %c %f \n", num1, op, num2);

    return result;
}