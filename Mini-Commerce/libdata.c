// Variable set 1 on "libglobalvar.c"
// const int COMMERCE_MAX_NAME_LENGHT = (20 + 1);

void Profile(int ClientID) {

	FILE *file_client = NULL;

	file_client = fopen("data_client.dat", "rb");

	typedef struct {
		char name[CLIENT_MAX_NAME_LENGHT];
		char hash[CLIENT_MAX_HASH_LENGHT];
		int id;
	} ClientData;

	ClientData client[1];

	fclose(file_client);

	return;
}

void Buy(void) {

	FILE *file_product = NULL;

	typedef struct {
		int id;
		char name[COMMERCE_MAX_NAME_LENGHT];
		float price;
		int quantity;
	} CommerceData;

	CommerceData product[1];

	return;
}

void Sell(void) {

	int TEMP_ID;
	char TEMP_NAME[COMMERCE_MAX_NAME_LENGHT];
	float TEMP_PRICE;
	int TEMP_QUANTITY;

	FILE *file_product = NULL;

	typedef struct {
		int id;
		char name[COMMERCE_MAX_NAME_LENGHT];
		float price;
		int quantity;
	} CommerceData;

	bool IsFuncSellRunning = true;

	while(IsFuncSellRunning == true) {
	
	}

	CommerceData product[1];

	return;
}

void Cart(void) {

	FILE *file_cart = NULL;

	typedef struct {
		int id;
		char name[COMMERCE_MAX_NAME_LENGHT];
		float price;
		int quantity;
	} CommerceData;

	CommerceData product[1];

	return;
}

bool IsMiniCommerceRunning = true;

void MiniCommerce(int CLIENT_SESSION) {

	int ClientID = CLIENT_SESSION;

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

	return;
}