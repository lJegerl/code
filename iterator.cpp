// iterator.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "Header.h"
#include <iostream>
#include <time.h>
#include <windows.h>
#include <vector>
using namespace std;


unsigned counting(ListIterator* li) {
    unsigned cnt = 0;
    if (li->first())
        do {
            cnt++;
            cerr << li->currentItem() << " ";
        } while (li->next());
        cerr << endl;
        return cnt;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand((unsigned)time(0));
    unsigned capacity, count;
    cout << "Введите объём стека: ";
    cin >> capacity;
    List list(capacity);
    cout << "Введите количество элементов для заполнения стека: ";
    cin >> count;
    for (auto i = 0; i < count; i++) {
        int x = rand() % 5;
        if (list.append(x))
            cout << x << " ";
    }
    cout << endl;

    ListIterator* litS3 = list.createIterator(Iterators::STEP, 3);
    ListIterator* litV4 = list.createIterator(Iterators::VALUE, 4);
    ListIterator* litPred = list.createIterator(Iterators::PREDICATE, 4);

    cout << counting((ListIteratorStep*)litS3) << endl;
    cout << counting((ListIteratorValue*)litV4) << endl;
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
