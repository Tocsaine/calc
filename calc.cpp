// Казанцев Иван ИУ8-13

#include <string>
#include <list>
#include <vector>
#include <cmath>

void calc(std::string &ex) { /// Функция высчитывания линейного примера без скобок
    std::list<double> numers;    ///Массив числовых значений
    std::vector<char> oper;      ///Массив операторов
    std::string strn;      ///Числовых значений в стандартном варианте на 1 больше чем операторов
    ///strn - промежуточная строка (записывает числа)

    std::list<char> exl;     ///Создаем промежуточный посимвольный лист
    for (auto i: ex) {     ///заполняем его нашим фрагментом примера
        exl.push_back(i);
    }
    exl.remove('(');    ///удаляем скобки (если они есть)
    exl.remove(')');


    if (*exl.begin() ==
        '-') {  ///Если первый элемент в фрагменте - "-", добавим в начало 0(для корректного подсчета)
        numers.push_back(0.);
    }
    for (auto i: exl) {      ///Заполняем массивы чисел и операторов
        if (std::isdigit(i) || i == '.') {
            strn += i;
        } else {
            if (!strn.empty()) {
                numers.push_back(stod(strn));
            }
            oper.push_back(i);
            strn = "";
        }
    }
    numers.push_back(stod(strn));    ///Заполнили
    double buf;    ///Далее - функции подсчета с расставленным приоритетом. Рассмотрим на примере степени
    auto it1 = numers.begin();
    auto it2 = numers.begin();
    if (find(exl.begin(), exl.end(), '^') != exl.end()) {
        for (size_t i = 0; i < oper.size(); ++i) {
            it1 = numers.begin();   ///2 итератора массива(лист) чисел
            it2 = numers.begin();
            if (oper[i] == '^') {
                std::advance(it1, i);     ///Двигаем первый итератор на число "слева" от оператора
                std::advance(it2, i + 1);   ///На число "справа" от итератора
                buf = pow(*it1, *it2);      ///Находим результат возведения их в степень
                it2++;
                numers.erase(it1, it2);    ///Удаляем старые элементы
                numers.insert(it2, buf);   ///Вставляем новое число в массив чисел
                oper.erase(oper.begin() + static_cast<int>(i));    ///Удаляем отработавший оператор

            }       ///Все далее - по аналогии
        }
    }
    it2 = numers.end();

    if (find(exl.begin(), exl.end(), '*') != exl.end()) {
        for (size_t i = 0; i < oper.size(); ++i) {
            it1 = numers.begin();
            it2 = numers.begin();
            if (oper[i] == '*') {
                std::advance(it1, i);
                std::advance(it2, i + 1);
                buf = (*it1) * (*it2);
                it2++;
                numers.erase(it1, it2);
                numers.insert(it2, buf);
                oper.erase(oper.begin() + static_cast<int>(i));
                i--;
            }
        }
    }
    if (find(exl.begin(), exl.end(), '/') != exl.end()) {
        for (size_t i = 0; i < oper.size(); ++i) {
            it1 = numers.begin();
            it2 = numers.begin();
            if (oper[i] == '/') {
                std::advance(it1, i);
                std::advance(it2, i + 1);
                buf = (*it1) / (*it2);
                it2++;
                numers.erase(it1, it2);
                numers.insert(it2, buf);
                oper.erase(oper.begin() + static_cast<int>(i));
                i--;
            }
        }
    }
    if (find(exl.begin(), exl.end(), '-') != exl.end()) {
        for (size_t i = 0; i < oper.size(); ++i) {
            it1 = numers.begin();
            it2 = numers.begin();
            if (oper[i] == '-') {
                std::advance(it1, i);
                std::advance(it2, i + 1);
                buf = (*it1) - (*it2);
                it2++;
                numers.erase(it1, it2);
                numers.insert(it2, buf);
                oper.erase(oper.begin() + static_cast<int>(i));
                i--;

            }
        }
    }
    if (find(exl.begin(), exl.end(), '+') != exl.end()) {
        for (size_t i = 0; i < oper.size(); ++i) {
            it1 = numers.begin();
            it2 = numers.begin();
            if (oper[i] == '+') {
                std::advance(it1, i);
                std::advance(it2, i + 1);
                buf = (*it1) + (*it2);
                it2++;
                numers.erase(it1, it2);
                numers.insert(it2, buf);
                oper.erase(oper.begin() + static_cast<int>(i));
                i--;
            }
        }
    }
    ex = "";
    for (auto i: numers) {    ///Возвращаем получившийся ответ
        ex += std::to_string(i);
    }
}
