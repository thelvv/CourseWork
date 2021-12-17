#include "main.h"

/* Частота дискретизации АЦП 128k отсчетов/сек, поэтому для уменьшения шага частот в полученном спектре
 * был взят большой размер массива входных данных.
 */


uint8_t get_max_amp(const float data[]) {
	if ((data[0] > data[1]) & (data[0] > data[2])) {
		return 1;
	} else if ((data[1] > data[0]) & (data[1] > data[2])) {
		return 2;
	} else if ((data[2] > data[0]) & (data[2] > data[1])) {
		return 3;
	}
		return 4;
}
