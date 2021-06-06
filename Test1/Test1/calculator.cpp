#include "calculator.h"
#include<iostream>
#include<cassert>

int calculator::evaluate(string_view exp) const
{
    int index = 0;
	return add_expression(exp, index);
}

int calculator::read_number(string_view expression, int& index) const
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
            switch (expression[i])
            {
            case '+':
                if (index != 0)
                {
                    if (!isdigit(expression[i - 1]) && isdigit(expression[i + 1]))
                    {
                        return read_number(expression, ++index);
                    }
                    else
                    {
                        return number;
                    }
                }
                else
                {
                    if (isdigit(expression[i + 1]))
                    {
                        return read_number(expression, ++index);
                    }
                    else
                    {
                        return number;
                    }
                }
            case '-':
                if (index != 0)
                {
                    if (!isdigit(expression[i - 1]) && isdigit(expression[i + 1]))
                    {
                        return -1 * read_number(expression, ++index);
                    }
                    else
                    {
                        return number;
                    }
                }
                else
                {
                    if (isdigit(expression[i + 1]))
                    {
                        return -1 * read_number(expression, ++index);
                    }
                    else
                    {
                        return number;
                    }
                }
            default:
                break;
            }

            return number;
        }
    }

    return number;
}

char calculator::read_add_operator(string_view exp, int& index) const
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

char calculator::read_mul_operator(string_view exp, int& index) const
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

int calculator::pri_exp(string_view exp, int& new_index) const
{
    if (exp[new_index] == '(')
    {
        int result = add_expression(exp, ++new_index);

        assert(exp[new_index++] == ')');

        return result;
    }
    else
    {
        string pri_str[3] = { "sin(", "cos(", "log(" };
        string tmp_str = "";
        float result = 0.0f;

        if (tolower(exp[new_index]) == 's')
        {
            for (int i = 0; i < pri_str[0].length(); i++)
            {
                tmp_str += exp[new_index++];
            }
            if (tmp_str == "sin(")
            {
                result = add_expression(exp, new_index);

                assert(exp[new_index++] == ')');

                return sin(result);
            }
        }
        else if (tolower(exp[new_index] == 'c'))
        {
            for (int i = 0; i < pri_str[1].length(); i++)
            {
                tmp_str += exp[new_index++];
            }
            if (tmp_str == "cos(")
            {
                result = add_expression(exp, new_index);

                assert(exp[new_index++] == ')');

                return cos(result);
            }
        }
        else if (tolower(exp[new_index] == 'l'))
        {
            for (int i = 0; i < pri_str[2].length(); i++)
            {
                tmp_str += exp[new_index++];
            }
            if (tmp_str == "log(")
            {
                result = add_expression(exp, new_index);

                assert(exp[new_index++] == ')');

                return log(result);
            }
        }

        return read_number(exp, new_index);
    }
}

int calculator::mul_expression(string_view exp, int& new_index) const
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

int calculator::add_expression(string_view exp, int& new_index) const
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