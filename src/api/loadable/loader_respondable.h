

#ifndef LOADER_RESPONDABLE_H
#define LOADER_RESPONDABLE_H

#include <cstring>

namespace ARK
{
namespace API
{
namespace Loader
{
namespace Respondable
{

/*  ================================================  */
/*  ============  */
/*  ARK::API::Loader::Respondable::Status  */
  struct Status {
    public:
      bool loaded;
      int now;
      char blocksCount[64];  //TODO review sizes

      Status(
          const char* const l,
          int n,
          const char* const bc
      ) : loaded(strcmp(l, "true") == 0), now(n), blocksCount() {
          strncpy(blocksCount, bc, sizeof(blocksCount) / sizeof(blocksCount[0]));
      }

      void description(char* const buf, size_t size);
  };
/*  ============  */
/*  ================================================  */


/*  ================================================  */
/*  ============  */
/*  ARK::API::Loader::Respondable::Sync  */
  struct Sync {
    public:
      bool syncing;
      int blocks;
      char height[64]; //TODO: review sizes
      char id[64];

      Sync(
          const char* s,
          int b,
          const char* const h,
          const char* const i
      ) : syncing(strcmp(s, "true") == 0), blocks(b), height(), id() {
          strncpy(height, h, sizeof(height) / sizeof(height[0]));
          strncpy(id, i, sizeof(id) / sizeof(id[0]));
      }

      void description(char* const buf, size_t size);
  };
/*  ============  */
/*  ================================================  */

};
};
};
};


#endif
