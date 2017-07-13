#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <sys/sysinfo.h>

#include <netinet/in.h>
#include <net/if.h>
#include <arpa/inet.h>

#include "si.h"


extern char lcd_str[33];


static const char cpu_temperature_path[] =
	"/sys/class/thermal/thermal_zone0/temp\0";


time_t t;
struct tm *tmptr;
struct sysinfo si;


int updateSystemInfo(void)
{
	 if (sysinfo(&si) < 0) {
		 printf("Can\'t get sysinfo: %s\n", strerror(errno));
		 return -1;
	 }

	return 0;
}

int getUptime(char *str, uint32_t time)
{
	int mins = 0, secs = 0, hours = 0;

	if (str == 0) {
		return -1;
	}

	do {
		secs = time % 60;
		time /= 60;
		if (time == 0) {
			break;
		}

		mins = time % 60;
		time /= 60;
		if (time == 0) {
			break;
		}

		hours = time % 24;
		time /= 24;
		if (time == 0) {
		}
	} while(0);

	sprintf(str, "%d d. %02d:%02d:%02d", time, hours, mins, secs);

	return 0;
}

int getCpuTemperature(double *cputemp)
{
	int fd;
	char str[8];

	memset(str, 0, 8);

	if ((fd = open(cpu_temperature_path, O_RDONLY)) < 0) {
		printf("[%s:%d] Can\'t open %s: %s\n"
			, __func__, __LINE__, cpu_temperature_path, strerror(errno));
		return -1;
	}

	if (read(fd, str, 8) < 0) {
		printf("[%s:%d] Can\'t read %s: %s\n"
			, __func__, __LINE__, cpu_temperature_path, strerror(errno));
		close(fd);
		return -1;
	}

	close(fd);
	*cputemp = ((double)atoi(str)) / 100.000;

	return 0;
}

int getTime(char **str)
{
	return 0;
}

int getDateTime(char **str)
{
	return 0;
}

int getIpAddress(const char *iface, char **ipaddr)
{
	return 0;
}
