#include <stdio.h>
#include <time.h>
#include <math.h>

void parse_datetime(const char *datetime, struct tm *tm) {
    sscanf(datetime, "%d:%d:%d %d-%d-%d",
           &tm->tm_hour, &tm->tm_min, &tm->tm_sec,
           &tm->tm_mday, &tm->tm_mon, &tm->tm_year);
    tm->tm_mon -= 1;    
    tm->tm_year -= 1900; 
    tm->tm_isdst = -1;  
}

int main() {
    int first_block_cost, subsequent_sec_cost;
    char start_time_str[20], start_date_str[20], end_time_str[20], end_date_str[20];
    
    scanf("%d %d %s %s %s %s", 
          &first_block_cost, &subsequent_sec_cost,
          start_time_str, start_date_str,
          end_time_str, end_date_str);
    
    char start_datetime[40], end_datetime[40];
    sprintf(start_datetime, "%s %s", start_time_str, start_date_str);
    sprintf(end_datetime, "%s %s", end_time_str, end_date_str);
    
    struct tm start_tm = {0}, end_tm = {0};
    parse_datetime(start_datetime, &start_tm);
    parse_datetime(end_datetime, &end_tm);
    
    time_t start_time = mktime(&start_tm);
    time_t end_time = mktime(&end_tm);
    
    double duration = difftime(end_time, start_time);
    
    double total_cost;
    if (duration <= 6) {
        total_cost = first_block_cost;
    } else {
        total_cost = first_block_cost + (duration - 6) * subsequent_sec_cost;
    }
    
    printf("%.2f\n", total_cost);
    
    return 0;
}