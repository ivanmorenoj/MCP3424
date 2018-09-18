#include <stdio.h>
#include <stdexcept>
#include <time.h>
#include <unistd.h>
#include <iostream>

#include "MCP3424.h"

using namespace std;

int main(int argc, char **argv){

  MCP3424 *adc;
  adc = new MCP3424[2]; //init the class

  adc[0].set_config_values(0x68,1,18,1,1);
  adc[1].set_config_values(0x69,1,18,1,1);

  printf("Channel\t|   1\t|   2\t|   3\t|   4\t|   5\t|   6\t|   7\t|   8\t|\n");
  printf("----------------------------------------------------------------------\n");
	for(;;){
    printf("V =>\t");
    for(char i = 0; i < 2; ++i){
      for (char j = 1; j <= 4; j++) {
        printf("|%.3f\t",adc[i].read_voltage(j));
      }
    }
    printf("|\n");
		usleep(2000000); // sleep 2 seconds
	}
	return (0);
}
