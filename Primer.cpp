// Костенко.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


vector<double> input_numbers(size_t count) {
    vector<double> result(count);
    for (size_t i = 0; i < count; i++) {
        cin >> result[i];
    }
    return result;
}

void find_minmax(vector<double> numbers, double& min, double& max) {
    min = *min_element(numbers.begin(), numbers.end());
    max = *max_element(numbers.begin(), numbers.end());
}


vector<size_t> make_histogram(vector<double> numbers, size_t bin_count) {
    vector<size_t> bins(bin_count);
    double min, max;
    find_minmax(numbers, min, max);
    double bin_size = (max - min) / bin_count;
    for (size_t i = 0; i < numbers.size(); i++) {
        bool found = false;
        for (size_t j = 0; (j < bin_count - 1) && !found; j++) {
            auto lo = min + j * bin_size;
            auto hi = min + (j + 1) * bin_size;
            if ((lo <= numbers[i]) && (numbers[i] < hi)) {
                bins[j]++;
                found = true;
            }
        }
        if (!found) {
            bins[bin_count - 1]++;
        }
    }
    return bins;
}

void show_histogram_text(vector<size_t> bins) {
    const size_t SCREEN_HEIGHT = 20;
    auto max_count = *max_element(bins.begin(), bins.end());
        if (max_count > SCREEN_HEIGHT)
            for (int i = 0; i < bins.size(); i++)
                bins[i] = SCREEN_HEIGHT * (static_cast<double>(bins[i]) / max_count);
        bool print_end;
        for (int i = 0; i < SCREEN_HEIGHT; i++) {
            print_end = true;
            for (int j = 0; j < bins.size(); j++) {
                if (bins[j] > i) {
                    cout << "*";
                    print_end = false;
                }
                else
                    cout << " ";
            }
            if (print_end)
                break;
            cout << endl;
        }
}


int main() {
    
    setlocale(LC_ALL, "Russian");
    size_t number_count, bin_count;
    cerr << "Enter number count: ";
    cin >> number_count;
    const auto numbers = input_numbers(number_count);
    cerr << "Enter bin count: ";
    cin >> bin_count;
    auto bins = make_histogram(numbers, bin_count);
    show_histogram_text(bins);
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
