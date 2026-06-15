#include "calculator.h"
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

bool ReadNumber(Number& result) {
    if (!(cin >> result)) {
        cerr << "Error: Numeric operand expected" << endl;
        return false;
    }
    return true;
}

bool RunCalculatorCycle() {
    Number current = 0;
    Number memory = 0;
    bool memory_set = false;
    string command;

    // Читаем начальное число
    if (!ReadNumber(current)) {
        return false;
    }

    while (cin >> command) {
        if (command == "+") {
            Number operand;
            if (!ReadNumber(operand)) {
                return false;
            }
            current += operand;
        }
        else if (command == "-") {
            Number operand;
            if (!ReadNumber(operand)) {
                return false;
            }
            current -= operand;
        }
        else if (command == "*") {
            Number operand;
            if (!ReadNumber(operand)) {
                return false;
            }
            current *= operand;
        }
        else if (command == "/") {
            Number operand;
            if (!ReadNumber(operand)) {
                return false;
            }
            // Не завершаем работу при делении на ноль, а присваиваем результат операции
            current = current / operand;
        }
        else if (command == "**") {
            Number exponent;
            if (!ReadNumber(exponent)) {
                return false;
            }
            current = pow(current, exponent);
        }
        else if (command == "=") {
            cout << current << endl;
        }
        else if (command == ":") {
            if (!ReadNumber(current)) {
                return false;
            }
        }
        else if (command == "c") {
            current = 0;
        }
        else if (command == "s") {
            memory = current;
            memory_set = true;
        }
        else if (command == "l") {
            if (!memory_set) {
                cerr << "Error: Memory is empty" << endl;
                return false;
            }
            current = memory;
        }
        else if (command == "q") {
            return true;
        }
        else {
            cerr << "Error: Unknown token " << command << endl;
            return false;
        }
    }

    return true;
}