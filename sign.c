#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

const char* docChuSo[] = {"khong", "mot", "hai", "ba", "bon", "nam", "sau", "bay", "tam", "chin"};
const char* donViLon[] = {"", " nghin", " trieu", " ty", " nghin ty", " trieu ty", " ty ty"};

void docNhomBaChuSo(int n, char* buffer, bool precedingGroupExists) {
    if (n < 0 || n > 999) {
        buffer[0] = '\0';
        return;
    }

    int tram = n / 100;
    int chuc = (n % 100) / 10;
    int donvi = n % 10;
    char temp_buffer[150] = ""; 
    char temp[50];              
    bool added_something = false; 

    if (tram > 0) {
        sprintf(temp, "%s tram", docChuSo[tram]);
        strcat(temp_buffer, temp);
        added_something = true;
    }

    if (chuc == 0) {
        if (donvi > 0) {
            if (tram > 0) { 
                sprintf(temp, " le %s", docChuSo[donvi]);
                strcat(temp_buffer, temp); 
            } else { 
                sprintf(temp, "%s", docChuSo[donvi]);
                if (!added_something) strcpy(temp_buffer, temp);
                 else strcat(temp_buffer, temp); 
            }
             added_something = true;
        }
    } else if (chuc == 1) { 
        if (added_something) strcat(temp_buffer, " "); 
        strcat(temp_buffer, "muoi");
        if (donvi == 5) {
            strcat(temp_buffer, " lam"); 
        } else if (donvi > 0) {
            sprintf(temp, " %s", docChuSo[donvi]);
            strcat(temp_buffer, temp);
        }
        added_something = true;
    } else { 
         if (added_something) strcat(temp_buffer, " "); 
        sprintf(temp, "%s muoi", docChuSo[chuc]); 
        strcat(temp_buffer, temp);
        if (donvi == 1) {
            strcat(temp_buffer, " mot"); 
        } else if (donvi == 4) { 
             strcat(temp_buffer, " tu");
        } else if (donvi == 5) {
            strcat(temp_buffer, " lam"); 
        } else if (donvi > 0) {
            sprintf(temp, " %s", docChuSo[donvi]);
            strcat(temp_buffer, temp);
        }
        added_something = true;
    }

    if (precedingGroupExists && n > 0 && n < 10 && tram == 0 && chuc == 0) {
        sprintf(buffer, "le %s", temp_buffer);
    } else {
        strcpy(buffer, temp_buffer);
    }
}


int main() {
    long long num;
    char final_result[500] = ""; 
    char chunk_buffer[150]; 
    bool is_negative = false;

    scanf("%lld", &num);
    if (num == 0) {
        printf("khong\n");
        return 0;
    }

    if (num < 0) {
        is_negative = true;
        num = -num; 
        strcpy(final_result, "am ");
    }

    long long divisor = 1;
    int max_level = 0;
    while (max_level < 6 && divisor <= num / 1000) {
        divisor *= 1000;
        max_level++;
    }

    bool first_part = true; 

    for (int level = max_level; level >= 0; --level) {
        if (divisor == 0) divisor = 1;
        int chunk = (int)(num / divisor);
        num %= divisor;

        if (chunk > 0) {
            bool preceding_group_exists = !first_part;
            docNhomBaChuSo(chunk, chunk_buffer, preceding_group_exists);
            if (!first_part) {
                strcat(final_result, " ");
            }
            strcat(final_result, chunk_buffer);
            strcat(final_result, donViLon[level]);

            first_part = false; 
        }
        if (divisor >= 1000) {
             divisor /= 1000;
        } else {
            divisor = 0; 
        }

    }
    printf("%s\n", final_result);
    return 0;
}