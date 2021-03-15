#include <iostream>
#include <vector>

void printSubset(unsigned num, int* set, unsigned size) {

	//променлива, с която ще итерираме по битовете
	int mask = 1;
	//променлива, с която итрерираме по множеството
	int pos = size - 1;

	std::cout << "{";
	for (size_t j = 0; j < size; j++) {

		//проверяваме дали текущият бит е вдигнат или не
        //ако е вдигнат => отпечатваме съответния елемент от множеството
		if (num & mask) {
			std::cout << ' ' << set[pos] << ' ';
		}

		mask <<= 1;
		pos--;
	}

	std::cout << "}" << std::endl;
}


void getSubsets(int* set, int size) {

	//нмираме броя подмножества
	int countSubsets = 1 << size;

	//генерираме числа между 0 и countSubsets - 1
	//в двоична бройна система всяко число представлява редица от 0 и 1
	//където 0 - показва, че елементът на тази позиция не се включва в текущото подмножество
	// 1 - показва, че елементът на тази позиция се включва в текущото подмножество
	for (unsigned i = 0; i <= countSubsets - 1; i++) {

		printSubset(i, set, size);

	}
}

void printSubsetRec(int* set, unsigned size, bool* subset) {

    std::cout << '{';

    for(int i = 0; i < size; i++) {
        if(subset[i])
            std::cout << ' ' << set[i] << ' ';
    }

    std::cout << '}' << std::endl;
}

void getSubsetsRec(int* set, unsigned size, bool* subset, unsigned pos = 0) {

    if(pos == size) {
        printSubsetRec(set, size, subset);
        return;
    }

    //за всеки елемент имаме по две опции:
    // - да не участва в текущото подмножество
    subset[pos] = 0;
    getSubsetsRec(set, size, subset, pos + 1);

    // - да участва в текущото подмножество
    subset[pos] = 1;
    getSubsetsRec(set, size, subset, pos + 1);
}

void getSubsetsRecWrapper(int* set, unsigned size) {

    bool* subset = new bool[size];

    getSubsetsRec(set, size, subset);

    delete[] subset;
}

int main() {

    int arr[] = {1, 2, 3, 4};
    getSubsets(arr, 4);

    std::cout << std::endl;
    getSubsetsRecWrapper(arr, 4);

    return 0;
}