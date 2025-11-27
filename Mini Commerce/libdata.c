typedef struct MarketData
{
	char *id;
	char *name;
	float price;
	int quantity;
	struct MarketData *link;
} MarketData;

MarketData *head;

int ProductIDCounter = 0;
int TotalProducts = 0;
int TotalProductsInCart = 0;

void CreateLinkedList(void)
{
	MarketData *temp;
	MarketData *next;
	MarketData *product;
}

void MiniCommerce(int ClientID);
void Profile(int ProfileID);
void Buy(void);
void Sell(void);
void Cart(void);

bool IsMiniCommerceRunning = true;

void MiniCommerce(int ClientID)
{
	fflush(stdin);

	char UserInput[64];
	int Selection;

	while (IsMiniCommerceRunning == true) {
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
			Profile(ClientID);
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

void Profile(int ProfileID)
{
	bool IsProfileRunning = true;
	int UserDataLocation = (ProfileID / 10) -1;

	int NameLenght = 0;
	int PasswordLenght = 0;
	char PasswordBuffer[64];
	char HashCache[64];

	int OldNameLenght = 0;
	char OldName[64];
	int OldPasswordLenght = 0;
	char OldPassword[64];

	char UserInput[64];
	int Selection;

	while (IsProfileRunning == true) {
		printf("\n# Profile #\n");
		printf("Name: %s\n", user[UserDataLocation].name);
		printf("ID: %i\n\n", user[UserDataLocation].id);
		printf("[1] Change name\n");
		printf("[2] Change password\n");
		printf("[3] Exit profile\n");
		printf("[4] Log out\n");
		printf("User: ");

		fgets(UserInput, sizeof(UserInput), stdin);
		UserInput[strcspn(UserInput, "\n")] = '\0';
		Selection = atoi(UserInput);

		switch (Selection) {

		case 1:
			OldNameLenght = strlen(user[UserDataLocation].name);
			strcpy(OldName, user[UserDataLocation].name);

			printf("\nChanging name\n");
			printf("User: ");
			fgets(UserInput, sizeof(UserInput), stdin);
			UserInput[strcspn(UserInput, "\n")] = '\0';
			NameLenght = strlen(UserInput);

			if(NameLenght >= 4 && NameLenght <= 64) {
				user[UserDataLocation].name = realloc(user[UserDataLocation].name, NameLenght * sizeof(char));

				if(user[UserDataLocation].name == NULL) {
					while(user[UserDataLocation].name == NULL) {
						user[UserDataLocation].name = realloc(user[UserDataLocation].name, OldNameLenght * sizeof(char));
					}
					printf("Something went wrong\n");
					strcpy(user[UserDataLocation].name, OldName);
				}

				else {
					strcpy(user[UserDataLocation].name, UserInput);
				}
				break;
			}

			else {
				printf("\nInvalid name\n");
			}
			break;

		case 2:
			printf("Changing password\n");
			printf("User: ");
			fgets(UserInput, sizeof(UserInput), stdin);
			UserInput[strcspn(UserInput, "\n")] = '\0';
			PasswordLenght = strlen(UserInput);

			if(PasswordLenght >= 8 && PasswordLenght <= 64) {
				user[UserDataLocation].name = realloc(user[UserDataLocation].name, sizeof(char));
				
				for(int i = 0; i < PasswordLenght; i++) {
					HashCache[i] = ((UserInput[i] % 10) + '0');
					if(i == (PasswordLenght + 1)) {
					HashCache[i] = '\0';
					}
				}

				strcpy(user[UserDataLocation].name, HashCache);
				break;
			}

			else {
				printf("\nInvalid password\n");
			}
			break;

		case 3:
			printf("\nExiting profile\n\n");
			IsProfileRunning = false;
			break;

		case 4:
			printf("\nGoodbye user\n\n");
			IsProfileRunning = false;
			IsMiniCommerceRunning = false;
			break;

		default:
			printf("\n\"%s\" not found\n\n", UserInput);
		}

		fflush(stdin);
	}

	return;
}

void Buy(void)
{
	if(TotalProducts == 0) {
		printf("\nMarket is empty\n\n");
		return;
	}

	bool IsBuyRunning = true;
	char UserInput[64];
	int Selection;

	while (IsBuyRunning == true) {
		printf("\n# Buying #\n");
		printf("[1] View Item\n");
		printf("[2] Add to cart\n");
		printf("[3] Exit\n");
		printf("User: ");

		fgets(UserInput, sizeof(UserInput), stdin);
		UserInput[strcspn(UserInput, "\n")] = '\0';
		Selection = atoi(UserInput);

		switch (Selection) {

		case 1:
			break;

		case 2:
			break;

		case 3:
			printf("\nExiting buy\n");
			IsBuyRunning = false;
			break;

		default:
			printf("\n\"%s\" not found\n\n", UserInput);
		}

		fflush(stdin);
	}

	return;
}

void Sell(void)
{
	bool IsSellRunning = true;
	char UserInput[64];
	int Selection;

	while (IsSellRunning == true) {
		printf("\n# Selling #\n");
		printf("[1] Add product\n");
		printf("[2] Update product\n");
		printf("[3] Remove product\n");
		printf("[4] Exit\n");
		printf("User: ");

		fgets(UserInput, sizeof(UserInput), stdin);
		UserInput[strcspn(UserInput, "\n")] = '\0';
		Selection = atoi(UserInput);

		switch (Selection) {

		case 1:
			break;

		case 2:
			break;

		case 3:
			break;

		case 4:
			printf("\nExiting sell\n\n");
			IsSellRunning = false;
			break;

		default:
			printf("\n\"%s\" not found\n\n", UserInput);
		}

		fflush(stdin);
	}

	return;
}

void Cart(void)
{
	bool IsCartRunning = true;
	char UserInput[64];
	int Selection;

	while (IsCartRunning == true) {
		printf("\n# Cart #\n");
		printf("[1] View contents\n");
		printf("[2] Remove a product\n");
		printf("[3] Exit\n");
		printf("User: ");

		fgets(UserInput, sizeof(UserInput), stdin);
		UserInput[strcspn(UserInput, "\n")] = '\0';
		Selection = atoi(UserInput);

		switch (Selection) {

		case 1:
			break;

		case 2:
			break;

		case 3:
			printf("\nExiting cart\n\n");
			IsCartRunning = false;
			break;

		default:
			printf("\n\"%s\" not found\n\n", UserInput);
		}

		fflush(stdin);
	}

	return;
}