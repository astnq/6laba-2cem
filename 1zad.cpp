// Вариант 10
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <time.h>

using namespace std;

void Generate_Matrix(int** matrix, int m, int n) { // Функция для заполнения матрицы случайными значениями и её вывода
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = rand() % 49 + 50; // Генерация случайного числа от 50 до 98
            cout << matrix[i][j] << " "; 
        }
        cout << endl; 
    }
}

int find_elements(vector<int>& nums, int** matrix, int m, int n) { // Функция нахождения неотрицательных элементов матрицы на нечётных местах в чётных строках и их суммы
    int sum = 0; // Переменная для хранения суммы
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (((i + 1) % 2 == 0) && ((j + 1) % 2 != 0) && (matrix[i][j] >= 0)) { // Проверка на чётную строку, нечётный столбец и неотрицательное значение
                nums.push_back(matrix[i][j]); 
                sum += matrix[i][j]; // Добавление эл-та к сумме
            }
        }
    }
    return sum; 
}

template <typename T> // Перегрузка оператора вывода для вектора
ostream& operator<<(ostream& os, const vector<T>& vec) { 
    for (const auto& element : vec) {
        os << element << " "; 
    }
    return os;
}

int main() {
    setlocale(LC_ALL, "Rus"); 
    srand(time(0)); 

    int m, n;
    cout << "Введите размерность матрицы: ";
    cin >> m >> n;

    int **matrix = new int*[m];    // Создание динамической матрицы
    for(int i = 0; i < m; i++) {
        matrix[i] = new int[n];
    }

    Generate_Matrix(matrix, m, n); // Заполнение и вывод матрицы
 
    vector<int> nums; 
    int sum = find_elements(nums, matrix, m, n); // Нахождение элементов и их суммы
    cout << "Массив неотрицательных элементов матрицы, стоящих в чётных строках, на нечётных местах: " << nums << endl;
    cout << "Сумма этих элементов: " << sum << endl;

    for(int i = 0; i < m; i++) {  // Освобождение памяти
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0; 
}
