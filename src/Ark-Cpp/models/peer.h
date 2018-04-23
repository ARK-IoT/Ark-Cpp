

#ifndef peer_h
#define peer_h

<<<<<<< HEAD
#include "platform.h"

#include <cstring>
#include <cstdio>

namespace ARK {

/*  ================================================  */
	/*  =========  */
	/*  ARK::Peer  */
	class Peer : public Printable {
	private:
		char ip_[40];
		int port_;
		char version_[64]; //TODO:  review array sizes
		int errors_;
		char os_[64];
		char height_[64];
		char status_[64];
		int delay_;

	public:
		Peer(
			const char* const i,
			int p,
			const char* const v,
			int e,
			const char* const o,
			const char* const h,
			const char* const s,
			int d
		);

		const char* ip() const noexcept { return ip_; }
		int port() const noexcept { return port_; }
		const char* version() const noexcept { return version_; }
		int errors() const noexcept { return errors_; }
		const char* os() const noexcept { return os_; }
		const char* height() const noexcept { return height_; }
		const char* status() const noexcept { return status_; }
		int delay() const noexcept { return delay_; }

		size_t printTo(Print& p) const override;
	};
	/*  =========  */
/*  ================================================  */

=======
namespace ARK
{
/*************************************************
*   ARK::peer_t
**************************************************/
struct peer_t
{
public:
	char ip[40];
	int port;
	char version[32];
	int errors;
	char os[32];
	char height[32];
	char status[32];
	int delay;
};
/*************************************************/

/**************************************************************************************************/

/*************************************************
*   ARK::Peer
**************************************************/
struct Peer : public peer_t, Printable
{
public:
	Peer(
			const char *const newIP,
			int newPort,
			const char *const newVersion,
			int newErrors,
			const char *const newOS,
			const char *const newHeight,
			const char *const newStatus,
			int newDelay
	);

	virtual size_t printTo(Print &p) const;
};
/*************************************************/
>>>>>>> master
};

#endif
