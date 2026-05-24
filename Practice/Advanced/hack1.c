// Basic TCP Port Scanner in C (for educational purposes only)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <IP>\n", argv[0]);
        return 1;
    }

    char *target_ip = argv[1];
    int port;
    struct sockaddr_in target;

    printf("Scanning ports on %s...\n\n", target_ip);

    for (port = 1; port <= 1024; port++) {
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock < 0) {
            perror("Socket error");
            continue;
        }

        target.sin_family = AF_INET;
        target.sin_port = htons(port);
        target.sin_addr.s_addr = inet_addr(target_ip);

        // Connect to the port
        int conn = connect(sock, (struct sockaddr *)&target, sizeof(target));
        if (conn == 0) {
            printf("Port %d is OPEN\n", port);
        }

        close(sock);
    }

    printf("\nScan complete.\n");
    return 0;
}
