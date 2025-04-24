#include <stdio.h>
#include <time.h>
#include <math.h>

void parse_datetime(const char *datetime, struct tm *tm) {
    sscanf(datetime, "%d:%d %d-%d-%d",
           &tm->tm_hour, &tm->tm_min, &tm->tm_mday, &tm->tm_mon, &tm->tm_year);
    tm->tm_mon -= 1;    
    tm->tm_year -= 1900; 
    tm->tm_sec = 0;
    tm->tm_isdst = -1;  
}


int calculate_rental_days(const char *start_datetime, const char *end_datetime) {
    struct tm start_tm = {0};
    struct tm end_tm = {0};
    
    parse_datetime(start_datetime, &start_tm);
    parse_datetime(end_datetime, &end_tm);
    
    time_t start_time = mktime(&start_tm);
    time_t end_time = mktime(&end_tm);
    
  
    double diff_seconds = difftime(end_time, start_time);
    double diff_days = diff_seconds / 86400.0;
    int days = (int)diff_days;
    
    if (days == 0) {
        return 1;
    }
    
    if (end_tm.tm_hour >= 20) {
        days += 1;
    }
    
    return days;
}


double calculate_payment(double daily_rate, const char *start_datetime, const char *end_datetime) {
    int days = calculate_rental_days(start_datetime, end_datetime);
    double subtotal = days * daily_rate;
    double total = subtotal * 1.10; 
    return total;
}

int main() {
    double daily_rate;
    char start_time[6], start_date[11], end_time[6], end_date[11];
    
    scanf("%lf %5s %10s %5s %10s", 
          &daily_rate, start_time, start_date, end_time, end_date);
    
    char start_datetime[20], end_datetime[20];
    sprintf(start_datetime, "%s %s", start_time, start_date);
    sprintf(end_datetime, "%s %s", end_time, end_date);
    
    double total = calculate_payment(daily_rate, start_datetime, end_datetime);
    
    printf("%.2lf\n", total);
    
    return 0;
}