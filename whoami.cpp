#include <iostream>
#include <cstdlib>
#include <unistd.h> // For gethostname

int main() {
    // Get the username
    const char* username = std::getenv("USER");
    if (username == nullptr) {
        username = std::getenv("USERNAME"); // For Windows compatibility
    }

    // Get the hostname
    char hostname[256];
    if (gethostname(hostname, sizeof(hostname)) != 0) {
        perror("gethostname failed");
        return 1;
    }

    // Print the information
    std::cout << "Whoami: " << (username ? username : "Unknown") << std::endl;
    std::cout << "Hostname: " << hostname << std::endl;

    return 0;
}
