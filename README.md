# bflags
## Общая информация
Библиотеку флагов **bflags** можно использовать в программах, написанных на языках программирования *С/C++*.    
**bflags** позволяет создавать переменные типа *Flags*, содержащие по 8 флагов каждая. Если необходимо использовать более 8 флагов достаточно создать массив переменных этого типа.    
Для работы с флагами были созданы специальные функции и процедуры. Использование их не по назначению может привести к некорректной работе программы.    
## Описание функций и процедур

Название | writeDecNumberInSystemN
--- | ---
Назначение | Преобразовывает полученное положительное целое десятичное число в N-ную систему счисления и записывает результат в виде строки.
Входные параметры | `number` - десятичное число, представление которого в N-ной системе счисления необходимо получить (число должно быть больше или равно 0); `output` - указатель на буфер, куда будет записан результат (не равен `NULL`); `outputLength` - размер буфера (число должно быть больше или равно 2. 1-й байт необходим для завершения выходной строки '\0', а 2-й - для записи хотябы одного символа результата. Прочие байты (если есть) будут заполнены остальными символами результата и нулями); `system` - система счисления, в которую необходимо перевести полученное число: 2 - в двоичную, 3 - в троичную, ... (число должно быть больше или равно 2, но меньше 21).
Выходной параметр | Целое число: *0* - функция отработала без ошибок; *-1* - ошибка во входных/входном параметрах; *-2* - свободное место для записи результата в `output` закончилось.
Аномалии | Не выявлены.
Правило вызова | short writeDecNumberInSystemN (const unsigned int number, char * const output, const unsigned int outputLength, const unsigned short system);

## Подключение
Для использования данной библиотеки в своих проектах необходимо выполнить следующие действия:
1. Скачать файлы *bflags.h* и *bflags.c* на свой компьютер.
2. Подключить библиотеку с помощью директивы *#include "путь_до_директории_со_скачанными_файлами/bflags.h"*. 
3. Убедиться, что имена процедур, функций... из *bflags.h* не совпадают с прочими в проекте.
4. Для улучшения читабельности кода можно сделать смысловые "обертки" над библиотечными функциями.
Допустим, что флаг *F5* отвечает за отображение чего-либо в вашем проекте. Тогда можно создать следующую процедуру:
```C
void setVisibilityOn(Flags* target)
{
    setOnExactFlags(Flags* target, F5);
}
```
Таким образом можно адаптировать библиотеку **bflags** под нужды конкретного проекта.
