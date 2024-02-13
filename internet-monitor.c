#include <stdlib.h>
#include <stdio.h>
#include <unistd.h> // for sleep()

int main() {
    // Loop indefinitely
    while (1) {
        // Try to ping Google's public DNS server to check for internet connectivity
        int status = system("ping -c 1 8.8.8.8 > /dev/null 2>&1");

        if (status != 0) {
            // Ping command failed - assume no internet connection and notify the user
            system("notify-send 'Internet Connectivity' 'Internet is down'");
        }

        // Wait for 5 seconds before checking again
        sleep(5);
    }

    return 0; // This line will never be reached
}

