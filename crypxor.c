/*
 * Crypxor 1.0.0
 * Copyright (C) 2019 HackerTsai
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Crypt(char infilename[], char outfilename[]) {
    FILE *output_file = fopen(outfilename, "w");
    FILE *target_file;
    if ((target_file = fopen(infilename, "r")) == NULL) {
        printf("Error when opening file.\n");
        exit(1);
    }
    unsigned int key;
    printf("Enter your key, a 6-digit number: ");
    scanf("%u", &key);
    if (key > 999999) {
        printf("Error: The key length is too long.\n");
        exit(1);
    }
    srand(key);
    printf("En/Decrypting the file... ");
    int m;
    while ((m = fgetc(target_file)) != EOF) {
        int k = rand() % 127 + 1;
        fputc(m ^ k, output_file);
    }
    fclose(target_file);
    fclose(output_file);
    printf("finished.\n");
}

int main(int argc, char *argv[]) {
    if (argc == 2) {
        if (strcmp(argv[1], "--help") == 0) {
            printf(
                "Usage:\n"
                "  crypxor --help\n"
                "  crypxor --version\n"
                "  crypxor [--out filename] file\n"
                "Options:\n"
                "  file              The file you want to en/decrypt.\n"
                "  --help            Display the information.\n"
                "  --version         Display version information.\n"
                "  --out filename    Output the result into a specified file.\n"
            );
        } else if (strcmp(argv[1], "--version") == 0) {
            printf(
                "Crypxor version 1.0.0\n"
                "Copyright (C) 2019 HackerTsai\n"
            );
        } else {
            Crypt(argv[1], "out.txt");
        }
    } else if (argc == 4) {
        if (strcmp(argv[1], "--out") == 0)
            Crypt(argv[3], argv[2]);
        else if (strcmp(argv[2], "--out") == 0)
            Crypt(argv[1], argv[3]);
    } else {
        printf(
            "Syntax error.\n"
            "Usage:\n"
            "  crypxor --help\n"
            "  crypxor [--out filename] file\n"
        );
    }
    return 0;
}