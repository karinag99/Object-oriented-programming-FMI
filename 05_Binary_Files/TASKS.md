
### Класове и бинарни файлове
***
<b>Задача 1.</b>  
Реализирайте клас <b>Date</b>, който пази информацията за дата,
т.е.: ден, месец, година. Да се реализират и следните
функционалности:  
- Конструктори  
- Извеждане на дата в следния вид : dd.mm.yyyy  
- Промяна на датата  
- Позволяват се помощни функции  


Реализирайте клас <b>Event</b>, съдържащ информацията за
събитие.  
Всяко събитие има следните атрибути:  
- Дата
- Продължителност (не повече от 3 часа)
- Кратко описание(до 128 символа)
И следните функционалности(позволени са помощни функции):
- Извеждане на събитие
- Промяна на датата
- Промяна на продължителността 


Реализирайте клас <b>Calendar</b>, съдържащ информацията за
множество събития(най-много 50). Нека има следните
функции:  
- Добавяне на събитие(сборът от продължителностите на
събитията в даден ден не трябва да надвишава 6 часа)
- Промяна на дата или продължителност на дадено събитие
(различаваме ги по техните описания)
- Сортиране на събитията по дати
- Извеждане на събитията за определена дата
- Конструктор с параметър - името на бинарен файл
- Функция, която запазва срещите в бинарен файл  
Реализирайте функция, която по подаден двоичен файл(съдържащ
множество от обекти от тип Event) , извежда на конзолата само
тези, които се намират на нечетна позиция.