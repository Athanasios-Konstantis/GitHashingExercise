#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int i = 0;
// Signal handler function
void onintr(int signum) {
	i += 1;
	printf("\nReceived signal %d SIGINT, %d times\n",signum,i);
	if(i == 2){
		signal(SIGINT, SIG_DFL);
	}
}

int main() {
    // Register the signal handler
    if (signal(SIGINT, onintr) == SIG_ERR) {
        perror("Error setting up signal handler");
        exit(EXIT_FAILURE);
    }
    //Sleep to keep the program running for a while
    printf("Waiting for a signal...\n");
    while(1){sleep(1);}

    return 0;
}
