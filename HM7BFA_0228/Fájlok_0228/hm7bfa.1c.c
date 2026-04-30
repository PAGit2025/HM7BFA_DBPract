#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *f;
    char filename[100];
    char line[256];

    // 1. Fájlnév bekérése
    printf("File name: ");
    fgets(filename, sizeof(filename), stdin);

    // \n törlése
    int i = 0;
    while (filename[i] != '\n' && filename[i] != '\0') i++;
    filename[i] = '\0';

    // 2. Fájl megnyitása írásra
    f = fopen(filename, "w");
    if (f == NULL) {
        printf("Hiba a fajl megnyitasakor!\n");
        return 1;
    }

    printf("Add meg a szoveget (#-ig):\n");

    // 3. Beolvasás soronként
    while (1) {
        fgets(line, sizeof(line), stdin);

        if (line[0] == '#')
            break;

        fputs(line, f);
    }

    fclose(f);

    // 4. Fájl megnyitása olvasásra
    f = fopen(filename, "r");
    if (f == NULL) {
        printf("Hiba a fajl megnyitasakor!\n");
        return 1;
    }

    printf("\nNAGYBETUSEN:\n");

    char ch;
    while ((ch = fgetc(f)) != EOF) {
        putchar(toupper(ch));
    }

    fclose(f);

    return 0;
}
