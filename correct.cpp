//
// Казанцев Иван ИУ8-13
//

#include <string>
#include <iostream>
#include <cmath>
#include "header.hpp"

void correct(std::string &ex) {    ///Корректировка строки
    auto it = ex.end();
    size_t count;   ///Длина заменяемого значения
    std::string buf;    ///Две промежуточные строки
    std::string str;    ///Проверяем, нужна ли проверка
    if ((find(ex.begin(), ex.end(), '-') != it) || (find(ex.begin(), ex.end(), '^') != it)) {
        for (int i = ex.size() - 1; i >= 0; --i) {

            ///На память

//            if ((ex[i] == ')') && (ex[i + 1] == '^')) {
//                double r;
//                size_t id;
//                count = 2;
//                bool flag = false;
//                int sum = 0;
//                i--;
//                while (sum != 1) {
//                    buf += ex[i];
//                    count++;
//                    i--;
//                    if (ex[i] == '('){
//                        sum++;
//                    }
//                    if (ex[i] == ')'){
//                        sum--;
//                    }
//                }
//                sum = 0;
//                for (int j = buf.size() - 1; j >= 0; --j) {
//                    str += buf[j];
//                }
//                //std::cout << str << std::endl;
//                solve(str);
//                //std::cout << str << std::endl;
//
//                i++;
//                id = i - 1;
//                i--;
//                buf = "";
//                i += count;
//                i++;
//                ///разобратсья
//                //std::cout << ex[i];
//                if (ex[i] == '(') {
//                    i++;
//                    count += 2;
//                    flag = true;
//                    while (sum != 1) {
//                        buf += ex[i];
//                        count++;
//                        i++;
//                        if (ex[i] == ')'){
//                            sum++;
//                        }
//                        if (ex[i] == '('){
//                            sum--;
//                        }
//                    }
//                } else {
//                    while (((std::isdigit(ex[i])) || (ex[i] == '.') || (ex[i] == '-')) && (i < ex.size())) {
//                        buf += ex[i];
//                        count++;
//                        i++;
//                    }
//                }
//                //std::cout << buf << std::endl;
//                if (flag) {
//                    solve(buf);
//                }
//                //std::cout << buf << std::endl;
//                //std::cout << str << ' ' << buf;
//                r = pow(stod(str), stod(buf));
//                //std::cout << r << std::endl;
//                str = std::to_string(r);
//                //std::cout << str;
//                count++;
//                ex.replace(id, count, str);
//                //std::cout << ex << std::endl;
//                i = id; /// += count
//                //std::cout << i;
//                count = 0;
//                str = "";
//                buf = "";
//            }

            if ((ex[i] == ')') && (ex[i + 1] == '^')) {    ///Разбираем случай, когда слева от степени - скобка
                double r;
                size_t id;     ///По аналогии, айди - место, куда будем вставлять новое выражение
                count = 2;     ///Базовая длина
                bool flag = false;   ///Условие
                int sum = 0;     ///Нужно для цикла
                i--;             ///Рассмотрим первый символ в скобке
                buf = ")";
                while (sum != 1) {
                    if (ex[i] == '(') {       ///Данный метод уже объяснялся
                        sum++;
                    }
                    if (ex[i] == ')') {
                        sum--;
                    }
                    buf += ex[i];
                    count++;
                    i--;
                }
                sum = 0;
                for (int j = buf.size() - 1; j >= 0; --j) {
                    str += buf[j];
                }
                solve(str);                          ///Решаем выражение (на случай, если много скобок)
                i++;
                id = i;
                buf = "";
                i += count;
                if (ex[i] == '(') {            ///То же, что и раньше, но вдруг справа тоже скобка?
                    i++;
                    count += 1;
                    flag = true;
                    buf = "(";
                    while (sum != 1) {
                        if (ex[i] == ')') {
                            sum++;
                        }
                        if (ex[i] == '(') {
                            sum--;
                        }
                        buf += ex[i];
                        count++;
                        i++;
                    }
                } else {
                    while (((std::isdigit(ex[i])) || (ex[i] == '.') || (ex[i] == '-')) && (i < ex.size())) {
                        buf += ex[i];
                        count++;
                        i++;
                    }
                }
                if (flag) {
                    solve(buf);
                }
                r = pow(stod(str), stod(buf));
                str = std::to_string(r);
                ex.replace(id, count, str);
                i = id; /// += count
                count = 0;
                str = "";
                buf = "";
            }

            if (((ex[i] == '^') && (ex[i + 1] == '(')) && (ex[i - 1] != ')')) {   ///Случай если скобка только справа
                double r;
                size_t id;
                count = 2;
                bool flag = false;
                i--;
                int sum = 0;
                while (((std::isdigit(ex[i])) || (ex[i] == '.')) && (i >= 0)) {
                    buf += ex[i];
                    count++;
                    i--;
                }
                for (int j = buf.size() - 1; j >= 0; --j) {
                    str += buf[j];
                }
                solve(str);

                i++;
                id = i;
                i--;
                buf = "";
                i += count;
                if (ex[i] == '(') {
                    i++;
                    count += 2;
                    flag = true;
                    buf = "(";
                    while (sum != 1) {
                        if (ex[i] == ')') {
                            sum++;
                        }
                        if (ex[i] == '(') {
                            sum--;
                        }
                        buf += ex[i];
                        count++;
                        i++;
                    }
                }
                if (flag) {
                    solve(buf);
                }
                r = pow(stod(str), stod(buf));
                str = std::to_string(r);
                count -= 2;
                ex.replace(id, count, str);
                std::cout << ex;
                i = id;
                count = 0;
                str = "";
                buf = "";
            }

            ///Остальные случаи очевидны
            if ((ex[i] == '*') && (ex[i + 1] == '-')) {
                count = 2;
                i--;
                while ((std::isdigit(ex[i])) || (ex[i] == '.') && (i >= 0)) {
                    buf += ex[i];
                    count++;
                    i--;
                }
                str += '-';
                for (int j = buf.size() - 1; j >= 0; --j) {
                    str += buf[j];
                }
                str += '*';
                ex.replace(i + 1, count, str);
                i += count;
                count = 0;
                str = "";
                buf = "";
            }
            if ((ex[i] == '/') && (ex[i + 1] == '-')) {
                count = 2;
                i--;
                while (((std::isdigit(ex[i])) || (ex[i] == '.')) && (i >= 0)) {
                    buf += ex[i];
                    count++;
                    i--;
                }
                str += '-';
                for (int j = buf.size() - 1; j >= 0; --j) {
                    str += buf[j];
                }
                str += '/';
                ex.replace(i + 1, count, str);
                i += count;
                count = 0;
                str = "";
                buf = "";
            }
//            if ((ex[i] == '+') && (ex[i + 1] == '-')) {
//                count = 1;
//                i--;
//                while (((std::isdigit(ex[i])) || (ex[i] == '.')) && (i >= 0)) {
//                    buf += ex[i];
//                    count++;
//                    i--;
//                }
//                for (int j = buf.size() - 1; j >= 0; --j) {
//                    str += buf[j];
//                }
//                ex.replace(i + 1, count, str);
//                i += count;
//                count = 0;
//                str = "";
//                buf = "";
//
//            }
            if ((ex[i] == '+' && ex[i+1] == '-') || (ex[i] == '-' && ex[i+1] == '+')){
                ex.replace(i, 2, "-");
            }
            if (ex[i] == '-' && ex[i+1] == '-'){
                ex.replace(i, 2, "+");
            }
//            if ((ex[i] == '-') && (ex[i + 1] == '-')) {
//                count = 1;
//                i--;
//                while (((std::isdigit(ex[i])) || (ex[i] == '.')) && (i >= 0)) {
//                    buf += ex[i];
//                    count++;
//                    i--;
//                }
//                for (int j = buf.size() - 1; j >= 0; --j) {
//                    str += buf[j];
//                }
//                str += '+';
//                //std::cout << str;
//                ex.replace(i + 1, count + 1, str);
//                i += count;
//                count = 0;
//                str = "";
//                buf = "";
//
//            }
            if (((ex[i] == '^') && (ex[i + 1] == '-')) && (ex[i - 1] != ')')) {
                double r;
                size_t id;
                count = 2;
                i--;
                while (((std::isdigit(ex[i])) || (ex[i] == '.')) && (i >= 0)) {
                    buf += ex[i];
                    count++;
                    i--;
                }
                for (int j = buf.size() - 1; j >= 0; --j) {
                    str += buf[j];
                }
                i++;
                id = i;
                i--;
                buf = "";
                i += count;
                buf += ex[i];
                i++;
                while (((std::isdigit(ex[i])) || (ex[i] == '.')) && (i < ex.size())) {
                    buf += ex[i];
                    count++;
                    i++;
                }
                r = pow(stod(str), stod(buf));
                str = std::to_string(r);
                ex.replace(id, count, str);
                i = id;
                count = 0;
                str = "";
                buf = "";
            }
        }
    }
}