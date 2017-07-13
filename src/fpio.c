#include <stdio.h>
#include "buttons.h"
#include "periph.h"


static int InitDisplayOutput(void)
{
	return 0;
}

static int DeinitDisplayOutput(void)
{
	return 0;
}

static int InitButtonsInput(void)
{
	return 0;
}

static int DeinitButtonsInput(void)
{
	return 0;
}


int RunFrontPanelIO(void)
{
	if (InitDisplayOutput() != 0) {
		return -1;
	}

	if (InitButtonsInput() != 0) {
		return -1;
	}
}

int StopFrontPanelIO(void)
{

}
