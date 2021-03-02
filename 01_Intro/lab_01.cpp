#include <iostream>

//task_01

//сложност по време - O(size)
//сложност по памет - константа
int findElement(int* arr, int size, int x) {

    for(int i = 0; i < size; i++) {
        if(arr[i] == x)
            return i;
    }

    return -1;
}

//рекурсивен алг. :
//сложност по време - O(log(n))
//сложност по памет - O(log(n))
int binarySearchRec(int* arr, int x, int l, int r) {

    if(l <= r) {
        
        int mid = (r - l)/2 + l;

        if(arr[mid] == x)
            return mid;
        
        if(arr[mid] < x)
            return binarySearchRec(arr, x, mid + 1, r);

        return binarySearchRec(arr, x, l, mid - 1);
    }

    return -1;
}

//итеративен алг. :
//сложност по време - O(log(n))
//сложност по памет - константна
int binarySearchIt(int* arr, int x, int l, int r) {

    while(l <= r) {

        int mid = (r - l)/2 + l;

        if(arr[mid] == x)
            return mid;

        if(arr[mid] < x)
            l = mid + 1;
        else 
            r = mid - 1;
    }

    return -1;
}

//task_02

//сложност по време - O(n^2)
//сложност по памет - константна
int findUnique(int* arr, int size) {

    bool flag;

    for(int i = 0; i < size; i++) {
        flag = 0;

        for(int j = 0; j < size; j++) {
            if(j == i)
                continue;
            if(arr[j] == arr[i])
                flag = 1;
        }

        if(!flag)
            return arr[i];
    }
    return -1;
}

//хистограма
//сложност по време - θ(n)
//сложност по памет - линейнa
int findUniqueBetterVersion(int* arr, int size) {

    int* hist = new int[size];

    for(int i = 0; i < size; i++) {
        hist[i] = 0;
    }

    for(int i = 0; i < size; i++) {
        hist[arr[i] - 1]++;
    }

    for(int i = 0; i < size; i++) {
        if(hist[i] == 1) {
            delete[] hist;
            return i + 1;
        }
    }

    delete[] hist;
    return -1;
}

// А ^ A = 0
// A ^ B ^ B ^ A = 0
// A ^ B ^ B ^ A  ^ C = C

//сложност по време - θ(n)
//сложност по памет - константна
int findUniqueBestVersion(int* arr, int size) {

    int res = arr[0];

    for(int i = 1; i < size; i++) 
        res = res ^ arr[i];

    return res;
}

int main() {

    return 0;
}