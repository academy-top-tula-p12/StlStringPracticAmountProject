#include <iostream>
#include <string>

std::string NumberToString(int number);
int StringToResult(std::string expression);


int main()
{
    int result;
    std::cout << "Input final result: ";
    std::cin >> result;
    /*std::string s = "12+34-5+67-9";
    int r = StringToResult(s);*/

    for (int number = 0; number < 6561; number++)
    {
        std::string str = NumberToString(number);
        //std::cout << str << "\n";
        if (StringToResult(str) == result)
           std::cout << str << " = " << result << "\n";
    }
}

std::string NumberToString(int number)
{
    std::string resultStr = "1";
    char digit = '2';
    while (number)
    {
        int code = number % 3;
        switch (code)
        {
        case 1: resultStr.push_back('-'); break;
        case 2: resultStr.push_back('+'); break;
        }
        resultStr.push_back(digit++);
        number /= 3;
    }
    while (digit <= '9')
        resultStr.push_back(digit++);
    return resultStr;
}

int StringToResult(std::string expression)
{
    int result{};
    char sign{ '+' };
    
    int index{};
    int operand{};
    while (index < expression.length())
    {
        if (expression[index] != '+' && expression[index] != '-')
            operand = operand * 10 + (expression[index] - 48);
        else
        {
            switch (sign)
            {
            case '+': result += operand; break;
            case '-': result -= operand; break;
            }
            operand = 0;
            sign = expression[index];
        }
        index++;
    }
    switch (sign)
    {
        case '+': result += operand; break;
        case '-': result -= operand; break;
    }
    return result;
}
