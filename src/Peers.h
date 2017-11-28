

namespace Networks {

    const char* devnet_hash = "578e820911f24e039733b45e4882b73e301f813a0d2c31330dafda84534ffa23";
    const char* mainnet_hash = "6e84d08bd299ed97c212c886c98a57e36545c8f5d645ca7eeae63a8bd62d8988";
    
    const int devnet_port = 4002;
    const int mainnet_port = 4001;
    
    const byte devnet_peers[5][4] = {
        { 167, 114, 29, 51 },
        { 167, 114, 29, 52 },
        { 167, 114, 29, 53 },
        { 167, 114, 29, 54 },
        { 167, 114, 29, 55 } 
    };
    
    const byte mainnet_peers[46][4] = {
        { 5, 39, 9, 240 },
        { 5, 39, 9, 241 },
        { 5, 39, 9, 242 },
        { 5, 39, 9, 243 },
        { 5, 39, 9, 244 },
        { 5, 39, 9, 250 },
        { 5, 39, 9, 251 },
        { 5, 39, 9, 252 },
        { 5, 39, 9, 253 },
        { 5, 39, 9, 254 },
        { 5, 39, 9, 255 },
        { 5, 39, 53, 48 },
        { 5, 39, 53, 49 },
        { 5, 39, 53, 50 },
        { 5, 39, 53, 51 },
        { 5, 39, 53, 52 },
        { 5, 39, 53, 53 },
        { 5, 39, 53, 54 },
        { 5, 39, 53, 55 },
        { 37, 59, 129, 160 },
        { 37, 59, 129, 161 },
        { 37, 59, 129, 162 },
        { 37, 59, 129, 163 },
        { 37, 59, 129, 164 },
        { 37, 59, 129, 165 },
        { 37, 59, 129, 166 },
        { 37, 59, 129, 167 },
        { 37, 59, 129, 168 },
        { 37, 59, 129, 169 },
        { 37, 59, 129, 170 },
        { 37, 59, 129, 171 },
        { 37, 59, 129, 172 },
        { 37, 59, 129, 173 },
        { 37, 59, 129, 174 },
        { 37, 59, 129, 175 },
        { 193, 70, 72, 80 },
        { 193, 70, 72, 81 },
        { 193, 70, 72, 82 },
        { 193, 70, 72, 83 },
        { 193, 70, 72, 84 },
        { 193, 70, 72, 85 },
        { 193, 70, 72, 86 },
        { 193, 70, 72, 87 },
        { 193, 70, 72, 88 },
        { 193, 70, 72, 89 },
        { 193, 70, 72, 90 }
    };
    
    
    typedef struct {
        const char* name;
        const char* nethash;
    } nethash_type;
    
    nethash_type nethash[2]  { 
        { "devnet", devnet_hash },
        { "mainnet", mainnet_hash }
    };
    
    typedef struct {
        const char* nethash;
        int port;
        byte peers[46][4];
    } network;
    
    
    network devnet = {
        devnet_hash,
        devnet_port,
        devnet_peers[5][4]
    };
    
    network mainnet = {
        mainnet_hash,
        mainnet_port,
        mainnet_peers[46][4]
    };
    
    network getNetworkFromNethash(const char* hash) {
        const char* nettype = getNetworkTypeFrom(hash);
        if (nettype == "devnet") { return devnet; }
        else if (nettype == "mainnet") { return mainnet; }
    }
    
    const char* getNetworkTypeFrom(const char* hash) {
        for ( int n = 0; n < 2; n++) {
            if (hash == nethash[n].nethash) {
                return nethash[n].name;
            } else { return "unknown"; }
        }
    }
    
};
