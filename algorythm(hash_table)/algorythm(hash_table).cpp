// algorythm(hash_table).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <unordered_map>
#include <string>

class PhoneDirectory {
private:
    std::unordered_map<std::string, std::string> directory;
public:
    void addEntry(std::string name, std::string phoneNumber) {
        if (directory.find(name) == directory.end()) {
            directory[name] = phoneNumber;
            std::cout << "Entry added successfully." << std::endl;
        }
        else {
            std::cout << "Entry already exists." << std::endl;
        }
    }
    void searchEntry(std::string name) {
        if (directory.find(name) != directory.end()) {
            std::cout << "Name: " << name << ", Phone Number: " << directory[name] << std::endl;
        }
        else {
            std::cout << "Entry not found." << std::endl;
        }
    }
    void deleteEntry(std::string name) {
        if (directory.find(name) != directory.end()) {
            directory.erase(name);
            std::cout << "Entry deleted successfully." << std::endl;
        }
        else {
            std::cout << "Entry not found." << std::endl;
        }
    }
};

int main() {
    PhoneDirectory pd;
    pd.addEntry("John", "1234567890");
    pd.searchEntry("John");
    pd.deleteEntry("John");
    pd.searchEntry("John");
    return 0;
}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
