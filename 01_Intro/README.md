***
## Указатели
***
### Акценти

- съхраняват адреса на дадена променлива

```cpp
    int a = 5;
    int* ptr = &a;
```

- dereference operator (*) - достъпваме стойността на променливата, чийто адрес съхранява указателят

```cpp
    int a = 5;
    int* ptr = &a;

    // 5
    std::cout << *ptr << std::endl;
```  

- имат еднакъв размер, независимо от типа 

```cpp
    int* intPtr;
    char* charPtr;
    double* doublePtr;

    //Same size
    std::cout << sizeof(intPtr) << std::endl 
              << sizeof(charPtr) << std::endl
              << sizeof(doublePtr) << std::endl;
```

- типът има значение за указателната аритметика

```cpp
    int* ptr;
    int arr[5] = {1, 2, 3, 4, 5};

    //arr съвпада с &arr[0]
    ptr = arr;

    //изместваме ptr с две позиции надясно => с 2*sizeof(int)
    std::cout << "Element at index 2" << *(ptr + 2) << std::endl;
```
- заделяне и освобождаване на динамична памет
```cpp
    int size;
    std::cin << size;

    //заделяме динамичен масив от тип int с големина size
    int* arr = new int[size];

    //освобождаваме заделената памет
    //! внимаваме къде освобождаваме паметта 
    //! внимаваме да не изгубим достъп до заделената памет
    delete []arr;
```

- указателите като параметър на функция - с референция или без?
    - промяна на стойността на променливата, към която сочи указателят

    ```cpp
    void increment(int* ptr) {
        *ptr++;
    }

    int main() {

        int a = 5;
        int* ptr = &a;

        increment(ptr);

        // a = 6
        std::cout << "a = " << a << std::endl;

        return 0;
    }
    ```
    - пренасочване на указателя към друго място в паметта
    ```cpp
    void swapPointers(int*& ptr1, int*& ptr2) {
        int* temp;
        temp = ptr1;
        ptr1 = ptr2;
        ptr2 = temp;
    }

    int main() {

        int a = 5;
        int* ptr1 = &a;

        int b = 10;
        int* ptr2 = &b;

        swapPointers(ptr1, ptr2);

        std::cout << "&a = " << &a << std::endl
                  << "&b = " << &b << std::endl
                  << "ptr1 = " << ptr1 << std::endl
                  << "ptr2 = " << ptr2 << std::endl;
        return 0;
    }
    ```
  
***    
## Сложност
## Асимптотични нотации
***

- Сложност - функция на големината на входа
- по памет
- по време

> &theta;(g(n)) = { &fnof;(n) | &exist; &scy;<sub>1</sub>, &scy;<sub>2</sub> > 0, &exist; n<sub>0</sub> &forall; n &ges; n<sub>0</sub> : 0 &les; &scy;<sub>1</sub> &sdot; g(n) &les; &fnof;(n) &les; &scy;<sub>2</sub> &sdot; g(n) }

> &Omicron;(g(n)) = { &fnof;(n) | &exist; &scy; > 0, &exist; n<sub>0</sub> &forall; n &ges; n<sub>0</sub> :
0 &les; &fnof;(n) &les;  &scy; &sdot; g(n) } -> <b>_горна граница_</b>

> &Omega;(g(n)) = { &fnof;(n) | &exist; &scy; > 0, &exist; n<sub>0</sub> &forall; n &ges; n<sub>0</sub> :
0 &les; &scy; &sdot; g(n) &les; &fnof;(n) } -> <b>_долна граница_</b>

> o(g(n)) = { &fnof;(n) | &exist; &scy; > 0, &exist; n<sub>0</sub> &forall; n &ges; n<sub>0</sub> :
0 &les; &fnof;(n) &lt;  &scy; &sdot; g(n) } -> <b>_строга горна граница_</b>

> &omega;(g(n)) = { &fnof;(n) | &exist; &scy; > 0, &exist; n<sub>0</sub> &forall; n &ges; n<sub>0</sub> :
0 &les; &scy; &sdot; g(n) &lt; &fnof;(n) } -> <b>_строга долна граница_</b>


