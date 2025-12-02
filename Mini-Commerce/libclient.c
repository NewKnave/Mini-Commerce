#define SUCCESS 0
#define FAILED 1

const int CLIENT_MAX_NAME_LENGHT = (64 + 1);
const int CLIENT_MAX_HASH_LENGHT = (64 + 1);
const int CLIENT_MAX_ID_LENGHT = (16 + 1);

int CurrentClientSession(void);
int SignInValidation(void);
void SignInProcess(void);

void SignUp(void);
int SignUpProcess(void);

void SimpleHash(const char *input, char *output, int out_len) {

	unsigned long hash = 5381;
    int c;

    while((c = *input++)) {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
	}

    snprintf(output, out_len, "%lx", hash);

	return;
}

char CURRENT_SESSION_ID[CLIENT_MAX_ID_LENGHT]; // Global session variable

int SignIn(void) {

    FILE *file_client;

    file_client = fopen("data_client.dat", "rb");

    if(file_client == NULL) {
        printf("\nNo data\n\n");
        return FAILED;
    }

    typedef struct {
        char name[CLIENT_MAX_NAME_LENGHT];
        char hash[CLIENT_MAX_HASH_LENGHT];
        char id[CLIENT_MAX_ID_LENGHT];
    } ClientData;

    ClientData client;

    char FETCH_NAME[CLIENT_MAX_NAME_LENGHT];
    char FETCH_PASSWORD[CLIENT_MAX_HASH_LENGHT];
    char FETCH_HASH[CLIENT_MAX_HASH_LENGHT];

    printf("Name: ");
    fgets(FETCH_NAME, sizeof(FETCH_NAME), stdin);
    FETCH_NAME[strcspn(FETCH_NAME, "\n")] = '\0';

    printf("Password: ");
    fgets(FETCH_PASSWORD, sizeof(FETCH_PASSWORD), stdin);
    FETCH_PASSWORD[strcspn(FETCH_PASSWORD, "\n")] = '\0';

    // Hash the fetched password to compare with stored hash
    SimpleHash(FETCH_PASSWORD, FETCH_HASH, CLIENT_MAX_HASH_LENGHT);

    bool found = false;

    // Search each record
    while(fread(&client, sizeof(ClientData), 1, file_client) == 1) {
        if(strcmp(client.name, FETCH_NAME) == 0 && strcmp(client.hash, FETCH_HASH) == 0) {
            found = true;
            // Copy the found user's ID to the global session variable
            strcpy(CURRENT_SESSION_ID, client.id);
            break;
        }
    }

    fclose(file_client);

    if(found == true) {
        printf("\nSign-in successful!\n");
        printf("Welcome, %s!\n", FETCH_NAME);
        printf("Session ID: %s\n", CURRENT_SESSION_ID);
        return SUCCESS;
    }
    else {
        printf("\nSign-in failed: Invalid credentials.\n\n");
        return FAILED;
    }
}

void SignUp(void) {

	int Validation = SignUpProcess();

	if(Validation == SUCCESS) {
		printf("\nSign up successfully\n\n");
		return;
	}
	else if(Validation == FAILED) {
		printf("Sign up failed\n\n");
		return;
	}
	else {
		printf("\nSystem Error\n\n");
		return;
	}
}

int SignUpProcess(void) {

    char TEMP_NAME[CLIENT_MAX_NAME_LENGHT];
    int TEMP_NAME_LENGHT = 0;

    char TEMP_PASSWORD[CLIENT_MAX_HASH_LENGHT];
    int TEMP_PASSWORD_LENGHT = 0;

    char TEMP_HASH[CLIENT_MAX_HASH_LENGHT];

    bool IsValidatingName = true;
    bool IsValidatingPassword = true;

    int ErrorCounter = 0;

    printf("\nThis program is a concept,\n");
    printf("so please do not input any password\n");
    printf("that you use to avoid potential leak,\n");
    printf("and DO NOT use your real name please\n");

    printf("\nPlease input a name\n");
    printf("Minimum name lenght is 4 characters\n");
    printf("Maximum name lenght is %i characters\n", (CLIENT_MAX_NAME_LENGHT - 1));
    while(IsValidatingName == true) {
        printf("Name: ");
        fgets(TEMP_NAME, sizeof(TEMP_NAME), stdin);
        TEMP_NAME[strcspn(TEMP_NAME, "\n")] = '\0';
        TEMP_NAME_LENGHT = strlen(TEMP_NAME);

        if(TEMP_NAME_LENGHT >= 4 && TEMP_NAME_LENGHT <= (CLIENT_MAX_NAME_LENGHT - 1)) {
            IsValidatingName = false;
        }
        else if(ErrorCounter == 2) {
            printf("Too many errors, exiting\n\n");
            return FAILED;
        }
        else {
            printf("Invalid name\n\n");
            ErrorCounter++;
        }
    }

	// Resetting the error counter to be reuse in the password
    ErrorCounter = 0;

    printf("\nPlease input a password\n");
    printf("Minimum password lenght is 8 characters\n");
    printf("Maximum password lenght is %i characters\n", (CLIENT_MAX_HASH_LENGHT - 1));
    while(IsValidatingPassword == true) {
        printf("Password: ");
        fgets(TEMP_PASSWORD, sizeof(TEMP_PASSWORD), stdin);
        TEMP_PASSWORD[strcspn(TEMP_PASSWORD, "\n")] = '\0';
        TEMP_PASSWORD_LENGHT = strlen(TEMP_PASSWORD);

        if(TEMP_PASSWORD_LENGHT >= 8 && TEMP_PASSWORD_LENGHT <= (CLIENT_MAX_HASH_LENGHT - 1)) {
            IsValidatingPassword = false;
        }
        else if(ErrorCounter == 2) {
            printf("Too many errors, exiting\n\n");
            return FAILED;
        }
        else {
            printf("Invalid password\n\n");
            ErrorCounter++;
        }
    }

    SimpleHash(TEMP_PASSWORD, TEMP_HASH, CLIENT_MAX_HASH_LENGHT);

    // ---- Find last client ID for increment ----
    unsigned long long next_id = 5000000000000000ULL;
    FILE *file_client = fopen("data_client.dat", "rb");
    if (file_client != NULL) {
        typedef struct {
            char name[CLIENT_MAX_NAME_LENGHT];
            char hash[CLIENT_MAX_HASH_LENGHT];
            char id[CLIENT_MAX_ID_LENGHT];
        } ClientData;

        ClientData client;
        // Go to last record
        if (fseek(file_client, -sizeof(ClientData), SEEK_END) == 0) {
            if (fread(&client, sizeof(ClientData), 1, file_client) == 1) {
                // parse last id if file is not empty
                if (client.id[0] != '\0') {
                    next_id = strtoull(client.id, NULL, 10) + 1ULL;
                }
            }
        }
        fclose(file_client);
    }
    // If file doesn't exist, will start at 5000000000000000

    FILE *file_client = fopen("data_client.dat", "ab");
    if(file_client == NULL) {
        printf("\nSystem Error\n\n");
        return FAILED;
    }

    typedef struct {
        char name[CLIENT_MAX_NAME_LENGHT];
        char hash[CLIENT_MAX_HASH_LENGHT];
        char id[CLIENT_MAX_ID_LENGHT];
    } ClientData;

    ClientData client;

    strcpy(client.name, TEMP_NAME);
    strcpy(client.hash, TEMP_HASH);

    snprintf(client.id, CLIENT_MAX_ID_LENGHT, "C%ld", time(NULL));

    fwrite(&client, sizeof(ClientData), 1, file_client);

    fclose(file_client);

    return SUCCESS;
}
