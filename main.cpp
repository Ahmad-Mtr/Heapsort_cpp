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

int getLastIndex(int i) {
    return n - i - 1;
}
int _L(int j){
    return 2*j;
}

int _R(int j){
    return 2*j+1;
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

void HeapSort_DrSamer_original() {
    Heapify();
    // Exactly as Notes except lastIndex()
    for (int i = 1; i < n; ++i) {
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
                    Swap(j, 2 * j + 1);
                    j = 2 * j;
                }
            } else if (((2 * j + 1) < getLastIndex(i)) && (A[2 * j + 1] > A[j])) {
                Swap(j, 2 * j + 1);

            } else break;
        }
    }
}
void HeapSort_DrSamer_fixedIndex() {
    Heapify();
    for (int i: A) {
        cout << i << "~~";
    }
    cout<<endl;
    // Fixed Index as Doctor's Code
    for (int i = 0; i < n; ++i) {
        int j = 0;
        Swap(j,n-i-1);
        while(_L(j)< getLastIndex(i)){
            if (A[_L(j)] > A[j]){
                if (_R(j) > getLastIndex(i)){
                    
                }
            }
        }

    }
    for (int i: A) {
        cout << i << "~~#";
    }
    cout<<endl;
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
    //HeapSort_DrSamer_original();
    HeapSort_DrSamer_fixedIndex();
    HeapSort_sol();
    for (int i: A) {
        cout << i << "\t";
    }

    return 0;
}
/*// Fixed Index as Doctor's Code
    for (int i = 0; i < n; ++i) {
        int j = 0;
        Swap(j, getLastIndex(i));
        //Heapify Loop
        while (getLeft(j) <= getLastIndex(i)) {
            if (A[getLeft(j)] > A[j]) {
                if (getRight(j) < getLastIndex(i)) {
                    if (A[getLeft(j)] > A[getRight(j)]) {
                        Swap(getLeft(j), j);
                        j = 2 * j + 1;
                    } else {
                        Swap(j, getRight(j));
                        j = 2 * j + 2;
                    }
                } else {
                    Swap(j, getLeft(j));
                    j = 2 * j + 1;
                }
            } else if (((getRight(j)) < getLastIndex(i)) && (A[getRight(j)] > A[j])) {
                Swap(j, getRight(j));
            } else break;
        }
    }*/
//
//void HeapSort() {   // Exactly as Notes except lastIndex()
//    for (int i = 1; i < n; ++i) {
//        int j = 1;
//        Swap(j, getLastIndex(i));
//
//        while ((2 * j) < getLastIndex(i)) {
//            if (A[2 * j] > A[j]) {
//                if ((2 * j + 1) < getLastIndex(i)) {
//                    if (A[2 * j] > A[2 * j + 1]) {
//                        Swap(2 * j, j);
//                        j = 2 * j;
//                    } else {
//                        Swap(j, 2 * j + 1);
//                        j = 2 * j + 1;
//
//                    }
//                } else {
//                    Swap(j, 2 * j + 1);
//                    j = 2 * j;
//                }
//            } else if (((2 * j + 1) < getLastIndex(i)) && (A[2 * j + 1] > A[j])) {
//                Swap(j, 2 * j + 1);
//
//            } else break;
//        }
//    }
//}