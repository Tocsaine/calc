//
// Казанцев Иван ИУ8-13
//

#include <iostream>
#include <string>
#include "header.hpp"

int main(){
    std::string ex;    ///Наш пример
    std::cin >> ex;     ///Вводим исходную строку   (sin(30)+1.5)^(16/4+0.5^-2)
    std::string test;
    test = check_and_fix(ex);    ///проверяем на ошибки
    std::cout << test;
    if (test == "Incorrect input!"){
        return 0;
    }
    func(ex);       ///Проверяем пример на вшивость (тригонометрию) и решаем ее если потребуется (func.cpp)
    ///correct(ex);     ///Функция корректировки строки (подробнее - в correct.cpp)
    solve(ex);      ///Функция решения Примера (подробнее - в solve.cpp)
    std::cout << std::endl << "ANSWER = " << ex;
}

///На память...
//    std::string ex;
//    std::cin >> ex;
//    correct(ex);
//    //calc(ex);
//    //std::cout << ex;
//    auto it = ex.begin();
//    std::string str = "";
//    size_t id = 0;
//    size_t size = 0;
//    size_t count = 0;
//    while (std::count(ex.begin(), ex.end(), '(') != 0){
//        //std::cout << ex << std::endl;
//        count++;
//        str = "";
//        for (size_t i = 0; i < ex.size(); ++i){
//            if (ex[i] == '('){
//                str = ex[i];
//                id = i;
//            }
//            if ((ex[i] != '(') && (ex[i] != ')')){
//                str += ex[i];
//            }
//            if ((ex[i] == ')') && (!str.empty())){
//                str += ex[i];
//                std::cout << std::endl;
//                //std::cout << str;
//                size = str.size();
//                calc(str);
//                //std::cout << " " << str;
//                ex.replace(id, size, str);
//                //std::cout << ex <<std::endl;
//                i = id;
//                str = "";
//                break;
//            }
//        }
//        correct(ex);
//        if (count == 20){
//            break;
//        }
//    }
//    calc(ex);
//    //std::cout << ex;
//    if (ex[0] != '-'){
//        calc(ex);
//    }
//    std::cout << ex;
//}