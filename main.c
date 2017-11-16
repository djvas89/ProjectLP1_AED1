#include <stdio.h>
#include <mem.h>

int main(int argc, const char *argv[]) {

    return 0;
}

//brute force string to string
char *strstr_bf(char *txt, char *pat) {
    int lenPat = strlen(pat);
    int n = strlen(txt);
    for (int i = 0; i < n - lenPat; ++i) {
        for (int j = 0; j < lenPat; ++j) {
            if (txt[i + j] != pat[j])
                break;
            if (j == lenPat) return &txt[i];
        }
        return -1;
    }
}

//client brute force string to string
void clientstrstr_bf() {
    char *txt = "ABCABCABCABCABA";
    char *pat = "ABCA";
    char *posmatch;
    int count = 0;
    posmatch = txt;
    while (posmatch != -1) {
        posmatch = strstr_bf(posmatch, pat);
        count++;
        posmatch += 1;
        printf("i = %d", (int) (posmatch - txt));
    }
}