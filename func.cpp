//
// Казанцев Иван ИУ8-13
//

#define _USE_MATH_DEFINES

#include <cmath>
#include <string>
#include "header.hpp"

void func(std::string &ex) {
    size_t id;   ///Место куда будем возвращать значения
    size_t count;   ///Длина исходного примера
    int sum = 0;     ///Нужно для функции (когда много скобок внутри значения синуса)
    std::string value;    ///Сюда записывается выражение под синусом/косинусом и тд
    double r;     ///Промежуточный парень для вычисления значений
    for (int i = 2; i < ex.size(); ++i) {
        if ((ex[i - 2] == 's') && (ex[i - 1] == 'i') && (ex[i] == 'n')) {    ///Если нашли синус
            count = 5;     ///Размер минимум 5 (sin())
            id = i - 2;    ///Воткнули исходный айди
            i += 2;        ///Перескакиваем i через скобочку
            value = "(";
            while (sum != 1) {     ///Вот и sum
                if (ex[i] == ')') {     ///Если нашлась закрывающая скобочка, она приблизит нас к окончанию цикла
                    sum++;              ///Если не нашлась - отдалит
                }                       ///Когда число открывающих скобочек будет равно числу закрывающих
                if (ex[i] == '(') {     ///Цикл прервется
                    sum--;
                }
                count++;
                value += ex[i];
                i++;
            }                           ///Решим получившееся выражение под синусом
            solve(value);
            count--;
            r = sin(stod(value) * M_PI / 180);      ///Посчитаем
            ex.replace(id, count, std::to_string(r));        ///Заменим исходный синус на результат
            count = 0;
            sum = 0;                   ///Вернем базовые значения
            i = id + value.size();
            value = "";
        }
        if ((ex[i - 2] == 'c') && (ex[i - 1] == 'o') && (ex[i] == 's')) {        ///Дальше - Все по аналогии
            count = 5;
            id = i - 2;
            i += 2;
            value = "(";
            while (sum != 1) {
                if (ex[i] == ')') {
                    sum++;
                }
                if (ex[i] == '(') {
                    sum--;
                }
                count++;
                value += ex[i];
                i++;
            }
            solve(value);
            count--;
            r = cos(stod(value) * M_PI / 180);
            ex.replace(id, count, std::to_string(r));
            count = 0;
            sum = 0;
            i = id + value.size();
            value = "";
        }
        if ((ex[i - 2] == 't') && (ex[i - 1] == 'a') && (ex[i] == 'n')) {
            count = 5;
            id = i - 2;
            i += 2;
            value = "(";
            while (sum != 1) {
                if (ex[i] == ')') {
                    sum++;
                }
                if (ex[i] == '(') {
                    sum--;
                }
                count++;
                value += ex[i];
                i++;
            }
            solve(value);
            count--;
            r = tan(stod(value) * M_PI / 180);
            ex.replace(id, count, std::to_string(r));
            count = 0;
            sum = 0;
            i = id + value.size();
            value = "";
        }
        if ((ex[i - 2] == 'c') && (ex[i - 1] == 't') && (ex[i] == 'g')) {
            count = 5;
            id = i - 2;
            i += 2;
            value = "(";
            while (sum != 1) {
                if (ex[i] == ')') {
                    sum++;
                }
                if (ex[i] == '(') {
                    sum--;
                }
                count++;
                value += ex[i];
                i++;
            }
            solve(value);
            count--;
            r = cos(stod(value) * M_PI / 180) / sin(stod(value) * M_PI / 180);
            ex.replace(id, count, std::to_string(r));
            count = 0;
            sum = 0;
            i = id + value.size();
            value = "";
        }
        if ((ex[i - 2] == 'e') && (ex[i - 1] == 'x') && (ex[i] == 'p')) {
            count = 5;
            id = i - 2;
            i += 2;
            value = "(";
            while (sum != 1) {
                if (ex[i] == ')') {
                    sum++;
                }
                if (ex[i] == '(') {
                    sum--;
                }
                count++;
                value += ex[i];
                i++;
            }
            count--;
            solve(value);
            r = exp(stod(value));
            ex.replace(id, count, std::to_string(r));
            count = 0;
            sum = 0;
            i = id + value.size();
            value = "";
        }
    }

}