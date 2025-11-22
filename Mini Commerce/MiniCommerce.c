#include <stdio.h>

#include "libbuy.c"
#include "libsell.c"
#include "libcart.c"
#include "libdatamanager.c"

int main(void)
{
	int State = 1;
	while(State == 1)
	{
		int userInput = 0;

		printf("# Mini Commerce #\n");
		printf("Please select one of the following\n");
		printf("[1] Buy\n[2] Sell\n[3] View Cart\n[4] Exit\n");
		printf("User: ");
		scanf("%i", &userInput);

		switch(userInput)
		{
			case 1:
				if(MainDataSize == 0)
				{
					printf("\nError (0-1) no data found\n\n");
					break;
				}
				buy();
				break;

			case 2:
				sell();
				break;

			case 3:
				if(CartDataSize == 0)
				{
					printf("\nError (0-2) no data found\n\n");
					break;
				}
				cart();
				break;

			case 4:
				printf("\nGoodbye User\n");
				State = 0;
				break;

			default:
				printf("\nError (0-3) command \"%i\" not found\n\n", userInput);
				fflush(stdin);
		}
	}
	return 0;
} // End of main