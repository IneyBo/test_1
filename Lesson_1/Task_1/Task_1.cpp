#include <iostream>
#include <fstream>

int* createArr(std::ifstream& fin, int* size) // Создание массива из считанных данных файла
{
    fin >> *size; // Вынес размер массива из самого массива в отдельную переменную
    int* arr = new int[*size];

    for (int i = 0; i < *size; i++)
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
        int size = 0, sizeArr1 = 0, sizeArr2 = 0;
        int* arr1 = createArr(fin, &size);
        sizeArr1 = size;
        int* arr2 = createArr(fin, &size);
        sizeArr2 = size;

        fin.close();

        std::ofstream fout(fileOut);

        // Вывод массива, который шел вторым в исходном файле
        fout << sizeArr2 << std::endl; // Вывод количества элементов массива
        fout << arr2[sizeArr2 - 1]; // Вывод последнего элемента массива
        for (int i = 0; i < sizeArr2 - 1; i++) // Вывод остальных элементов
        {
            fout << " " << arr2[i];
        }
        fout << std::endl;

        delete[] arr2; // Сделал очищение памяти для двух массивов отдельно. Видимо тут и была утечка, когда два массива через запятую шли.

        // Вывод массива, который шел первым в исходном файле
        fout << sizeArr1 << std::endl; // Вывод количества элементов массива
        for (int i = 1; i < sizeArr1; i++) // Вывод элементов массива со второго по последний
        {
            fout << arr1[i] << " ";
        }
        fout << arr1[0]; // Вывод первого элемента массива

        delete[] arr1;

        fout.close();
    }

    return 0;
}
