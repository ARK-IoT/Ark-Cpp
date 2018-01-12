

#ifndef json_h
#define json_h

namespace ARK {
  namespace Utilities {


    /*  ARK::Utilities::JSONString jString(_jsonStr); */
    /*  jString.valueFor(_keyName); */
    struct JSONString {

      #define Range(x,y) ( (y) > (x) ? (y - x) : (x - y ) )
      String jsonStr;

      private:

        int getKeyIndex(String _key);
        int getKeyEndex(String _key);
        int getKeyRange(String _key);
        String getKeySubstring(String _key);
        int getValueIndex(String _key);
        int getValueEndex(String _key);
        int getValueRange(String _key);
        String getValueSubstring(String _key);
        
      public:

        JSONString(String _jsonStr);
        String valueFor(String _key);
        
    };

  };
};

ARK::Utilities::JSONString::JSONString(String _jsonStr) {
  this->jsonStr = _jsonStr;
};

String ARK::Utilities::JSONString::valueFor(String _key) {
  return this->getValueSubstring(_key);
};

int ARK::Utilities::JSONString::getKeyIndex(String _key) {
  return this->jsonStr.indexOf(_key);
};

int ARK::Utilities::JSONString::getKeyEndex(String _key) {
  String separator1 = "\":";
  int keyIndex = this->getKeyIndex(_key);
  return this->jsonStr.indexOf(separator1, keyIndex);
};

int ARK::Utilities::JSONString::getKeyRange(String _key) {
  int keyIndex = this->getKeyIndex(_key);
  int keyEndex = this->getKeyEndex(_key);
  return Range(keyIndex, keyEndex);
};

String ARK::Utilities::JSONString::getKeySubstring(String _key) {  
  int keyIndex = this->getKeyIndex(_key);
  int keyRange = this->getKeyRange(_key);
  return this->jsonStr.substring(keyIndex, keyIndex + keyRange);
};

int ARK::Utilities::JSONString::getValueIndex(String _key) {
  int keyEndex = this->getKeyEndex(_key) + 1;
  while ( keyEndex == this->jsonStr.indexOf("\"", keyEndex)
            || keyEndex == this->jsonStr.indexOf(":", keyEndex) ) { 
      ++keyEndex;
  }

  return keyEndex;
};

int ARK::Utilities::JSONString::getValueEndex(String _key) {
  int valueIndex = this->getValueIndex(_key);
  while ( isPunct(this->jsonStr.charAt(valueIndex)) && isAlphaNumeric(this->jsonStr.charAt(valueIndex +1)) ) { valueIndex++; }
  int valueEndex = valueIndex;
  while ( ( isAlphaNumeric(this->jsonStr.charAt(valueEndex)) && !isSpace(this->jsonStr.charAt(valueEndex)) )
          || (this->jsonStr.charAt(valueEndex) == '.')
          || (this->jsonStr.charAt(valueEndex) == '-')
          || ( (this->jsonStr.charAt(valueEndex) == '/') && (this->jsonStr.charAt(valueEndex + 1) == '/') )
          || ( (this->jsonStr.charAt(valueEndex) == ':') && (this->jsonStr.charAt(valueEndex - 1) != '"') )
        ) { valueEndex++; }
  return valueEndex;
};

int ARK::Utilities::JSONString::getValueRange(String _key) {
  int valueIndex = this->getValueIndex(_key);
  int valueEndex = this->getValueEndex(_key);
  return Range(valueIndex, valueEndex);
};

String ARK::Utilities::JSONString::getValueSubstring(String _key) {  
  int valueRange = this->getValueRange(_key);
  int valueIndex = this->getValueIndex(_key);
  return this->jsonStr.substring(valueIndex, valueIndex + valueRange);
};

#endif

