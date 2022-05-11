#include <iostream>
#include "DynamicArray.h"
#include "LinkedList.h"
#include "ArraySequence.h"
#include "LinkedListSequence.h"
#include "Tests.h"
using namespace std;

#define main_mune cout<<"С чем будем работать?\n\t1)Динамический массив\n\t2)Односвязный список\n\t3)Тесты\n4)Выход\n"
#define arr_menu cout<<"Команды:\n\t1)Получить элемент по индексу\n\t2)Задать элемент по индексу\n\t3)Добавить элемент в начало\n\t4)Добавить элемент в конец\n\t5)Вывести массив\n6)Выход\n"
#define list_menu cout<<"Команды:\n\t1)Получить элемент по индексу\n\t2)Добавить элемент в конец\n\t3)Добавить элмент в начало\n\t4)Задать элмент по индексу\n\t5)Получить подсписок\n\t6)Вывести список\n7)Выход\n"

int main() {
    setlocale(LC_ALL, "rus");
    
    main_mune;
    while (true) {
        int menu1;
        cin >> menu1;
        switch (menu1) {
        case 1: {
            cout << "Введите количество элементов: ";
            int size;
            cin >> size;
            ArraySequence<int> arr(size);
            cout << "Заполните массив: ";
            for (int i = 0; i < size; i++) {
                int a;
                cin >> a;
                arr.insertAt(a, i);
            }
            arr_menu;
            while (true) {
                int menu2;
                cin >> menu2;
                switch (menu2) {
                case 1:
                    int index;
                    cout << "Введите индекс: ";
                    cin >> index;
                    cout << "Значение: " << arr.get(index) << endl;
                    break;
                case 2:
                    int index1, item;
                    cout << "Введите индекс: ";
                    cin >> index1;
                    cout << "Введите элемент: ";
                    cin >> item;
                    arr.insertAt(item, index1);
                    break;
                case 3:
                    int item2;
                    cout << "Введите элемент: ";
                    cin >> item2;
                    arr.prepend(item2);
                    break;
                case 4:
                    int item3;
                    cout << "Введите элемент: ";
                    cin >> item3;
                    arr.append(item3);
                    break;
                case 5:
                    arr.output();
                    break;
                case 6:
                    return 0;
                    break;
                default:
                    return 0;
                    break;
                }
            }
            break;
        }
        case 2: {
            LinkedListSequence<int> list;
            list_menu;
            while (true) {
                int menu3;
                cin >> menu3;
                switch (menu3) {
                case 1:
                    cout << "Введите индекс: ";
                    int index3;
                    cin >> index3;
                    cout << "Значение: " << list.get(index3) << endl;
                    break;
                case 2:
                    int item3;
                    cout << "Введите значение: ";
                    cin >> item3;
                    list.append(item3);
                    break;
                case 3:
                    int item4;
                    cout << "Введите значение: ";
                    cin >> item4;
                    list.prepend(item4);
                    break;
                case 4:
                    cout << "Введите индекс: ";
                    int index4;
                    cin >> index4;
                    int item5;
                    cout << "Введите значение: ";
                    cin >> item5;
                    list.insertAt(item5, index4);
                    break;
                case 5:
                    int startIndext, endIndex;
                    cout << "Введите начальный индекс: ";
                    cin >> startIndext;
                    cout << "Введите конечный индекс: ";
                    cin >> endIndex;
                    list.getSubsequence(startIndext, endIndex).output();
                    break;
                case 6:
                    list.output();
                    break;
                case 7:
                    return 0;
                    break;
                default:
                    return 0;
                    break;
                }
            }
            break;
        }
        case 3:
            startAllTests();
            break;
        case 4:
            return 0;
            break;
        default:
            return 0;
            break;
        }
    }

    return 0;
}