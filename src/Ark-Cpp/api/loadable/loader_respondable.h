

#ifndef LOADER_RESPONDABLE_H
#define LOADER_RESPONDABLE_H

#include <cstring>

namespace ARK {
namespace API {
namespace Loader {
namespace Respondable {

/*  ================================================  */
/*  ============  */
/*  ARK::API::Loader::Respondable::Status  */
class Status {
private:
    bool loaded_;
    int now_;
    char blocksCount_[64];  //TODO review sizes

public:
    Status(
        const char* const l,
        int n,
        const char* const bc
    ) : loaded_(strcmp(l, "true") == 0), now_(n), blocksCount_() {
        strncpy(blocksCount_, bc, sizeof(blocksCount_) / sizeof(blocksCount_[0]));
    }

	bool loaded() const noexcept { return loaded_; }
	int now() const noexcept { return now_; }
	const char* blocks_count() const noexcept { return blocksCount_; }

    void description(char* const buf, size_t size);
};
/*  ============  */
/*  ================================================  */


/*  ================================================  */
/*  ============  */
/*  ARK::API::Loader::Respondable::Sync  */
class Sync {
private:
    bool syncing_;
    int blocks_;
    char height_[64]; //TODO: review sizes
    char id_[64];

public:
    Sync(
        const char* s,
        int b,
        const char* const h,
        const char* const i
    ) : syncing_(strcmp(s, "true") == 0), blocks_(b), height_(), id_() {
        strncpy(height_, h, sizeof(height_) / sizeof(height_[0]));
        strncpy(id_, i, sizeof(id_) / sizeof(id_[0]));
    }

	bool syncing() const noexcept { return syncing_; }
	int blocks() const noexcept { return blocks_; }
	const char* height() const noexcept { return height_; }
	const char* id() const noexcept { return id_; }

    void description(char* const buf, size_t size);
};
/*  ============  */
/*  ================================================  */

}
}
}
}


#endif
