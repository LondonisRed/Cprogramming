#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

time_t parseDateTime(const char *timeStr, const char *dateStr) {
    struct tm tm = {0};
    int hour, minute, day, month, year;
    
    sscanf(timeStr, "%d:%d", &hour, &minute);
    sscanf(dateStr, "%d-%d-%d", &day, &month, &year);
    
    tm.tm_hour = hour;
    tm.tm_min = minute;
    tm.tm_mday = day;
    tm.tm_mon = month - 1;
    tm.tm_year = year - 1900;
    tm.tm_isdst = -1;
    
    return mktime(&tm);
}

int calculateRentalDays(const char *time1, const char *date1, const char *time2, const char *date2) {
    time_t start = parseDateTime(time1, date1);
    time_t end = parseDateTime(time2, date2);
    
    if (start == -1 || end == -1) return 0;
    
    double seconds = difftime(end, start);
    double days = seconds / (24 * 60 * 60);
    
    return (int)ceil(days);
}

double calculateTotal(int dailyRate, int days) {
    double service = dailyRate * 0.125;
    double insurance = dailyRate * 0.11;
    double totalPerDay = dailyRate + service + insurance;
    return totalPerDay * days;
}

int main() {
    int dailyRate;
    char time1[6], date1[11], time2[6], date2[11];
    
    scanf("%d %5s %10s %5s %10s", &dailyRate, time1, date1, time2, date2);
    
    int days = calculateRentalDays(time1, date1, time2, date2);
    double total = calculateTotal(dailyRate, days);
    
    printf("%.2lf\n", total);
    
    return 0;
}