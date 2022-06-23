#include "header.h"


long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	//     seconds from 1970 and microsecond from 1970
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}
