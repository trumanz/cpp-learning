#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "gtest/gtest.h"
#include <map>
#include <string>
#include <sstream>
#include <jsoncpp/json/json.h>


static std::string getExampleJson() {

   std::stringstream ss;
   ss << "{\n";
   ss <<  "\"encoding\" : \"UTF-8\",\n";
   ss <<  "\"plug-ins\" : [\n";
   ss <<  "\"python\",\n";
   ss <<  "\"c++\",\n";
   ss <<  "\"ruby\"\n";
   ss <<  "],\n";
   ss <<  "\"indent\" : { \"length\" : 3, \"use_space\": true }\n";
   ss <<  "}";
   return ss.str();
}

TEST(jsoncpp, parse) {

   std::stringstream ss;
   ss << getExampleJson();
   Json::Value root;
   Json::Reader reader;
   //printf("parse, \n%s\n", ss.str().c_str());
   bool parsingSuccessful = reader.parse(ss, root);

   if(!parsingSuccessful) {
        printf("Failed to parse, %s\n", reader.getFormatedErrorMessages().c_str());
   }
   ASSERT_EQ(parsingSuccessful, true);

   std::string encoding = root.get("encoding", "thisDefaultValue").asString();
   ASSERT_EQ(encoding, "UTF-8");
  
   Json::Value plugins = root["plug-ins"];
   ASSERT_EQ(3, plugins.size());
   EXPECT_EQ("python", plugins[0].asString());
   EXPECT_EQ("c++",    plugins[1].asString());
   EXPECT_EQ("ruby",   plugins[2].asString());

  
   ASSERT_EQ(3, root["indent"]["length"].asInt());
   ASSERT_EQ(true, root["indent"]["use_space"].asBool());
}

TEST(jsoncpp, parse_not_exist) {

   std::stringstream ss;
   ss << getExampleJson();
   Json::Value root;
   Json::Reader reader;
   //printf("parse, \n%s\n", ss.str().c_str());
   bool parsingSuccessful = reader.parse(ss, root);

   if(!parsingSuccessful) {
        printf("Failed to parse, %s\n", reader.getFormatedErrorMessages().c_str());
   }
   ASSERT_EQ(parsingSuccessful, true);

   std::string encoding = root.get("encoding2", "thisDefaultValue").asString();
   ASSERT_EQ(encoding, "thisDefaultValue");
  
   Json::Value plugins = root["plug-ins2"];
   ASSERT_EQ(true, plugins.empty());

}




