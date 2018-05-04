
#include "models/peer.h"

namespace ARK
{

/*************************************************
*	Constructor
**************************************************/
Peer::Peer(
		const char *const newIP,
		int 							newPort,
		const char *const newVersion,
		int 							newErrors,
		const char *const newOS,
		const char *const newHeight,
		const char *const newStatus,
		int 							newDelay
)	:
		port_(newPort),
		errors_(newErrors),
		delay_(newDelay)
{
	strncpy(this->ip_, newIP, sizeof(ip_) / sizeof(ip_[0]));
	strncpy(this->version_, newVersion, sizeof(version_) / sizeof(version_[0]));
	strncpy(this->os_, newOS, sizeof(os_) / sizeof(os_[0]));
	strncpy(this->height_, newHeight, sizeof(height_) / sizeof(height_[0]));
	strncpy(this->status_, newStatus, sizeof(status_) / sizeof(status_[0]));
};
/*************************************************/

/*************************************************
*
**************************************************/
size_t Peer::printTo(Print &p) const
{
	size_t size = 0;
		size += p.print("ip: ");
		size += p.print(this->ip_);

		size += p.print("\nport: ");
		size += p.print(this->port_);

		size += p.print("\nversion: ");
		size += p.print(this->version_);

		size += p.print("\nerrors: ");
		size += p.print(this->errors_);

		size += p.print("\nos: ");
		size += p.print(this->os_);

		size += p.print("\nheight: ");
		size += p.print(this->height_);

		size += p.print("\nstatus: ");
		size += p.print(this->status_);

		size += p.print("\ndelay: ");
		size += p.print(this->delay_);
	return size;
}
/*************************************************/

};
