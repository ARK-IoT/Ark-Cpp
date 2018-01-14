

#ifndef json_h
#define json_h

#include "../../include/ArduinoJson/ArduinoJson.h"


namespace ARK {
  namespace Utilities {


    /*  ARK::Utilities::JSONString jString(_jsonStr); */
    /*  jString.valueFor(_keyName); */
    struct JSONString {

      private:

        String jsonStr;
  
      public:

        JSONString(String _jsonStr);
        String valueFor(String _key);
        String subvalueFor(String _key, int _pos);
        String valueIn(String _key, String _subkey);
        String subvalueIn(String _key, String _subkey);
        String subarrayValueIn(String _key, int _pos, String _subkey);

        /*    BROKEN: fix for large callbacks    */
        /*  Delegates callback is ~13,564 bytes  */
        /*     Peers callback is ~10,792 bytes   */
        // String largeSubarrayValueIn(String _key, int _pos, String _subkey, int _objectSize);
    };

  };
};


ARK::Utilities::JSONString::JSONString(String _jsonStr) {
  this->jsonStr = _jsonStr;
};

/*    { "key1": value1, "key2": value2 }    */
String ARK::Utilities::JSONString::valueFor(String _key) {
  const size_t capacity = JSON_OBJECT_SIZE(3) + JSON_ARRAY_SIZE(2) + 60;
  DynamicJsonBuffer jsonBuffer(capacity);
  JsonObject& root = jsonBuffer.parseObject(this->jsonStr);
  return root[_key];
}
/*    { "key": { subValue1, subvalue2 } }    */
String ARK::Utilities::JSONString::subvalueFor(String _key, int _pos) {
  const size_t capacity = JSON_OBJECT_SIZE(3) + JSON_ARRAY_SIZE(2) + 60;
  DynamicJsonBuffer jsonBuffer(capacity);
  JsonObject& root = jsonBuffer.parseObject(this->jsonStr);
  return root[_key][_pos];
}

String ARK::Utilities::JSONString::valueIn(String _key, String _subkey) {
  const size_t capacity = JSON_OBJECT_SIZE(3) + JSON_ARRAY_SIZE(2) + 60;
  DynamicJsonBuffer jsonBuffer(capacity);
  JsonObject& root = jsonBuffer.parseObject(this->jsonStr);
  return root[_key][_subkey];
}

String ARK::Utilities::JSONString::subvalueIn(String _key, String _subkey) {
  const size_t capacity = JSON_OBJECT_SIZE(3) + JSON_ARRAY_SIZE(2) + 60;
  DynamicJsonBuffer jsonBuffer(capacity);
  JsonObject& root = jsonBuffer.parseObject(this->jsonStr);
  JsonObject& newRoot = root[_key];
  return newRoot[_subkey];
}

String ARK::Utilities::JSONString::subarrayValueIn(String _key, int _pos, String _subkey) {
  const size_t capacity = JSON_OBJECT_SIZE(3) + JSON_ARRAY_SIZE(2) + 60;
  DynamicJsonBuffer jsonBuffer(capacity);
  JsonObject& root = jsonBuffer.parseObject(this->jsonStr);
    // JsonArray& root = jsonBuffer.parseArray(this->jsonStr);
  return root[_key][_pos][_subkey];
}

/*    BROKEN: fix for large callbacks    */
/*  Delegates callback is ~13,564 bytes  */
/*     Peers callback is ~10,792 bytes   */
// String ARK::Utilities::JSONString::largeSubarrayValueIn(String _key, int _pos, String _subkey, int _objectSize) {
//   StaticJsonBuffer<11000> jsonBuffer;
//   JsonObject& root = jsonBuffer.parseObject(this->jsonStr);
//   // return root[_key][_pos][_subkey];
//   JsonArray& rootArray = root[_key];
//   JsonObject& newRoot = rootArray[_pos];
//   return newRoot[_subkey];
// }

#endif

