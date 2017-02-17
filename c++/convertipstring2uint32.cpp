#include <iostream>
#include <arpa/inet.h>
//#include <netinet/in.h>
//#include <sys/socket.h>

using namespace std;
string ip="10.10.10.10";
in_addr addr;

int main(void)
{
	inet_aton(ip.c_str(), &addr);
	printf("ip=%d\r\n", addr);
	printf("0x%d")
	return 0;
}
