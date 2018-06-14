#include <stdio.h>
#include <windows.h>
#include <dir.h>

void ShowMusic();
int pereklad(char *sign);

int main() {
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

void ShowMusic() {
    printf("Music: \n");
    WIN32_FIND_DATA FindFileData;
    HANDLE hf = FindFirstFile("YourMusic/*", &FindFileData);
    char fileNames[200][MAX_PATH];
    int i = 0;

        if (hf==INVALID_HANDLE_VALUE){
            puts("Path not found");
            return 1;
        }

        while (FindNextFile(hf,&FindFileData)) {
            strcpy(fileNames[i], FindFileData.cFileName);
            printf("%i.%s\n",i ,fileNames[i]);
            ++i;
        }
    FindClose(hf);
}

int pereklad(char *sign) {
return atoi(sign);
}
