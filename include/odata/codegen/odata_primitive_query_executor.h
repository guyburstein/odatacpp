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

#include "odata/client/odata_client.h"
#include "odata/common/utility.h"
#include "odata/core/odata_core.h"
#include "odata/codegen/odata_service_context.h"
#include "cpprest/uri.h"
#include "cpprest/asyncrt_utils.h"
#include "cpprest/json.h"
#include "cpprest/http_client.h"

namespace odata { namespace codegen {

template<typename ElementType>
class odata_primitive_query_executor
{
public:
	odata_primitive_query_executor(std::shared_ptr<::odata::codegen::odata_service_context> client_context) : m_client_context(client_context)
	{
	}

	typedef typename std::vector<ElementType> return_type;

	::pplx::task<return_type> execute_query(const ::utility::string_t& query_expression)
	{
		if (!m_client_context || !m_client_context->get_client())
		{
			return ::pplx::task_from_result(std::vector<ElementType>());
		}

		return m_client_context->get_client()->get_data_from_server(query_expression).then(
            [this] (const std::vector<std::shared_ptr<odata::core::odata_value>>& values) -> std::vector<ElementType>
			{
				std::vector<ElementType> vec;

				for(auto iter = values.cbegin(); iter != values.cend(); iter++)
				{
					auto primitive_value = std::dynamic_pointer_cast<::odata::core::odata_primitive_value>(*iter);
					if (primitive_value)
					{
						vec.push_back(primitive_value->as<ElementType>());
					}
				}
			
				return std::move(vec); 
			});
	}

	::pplx::task<return_type> execute_operation_query(const ::utility::string_t& query_expression, const std::vector<std::shared_ptr<::odata::core::odata_parameter>>& parameters, bool is_function)
	{
		if (!m_client_context || !m_client_context->get_client())
		{
			return ::pplx::task_from_result(return_type());
		}

		std::vector<std::shared_ptr<::odata::core::odata_value>> ret_values;
		m_client_context->get_client()->send_data_to_server(query_expression, parameters, ret_values, is_function ? HTTP_GET : HTTP_POST).get();

		std::vector<ElementType> vec;
		for(auto iter = ret_values.cbegin(); iter != ret_values.cend(); iter++)
		{
			auto primitive_value = std::dynamic_pointer_cast<::odata::core::odata_primitive_value>(*iter);
			if (primitive_value)
			{
				vec.push_back(primitive_value->as<ElementType>());
			}
		}
			
		return ::pplx::task_from_result(std::move(vec)); 
	}

protected:
	std::shared_ptr<::odata::codegen::odata_service_context> m_client_context;
};

}}
