#include <iostream>
#include <vector>
#include <thread>

using namespace std;

const int SIZE = 3;
int A[SIZE][SIZE], B[SIZE][SIZE], C[SIZE][SIZE];

void multiplyRow(int row) {
    for (int j = 0; j < SIZE; j++) {
        C[row][j] = 0;
        for (int k = 0; k < SIZE; k++) {
            C[row][j] += A[row][k] * B[k][j];
        }
    }
}

int main() {
    cout << "Enter matrix A (" << SIZE << "x" << SIZE << "):\n";
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            cin >> A[i][j];

    cout << "Enter matrix B (" << SIZE << "x" << SIZE << "):\n";
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            cin >> B[i][j];

    vector<thread> threads;
    for (int i = 0; i < SIZE; i++)
        threads.emplace_back(multiplyRow, i);

    for (auto &t : threads)
        t.join();

    cout << "\nResultant Matrix C:\n";
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++)
            cout << C[i][j] << " ";
        cout << endl;
    }

    return 0;
}
