#ifndef __common_h__
#define __common_h__

#include<sys/time.h>
#include<assert.h>
#include<pthread.h>

double GetTime(){
	struct timeval t;
	int rc = gettimeofday(&t, NULL);
	assert(rc == 0);
	return (double)t.tv_sec + (double)t.tv_usec/1e6;
}

void Spin(int time){
	double t = GetTime();

	while(GetTime() - t < time);

}


#endif