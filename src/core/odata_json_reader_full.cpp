/*
 * Copyright (c) Microsoft Corporation. All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
 
 #include "odata/core/odata_json_reader_full.h"

using namespace ::web;
using namespace ::odata::edm;
using namespace ::odata::communication;
using namespace ::odata::utility;

namespace odata { namespace core
{

std::shared_ptr<odata_payload> entity_json_reader_full::deserilize(const web::json::value& response, std::shared_ptr<edm_entity_set> set)
{
	throw std::runtime_error("full metadata reader not implemented!"); 
}

}}