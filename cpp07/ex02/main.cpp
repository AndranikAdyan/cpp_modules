#include "Array.hpp"

int main() {
    try {
        Array<int> arrInt(5);
        for (size_t i = 0; i < arrInt.size(); ++i)
            arrInt[i] = i * 10;

        std::cout << "Int array: ";
        for (size_t i = 0; i < arrInt.size(); ++i)
            std::cout << arrInt[i] << " ";
        std::cout << std::endl;

        Array<int> arrCopy(arrInt);
        std::cout << "Copy array: ";
        for (size_t i = 0; i < arrCopy.size(); ++i)
            std::cout << arrCopy[i] << " ";
        std::cout << std::endl;

        Array<int> arrAssign;
        arrAssign = arrInt;
        std::cout << "Assigned array: ";
        for (size_t i = 0; i < arrAssign.size(); ++i)
            std::cout << arrAssign[i] << " ";
        std::cout << std::endl;

        Array<std::string> arrStr(3);
        arrStr[0] = "apple";
        arrStr[1] = "banana";
        arrStr[2] = "cherry";

        std::cout << "String array: ";
        for (size_t i = 0; i < arrStr.size(); ++i)
            std::cout << arrStr[i] << " ";
        std::cout << std::endl;

        const Array<std::string>& constArr = arrStr;
        std::cout << "Const array access: " << constArr[1] << std::endl;

        try {
            arrInt[10] = 100;
        } catch (const std::out_of_range& e) {
            std::cout << "Caught exception: " << e.what() << std::endl;
        }

    } catch (const std::exception& e) {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }

    return 0;
}
