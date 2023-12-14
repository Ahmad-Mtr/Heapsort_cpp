#include <iostream>

using namespace std;
const int n = 5;
int A[n] = {3,7,5,1,9};

int getLastIndex(int i) {
    return n - i - 1;
}
void Swap(int indexA, int indexB) {
    int temp = A[indexA];
    A[indexA] = A[indexB];
    A[indexB] = temp;
}
void Heapify() {
    for (int i = 1; i < n; ++i) {
        int j = i;
        while (j > 0) {
            if (A[j] > A[j / 2]) {
                Swap(j, j / 2);
                j = j / 2;
            } else {
                break;
            }
        }
    }
}
void HeapSort_FromNotes_original() {
    Heapify();
    // Exactly as Notes
    for (int i = 1; i <= n; ++i) {
        int j = 1;
        Swap(j, getLastIndex(i));

        while ((2 * j) < getLastIndex(i)) {
            if (A[2 * j] > A[j]) {
                if ((2 * j + 1) < getLastIndex(i)) {
                    if (A[2 * j] > A[2 * j + 1]) {
                        Swap(2 * j, j);
                        j = 2 * j;
                    } else {
                        Swap(j, 2 * j + 1);
                        j = 2 * j + 1;
                    }
                } else {
                    Swap(j, 2 * j);
                    j = 2 * j;
                }
            } else if (((2 * j + 1) < getLastIndex(i)) && (A[2 * j + 1] > A[j])) {
                Swap(j, 2 * j + 1);

            } else break;
        }
    }
}
int main() {
    HeapSort_FromNotes_original();
    for (int i: A) {
        cout << i << "\t";
    }
    return 0;
}