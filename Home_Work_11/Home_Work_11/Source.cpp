#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void write_arr(const string& filename, const int* arr, const int size)
{
    fstream fs_1;

    fs_1.open(filename, fstream::out);
    if (fs_1.is_open()) // проверяем, что файл успешно открыт
    {
        fs_1 << size << '\n';  // записываем размер массива
        for (int i = 0; i < size; i++)
            fs_1 << arr[i] << ' '; // записываем значения через пробел
        fs_1 << '\n';

        fs_1.close(); // закрываем файл
    }
}

//void read_arr(const string& filename, int*& arr, int& size, int& i, int& j, int& descriptor)
//{
//    fstream fs;
//
//    fs.open(filename, fstream::in);
//    if (fs.is_open()) // проверяем, что файл успешно открыт
//    {
//        fs >> size;  // читаем размер массива
//        j += (size / 10);
//        arr = new int[size];
//        fs.seekg(descriptor);
//        for (i; i < j && i < size; i++)
//        {
//            fs >> arr[i]; // читаем из файла разделительные символы - пробел и перенос строки
//        }
//
//        descriptor += i * 2;
//        
//        fs.close(); // закрываем файл
//    }
//}

void read_arr(const string& filename, int*& arr, int& size)
{
    fstream fs;

    fs.open(filename, fstream::in);
    if (fs.is_open()) // проверяем, что файл успешно открыт
    {
        fs >> size;  // читаем размер массива
        arr = new int[size];
        for (int i = 0; i < size/2; i++)
            fs >> arr[i]; // читаем из файла разделительные символы - пробел и перенос строки

        fs.close(); // закрываем файл
    }
}

int getMax(int* arr, const int& size)
{
    int max = arr[0];

    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

void countSort(int* arr, int size)
{
    int* output = new int[size];
    int max = getMax(arr, size);
    int* count = new int[max + 1]{0};

    for (int i = 0; i < size; i++)
    {
        count[arr[i]]++;
    }

    for (int i = 1; i <= max; i++)
    {
        count[i] += count[i - 1];
    }

    for (int i = 0; i < size; i++)
    {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for (int i = 0; i < size; i++)
    {
        arr[i] = output[i];
    }

    delete[] count;
    delete[] output;
}

int main()
{
    string name = "file_";
    char number = '0';

    string filename_r = "array_1.txt", filename_w = "";

    int size = 1, filecount = 0, limit = 0, k = 0;
    int* arr_from_file; 

    fstream fs;
    fs.open(filename_r, fstream::in);
    fs >> size;  // читаем размер массива

    do
    {
        arr_from_file = nullptr;
        if (fs.is_open()) // проверяем, что файл успешно открыт
        {
            limit += (size / 10);
            arr_from_file = new int[size/10];
            for (int i = 0; i < 10; i++)
                fs >> arr_from_file[i]; // читаем из файла разделительные символы - пробел и перенос строки
        }

        countSort(arr_from_file, (size/10));

        filename_w = name + number + ".txt";
        cout << filename_w << endl;
        write_arr(filename_w, arr_from_file, (size / 10));
        number++;

        for (int k = 0; k < size/10; k++)
        {
            cout << arr_from_file[k] << endl;
        }
        
        filecount += 10;
        delete[] arr_from_file;

    } while (filecount < size);

    fs.close(); // закрываем файл

    arr_from_file = nullptr;

    int f_readCount = 0;
    string filename_r_sort;
    int size_r = size / f_readCount;
    
    while (f_readCount < size/10)
    {
        fs.open(filename_r_sort, fstream::in);

        if (fs.is_open())
        {

        }

        f_readCount++;
    }

	return 0;
}