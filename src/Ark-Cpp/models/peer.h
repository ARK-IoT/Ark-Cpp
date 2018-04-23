

#ifndef peer_h
#define peer_h

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
};

#endif
