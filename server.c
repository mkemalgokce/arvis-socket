#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdbool.h>
#include "deviceconnector.h"
int main() {
    int serverSocket, clientSocket;
    struct sockaddr_in serverAddr, clientAddr;
    socklen_t clientAddrLen = sizeof(clientAddr);
    uint8_t buffer;

    writeLowForAllPins();
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        perror("[+] Socket oluşturulamadı.");
        exit(1);
    }

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(12345);  

   
    if (bind(serverSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == -1) {
        perror("[!] Bind hatası.");
        exit(1);
    }

    if (listen(serverSocket, 5) == -1) {
        perror("[!] Listen hatası.");
        exit(1);
    }

    printf("[+] Server başlatıldı. Bağlantı bekleniyor...\n");

    while (1) {
        clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddr, &clientAddrLen);
        if (clientSocket == -1) {
            printf("[!] Accept hatası\n");

        }else {
	
		printf("[+] İstemci bağlandı: %s\n", inet_ntoa(clientAddr.sin_addr));


		recv(clientSocket, &buffer, sizeof(buffer), 0);
            
		if (buffer == 1 || buffer == 2) {
			printf("[+] Mesaj alındı: %d\n", buffer);
			sendSignal(buffer);
			buffer = 0;
			
		}
	}

        
    }


    close(clientSocket);
    close(serverSocket);

    return 0;
}
