#include <stdio.h>
#include <time.h>
#include <math.h>
#include <string.h>

struct tm parseDateTime(const char *timeStr, const char *dateStr) {
    struct tm tm = {0};
    sscanf(timeStr, "%d:%d", &tm.tm_hour, &tm.tm_min);
    sscanf(dateStr, "%d-%d-%d", &tm.tm_mday, &tm.tm_mon, &tm.tm_year);
    tm.tm_mon -= 1; 
    tm.tm_year -= 1900; 
    return tm;
}

double calculateParkingFee(int initialFee, int blockFee, const char *entryTime, const char *entryDate, 
                          const char *exitTime, const char *exitDate) {
    struct tm entry = parseDateTime(entryTime, entryDate);
    struct tm exit = parseDateTime(exitTime, exitDate);
    
    time_t entry_sec = mktime(&entry);
    time_t exit_sec = mktime(&exit);
    
    if (entry_sec == -1 || exit_sec == -1) {
        return 0;
    }
    
    double diff_seconds = difftime(exit_sec, entry_sec);
    int total_minutes = (int)(diff_seconds / 60);
    
    if (total_minutes <= 60) {
        return (double)initialFee;
    }
    
    int remaining_minutes = total_minutes - 60;
    int blocks = (remaining_minutes + 29) / 30; 
    
    return (double)(initialFee + blocks * blockFee);
}

int main() {
    int initialFee, blockFee;
    char entryTime[6], entryDate[11], exitTime[6], exitDate[11];
    
    scanf("%d %d %s %s %s %s", &initialFee, &blockFee, entryTime, entryDate, exitTime, exitDate);
    
    double fee = calculateParkingFee(initialFee, blockFee, entryTime, entryDate, exitTime, exitDate);
    printf("%.2f\n", fee);
    
    return 0;
}