#include <stdio.h>
#include <sys/time.h>

int main(int argc, char *argv[]){

	struct timeval tv;	
	int i;
	for(i=0;i<10;i++){
		gettimeofday(&tv, NULL);
	}
	return 0;
}
