//
// Казанцев Иван ИУ8-13
//

#include <string>
#include <iostream>
#include <algorithm>

bool isLetter(char x) {        ///Функция определения того, буква ли данный чар
    return (x >= 'A' && x <= 'Z') || (x >= 'a' && x <= 'z');
}

std::string check_and_fix(std::string &ex) {
    std::string str;      ///Временная строка
    size_t count1 = 0;    ///Подсчет открывающихся скобок
    size_t count2 = 0;    ///подсчет закрываюшихся скобок

    if (ex.find_first_not_of("sincotgexpa0123456789^+/()*-.,") != std::string::npos) { ///Если есть лишние символы
        return "Incorrect input!";
    }
    if (ex[0] == '+' || ex[0] == '*' || ex[0] == '/' || ex[0] == '^') {      ///Если начинается с бесполезного символа
        return "Incorrect input!";
    }
    {
        std::string x;        ///Переменная, в которую вводится значение Х
        std::vector<size_t> places;       ///Вектор позиций Х
        if (find(ex.begin(), ex.end(), 'x') != ex.end()) {     ///Если есть подозрения на наличие Х
            for (size_t i = 0; i < ex.size(); ++i) {
                if (tolower(ex[i]) == 'x' && ex[i - 1] != 'e' && ex[i + 1] != 'p') {   ///Если это не exp
                    places.push_back(i);        ///Считываем позицию
                }
            }
        }
        if (!places.empty()) {         ///Если Х есть
            std::cout << "Enter value of x-";
            std::cin >> x;
            for (auto i: places) {
                ex.replace(i, 1, x);         ///Меняем Х на введенное значение
            }
        }
    }
    for (size_t i = 0; i < ex.size(); ++i) {
        if (ex[i] == ' ') {        ///Удаляем пробелы если есть
            ex.erase(i, 1);
        }
        if (ex[i] == ',') {        ///Заменяем запятые на точки
            ex.replace(i, 1, ".");
        }
        if (ex[i] == '(') {          ///Считаем число открывающихся скобок
            count1++;
        }
        if (ex[i] == ')') {        ///Считаем число закрывающихся скобок
            count2++;
        }
        if ((ex[i] == '(' && (ex[i + 1] == ')')) || (ex[i] == ')' && ex[i + 1] == '(')) {   ///Бессмысленные скобки
            return "Incorrect input!";
        }
        if ((ex[i] == '*' && ex[i + 1] == '/') || (ex[i] == '/' && ex[i + 1] == '*') ||
            (ex[i] == '*' && ex[i + 1] == '^') || (ex[i] == '^' && ex[i + 1] == '*') ||
            (ex[i] == '/' && ex[i + 1] == '^') || (ex[i] == '^' && ex[i + 1] == '/')) {
            return "Incorrect input!";   ///Бессмысленные символы подряд
        }
        if ((!(std::isdigit(ex[i]) || ex[i] == '(' || ex[i] == ')')) &&
            (!(std::isdigit(ex[i + 1]) || ex[i + 1] == '(' || ex[i + 1] == ')')) &&
            (ex[i] == ex[i + 1])) {      ///Бессмысленные символа подряд
            return "Incorrect input!";

        }
        if ((ex[i] == '.' && (!std::isdigit(ex[i - 1]))) || (ex[i] == '.' && (!std::isdigit(ex[i + 1])))) {
            return "Incorrect input!";      ///Неправильно заданное число
        }
    }
    if (count1 != count2) {     ///количество открывающихся скобок не равно количеству закрывающихся
        return "Incorrect input!";
    }
    if (ex.find_first_of("sincotgexpa") != std::string::npos) {    ///Проверяем, все ли буквы использованы как надо
        for (size_t i = 0; i < ex.size(); ++i) {
            while ((isLetter(ex[i])) && (i < ex.size())) {
                str += ex[i];
                i++;
            }
            if ((!str.empty()) && (str != "sin" && str != "cos" && str != "tan" && str != "ctg" && str != "exp")) {
                return "Incorrect input!";
            }
            str = "";
        }
    }
    std::cout << ex;
    return " alright";
}