#include "jsoncpp_orm.h"
using namespace cpporm;

void Mapper::get(const Json::Value& json, int* e){
      e[0] =  json.asInt();
}



void Mapper::get(const Json::Value& json, std::string* e){
      e[0] =  json.asString();
}



