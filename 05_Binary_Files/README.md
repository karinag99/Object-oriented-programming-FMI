***
## Бинарни файлове - файлове с пряк достъп
***

   [Решението, което написахме на практикума](https://codecollab.io/@ivantenevvasilev/%D0%9F%D1%80%D0%B0%D0%BA%D1%82%D0%B8%D0%BA%D1%83%D0%BC%2006.04.2021#)

 - Отваряне на файл
    - добавяма режим `ios::binary`

    ### Пример
    ```cpp
    #include <fstream>
    #include <iostream>

    int main() {

    const char* filename = "test.bin";

    ifstream iFile;
    iFile.open(filename, ios::in | ios::binary);

    //...

    iFile.close();

    return 0;
    }

 - Четене и писане 
    - четене - `read( char * memoryBlock, std::streamsize count )`
    - писане - `write( const char * memoryBlock, std::streamsize count )`

 - get, put указатели
    - `tellg()` - връща текущата позиция на get указателя
    - `tellp()` - връща текущата позиция на put указателя
    - `seekg(\<position>, \<direction>)`
    - `seekp(\<position>, \<direction>)`  
        <b>position</b>  - положително или отрицателно число  
        <b>direction</b> - може да бъде `ios::beg`, `ios::end` или `ios::cur`
