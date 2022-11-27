// Казанцев Иван ИУ8-13

#include <string>
#include <vector>
#include <cmath>
#include "header.hpp"

void solve(std::string &ex) {        ///Алгоритм высчитывания выражения со скобками


    correct(ex);    ///Проверка никогда не будет лишней

    std::string str;
    size_t id = 0;           ///Данные аналогично всему что было описано до
    size_t size;
    size_t count = 0;
    while (std::count(ex.begin(), ex.end(), '(') != 0) {
        count++;                 ///Во избежании вечного цикла
        str = "";
        for (size_t i = 0; i < ex.size(); ++i) {
            if (ex[i] == '(') {             ///Если новая скобочка, то все это дело мы обнуляем
                str = ex[i];
                id = i;
            }
            if ((ex[i] != '(') && (ex[i] != ')')) {        ///Если это не скобочки, мы записываем
                str += ex[i];
            }
            if ((ex[i] == ')') && (!str.empty())) {          ///Если скобочка закрывается, начинаем махинации
                str += ex[i];             ///Дописываем последнюю скобочку
                size = str.size();        ///Считываем размер
                calc(str);             ///Считаем что в скобочке (это мы умеем)
                ex.replace(id, size, str);       ///Заменяем
                i = id;
                str = "";
                break;
            }
        }
        correct(ex);          ///проверка на вшивость
        if (count == 20) {
            break;
        }
    }
    calc(ex);            ///Посчитаем что осталось
    if (ex[0] != '-') {     ///Можно и еще разок
        calc(ex);
    }
}