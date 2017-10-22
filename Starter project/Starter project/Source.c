#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#define MAX_LENGHT 256
struct dates {
	int date;
	int month;
	int year;
};
void lenght();
void position();
void calendar();
void NumberLenght();
int main() {
	int input = 0;
	
		do {
				printf("|------------------------------|\n");
				printf("|Validate position:        (1.)|\n");
				printf("|Validate lenght:          (2.)|\n");
				printf("|Validate Number lenght:   (3.)|\n");
				printf("|Validate date:            (4.)|\n");
				printf("|Exit:                     (5.)|\n");
				printf("|------------------------------|\n");
				printf("Type in:");
				input = getchar();
if (input >= '0'&&input <= '4') {
				getchar();

				switch (input) {
					
				case '1':
					position();

					break;
				case '2':
					lenght();
					break;
				case '3':
					NumberLenght();

					break;
				case '4':
					calendar();
					break;
				case '5':
					exit(0);
					break;
					}
}
else { break; }
		} while (input != '4');
	
	system("pause");
	return 0;
}
void calendar() {
	struct dates taker;
	int  i = 0;
	do {
		printf("Validation: D/M/Y:\n");
		scanf("%d/%d/%d", &taker.date, &taker.month, &taker.year);
		if (taker.month >= 1 && taker.month <= 12) {
			if (taker.date >= 1 && taker.date <= 31) {
				if (taker.year >= 0 && taker.year <= 100000) {
					if (taker.month >= 1 && taker.month <= 12) {
						if ((taker.date >= 1 && taker.date <= 31) && (taker.month == 1 || taker.month == 3 || taker.month == 5 || taker.month == 7 || taker.month == 8 || taker.month == 10 || taker.month == 12)) {
							i++;
						}
						if ((taker.date >= 1 && taker.date <= 30) && (taker.month == 4 || taker.month == 6 || taker.month == 9 || taker.month == 11)) {
							i++;
						}
						if ((taker.date >= 1 && taker.date <= 28) && (taker.month == 2)) {
							i++;
						}
						if (taker.date == 29 && taker.month == 2 && (taker.year % 400 == 0 || (taker.year % 4 == 0 && taker.year % 100 != 0))) {
							i++;
						}
						if (i > 0) {
							printf("The date exists!\n"); break;
						}
						else { printf("Date doesn't exist!\n"); break; }

					}
					else { printf("Unexisting month!\n"); break; }

				}
				else {
					printf("Unexisting year!\n"); break;
				}
			}
			else {
				printf("No date inserted!\n"); break;
			}
		}
		else {
			printf("No month inserted!\n"); break;
		}

	} while (i != 1);
}
void position() {
	char string[MAX_LENGHT];
	char a;
	int counter = 0;
	int getch();
	printf("You can only enter lowercase characters below!\n");
	printf("Else Program stopps!\n");
	printf("________________________________________________________________________________\n");
	printf("-->");
	do {
		a = getch();
		if (a != '\r') {
			if (a >= 'a'&&a <= 'z') {
				string[counter] = a;
				counter++;
				string[counter] = '\0';
				printf("%c", string[counter - 1]);
			}
			else { printf("\nYou can only enter lowercase characters!\n"); }
		}
		else {
			printf("\nEntered letters are correct:%s\n", string);
			counter = MAX_LENGHT;
		}
	} while (counter<256);
}
void lenght() {
	char a;
	int counter = 0;
	char string[MAX_LENGHT];
start:
	printf("|-------------------------------|\n");
	printf("|Password lenght is 10 symbols. |\n");
	printf("|[Enter password]               |\n");

	printf("[>>:");
	while ((a = _getche()) != '\r') {
		printf("\b*");
		if ((a >= 'a'&&a <= 'z') || (a >= 'A'&&a <= 'Z')) {
			string[counter] = a;
			counter++;
			string[counter] = '\0';
		}
		else { printf("\nPassword contains only Lower and Upper case letters!!!\n"); goto start; }

		if (counter + 1>10)
		{
			printf("\nPassword is :(%s)\n", string);  break;
		}
	}
	system("pause");
}
void NumberLenght() {

	int a = 0;
	int getch();
	int counter = 0;
	char string[MAX_LENGHT];
	char x = '-';
	printf("Serial number contains 10 numeric code!\n");
	printf("Insert Serial number:");
	do {
		a = getch();
		if (a >= 48 && a <= 57) {
			string[counter] = a;
			counter++;
			string[counter] = '\0';
			printf("%c", string[counter - 1]);
		}
		else {
			printf("\nYou can only insert integer!\n");

		}if (counter == 2 || counter == 4 || counter == 6 || counter == 8)
			printf("%c", x);
		else if (counter == 9) {
			x = 0;
		}

	} while (counter < 10);
	printf("\n");
	system("pause");
}