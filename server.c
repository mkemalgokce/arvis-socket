#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdbool.h>
int main() {
    int serverSocket, clientSocket;
    struct sockaddr_in serverAddr, clientAddr;
    socklen_t clientAddrLen = sizeof(clientAddr);
    char buffer[1] = {0};

    // Socket oluşturma
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        perror("Socket oluşturulamadı");
        exit(1);
    }

    // Server adres ve port ayarları
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(12345);  // Örnek olarak 12345 portunu kullanıyoruz

    // Socket'i adres ve port ile bağlama
    if (bind(serverSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == -1) {
        perror("Bind hatası");
        exit(1);
    }

    // Socket'i dinleme moduna al
    if (listen(serverSocket, 5) == -1) {
        perror("Listen hatası");
        exit(1);
    }

    printf("Server başlatıldı. Bağlantı bekleniyor...\n");

    // İstemci bağlantısını kabul et
    

    // Mesajları sürekli olarak bekleyin
    while (1) {
        clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddr, &clientAddrLen);
        if (clientSocket == -1) {
            perror("Accept hatası");
            exit(1);
        }

        printf("İstemci bağlandı: %s\n", inet_ntoa(clientAddr.sin_addr));
        while(1) {
            // 1 byte boyutunda mesaj al
            recv(clientSocket, buffer, sizeof(buffer), 0);
            
            if (buffer[0] == 1) {
                printf("Mesaj alındı: 1\n");
                buffer[0] = 0;
                break;
            }
        }
        
        
    }

    // Soketleri kapat
    close(clientSocket);
    close(serverSocket);

    return 0;
}
