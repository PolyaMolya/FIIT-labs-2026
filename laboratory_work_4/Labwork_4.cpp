#include "stdio.h"
#include "stdlib.h"
#define SIZE 10

int find_index(char elem[], char code[][7]) {
	int index = -1;
	int flag = 0;
	for (int i = 0; i < SIZE; i++) {
		flag = 0;
		for (int j = 0; j < 4; j++) 
			if (code[i][j] != elem[j]) {
				flag++;
				break;
			}
		if (flag == 0)
			return i;
	}
	return index;
}

int round(float num) {
	int num_int = (int)(num * 10);
	num_int = num_int % 10;
	if (num_int > 5)
		return (int)(num + 1);
	else
		return (int)num;
}


int main() {
	char code[SIZE][7] = {"1234\0", "5678\0", "2345\0", "9548\0", "8934\0", "5289\0", "9999\0", "3368\0", "8732\0", "4760\0"};
	int cost[SIZE] = { 100, 200, 350, 700, 500, 470, 260, 125, 900, 1200 };
	int quantity[SIZE] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int discount[SIZE] = { 30, 20, 10, 15, 45, 20, 25, 10, 5, 1 };
	char names[SIZE][20] = { "Bread\0", "Chips\0", "Potatoes\0", "Cola\0", "Chicken\0", "Candies\0", "Carrots\0", "Water bottle\0", "Sausages\0", "Beef\0" };
	printf("Products:\n");
	for (int i = 0; i < SIZE; i++) {
		printf("%i)", i + 1);
		printf("%s, ", names[i]);
		printf("code: %s, ", code[i]);
		printf("cost: %i, ", cost[i]);
		printf("discount: %i%%\n", discount[i]);
	}
	int input = 0;
	int flag = 0;
	int continue_cycle = 0;
	char c;
	int index_input = -1;
	int total_cost = 0;
	int total_cost_without_discount = 0;
	int cnt = 1;
	do {
		flag = 0;
		continue_cycle = 0;
		printf("\n1)Scan code\n2)Print description\n3)Add to check\n4)Print check\n5)Calculate total cost\n\nEnter number(1-5): ");
		scanf_s("%i", &input);
		while ((c = getchar()) != '\n') ;
		printf("\n");
		switch (input) {
		case(1):
			do {
				char input_code[7] = { "0000\0" };
				printf("Enter code: ");
				for (int i = 0; i < 4; i++)
					scanf_s("%c", &input_code[i]);
				while ((c = getchar()) != '\n');
				index_input = find_index(input_code, code);
				if (index_input == -1)
					printf("\nCode not found, please enter again\n");
			} while (index_input == -1);
			printf("\nCode found!\n");
			continue_cycle++;
			break;
		case(2):
			if (index_input == -1) 
				printf("Please enter code first\nEnter 1 to scan code\n");
			else 
				printf("\n%s\nCode: %s\nCost: %i\nDiscount: %i%%\n", names[index_input], code[index_input], cost[index_input], discount[index_input]);
			continue_cycle++;
			break;
		case(3):
			if (index_input == -1)
				printf("Please enter code first\nEnter 1 to scan code\n");
			else {
				quantity[index_input]++;
				total_cost += cost[index_input] - round((float)cost[index_input] / 100.0 * (float)discount[index_input]);
				printf("%s was successfully added to check!\n", names[index_input]);
			}
			continue_cycle++;
			break;
		case(4):
			for (int i = 0; i < SIZE; i++)
				if (quantity[i]) {
					printf("%i)%s - %i - %i - %i\n", cnt, names[i], cost[i], quantity[i], quantity[i] * round(cost[i] - ((float)cost[i] / 100.0 * (float)discount[i])));
					cnt++;
					total_cost_without_discount += cost[i] * quantity[i];
				}
			printf("\nTotal(without discount): %i\nTotal discount: %i\nTotal: %i\n", total_cost_without_discount, total_cost_without_discount - total_cost, total_cost);
			break;
		case(5):
			printf("Total cost will be: %i\n", total_cost);
			continue_cycle++;
			break;
		default:
			flag++;
		}
		if (flag) {
			printf("\nError: number must be in range 1-5\n");
		}
	} while (flag || continue_cycle);
}