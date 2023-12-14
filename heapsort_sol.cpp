#include <iostream>

using namespace std;
const int n = 5;
int A[n] = {3,7,5,1,9};

int getLeft(int index) {
    return index * 2 + 1;
}
int getRight(int index) {
    return index * 2 + 2;
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
void HeapSort_sol() {
    Heapify();
    for (int i = n - 1; i > 0; --i) {
        Swap(0, i);
        int j = 0;
        while (getLeft(j) < i) {
            int maxChild = getLeft(j);
            if (getRight(j) < i && A[getRight(j)] > A[maxChild]) {
                maxChild = getRight(j);
            }
            if (A[maxChild] > A[j]) {
                Swap(maxChild, j);
                j = maxChild;
            } else {
                break;
            }
        }
    }
}
int main() {
    HeapSort_sol();
    for (int i: A) {
        cout << i << "\t";
    }
    return 0;
}