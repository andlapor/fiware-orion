#ifndef SRC_LIB_JSONPARSEV2_UTILSPARSE_H_
#define SRC_LIB_JSONPARSEV2_UTILSPARSE_H_

/*
*
* Copyright 2016 Telefonica Investigacion y Desarrollo, S.A.U
*
* This file is part of Orion Context Broker.
*
* Orion Context Broker is free software: you can redistribute it and/or
* modify it under the terms of the GNU Affero General Public License as
* published by the Free Software Foundation, either version 3 of the
* License, or (at your option) any later version.
*
* Orion Context Broker is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero
* General Public License for more details.
*
* You should have received a copy of the GNU Affero General Public License
* along with Orion Context Broker. If not, see http://www.gnu.org/licenses/.
*
* For those usages not covered by this license please contact with
* iot_support at tid dot es
*
* Author: Orion dev team
*/

#include "rapidjson/document.h"

template <typename T>
struct Opt {
  T           value;
  bool        given;
  std::string error;
  Opt(T v, bool g): value(v), given(g), error() {}
  Opt(std::string err): value(), given(true), error(err) {}
  bool ok() { return error.empty(); }
};

/*
 * getStringMust -  get a mandatory string from the rapidjson node
 */
Opt<std::string> getStringMust(const rapidjson::Value& parent, const char* field,const std::string& description = "");


/*
 * getStringOpt - get a optional string from the rapidjson node
 */
Opt<std::string> getStringOpt(const rapidjson::Value& parent, const char* field, const std::string& description = "");



/*
 * getInt64Must - get a mandatory int64_t from the rapidjson node
 */
Opt<int64_t> getInt64Must(const rapidjson::Value& parent, const char* field, const std::string& description = "");



/*
 * getInt64Opt - get a optional int64_t from the rapidjson node
 */
Opt<int64_t> getInt64Opt(const rapidjson::Value& parent, const char* field, const std::string& description = "");

#endif // SRC_LIB_JSONPARSEV2_UTILSPARSE_H
