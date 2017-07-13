#include <stdio.h>
#include <signal.h>

static void catch_signal(int sig)
{
	if (sig == SIGQUIT) {
		printf("[%s:%d] Signal %d recieved\n", __FUNCTION__, __LINE__, sig);
	}
}

int main(int argc, char **argv)
{
	signal(SIGQUIT, catch_signal);
	return 0;
}
