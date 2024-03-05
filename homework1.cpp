#include <iostream>
#include <omp.h>
using namespace std;
int main() 
{
    setlocale(LC_ALL, "Russian");
    int k, N;
    cout << "Введите количество чисел (N): ";
    cin >> N;
    cout << "Введите количество потоков (k): ";
    cin >> k;
    int total_sum = 0;
    #pragma omp parallel num_threads(k) reduction(+:total_sum)
    {
        int id = omp_get_thread_num();
        int partial_sum = 0;
        for (int i = id + 1; i <= N; i += k) 
        {
            partial_sum += i;
        }
        #pragma omp critical
        {
            cout << "[" << id << "]: Sum = " << partial_sum << endl;
        }
        total_sum += partial_sum;
    }
    cout << "Sum = " << total_sum << endl;
    return 0;
}
