

#include "models.h"

ARK::Peer::Peer(
		const char *const newIP,
		int 							newPort,
		const char *const newVersion,
		int 							newErrors,
		const char *const newOS,
		const char *const newHeight,
		const char *const newStatus,
		int 							newDelay
)
{
	strncpy(ip, newIP, sizeof(ip) / sizeof(ip[0]));
	port = newPort;
	strncpy(version, newVersion, sizeof(version) / sizeof(version[0]));
	errors = newErrors;
	strncpy(os, newOS, sizeof(os) / sizeof(os[0]));
	strncpy(height, newHeight, sizeof(height) / sizeof(height[0]));
	strncpy(status, newStatus, sizeof(status) / sizeof(status[0]));
	delay = newDelay;
};

/*************************************************
*
**************************************************/
size_t ARK::Peer::printTo(Print &p) const
{
	size_t size = 0;

	size += p.print("ip: ");
	size += p.print(this->ip);

	size += p.print("\nport: ");
	size += p.print(this->port);

	size += p.print("\nversion: ");
	size += p.print(this->version);

	size += p.print("\nerrors: ");
	size += p.print(this->errors);

	size += p.print("\nos: ");
	size += p.print(this->os);

	size += p.print("\nheight: ");
	size += p.print(this->height);

	size += p.print("\nstatus: ");
	size += p.print(this->status);

	size += p.print("\ndelay: ");
	size += p.print(this->delay);

	return size;
}
/*************************************************/
