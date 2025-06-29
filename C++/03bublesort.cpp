#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <random>
#include <chrono> // For timing
using namespace std;
using namespace std::chrono;

void bubble_sort(vector<int>& vec) {
    int n = vec.size();
    for (int i = 0; i < n - 1; ++i) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; ++j) {
            if (vec[j] > vec[j + 1]) {
                // Swap using std::swap
                swap(vec[j], vec[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}


int main() {


    // Start timing
    int n = 1000;
    auto start = high_resolution_clock::now();
    std::vector<int> input_data;
    for (int i=n; i > 0; --i) input_data.push_back(i);
    bubble_sort(input_data);
    cout << input_data.size();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "\nsorting time for " <<n <<" records is "<< duration.count()/1000 << " miniseconds" << endl;


    n = 2000;
    start = high_resolution_clock::now();
    input_data.clear();
    for (int i=n; i > 0; --i) input_data.push_back(i);
    bubble_sort(input_data);
    cout << input_data.size();
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "\nsorting time for " <<n <<" records is "<< duration.count()/1000 << " miniseconds" << endl;

    n = 4000;
    start = high_resolution_clock::now();
    input_data.clear();
    for (int i=n; i > 0; --i) input_data.push_back(i);
    bubble_sort(input_data);
    cout << input_data.size();
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "\nsorting time for " <<n <<" records is "<< duration.count()/1000 << " miniseconds" << endl;

    n = 8000;
    start = high_resolution_clock::now();
    input_data.clear();
    for (int i=n; i > 0; --i) input_data.push_back(i);
    bubble_sort(input_data);
    cout << input_data.size();
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "\nsorting time for " <<n <<" records is "<< duration.count()/1000 << " miniseconds" << endl;

    n = 16000;
    start = high_resolution_clock::now();
    input_data.clear();
    for (int i=n; i > 0; --i) input_data.push_back(i);
    bubble_sort(input_data);
    cout << input_data.size();
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "\nsorting time for " <<n <<" records is "<< duration.count()/1000 << " miniseconds" << endl;

    return 0;
}
