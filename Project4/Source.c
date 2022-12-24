#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <time.h>

struct point {
	float x;
	float y;
	char name;
};

struct product {
	char productName[32];
	int createDay;
	int createMonth;
	int createYear;
	int bestBeforeDate;
	float price;
	int seriaNumber;
};

typedef struct point Point;
typedef struct product Product;

int put_point(Point z);
float dist(Point z, Point w);
float findCenterX(Point z, Point w);
float findCenterY(Point z, Point w);

int main() {
	setlocale(LC_ALL, "RUS");

	// 1
	Point b, a;
	printf("Введите название 1 точки: ");
	scanf("%c", &a.name);
	printf("Введите x координату 1 точки: ");
	scanf("%f", &a.x);
	printf("Введите y координату 1 точки: ");
	scanf("%f", &a.y);
	getchar();
	printf("Введите название 2 точки: ");
	scanf("%c", &b.name);
	getchar();
	printf("Введите x координату 2 точки: ");
	scanf("%f", &b.x);
	printf("Введите y координату 2 точки: ");
	scanf("%f", &b.y);
	put_point(a);
	put_point(b);
	printf("\nРасстояние между %c и %c = %f", a.name, b.name, dist(a, b));
	printf("\nЦентр отрезка между точками %c и %c находится в точке M(%.2f;%.2f)", a.name, b.name, findCenterX(a, b), findCenterY(a, b));

	// 2
	struct tm* mytime;
	time_t t;
	t = time(NULL);
	mytime = localtime(&t);
	printf("Московское время %02d:%02d:%02d \n", mytime->tm_hour, mytime->tm_min, mytime->tm_sec);
	switch (mytime->tm_wday)
	{
	case 0:
		printf("\nСегодня воскресенье");
		break;
	case 1:
		printf("\nСегодня понедельник");
		break;
	case 2:
		printf("\nСегодня вторник");
		break;
	case 3:
		printf("\nСегодня среда");
		break;
	case 4:
		printf("\nСегодня четверг");
		break;
	case 5:
		printf("\nСегодня пятница");
		break;
	case 6:
		printf("\nСегодня суббота");
		break;
	default:
		printf("\nУ вас странная неделя :(");
	}

	// 3
	puts("\n");
	Product anotherProduct;
	puts("Введите название продукта: ");
	scanf("%s", anotherProduct.productName);
	puts("Введите номер дня производства товара(в месяце):");
	scanf("%d", &anotherProduct.createDay);
	puts("Введите номер месяца производства товара:");
	scanf("%d", &anotherProduct.createMonth);
	puts("Введите год производства товара:");
	scanf("%d", &anotherProduct.createYear);
	puts("Введите срок годности товара(в днях):");
	scanf("%d", &anotherProduct.bestBeforeDate);
	puts("Введите цену товара:");
	scanf("%f", &anotherProduct.price);
	puts("Введите номер серии товара:");
	scanf("%d", &anotherProduct.seriaNumber);
	printf("Товар %s. Годен до %02d:%02d:%02d", anotherProduct.productName, (anotherProduct.createDay + anotherProduct.bestBeforeDate), anotherProduct.createMonth, anotherProduct.createYear);
}

int put_point(Point z) {
	printf("\npoint %c (%.1f; %.1f)", z.name, z.x, z.y);
	return 0;
}

float dist(Point z, Point w) {
	float res = sqrt(pow(w.x - z.x, 2) + pow(w.y - z.y, 2));
	return res;
}

float findCenterX(Point z, Point w) {
	float res = (z.x + w.x) / 2;
	return res;
}

float findCenterY(Point z, Point w) {
	float res = (z.y + w.y) / 2;
	return res;
}