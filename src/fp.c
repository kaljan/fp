#include <stdio.h>


static int frontPanelStop;


void FrontPanelStop(void)
{
	frontPanelStop = 1;
}

int FrontPanel(void)
{
	frontPanelStop = 0;

	// Инициализации.

	// Сначала запускаем LCD, если не запустился выходим с ошибкой

	// Следующее -- инициализация кнопок. тоже выходим.

	// Инициализация меню.

	// Первичный сбор системной информации:
	// - Системное время
	// - Аптайм
	// - Подключение к сети и адреса
	// - Температура процессора

	while (1) {
		if (frontPanelStop) {
			break;
		}
	}
}
