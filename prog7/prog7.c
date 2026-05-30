#include <stdio.h>
#include <string.h>

void buildLPS(char pat[], int lps[]) {

    int len = 0;
    int i = 1;
    int m = strlen(pat);

    lps[0] = 0;

    while(i < m) {

        if(pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {

            if(len != 0) {
                len = lps[len - 1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

int KMPSearch(char str[], char pat[]) {

    int n = strlen(str);
    int m = strlen(pat);

    int lps[m];
    buildLPS(pat, lps);

    int i = 0;  // index for str
    int j = 0;  // index for pat

    while(i < n) {

        if(str[i] == pat[j]) {
            i++;
            j++;
        }

        if(j == m) {
            return i - j;      // starting index of match
        }

        else if(i < n && str[i] != pat[j]) {

            if(j != 0) {
                j = lps[j - 1];
            }
            else {
                i++;
            }
        }
    }

    return -1;
}

int main() {

    char str[] = "ababeabfabc";
    char pat[] = "abe";

    int index = KMPSearch(str, pat);

    if(index != -1)
        printf("Pattern found at index %d\n", index);
    else
        printf("Pattern not found\n");

    return 0;
}