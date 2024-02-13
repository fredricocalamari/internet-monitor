#include <stdlib.h>
#include <unistd.h>

int main() {
    const char *ping_command = "ping -c 1 8.8.8.8 > /dev/null 2>&1";
    const char *notify_command = "notify-send 'Internet Connectivity' 'Internet is down'";

    // Perform a single connectivity check
    if (system(ping_command) != 0) {
        // If ping fails, display the notification
        system(notify_command);
    }

    return 0;
}
