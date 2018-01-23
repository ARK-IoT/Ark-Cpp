

#ifndef api_helpers_h
#define api_helpers_h

namespace ARK {
  namespace API {
    namespace Helpers {

      int substringCount(const String& str, const String& sub) {
        if (sub.length() == 0) return 0;
        int count = 0;
        for ( size_t offset = str.indexOf(sub);
              offset != std::string::npos;
              offset = str.indexOf(sub, offset + sub.length())){ ++count; }
        return count;
      };

/*  ==========================================================================  */

			struct Successable {
				public:
					bool success;
			};

    };
  };
};

#endif
