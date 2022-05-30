#include <stdio.h>
#include <string.h>
#include <ctype.h>

#pragma warning(disable: 4996)

char KEYWORD[4] = "CODE";
char emptyWord[] = "";

void createEmptyWord() {
    for (int i = 0; i < strlen(KEYWORD); i++) {

        emptyWord[i] = '_';
    }

}

void checkLetters(char goodLetters[], char badLetters[], char playerWord[]) {
    for (int i = 0; i < strlen(KEYWORD); i++) {
        int isFind = 0;
        if (playerWord[i] == KEYWORD[i]) {
            emptyWord[i] = playerWord[i];
            if (strchr(goodLetters, playerWord[i]) != NULL) {
                for (int j = 0; j < strlen(KEYWORD); j++) {
                    if (goodLetters[j] == playerWord[i])
                        goodLetters[j] = ' ';
                }

            }

            isFind = 1;
        }
        for (int j = 0; j < strlen(KEYWORD); j++)
            if ((playerWord[i] == KEYWORD[j]) && (i != j) && (strchr(badLetters, playerWord[i]) == NULL)) {
                strncat(goodLetters, &playerWord[i], 1);
                isFind = 1;
            }

        if ((isFind == 0) && (strchr(badLetters, playerWord[i]) == NULL))
            strncat(badLetters, &playerWord[i], 1);

    }

}
void makeUpperCase(char playerWord[]) {
    int i = 0;
    while (playerWord[i]) {
        playerWord[i] = toupper(playerWord[i]);
        i++;
    }

}

int checkAnswer(char playerWord[]) {

    if (strncmp(playerWord, KEYWORD, (int)strlen(KEYWORD)) == 0)
        return 1;
    else
        return 0;
}

int main() {
    createEmptyWord();
    char goodLetters[30] = "";
    char badLetters[30] = "";
    char playerWord[30] = "";
    printf("The code word has %d letters - guess it!\n", (int)strlen(KEYWORD));

    for (int i = 0; i < 7; i++) {
        printf("It's youre %d attempt. Word: %s Good letters: %s"
            " Bad letters:%s \nGuess word:", i + 1, emptyWord, goodLetters, badLetters);
        fgets(playerWord, 256, stdin);
        makeUpperCase(playerWord);
        checkLetters(goodLetters, badLetters, playerWord);
        if (checkAnswer(playerWord) == 1) {
            printf("YOU WON IN %d ATTEMPT", i + 1);
            exit(0);
        }

    }
    printf("YOU LOSE");

    return 0;
}
