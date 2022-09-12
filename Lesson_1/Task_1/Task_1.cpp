#include <iostream>
#include <fstream>

int* createArr(std::ifstream& fin, int* size) // Create array from file
{
    fin >> *size; // Removed array size from array to separate variable
    int* arr = new int[*size];

    for (int i = 0; i < *size; i++)
    {
        fin >> arr[i];
    }

    return arr;
}

int main()
{
    setlocale(LC_ALL, "Russian");

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

        // Second array output
        fout << sizeArr2 << std::endl; // Number of array elements output
        fout << arr2[sizeArr2 - 1]; // Last element of array output
        for (int i = 0; i < sizeArr2 - 1; i++) // Other elements output
        {
            fout << " " << arr2[i];
        }
        fout << std::endl;

        delete[] arr2; // Cleaned up memory for two arrays separately

        // First array output
        fout << sizeArr1 << std::endl; // Number of array elements output
        for (int i = 1; i < sizeArr1; i++) // Output of array elements from the second to the last
        {
            fout << arr1[i] << " ";
        }
        fout << arr1[0]; // First element output

        delete[] arr1;

        fout.close();
    }

    return 0;
}
