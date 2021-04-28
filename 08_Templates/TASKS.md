***
### Шаблони
***

### Задача 1(от контролно).
Напишете програма, която поддържа работа със стек. Стекът трябва да може да съдържа всякакъв тип елементи(неограничено количество).Особеното при него е, че, като добавяме елементи, то те се нареждат един над друг и имаме достъп само до последния добавен елемент.  
Трябва във всеки един момент да можем да достъпим:
- броя елементи -- `size_t size() const`
- капацитета на нашия контейнер -- `size_t capacity() const`
- последния добавен елемент -- `Type top() const`  
Освен това би било добре да можем да:
- добавяме елементи -- `void push(const Type&)`
- да махаме елементи, като махането отново е на принципа на достъпването на елементи - можем да махнем само последния добавен елемент -- `void pop()`  
Трябва да можем и да проверяваме дали имаме елементи в контейнера или той е празен -- `bool empty() const `
Още функционалности, които трябва да можем да поддържаме:
- размяна на съдържанието на два контейнера -- `void swap(const Stack<Type>& )`
- събиране на съдържанията на два контейнера в трети, като първо трябва да добавим елементите на първия контейнер и после на втория, без да променяме подредбата на елементите -- `Stack<Type> operator+(const Stakc<Type>& )`
- умножаване на контейнер с число(n), като получаваме нов контейнер със съдържание - n пъти съдържанието на контейнера, който умножаваме, като отново запазваме подредбата -- `Stack<Type>& operator*=(size_t n)`    


![](https://github.com/karinag99/Object-oriented-programming-FMI/blob/main/08_Templates/stack_image_updated.png)


