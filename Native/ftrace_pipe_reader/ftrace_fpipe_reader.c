#include <stdio.h>


main(int argc, char *argv[]){
	
	//Setup the output file
	FILE *output_fp = fopen(argv[1],"w+");
	if(output_fp == NULL){
		printf("File doesn't exist, attempting to create it...");	
	}

	//Setup the file pointer to the trace pipe
	FILE *trace_pipe_fp = fopen("/sys/kernel/debug/tracing/trace_pipe","r");
	if(trace_pipe_fp!=NULL){

		//Start reading from the pipe
		char line[128];
		while(fgets(line,sizeof line,trace_pipe_fp)!=NULL){
			//fputs(line,stdout);
			fprintf(output_fp,"%s",line);
		}
		fclose(trace_pipe_fp);
	}else{
		printf("Couldn't open the trace pipe for reading...");
	}
}
