#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

// Signal handler function
void onintr(int signum) {
    printf("\nReceived signal SIGINT\n");

    exit(0);
}

int main() {
    // Register the signal handler
    if (signal(SIGINT, onintr) == SIG_ERR) {
        perror("Error setting up signal handler");
        exit(EXIT_FAILURE);
    }
    // Example: Sleep to keep the program running for a while
    printf("Waiting for a signal...\n");
    while(1){sleep(1);}

    return 0;
}
