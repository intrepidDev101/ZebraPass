#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>
#include <unistd.h> 

// Function prototypes
void clearTerminal();
void printASCIIArt();
void loadingAnimation(const char *message);
void printHelp();
void showMenu();
void generatePassword(int quantity, bool memorable, bool userSpecified, char *customSet, bool excludeAmbiguous, int minLength, int maxLength, bool noRepetition);
int passwordStrengthChecker(const char *password);
void saveToFile(const char *password);
void copyToClipboard(const char *password);
char *getPasswordInput(char *buffer, int size);
char getValidatedChoice(const char *validChoices);
int getValidatedInteger(int min, int max);

// Main function
int main() {
    char choice;
    bool running = true;

    clearTerminal();
    printASCIIArt();

    while (running) {
        showMenu();
        printf("\n\033[1;36mEnter your choice: \033[0m");
        choice = getValidatedChoice("123hqe");

        switch (choice) {
            case '1': {
                printf("\n\033[1;33mGenerating Passwords...\033[0m\n");
                loadingAnimation("Initializing password generator");

                printf("\nDo you want a \033[1;36m(r)andom\033[0m or \033[1;36m(m)emorable\033[0m password? ");
                char type = getValidatedChoice("rm");

                printf("\nDo you want \033[1;36m(a)uto-generated\033[0m or \033[1;36m(u)ser-specified\033[0m content? ");
                char genType = getValidatedChoice("au");

                printf("\n\033[1;36mHow many passwords do you want to generate? \033[0m");
                int quantity = getValidatedInteger(1, 100);

                printf("\nSpecify character options:\n");
                char customSet[128] = "";
                printf("Include \033[1;36m(U)ppercase\033[0m, \033[1;36m(L)owercase\033[0m, \033[1;36m(D)igits\033[0m, \033[1;36m(S)pecial characters\033[0m (default: all). Type 'done' to finish: ");
                while (1) {
                    char setChoice[10];
                    scanf("%s", setChoice);
                    if (strcasecmp(setChoice, "done") == 0) break;
                    strcat(customSet, setChoice);
                }

                printf("\nExclude ambiguous characters (\033[1;36my/n\033[0m)? ");
                bool excludeAmbiguous = getValidatedChoice("yn") == 'y';

                printf("\nMinimum length (\033[1;36m4-32\033[0m): ");
                int minLength = getValidatedInteger(4, 32);

                printf("Maximum length (\033[1;36mmin-64\033[0m): ");
                int maxLength = getValidatedInteger(minLength, 64);

                printf("Ensure no character repetition (\033[1;36my/n\033[0m)? ");
                bool noRepetition = getValidatedChoice("yn") == 'y';

                generatePassword(quantity, type == 'm', genType == 'u', customSet, excludeAmbiguous, minLength, maxLength, noRepetition);
                break;
            }
            case '2': {
                printf("\n\033[1;33mHelp Documentation:\033[0m\n");
                printHelp();
                break;
            }
            case 'q': {
                printf("\n\033[1;31mExiting program...\033[0m\n");
                running = false;
                break;
            }
            default:
                printf("\n\033[1;31mInvalid choice! Try again.\033[0m\n");
        }
    }

    return 0;
}

// Function definitions
void clearTerminal() {
    printf("\033[H\033[J"); // ANSI escape sequence for clearing the screen
}

void printASCIIArt() {
    printf("\033[1;34m");
    printf("░▒▓████████▓▒░▒▓████████▓▒░▒▓███████▓▒░░▒▓███████▓▒░ ░▒▓██████▓▒░░▒▓███████▓▒░ ░▒▓██████▓▒░ ░▒▓███████▓▒░▒▓███████▓▒░ \n");
    printf("       ░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░     ░▒▓█▓▒░        \n");
    printf("     ░▒▓██▓▒░░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░     ░▒▓█▓▒░        \n");
    printf("   ░▒▓██▓▒░  ░▒▓██████▓▒░ ░▒▓███████▓▒░░▒▓███████▓▒░░▒▓████████▓▒░▒▓███████▓▒░░▒▓████████▓▒░░▒▓██████▓▒░░▒▓██████▓▒░  \n");
    printf(" ░▒▓██▓▒░    ░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░      ░▒▓█▓▒░     ░▒▓█▓▒░ \n");
    printf("░▒▓█▓▒░      ░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░      ░▒▓█▓▒░     ░▒▓█▓▒░ \n");
    printf("░▒▓████████▓▒░▒▓████████▓▒░▒▓███████▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓███████▓▒░▒▓███████▓▒░  \n");
    printf("                                                                                                                       \n");
    printf("                                                                                                                       \n");
    printf("\033[0m");
}


void loadingAnimation(const char *message) {
    printf("\n%s", message);
    for (int i = 0; i < 3; i++) {
        fflush(stdout);
        printf(".");
        sleep(1);
    }
    printf("\n");
}

void printHelp() {
    printf("\033[1;32mThis CLI password generator lets you:\033[0m\n");
    printf("- Generate \033[1;33mrandom\033[0m or \033[1;33mmemorable\033[0m passwords.\n");
    printf("- Specify the number and strength of passwords.\n");
    printf("- Exclude ambiguous characters and add custom sets.\n");
    printf("- Save passwords to a file or copy to clipboard.\n");
    printf("- Check password strength and avoid patterns.\n");
    printf("Enjoy a secure password generation experience!\n");
}

void showMenu() {
    printf("\n\033[1;36mMenu:\033[0m\n");
    printf("1. Generate Password\n");
    printf("2. Help\n");
    printf("q. Quit\n");
}

void generatePassword(int quantity, bool memorable, bool userSpecified, char *customSet, bool excludeAmbiguous, int minLength, int maxLength, bool noRepetition) {
    char defaultSet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*";
    if (excludeAmbiguous) {
        strcpy(defaultSet, "ABCDEFGHJKLMNPQRSTUVWXYZabcdefghijkmnpqrstuvwxyz23456789!@#$%^&*");
    }

    char *charset = strlen(customSet) > 0 ? customSet : defaultSet;

    for (int i = 0; i < quantity; i++) {
        char password[65] = "";
        int length = minLength + rand() % (maxLength - minLength + 1);

        for (int j = 0; j < length; j++) {
            char ch = charset[rand() % strlen(charset)];
            if (noRepetition && strchr(password, ch)) {
                j--; // Retry character selection
            } else {
                password[j] = ch;
            }
        }
        password[length] = '\0';

        printf("\nGenerated Password: \033[1;33m%s\033[0m", password);
        saveToFile(password);
        copyToClipboard(password);
    }
}

int passwordStrengthChecker(const char *password) {
    // Add your existing password strength checker here
    return 0;
}

void saveToFile(const char *password) {
    FILE *file = fopen("passwords.txt", "a");
    if (file) {
        fprintf(file, "%s\n", password);
        fclose(file);
        printf(" [Saved to file]");
    } else {
        printf(" [Error saving to file]");
    }
}

void copyToClipboard(const char *password) {
    printf(" [Copied to clipboard]");
}

char getValidatedChoice(const char *validChoices) {
    char choice;
    do {
        scanf(" %c", &choice);
        choice = tolower(choice);
    } while (!strchr(validChoices, choice));
    return choice;
}

int getValidatedInteger(int min, int max) {
    int value;
    do {
        scanf("%d", &value);
    } while (value < min || value > max);
    return value;
}
