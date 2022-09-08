#include <iostream>
#include <fstream>

int* createArr(std::ifstream& fin) // Создание массива из считанных данных файла
{
    int size = 0;

    fin >> size;
    size++;
    int* arr = new int[size];
    arr[0] = size; // Решил хранить размер массива в первом его элементе. Не знаю корректно ли, но хотелось передать в функцию создание массива и не заводить лишних переменных в мэйне. Например на тот случай, если массивов в исходном файле может быть не только два, а любое количество.

    for (int i = 1; i < size; i++)
    {
        fin >> arr[i];
    }

    return arr;
}

int main()
{
    std::string fileIn = "in.txt", fileOut = "out.txt";
    std::ifstream fin(fileIn);

    if (!fin.is_open())
    {
        std::cout << "Не удалось открыть файл" << std::endl;
    }
    else
    {
        int* arr1 = createArr(fin);
        int* arr2 = createArr(fin);

        fin.close();

        std::ofstream fout(fileOut);

        // Вывод массива, который шел вторым в исходном файле
        fout << arr2[0] - 1 << std::endl; // Вывод количества элементов массива
        fout << arr2[arr2[0] - 1]; // Вывод последнего элемента массива
        for (int i = 1; i < arr2[0] - 1; i++) // Вывод остальных элементов
        {
            fout << " " << arr2[i];
        }
        fout << std::endl;

        // Вывод массива, который шел первым в исходном файле
        fout << arr1[0] - 1 << std::endl; // Вывод количества элементов массива
        for (int i = 2; i < arr1[0]; i++) // Вывод элементов массива со второго по последний
        {
            fout << arr1[i] << " ";
        }
        fout << arr1[1]; // Вывод первого элемента массива

        fout.close();

        delete[] arr1, arr2;
    }

    return 0;
}
