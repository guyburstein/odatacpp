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
 
 #pragma once

#include "cpprest/json.h"
#include "odata/communication/http_communication.h"
#include "odata/common/utility.h"
#include "odata/core/odata_core.h"
#include "odata/edm/odata_edm.h"


namespace odata { namespace core
{

class entity_json_writer_full
{
public:
	entity_json_writer_full(std::shared_ptr<::odata::edm::edm_model> schema) : m_model(schema)
	{
	}

	ODATACPP_API ::web::json::value serialize(std::shared_ptr<odata_value> value_object);
	ODATACPP_API ::web::json::value serialize(std::vector<std::shared_ptr<odata_value>> value_objects);


private:
	std::shared_ptr<::odata::edm::edm_model> m_model;
};

}}



