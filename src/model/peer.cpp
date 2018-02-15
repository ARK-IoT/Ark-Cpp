#include "peer.h"

#include <cstring>
#include <cstdio>

ARK::Peer::Peer(
	const char* const i,
	int p,
	const char* const v,
	int e,
	const char* const o,
	const char* const h,
	const char* const s,
	int d
) : ip_(), port_(p), version_(), errors_(e), os_(), height_(), status_(), delay_(d) {
	strncpy(ip_, i, sizeof(ip_) / sizeof(ip_[0]));
	strncpy(version_, v, sizeof(version_) / sizeof(version_[0]));
	strncpy(os_, o, sizeof(os_) / sizeof(os_[0]));
	strncpy(height_, h, sizeof(height_) / sizeof(height_[0]));
	strncpy(status_, s, sizeof(status_) / sizeof(status_[0]));
}

/*  ================================================  */
/*  =========  */
/*  Description  */
void ARK::Peer::Peer::description(char* const buf, size_t /*size*/) {
	strcpy(buf, "ip: ");
	strcat(buf, this->ip_);
	strcat(buf, "\nport: ");
	auto len = strlen(buf);
	sprintf(buf + len, "%d", this->port_);
	strcat(buf, "\nversion: ");
	strcat(buf, this->version_);
	strcat(buf, "\nerrors: ");
	len = strlen(buf);
	sprintf(buf + len, "%d", this->errors_);
	strcat(buf, "\nos: ");
	strcat(buf, this->os_);
	strcat(buf, "\nheight: ");
	strcat(buf, this->height_);
	strcat(buf, "\nstatus: ");
	strcat(buf, this->status_);
	strcat(buf, "\ndelay: ");
	len = strlen(buf);
	sprintf(buf + len, "%d", this->delay_);
}
/*  =========  */
/*  ================================================  */

