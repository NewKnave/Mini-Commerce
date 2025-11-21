#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void BuyProduct(void);
void SellProduct(void);
void Cart(void);

typedef struct {
	char *name;
	float price;
	int id;
	int quantity;
	} data;

int main(void) {
	int isRunning = 1;
	int mainDataSize = 0;
	int cartDataSize = 0;

	int idCounter = 0;
	int userInput = 0;

	while(isRunning == 1) {
			printf("# Mini Commerce #\n");
			printf("Please select one of the following\n");
			printf("[1] Buy\n[2] Sell\n[3] View Cart\n[4] Exit\n");
			printf("User: ");
			scanf("%i", &userInput);

			switch(userInput) {
				case 0:
				printf("\nError (0-0) Invalid input\n\n");
				fflush(stdin); // Clears the input
				break;

				case 1:
				if(mainDataSize == 0) {
					printf("\nError (0-1) no data found	\n\n");
					break;
					}
				BuyProduct();
				break;

				case 2:
				idCounter++;
				SellProduct();
				break;

				case 3:
				if(cartDataSize == 0) {
					printf("\nError (0-2) no data found	\n\n");
					break;
					}
				Cart();
				break;

				case 4:
				printf("\nGoodbye User\n");
				return 0;

				default:
				printf("\nError (0-3) command \"%i\" not found\n\n", userInput);
			}
		userInput = 0;
		}

	return 0;
	} // End of main

void BuyProduct(void) {}
void SellProduct(void) {}
void Cart(void) {}