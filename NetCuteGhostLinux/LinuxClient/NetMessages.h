#pragma once

#include <string>

#define NET_MAXLEN 32
#define BUFSIZE 64
#define MAX_LISTEN 4


class NetMeta
{
public:
	NetMeta() = delete;
	
	static const char CHATTING;
	static const char GAMECTRL;
	static const char COMMAND;
	static const char INTERPROC;
};


#pragma pack(1)
struct GamePacket
{
	int playerindex;
	char content[NET_MAXLEN];
};
#pragma pack()



class NetMessage
{
public:
	NetMessage() = delete;
	
	class LnxClient
	{
	public:
		LnxClient() = delete;
		
		class GAME
		{
		public:
			GAME() = delete;
			
			// movement section;
			static const std::string UP;
			static const std::string DOWN;
			static const std::string LEFT;
			static const std::string RIGHT;
			
			// slow movement section;
			static const std::string SLOWUP;
			static const std::string SLOWDOWN;
			static const std::string SLOWLEFT;
			static const std::string SLOWRIGHT;
			
			// action section;
			static const std::string STOP;
			static const std::string DASH;
		};
		
		class CMD
		{
		public:
			CMD() = delete;
			
			static const std::string QUIT;
		};
	};
	
	
	
	class LnxServer
	{
	public:
		LnxServer() = delete;
		
		#pragma pack(1)
		struct MessageBuf
		{
			long mtype;
			int index;
			char content[NET_MAXLEN];
		};
		#pragma pack()
		
		class IPC
		{
		public:
			IPC() = delete;
			
			static const std::string INDEX;
		};
	};
};