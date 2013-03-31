#include <stdio.h>


main(int argc, char *argv[]){
        FILE *trace_pipe_fp;
        FILE *output_fp;

        output_fp = fopen("/data/trace_output.txt","w+");
        trace_pipe_fp = fopen("/sys/kernel/debug/tracing/trace_pipe","r");
        if(trace_pipe_fp != NULL && output_fp!=NULL){
          int print_timestamp = 1;

          char line[128];
          while(fgets(line,sizeof line,trace_pipe_fp)!=NULL){
            //fputs(line,stdout);
            if(print_timestamp!=0){
              time_t timestamp = time(NULL);
              print_timestamp = 0;
            }
            fprintf(output_fp,"%s",line);
          }
          fclose(trace_pipe_fp);
        }else{
          printf("Couldn't open file for reading or writing! \n");
        }
}
