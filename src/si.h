#ifndef SI_H
#define SI_H

#include <stdint.h>

typedef struct _DateTime {
	int year;
	int month;
	int weekDay;
	int dayOfMonth;
	int hour;
	int minute;
	int second;
} DateTime;

int updateSystemInfo(void);
int getUptime(char *str, uint32_t time);
int getCpuTemperature(double *cputemp);
int getTime(char **str);
int getDateTime(char **str);
int getIpAddress(const char *iface, char **ipaddr);

#endif // SI_H
