#include <stdio.h>
#include <locale.h>
#include <math.h>
void main()
{
    //ПРОБЛЕМА ПРОГРАММЫ В ТОМ, ЧТО ЗАПУСКАЕТСЯ ЧЕРЕЗ СТОРОННИЕ КОМПИЛЯТОРЫ, НО НЕ РАБОТАЕТ В VISUAL STUDIO
    //задаем переменные + локализация
    char* locale = setlocale(LC_ALL, "Rus");
    int x1, y1, x2, y2, r1, r2;
    double distance, R, r; //расстояние между центрами, больший и меньший радиус
    //
    //ввод данных
    printf("x1 и y1 - координаты центра 1 окружности, x2 и y2 - координаты центра 2 окружности, r1 и r2 - радиусы 1 и 2 окружности соответственно");
    printf("Введите x1,y1,x2,y2,r1,r2 в соответсвующем порядке ");
    scanf_s("%d,%d,%d,%d,%d,%d", &x1, &y1, &x2, &y2, &r1, &r2);
    //
    //настройка переменных
    distance = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
    if (r1 > r2)
    {
        R = r1;
        r = r2;
    }
    else
    {
        R = r2;
        r = r1;
    }
    //
    //логические преобразования
    if (distance > (R + r))
    {
        printf("Окружности не пересекаются, лежат отдельно друг от друга");
    }
    else if (distance == (R + r))
    {
        printf("Окружности лежат отдельно друг от друга, имеют 1 точку пересечения");
    }
    else if (distance < (R - r))
    {
        printf("Одна окружность лежит внутри другой, не пересекаются");
    }
    else if (distance == (R - r))
    {
        printf("Одна окружность лежит внутри другой, 1 пересечение");
    }
    else if (((R - r) < distance) && (distance < (R + r)))
    {
        printf("Окружности пересекаются в двух точках");
    }
    else if ((distance == 0) && (R == r))
    {
        printf("Окружности совпадают");
    }
    else
    {
        printf("Fail");
    }
}