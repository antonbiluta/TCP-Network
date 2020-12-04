#include <iostream>
#pragma comment(lib,"ws2_32.lib")
#include<WinSock2.h>
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <string>

#pragma warning(disable: 4996)

SOCKET Connection;

enum Packet {
	P_ChatMassage,
	P_Test

};

bool ProcessPacket(Packet packettype) {
	switch (packettype) {
	case P_ChatMassage:
	{
		int msg_size;
		recv(Connection, (char*)&msg_size, sizeof(int), NULL);
		char* msg = new  char[msg_size + 1];
		msg[msg_size] = '\0';
		recv(Connection, msg, msg_size, NULL);
		std::cout <<"Another user:"<< msg << std::endl;
		delete[] msg;
		break;
	}
	case P_Test:
		std::cout << "Test packet.\n";
		break;
	default:
		std::cout << "Unrecognized packet: " << packettype << std::endl;
		break;
	}
	return true;
}

void ClientHandler() {
	Packet packettype;
	while (true) {
		recv(Connection, (char*)&packettype, sizeof(Packet), NULL);

		if (!ProcessPacket(packettype)) {
			break;
		}
	}
	closesocket(Connection);
}

int main(int argc, char* argv[]) {
	//WSAStartup
	WSAData wsaData;
	WORD DLLVersion = MAKEWORD(2, 1);
	if (WSAStartup(DLLVersion, &wsaData) != 0) {
		std::cout << "Error#1\n";
		exit(1);
	}

	SOCKADDR_IN addr;
	int sizeofaddr = sizeof(addr);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(1111);
	addr.sin_family = AF_INET;
	Connection = socket(AF_INET, SOCK_STREAM, NULL);
	if (connect(Connection, (SOCKADDR*)&addr, sizeof(addr)) != 0) {
		std::cout << "Error: failed connect ot server\n";
		return 1;
	}
	std::cout << "Connected\n";

	CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)ClientHandler, NULL, NULL, NULL);

	std::string msgl;
	while (true) {
		std::getline(std::cin, msgl);
		int msg_size = msgl.size();
		Packet packettyp = P_ChatMassage;
		send(Connection, (char*)&packettyp, sizeof(Packet), NULL);
		send(Connection, (char*)&msg_size, sizeof(int), NULL);
		send(Connection, msgl.c_str(), msg_size, NULL);
		Sleep(10);
	}

	system("pause");
}
