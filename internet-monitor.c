#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    int failCount = 0;
    while (1) {
        int status = system("ping -c 1 8.8.8.8 > /dev/null 2>&1");
        if (status != 0) {
            failCount++;
            if (failCount >= 3) {
                system("notify-send 'Internet Connectivity' 'Internet is down'");
                failCount = 0;
            }
        } else {
            failCount = 0;
        }
        sleep(5);
    }
    return 0;
}

