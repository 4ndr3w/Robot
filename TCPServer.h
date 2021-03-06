#ifndef TCP_Server_h
#define TCP_Server_h

#include "semLib.h"

class TCPServer {
	int port;
	int taskId;
public:
	TCPServer(int port);
	virtual ~TCPServer();
	void spawnServer();
	virtual void handleClient(int) = 0;
};

class BroadcastTCPServer : public TCPServer {
	struct ClientNode {
		ClientNode *prev;
		int socket;
		ClientNode *next;
	};

	ClientNode *firstClient;
	ClientNode *lastClient;

	SEM_ID mutex;

public:
	BroadcastTCPServer(int port);
	void handleClient(int sock);
	void broadcast(char* message, int len);
};

#endif
