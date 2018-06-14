#include <stdio.h>
#include <windows.h>
#include <dir.h>

void Welcome();
void ShowMusic();
int pereklad(char *sign);

int main() {
    Welcome();
    ShowMusic();

    char *sign;
    int number = 0;

    mkdir("YourMusic");

    while (*sign != 'Q') {
    scanf ("%s", sign);

    if(*sign >= 48 && *sign <= 57) {
       number = pereklad(sign);
       printf("%i\n", number);
    }
    else{
        switch (*sign) {
            case 'S':
            ShowMusic();
            break;

            case 'Q':
            return 0;
            break;

            default:
            printf("Error\n");
            }
        }
    }
    return 0;
}

void Welcome() {
printf("******************************\n");
printf("* Welcome to MP3 player      *\n");
printf("* S - Show Music             *\n");
printf("* C - Continue playing       *\n");
printf("* P - Pause                  *\n");
printf("* 1, 2,... - number of song  *\n");
printf("* Q - Quit                   *\n");
printf("******************************\n");
}

void ShowMusic() {
    printf("List: \n");
    WIN32_FIND_DATA FindFileData;
    HANDLE hf = FindFirstFile("YourMusic/*", &FindFileData);
    char fileNames[200][MAX_PATH];
    int i = 1;
        if (hf==INVALID_HANDLE_VALUE){
            puts("Path not found");
            return 1;
        }

    FindNextFile(hf,&FindFileData);

        while (FindNextFile(hf,&FindFileData)) {
            strcpy(fileNames[i], FindFileData.cFileName);
            printf("%i.%s\n",i ,fileNames[i]);
            i++;
        }
    FindClose(hf);
}

int pereklad(char *sign) {
return atoi(sign);
}
