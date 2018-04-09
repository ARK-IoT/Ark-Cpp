

// 7DE is a hex number
// 7DE = (7 * 16^2) + (13 * 16^1) + (14 * 16^0) 
// 7DE = (7 * 256) + (13 * 16) + (14 * 1) 
// 7DE = 1792 + 208 + 14 
// 7DE = 2014 (in decimal number)

//  example sha256: 
//      950981ce17df662dbc1d25305f8597a71309fb8f7232203a0944477e2534b021  | len = 64
//      95:09:81:ce:17:df:66:2d:bc:1d:25:30:5f:85:97:a7:13:09:fb:8f:72:32:20:3a:09:44:47:7e:25:34:b0:21 | len = 32
//
//  Hex Encoded (base16)
// 
//  output size:  256-bits
// 
//  ascii chars:  64
// 
//  Internal state size:  (8 × 32)
//  Block-size:   512
//  32 bytes
//  8-bit character width
// Hex: 4 bits per char 

// #define SHA256_SIZE_CHAR_WIDTH 4
// #define SHA256_SIZE_BASE 16

// #define SHA256_SIZE_WORD_WIDTH 8
// #define SHA256_SIZE_WORD 32

// #define SHA256_SIZE_HEX 64
// #define SHA256_SIZE_OUTPUT 256


#ifndef SHA256_H
#define SHA256_H


/*
 * Derived from https://github.com/intrbiz/arduino-crypto
 * =====
 * Balsa SCGI Copyright (c) 2012, Chris Ellis All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *    Redistributions of source code must retain the above copyright notice,
 *      this list of conditions and the following disclaimer.
 *    Redistributions in binary form must reproduce the above copyright notice,
 *      this list of conditions and the following disclaimer in the documentation
 *      and/or other materials provided with the distribution.
 *    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 *      AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 *      THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 *      IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 *      INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 *      (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *      LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 *      HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 *      OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 *      EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * =====
 * 
 *  Refactored & Expanded sleepdeficit 2017 (MIT)
 *  
 */

namespace ARK
{
namespace Crypto
{

class SHA256
{
private:
	typedef uint8_t byte;

  public:

    SHA256() : buffer()
    {
      total[0] = 0;
      total[1] = 0;
      state[0] = 0x6A09E667;
      state[1] = 0xBB67AE85;
      state[2] = 0x3C6EF372;
      state[3] = 0xA54FF53A;
      state[4] = 0x510E527F;
      state[5] = 0x9B05688C;
      state[6] = 0x1F83D9AB;
      state[7] = 0x5BE0CD19;
    };


    static void processToByteBuffer(char* sha256Buffer, const byte * bytes, int len)
    {

      //Serial.print("bytes: ");
      //Serial.print(bytes[0]);
      //Serial.print(bytes[1]);
      //Serial.print(bytes[2]);
      //Serial.print(bytes[3]);
      //Serial.println();

      SHA256 sha256;
      sha256.update(bytes, len);
      
      byte hash[32];
      sha256.finalize(hash);  

           // Serial.print("hash: ");


        /* hash now contains our 32 byte hash */
      for (byte i=0; i < 32; i++)
      {
          //if (hash[i]<0x10) { Serial.print('0'); }
          // else { 
            //Serial.print(hash[i], 8); 
            // }
      }


      for (byte i=0; i < 32; i++)
      { 
        char tmp[2];
          if (hash[i]<0x10) { sprintf(tmp, "%.1X", 0); }
          else { sprintf(tmp, "%.2X", hash[i]); };
        strcat(sha256Buffer, tmp);
      }

            // Serial.print("hash: ");

      // for (int i = 0; i < len; i++)
      //   Serial.print(hash[i], HEX);
      // Serial.println();
      // Serial.println();


      // Serial.print("hash2-8: ");
      // for (int i = 0; i < 32; i++)
      //   Serial.print(hash[i], 8);
      // Serial.println();
      // Serial.println();


      // for (byte i = 0; i < 32; i++)
      // {
      //   char tmp[2] = { "\0" };
      //   if (hash[i] != 0)
      //   {
      //     sprintf(tmp, "%.2x",hash[i]);
      //   }
      //   else
      //   {
      //     sprintf(tmp, "%.1x", 0);
      //     i--;
      //   }
      //   strcat(sha256Buffer, tmp);
      // }
      // strcat(sha256Buffer, "\0");

        // strcpy(sha256Buffer, hash)
        // sha256Buffer = hash;

//Serial.println();

      // for (byte i = 0; i < 32; i++)
      // {
      //   char tmp[2] = { "\0" };
      //   if (hash[i] != 0)
      //   {
      //     sprintf(tmp, "%.2x",hash[i]);
      //   }
      //   else
      //   {
      //     sprintf(tmp, "%.1x", 0);
      //     i--;
      //   }
      //   strcat(sha256Buffer, tmp);
      // }
      // strcat(sha256Buffer, "\0");

      // for (byte i = 0; i < len; i++)
      // {
      //   char tmp[3] = { "\0" };
      //   if (hash[i] != 0)
      //   {
      //     sprintf(tmp, "%.2x",hash[i/2]);
      //   }
      //   else
      //   {
      //     sprintf(tmp, "%.1x", 0);
      //     // i--;
      //   }
      //   strcat(sha256Buffer, tmp);
      // }
      // strcat(sha256Buffer, "\0");
      // free(tempBuffer);
    }

    static void processToBuffer(char* sha256Buffer, const char* passphrase)
    {
      SHA256 sha256;
      sha256.update(passphrase);
      
      byte hash[32];
      sha256.finalize(hash);  

      for (byte i = 0; i < 32; i++)
      {
        char tmp[2] = { "\0" };
        if (hash[i] != 0)
        {
          sprintf(tmp, "%.2x",hash[i]);
        }
        else
        {
          sprintf(tmp, "%.1x", 0);
          i--;
        }
        strcat(sha256Buffer, tmp);
      }
      strcat(sha256Buffer, "\0");
      // free(tempBuffer);
    }

  private:

    uint32_t total[2];
    uint32_t state[8];
    uint8_t  buffer[64];

    void update(const byte * msg, unsigned int len)
    {
      uint32_t left = total[0] & 0x3F;
      uint32_t fill = 64 - left;
  
      total[0] += len;
      total[0] &= 0xFFFFFFFF;
  
      if (total[0] < len)
        total[1]++;
      if (left && len >= fill) {
        memcpy((void *) (buffer + left), (void *) msg, fill);
        process(buffer);
        len -= fill;
        msg  += fill;
        left = 0;
      }
      while (len >= 64) {
        process(msg);
        len -= 64;
        msg  += 64;
      }
      if (len)
        memcpy((void *) (buffer + left), (void *) msg, len);
    };

    void update(const char *msg) { update((byte*) msg, strlen(msg)); }

    void finalize(byte *digest) {
      uint32_t last, padn;
      uint32_t high, low;
      byte msglen[8];
  
      high = (total[0] >> 29)
           | (total[1] <<  3);
      low  = (total[0] <<  3);

      #define PUT_UINT32(n,b,i)                  \
      {                                          \
          (b)[(i)    ] = (byte) ((n) >> 24);     \
          (b)[(i) + 1] = (byte) ((n) >> 16);     \
          (b)[(i) + 2] = (byte) ((n) >>  8);     \
          (b)[(i) + 3] = (byte) ((n)      );     \
      }
        
      PUT_UINT32(high, msglen, 0);
      PUT_UINT32(low,  msglen, 4);
  
      last = total[0] & 0x3F;
      padn = (last < 56) ? (56 - last) : (120 - last);

      static const byte sha256_padding[64] = {
       0x80, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
          0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
          0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
          0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
      };
  
      update(sha256_padding, padn);
      update(msglen, 8);
  
      PUT_UINT32(state[0], digest,  0);
      PUT_UINT32(state[1], digest,  4);
      PUT_UINT32(state[2], digest,  8);
      PUT_UINT32(state[3], digest, 12);
      PUT_UINT32(state[4], digest, 16);
      PUT_UINT32(state[5], digest, 20);
      PUT_UINT32(state[6], digest, 24);
      PUT_UINT32(state[7], digest, 28);
    };
    
    void process(const byte digest[64]) {
      
        uint32_t temp1, temp2, W[64];
        uint32_t A, B, C, D, E, F, G, H;

        #define GET_UINT32(n,b,i)                  \
        {                                          \
            (n) = ((uint32_t) (b)[(i)    ] << 24)  \
                | ((uint32_t) (b)[(i) + 1] << 16)  \
                | ((uint32_t) (b)[(i) + 2] <<  8)  \
                | ((uint32_t) (b)[(i) + 3]      ); \
        }
    
        GET_UINT32(W[0],  digest,  0);
        GET_UINT32(W[1],  digest,  4);
        GET_UINT32(W[2],  digest,  8);
        GET_UINT32(W[3],  digest, 12);
        GET_UINT32(W[4],  digest, 16);
        GET_UINT32(W[5],  digest, 20);
        GET_UINT32(W[6],  digest, 24);
        GET_UINT32(W[7],  digest, 28);
        GET_UINT32(W[8],  digest, 32);
        GET_UINT32(W[9],  digest, 36);
        GET_UINT32(W[10], digest, 40);
        GET_UINT32(W[11], digest, 44);
        GET_UINT32(W[12], digest, 48);
        GET_UINT32(W[13], digest, 52);
        GET_UINT32(W[14], digest, 56);
        GET_UINT32(W[15], digest, 60);
    
    #define  SHR(x,n) ((x & 0xFFFFFFFF) >> n)
    #define ROTR(x,n) (SHR(x,n) | (x << (32 - n)))
    
    #define S0(x) (ROTR(x, 7) ^ ROTR(x,18) ^  SHR(x, 3))
    #define S1(x) (ROTR(x,17) ^ ROTR(x,19) ^  SHR(x,10))
    
    #define S2(x) (ROTR(x, 2) ^ ROTR(x,13) ^ ROTR(x,22))
    #define S3(x) (ROTR(x, 6) ^ ROTR(x,11) ^ ROTR(x,25))
    
    #define F0(x,y,z) ((x & y) | (z & (x | y)))
    #define F1(x,y,z) (z ^ (x & (y ^ z)))
    
    #define R(t)                               \
    (                                          \
        W[t] = S1(W[t -  2]) + W[t -  7] +     \
               S0(W[t - 15]) + W[t - 16]       \
    )
    
    #define P(a,b,c,d,e,f,g,h,x,K)             \
    {                                          \
        temp1 = h + S3(e) + F1(e,f,g) + K + x; \
        temp2 = S2(a) + F0(a,b,c);             \
        d += temp1; h = temp1 + temp2;         \
    }
    
        A = state[0];
        B = state[1];
        C = state[2];
        D = state[3];
        E = state[4];
        F = state[5];
        G = state[6];
        H = state[7];
    
        P(A, B, C, D, E, F, G, H, W[ 0], 0x428A2F98);
        P(H, A, B, C, D, E, F, G, W[ 1], 0x71374491);
        P(G, H, A, B, C, D, E, F, W[ 2], 0xB5C0FBCF);
        P(F, G, H, A, B, C, D, E, W[ 3], 0xE9B5DBA5);
        P(E, F, G, H, A, B, C, D, W[ 4], 0x3956C25B);
        P(D, E, F, G, H, A, B, C, W[ 5], 0x59F111F1);
        P(C, D, E, F, G, H, A, B, W[ 6], 0x923F82A4);
        P(B, C, D, E, F, G, H, A, W[ 7], 0xAB1C5ED5);
        P(A, B, C, D, E, F, G, H, W[ 8], 0xD807AA98);
        P(H, A, B, C, D, E, F, G, W[ 9], 0x12835B01);
        P(G, H, A, B, C, D, E, F, W[10], 0x243185BE);
        P(F, G, H, A, B, C, D, E, W[11], 0x550C7DC3);
        P(E, F, G, H, A, B, C, D, W[12], 0x72BE5D74);
        P(D, E, F, G, H, A, B, C, W[13], 0x80DEB1FE);
        P(C, D, E, F, G, H, A, B, W[14], 0x9BDC06A7);
        P(B, C, D, E, F, G, H, A, W[15], 0xC19BF174);
        P(A, B, C, D, E, F, G, H, R(16), 0xE49B69C1);
        P(H, A, B, C, D, E, F, G, R(17), 0xEFBE4786);
        P(G, H, A, B, C, D, E, F, R(18), 0x0FC19DC6);
        P(F, G, H, A, B, C, D, E, R(19), 0x240CA1CC);
        P(E, F, G, H, A, B, C, D, R(20), 0x2DE92C6F);
        P(D, E, F, G, H, A, B, C, R(21), 0x4A7484AA);
        P(C, D, E, F, G, H, A, B, R(22), 0x5CB0A9DC);
        P(B, C, D, E, F, G, H, A, R(23), 0x76F988DA);
        P(A, B, C, D, E, F, G, H, R(24), 0x983E5152);
        P(H, A, B, C, D, E, F, G, R(25), 0xA831C66D);
        P(G, H, A, B, C, D, E, F, R(26), 0xB00327C8);
        P(F, G, H, A, B, C, D, E, R(27), 0xBF597FC7);
        P(E, F, G, H, A, B, C, D, R(28), 0xC6E00BF3);
        P(D, E, F, G, H, A, B, C, R(29), 0xD5A79147);
        P(C, D, E, F, G, H, A, B, R(30), 0x06CA6351);
        P(B, C, D, E, F, G, H, A, R(31), 0x14292967);
        P(A, B, C, D, E, F, G, H, R(32), 0x27B70A85);
        P(H, A, B, C, D, E, F, G, R(33), 0x2E1B2138);
        P(G, H, A, B, C, D, E, F, R(34), 0x4D2C6DFC);
        P(F, G, H, A, B, C, D, E, R(35), 0x53380D13);
        P(E, F, G, H, A, B, C, D, R(36), 0x650A7354);
        P(D, E, F, G, H, A, B, C, R(37), 0x766A0ABB);
        P(C, D, E, F, G, H, A, B, R(38), 0x81C2C92E);
        P(B, C, D, E, F, G, H, A, R(39), 0x92722C85);
        P(A, B, C, D, E, F, G, H, R(40), 0xA2BFE8A1);
        P(H, A, B, C, D, E, F, G, R(41), 0xA81A664B);
        P(G, H, A, B, C, D, E, F, R(42), 0xC24B8B70);
        P(F, G, H, A, B, C, D, E, R(43), 0xC76C51A3);
        P(E, F, G, H, A, B, C, D, R(44), 0xD192E819);
        P(D, E, F, G, H, A, B, C, R(45), 0xD6990624);
        P(C, D, E, F, G, H, A, B, R(46), 0xF40E3585);
        P(B, C, D, E, F, G, H, A, R(47), 0x106AA070);
        P(A, B, C, D, E, F, G, H, R(48), 0x19A4C116);
        P(H, A, B, C, D, E, F, G, R(49), 0x1E376C08);
        P(G, H, A, B, C, D, E, F, R(50), 0x2748774C);
        P(F, G, H, A, B, C, D, E, R(51), 0x34B0BCB5);
        P(E, F, G, H, A, B, C, D, R(52), 0x391C0CB3);
        P(D, E, F, G, H, A, B, C, R(53), 0x4ED8AA4A);
        P(C, D, E, F, G, H, A, B, R(54), 0x5B9CCA4F);
        P(B, C, D, E, F, G, H, A, R(55), 0x682E6FF3);
        P(A, B, C, D, E, F, G, H, R(56), 0x748F82EE);
        P(H, A, B, C, D, E, F, G, R(57), 0x78A5636F);
        P(G, H, A, B, C, D, E, F, R(58), 0x84C87814);
        P(F, G, H, A, B, C, D, E, R(59), 0x8CC70208);
        P(E, F, G, H, A, B, C, D, R(60), 0x90BEFFFA);
        P(D, E, F, G, H, A, B, C, R(61), 0xA4506CEB);
        P(C, D, E, F, G, H, A, B, R(62), 0xBEF9A3F7);
        P(B, C, D, E, F, G, H, A, R(63), 0xC67178F2);
    
        state[0] += A;
        state[1] += B;
        state[2] += C;
        state[3] += D;
        state[4] += E;
        state[5] += F;
        state[6] += G;
        state[7] += H;
    }

};

};
};

#endif
