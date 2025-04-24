#include <stdio.h>
#include <stdlib.h>

int timeToMinutes(char* time) {
    int hours, minutes;
    sscanf(time, "%d:%d", &hours, &minutes);
    return hours * 60 + minutes;
}

void printDuration(int totalMinutes) {
    int hours = totalMinutes / 60;
    int minutes = totalMinutes % 60;
    printf("%d:%02d\n", hours, minutes);
}

int main() {
    int n;
    scanf("%d", &n);
    
    char inLog[n][6], outLog[n][6]; 

    for (int i = 0; i < n; i++) {
        scanf("%s", inLog[i]);
    }

    for (int i = 0; i < n; i++) {
        scanf("%s", outLog[i]);
    }

    int totalMinutes = 0;

    for (int i = 0; i < n; i++) {
        int inMinutes = timeToMinutes(inLog[i]);
        int outMinutes = timeToMinutes(outLog[i]);
        totalMinutes += (outMinutes - inMinutes);
    }

    printDuration(totalMinutes);
    return 0;
}
