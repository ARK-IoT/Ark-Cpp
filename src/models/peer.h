

#ifndef PEER_H
#define PEER_H

#include "utilities/platform.h"

#include <cstring>
#include <cstdio>

namespace ARK
{
/*************************************************
*	ARK::peer_t
**************************************************/
struct peer_t
{
	protected:
		char	ip_[40];
		int 	port_;
		char	version_[32];
		int		errors_;
		char	os_[32];
		char	height_[32];
		char	status_[32];
		int		delay_;
};
/*************************************************/

/**************************************************************************************************/

/*************************************************
*	ARK::Peer
**************************************************/
struct Peer :
		public peer_t,
		Printable
{
	public:
		/*************************************************
		*	Constructor
		**************************************************/
		Peer(
				const char *const newIP,
				int 							newPort,
				const char *const newVersion,
				int 							newErrors,
				const char *const newOS,
				const char *const newHeight,
				const char *const newStatus,
				int								newDelay
		);
		/*************************************************/

		/*************************************************
		*	Accessors
		**************************************************/
		const char *ip() const noexcept { return ip_; }
		int port() const noexcept { return port_; }
		const char* version() const noexcept { return version_; }
		int errors() const noexcept { return errors_; }
		const char* os() const noexcept { return os_; }
		const char* height() const noexcept { return height_; }
		const char* status() const noexcept { return status_; }
		int delay() const noexcept { return delay_; }
		/*************************************************/

		/*************************************************
		*
		**************************************************/
		virtual size_t printTo(Print &p) const;
		/*************************************************/

};
/*************************************************/

};

#endif
