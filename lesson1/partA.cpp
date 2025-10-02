#include <iostream>
#include <random>
#include <vector>
#include <iterator>
#include <algorithm>


//Utilities
bool generate_rand()
{
    // 1. Источник случайности (может быть аппаратный)
    std::random_device rd;

    // 2. Генератор (Mersenne Twister)
    std::mt19937 gen(rd());

    // 3. Распределение (целые числа от 1 до 6, как кубик)
    std::uniform_real_distribution<> dist(1.0,100.0);

    // 4. Генерация
    for (int i = 0; i < 10; ++i) {
        std::cout << dist(gen) << " ";
    }
    std::cout << std::endl;

    return 0;
}


template<typename T>
bool safe_add(int a,int b, T& out)
{
    long long temp = 0;
    if (__builtin_add_overflow(a,b,&out))
        {
            temp = static_cast<long long>(a) + static_cast<long long>(b);
            if (temp > INT32_MAX || temp < INT32_MIN)
            {
                std::cout << "Overflow detected" << std::endl;
            }
            out = temp;
            return false;
        }
    else
    {
        std::cout << "No overflow" << std::endl;
        out = a+b;
        return true;
    }
}

bool safe_add_double(double a,double b, double& out)
{
    if (__builtin_add_overflow(a,b,&out))
        {
            std::cout << "Overflow detected" << std::endl;
            out = 0;            
            return false;
        }
    else
    {
        std::cout << "No overflow" << std::endl;
        out = a+b;
        return true;
    }
}

bool simpleSum(std::vector<double> arr,double& result)
{
    // проверка на пустой массив
    if (arr.empty())
    {
        std::cout << "The number array is empty, try again" << std::endl;
        result = 0;
        return false;
    }
    // обнуление результата
    result = 0;
    // суммирование с проверкой на переполнение
    for (int i = 0;i < arr.size();i++)
    {
        if (i == 0) // первое значение, присваеваем результату
            {
                result = arr.at(0);
                continue;
            }
        else
            if (safe_add_double(result,arr.at(i),result)) // 
            {
                continue;
            }
            else if (!safe_add_double(result,arr.at(i),result))
            {
                std::cout << "Overflow detected" << std::endl;
                result = 0;
                return false;
            }
    }
}

int main()
{
    int num1 = 0;
    int num2 = 0;

}