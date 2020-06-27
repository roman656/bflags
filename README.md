# bflags
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
