#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdbool.h>
int main() {
    int clientSocket;
    struct sockaddr_in serverAddr;
    char buffer[1] = {1};

    // Socket oluşturma
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1) {
        perror("[!] Socket oluşturulamadı.");
        exit(1);
    }

    // Server adres ve port ayarları
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");  // Sunucu IP adresi
    serverAddr.sin_port = htons(12345);  // Sunucu portu

    // Sunucuya bağlan
    if (connect(clientSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == -1) {
        perror("[!] Bağlantı hatası.");
        exit(1);
    }

    printf("[+] Sunucuya bağlandı.\n");

    // 1 byte mesajı gönder
    ssize_t bytesSent = send(clientSocket, buffer, sizeof(buffer), 0);
    if (bytesSent == -1) {
        perror("[!] Gönderme hatası.");
        exit(1);
    }

    printf("[+] Mesaj gönderildi: 1\n");

    // Socket'i kapat
    close(clientSocket);

    return 0;
}
