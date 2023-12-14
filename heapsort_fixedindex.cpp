#include <iostream>

using namespace std;
const int n = 5;
int A[n] = {3,7,5,1,9};

int getLeft(int j) {
    return j * 2 + 1;
}
int getRight(int j) {
    return j * 2 + 2;
}
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
void HeapSort_FromNotes_fixedIndex() {
    Heapify();
    // Exactly as Notes - fixed index
    for (int i = 0; i < n; ++i) {
        int last_unsorted_index = getLastIndex(i);

        int j = 0;
        Swap(j, last_unsorted_index);
        while ((getLeft(j)) < last_unsorted_index) {
            int left = getLeft(j);
            int right = getRight(j);

            if (A[left] > A[j]) {
                if ((right) < last_unsorted_index) {
                    if (A[left] > A[right]) {
                        Swap(left, j);
                        j = left;
                    } else {
                        Swap(j, right);
                        j = right;
                    }
                } else {
                    Swap(j, left);
                    j = left;
                }
            } else if ((right < last_unsorted_index) && (A[right] > A[j])) {
                Swap(j, right);

            } else break;
        }
    }

}
int main() {
    HeapSort_FromNotes_fixedIndex();
    for (int i: A) {
        cout << i << "\t";
    }
    return 0;
}