#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct MarketData
{
	char *id;
	char *name;
	float price;
	int quantity;
	struct MarketData *link;
} MarketData;

MarketData *head;

void CreateLinkedList(void)
{
	MarketData *temp;
	MarketData *next;
	MarketData *product;
}

void MiniCommerce(int ClientID);
void Profile(void);
void Buy(void);
void Sell(void);
void Cart(void);

void MiniCommerce(int ClientID)
{
	bool IsProgramRunning = true;
	char UserInput[64];
	int Selection;

	while (IsProgramRunning == true) {
		printf("# Mini Commerce #\n");
		printf("[1] Profile\n");
		printf("[2] Buy\n");
		printf("[3] Sell\n");
		printf("[4] Cart\n");
		printf("User: ");

		fgets(UserInput, sizeof(UserInput), stdin);
		UserInput[strcspn(UserInput, "\n")] = '\0';
		Selection = atoi(UserInput);

		switch (Selection) {

		case 1:
			Profile();
			break;

		case 2:
			Buy();
			break;

		case 3:
			Sell();
			break;

		case 4:
			Cart();
			break;

		default:
			printf("\n\"%s\" not found\n\n", UserInput);
		}

		fflush(stdin);
	}
}

void Profile(void)
{

}

void Buy(void)
{

}

void Sell(void)
{

}

void Cart(void)
{

}