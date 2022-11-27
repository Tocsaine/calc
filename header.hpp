//
// Казанцев Иван ИУ8-13
//

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <iterator>
#include <cmath>

#ifndef CALC_HEADER_HPP
#define CALC_HEADER_HPP

void calc(std::string &ex);    ///Подсчет выражений без скобок
void correct(std::string &ex);  ///Корректировка введенного примера
void solve(std::string &ex);    ///Алгоритм работы со множеством скобок
void func(std::string &ex);     ///Тригонометрия
std::string check_and_fix(std::string& ex);    ///Начальная проверка на ошибки

#endif //CALC_HEADER_HPP
