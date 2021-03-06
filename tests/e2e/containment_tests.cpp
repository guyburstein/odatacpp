/***
* ==++==
*
* Copyright (c) Microsoft Corporation. All rights reserved. 
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
* http://www.apache.org/licenses/LICENSE-2.0
* 
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*
* ==--==
* =+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
*
* containment_tests.cpp
*
*
*
* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
****/

#include "e2e_tests.h"
#include "odata_wcf_service.h"

namespace tests { namespace e2e { namespace odata {

using namespace odata_wcf_service;

SUITE(containment_tests_raw_client)
{

TEST_FIXTURE(e2e_raw_client, query_contained_entityset)
{
	auto entity_set = client.get_data_from_server(U("Accounts(101)/MyPaymentInstruments")).get();
	VERIFY_ARE_EQUAL(entity_set.size(), 3);
	VERIFY_ARE_EQUAL(edm_type_kind_t::Entity, entity_set[0]->get_value_type()->get_type_kind());

	auto first_entity = std::dynamic_pointer_cast<odata_entity_value>(entity_set[0]);
	std::shared_ptr<odata_value> property_value;
	VERIFY_IS_TRUE(first_entity->get_property_value(U("PaymentInstrumentID"), property_value));
	auto primitive_value = std::dynamic_pointer_cast<odata_primitive_value>(property_value);
	int32_t id = primitive_value->as<int32_t>();
	VERIFY_ARE_EQUAL(101901, id);
}

TEST_FIXTURE(e2e_raw_client, query_contained_entity)
{
	auto entity_set = client.get_data_from_server(U("Accounts(101)/MyPaymentInstruments(101902)")).get();
	VERIFY_ARE_EQUAL(entity_set.size(), 1);
	VERIFY_ARE_EQUAL(edm_type_kind_t::Entity, entity_set[0]->get_value_type()->get_type_kind());

	auto first_entity = std::dynamic_pointer_cast<odata_entity_value>(entity_set[0]);
	std::shared_ptr<odata_value> property_value;
	VERIFY_IS_TRUE(first_entity->get_property_value(U("PaymentInstrumentID"), property_value));
	VERIFY_ARE_EQUAL(edm_type_kind_t::Primitive, property_value->get_value_type()->get_type_kind());
	auto primitive_value = std::dynamic_pointer_cast<odata_primitive_value>(property_value);
	int32_t id = primitive_value->as<int32_t>();
	VERIFY_ARE_EQUAL(101902, id);
}

TEST_FIXTURE(e2e_raw_client, query_contained_single_valued_entity)
{
	auto entity_set = client.get_data_from_server(U("Accounts(101)/MyGiftCard")).get();
	VERIFY_ARE_EQUAL(entity_set.size(), 1);
	VERIFY_ARE_EQUAL(edm_type_kind_t::Entity, entity_set[0]->get_value_type()->get_type_kind());

	auto first_entity = std::dynamic_pointer_cast<odata_entity_value>(entity_set[0]);
	std::shared_ptr<odata_value> property_value;
	VERIFY_IS_TRUE(first_entity->get_property_value(U("Amount"), property_value));
	VERIFY_ARE_EQUAL(edm_type_kind_t::Primitive, property_value->get_value_type()->get_type_kind());
	auto primitive_value = std::dynamic_pointer_cast<odata_primitive_value>(property_value);
	double amount = primitive_value->as<double>();
	VERIFY_ARE_EQUAL(19.9, amount);
}

TEST_FIXTURE(e2e_raw_client, create_contained_entity)
{
	auto model = client.get_model().get();

	::utility::string_t entity_type_name = U("PaymentInstrument");
	std::shared_ptr<odata_entity_value> entity = std::make_shared<odata_entity_value>(model->find_entity_type(entity_type_name));

	entity->set_value(U("PaymentInstrumentID"), 101920);
	entity->set_value(U("FriendlyName"), U("created by cpp test"));
	datetime now(datetime::utc_now());
	entity->set_value(U("CreatedDate"), now);

	//send the POST request to create the entity
	auto response_code = client.create_entity(U("Accounts(101)/MyPaymentInstruments"), entity).get();
	VERIFY_ARE_EQUAL(201, response_code);

	//query the newly created entity
	auto query_result = client.get_data_from_server(U("Accounts(101)/MyPaymentInstruments(101920)")).get();
	VERIFY_ARE_EQUAL(query_result.size(), 1);

	auto new_entity = std::dynamic_pointer_cast<odata_entity_value>(query_result[0]);
	std::shared_ptr<odata_value> property_value;
	VERIFY_IS_TRUE(entity->get_property_value(U("FriendlyName"), property_value));
	auto primitive_value = std::dynamic_pointer_cast<odata_primitive_value>(property_value);
	::utility::string_t firendly_name = primitive_value->as<::utility::string_t>();
	VERIFY_ARE_EQUAL(U("created by cpp test"), firendly_name);
}

TEST_FIXTURE(e2e_raw_client, create_contained_single_valued_entity)
{
	auto model = client.get_model().get();

	::utility::string_t entity_type_name = U("GiftCard");
	std::shared_ptr<odata_entity_value> entity = std::make_shared<odata_entity_value>(model->find_entity_type(entity_type_name));

	entity->set_value(U("GiftCardID"), 304);
	::utility::string_t card_number = U("AAASSSDD30");
	entity->set_value(U("GiftCardNO"), card_number);
	entity->set_value(U("Amount"), 132.0);
	datetime now(datetime::utc_now());
	entity->set_value(U("ExperationDate"), now);

	//send the PATCH request to create the entity
	auto response_code = client.send_data_to_server(U("Accounts(104)/MyGiftCard"), entity,  U("PATCH")).get();
	VERIFY_ARE_EQUAL(204, response_code);

	//query the newly created entity
	auto query_result = client.get_data_from_server(U("Accounts(104)/MyGiftCard")).get();
	VERIFY_ARE_EQUAL(query_result.size(), 1);

	auto new_entity = std::dynamic_pointer_cast<odata_entity_value>(query_result[0]);
	std::shared_ptr<odata_value> property_value;
	VERIFY_IS_TRUE(entity->get_property_value(U("Amount"), property_value));
	auto primitive_value = std::dynamic_pointer_cast<odata_primitive_value>(property_value);
	double amount = primitive_value->as<double>();
	VERIFY_ARE_EQUAL(132.0, amount);
}

}

SUITE(containment_tests)
{

TEST_FIXTURE(e2e_test_case, query_contained_entity)  
{	
	auto accounts = service_context->create_accounts_query()->key(U("101"))->expand(U("MyGiftCard,MyPaymentInstruments"))->execute_query().get();
	VERIFY_ARE_EQUAL(1, accounts.size());
	std::shared_ptr<Account> account101 = accounts[0];

	VERIFY_ARE_EQUAL(19.9, account101->get_mygiftcard()->get_amount());
	VERIFY_ARE_EQUAL(U("101 first PI"), account101->get_mypaymentinstruments()[0]->get_friendlyname());
	VERIFY_ARE_EQUAL(U("http://odatae2etest.azurewebsites.net/cpptest/DefaultService/Accounts(101)/MyGiftCard"), account101->get_mygiftcard()->get_edit_link());
	VERIFY_ARE_EQUAL(U("http://odatae2etest.azurewebsites.net/cpptest/DefaultService/Accounts(101)/MyPaymentInstruments(101901)"), account101->get_mypaymentinstruments()[0]->get_edit_link());

	accounts = service_context->create_accounts_query()->key(U("103"))->execute_query().get();
	VERIFY_ARE_EQUAL(1, accounts.size());
	std::shared_ptr<Account> account103 = accounts[0];

	account103->load_mygiftcard().get();
	account103->load_mypaymentinstruments().get();

	VERIFY_ARE_EQUAL(1.9, account103->get_mygiftcard()->get_amount());
	VERIFY_ARE_EQUAL(U("103 frist PI"), account103->get_mypaymentinstruments()[0]->get_friendlyname());
	VERIFY_ARE_EQUAL(U("http://odatae2etest.azurewebsites.net/cpptest/DefaultService/Accounts(103)/MyGiftCard"), account103->get_mygiftcard()->get_edit_link());
	VERIFY_ARE_EQUAL(U("http://odatae2etest.azurewebsites.net/cpptest/DefaultService/Accounts(103)/MyPaymentInstruments(103901)"), account103->get_mypaymentinstruments()[0]->get_edit_link());
}

TEST_FIXTURE(e2e_test_case, create_contained_entity)  
{	
	auto accounts = service_context->create_accounts_query()->key(U("101"))->execute_query().get();
	VERIFY_ARE_EQUAL(1, accounts.size());
	std::shared_ptr<Account> account = accounts[0];

	auto new_pi = std::make_shared<CreditCardPI>(service_context);
	new_pi->set_paymentinstrumentid(101920);
	new_pi->set_friendlyname(U("cpp test containment creation"));
	new_pi->set_createddate(::utility::datetime::utc_now());
	new_pi->set_cardnumber(U("9200000000000000"));
	new_pi->set_cvv(U("801"));
	new_pi->set_holdername(U("cpp"));
	new_pi->set_balance(32.0);
	new_pi->set_experationdate(::utility::datetime::utc_now());
	auto status_code = service_context->add_related_object(account, U("MyPaymentInstruments"), new_pi).get();

	VERIFY_ARE_EQUAL(201, status_code);
	VERIFY_ARE_EQUAL(U("http://odatae2etest.azurewebsites.net/cpptest/DefaultService/Accounts(101)/MyPaymentInstruments(101920)"), new_pi->get_edit_link());

	auto pi = service_context->create_query<odata_singleton_query_executor<PaymentInstrument>, odata_query_builder>(U("Accounts(101)/MyPaymentInstruments(101920)"))
		->execute_query().get();
	VERIFY_ARE_EQUAL(U("cpp test containment creation"), pi->get_friendlyname());
}

TEST_FIXTURE(e2e_test_case, create_contained_single_valued_entity)  
{
	auto accounts = service_context->create_accounts_query()->key(U("101"))->execute_query().get();
	VERIFY_ARE_EQUAL(1, accounts.size());
	std::shared_ptr<Account> account = accounts[0];

	auto new_giftcard = std::make_shared<GiftCard>(service_context);
	new_giftcard->set_giftcardid(304);
	new_giftcard->set_giftcardno(U("AAB999A"));
	new_giftcard->set_amount(30.0);
	new_giftcard->set_experationdate(::utility::datetime::utc_now());
	auto status_code = service_context->update_related_object(account, U("MyGiftCard"), new_giftcard).get();

	VERIFY_ARE_EQUAL(204, status_code);
	VERIFY_ARE_EQUAL(U("http://odatae2etest.azurewebsites.net/cpptest/DefaultService/Accounts(101)/MyGiftCard"), new_giftcard->get_edit_link());

	account->load_mygiftcard().get();
	auto giftcard = account->get_mygiftcard();
	VERIFY_ARE_EQUAL(304, giftcard->get_giftcardid());
	VERIFY_ARE_EQUAL(30.0, giftcard->get_amount());
}

TEST_FIXTURE(e2e_test_case, update_contained_entity)
{
	auto accounts = service_context->create_accounts_query()->key(U("101"))->execute_query().get();
	VERIFY_ARE_EQUAL(1, accounts.size());
	std::shared_ptr<Account> account = accounts[0];

	account->load_mygiftcard().get();
	auto giftcard = account->get_mygiftcard();

	giftcard->set_amount(91.1);
	auto status_code = service_context->update_object(giftcard);

	account->load_mygiftcard().get();
	auto new_giftcard = account->get_mygiftcard();
	VERIFY_ARE_EQUAL(91.1, new_giftcard->get_amount());
}


TEST_FIXTURE(e2e_test_case, delete_contained_entity) 
{
	auto accounts = service_context->create_accounts_query()->key(U("101"))->expand(U("MyPaymentInstruments"))->execute_query().get();
	VERIFY_ARE_EQUAL(1, accounts.size());
	std::shared_ptr<Account> account = accounts[0];

	VERIFY_ARE_EQUAL(3, account->get_mypaymentinstruments().size());
	auto cc = std::dynamic_pointer_cast<CreditCardPI>(account->get_mypaymentinstruments()[1]);
	VERIFY_ARE_EQUAL(U("101 frist credit PI"), cc->get_friendlyname());

	auto status_code = service_context->delete_object(cc).get();
	VERIFY_ARE_EQUAL(204, status_code);

	account->load_mypaymentinstruments().get();
	VERIFY_ARE_EQUAL(2, account->get_mypaymentinstruments().size());
}

TEST_FIXTURE(e2e_test_case, query_contained_entities_with_query_options) 
{
	auto pis = service_context->create_query<odata_entityset_query_executor<PaymentInstrument>, odata_query_builder>(U("Accounts(101)/MyPaymentInstruments"))
		->filter(U("PaymentInstrumentID gt 101901"))->execute_query().get(); 
	VERIFY_ARE_EQUAL(2, pis.size());
	VERIFY_ARE_EQUAL(101902, pis[0]->get_paymentinstrumentid());
	VERIFY_ARE_EQUAL(101903, pis[1]->get_paymentinstrumentid());

	//complicated query options
		
}

TEST_FIXTURE(e2e_test_case, level2_contained_entity) 
{
	auto accounts = service_context->create_accounts_query()->key(U("103"))->execute_query().get();
	VERIFY_ARE_EQUAL(1, accounts.size());
	VERIFY_ARE_EQUAL(103, accounts[0]->get_accountid());

	auto account = accounts[0];
	account->load_mypaymentinstruments().get();
	auto pis = account->get_mypaymentinstruments();
	VERIFY_ARE_EQUAL(4, pis.size());
	VERIFY_ARE_EQUAL(103901, pis[0]->get_paymentinstrumentid());

	auto pi = pis[0];
	pi->load_billingstatements().get();
	auto statements = pi->get_billingstatements();
	VERIFY_ARE_EQUAL(2, statements.size());
	VERIFY_ARE_EQUAL(103901002, statements[1]->get_statementid());
	VERIFY_ARE_EQUAL(U("http://odatae2etest.azurewebsites.net/cpptest/DefaultService/Accounts(103)/MyPaymentInstruments(103901)/BillingStatements(103901002)"), statements[1]->get_edit_link());

	auto single_statement = service_context->create_query<odata_singleton_query_executor<Statement>, odata_query_builder>(U("Accounts(103)/MyPaymentInstruments(103901)/BillingStatements(103901001)"))
		->execute_query().get();
	VERIFY_ARE_EQUAL(103901001, single_statement->get_statementid());
	VERIFY_ARE_EQUAL(U("http://odatae2etest.azurewebsites.net/cpptest/DefaultService/Accounts(103)/MyPaymentInstruments(103901)/BillingStatements(103901001)"), single_statement->get_edit_link());
}

TEST_FIXTURE(e2e_test_case, level2_noncontained_entity) 
{
	auto accounts = service_context->create_accounts_query()->key(U("103"))->execute_query().get();
	VERIFY_ARE_EQUAL(1, accounts.size());
	VERIFY_ARE_EQUAL(103, accounts[0]->get_accountid());

	auto account = accounts[0];
	account->load_mypaymentinstruments().get();
	auto pis = account->get_mypaymentinstruments();
	VERIFY_ARE_EQUAL(4, pis.size());
	VERIFY_ARE_EQUAL(103901, pis[0]->get_paymentinstrumentid());

	auto pi = pis[0];
	pi->load_thestoredpi().get();
	auto the_stored_pi = pi->get_thestoredpi();
	VERIFY_IS_NOT_NULL(the_stored_pi);
	VERIFY_ARE_EQUAL(802, the_stored_pi->get_storedpiid());
	VERIFY_ARE_EQUAL(U("http://odatae2etest.azurewebsites.net/cpptest/DefaultService/StoredPIs(802)"), the_stored_pi->get_edit_link());
}

TEST_FIXTURE(e2e_test_case, derived_type_contained_entity) 
{
	auto accounts = service_context->create_accounts_query()->key(U("101"))->execute_query().get();
	VERIFY_ARE_EQUAL(1, accounts.size());
	VERIFY_ARE_EQUAL(101, accounts[0]->get_accountid());

	auto account = accounts[0];
	account->load_mypaymentinstruments().get();
	auto pis = account->get_mypaymentinstruments();
	VERIFY_ARE_EQUAL(3, pis.size());
	
	VERIFY_ARE_EQUAL(101901, pis[0]->get_paymentinstrumentid());
	auto cc1 = std::dynamic_pointer_cast<CreditCardPI>(pis[1]);
	VERIFY_IS_NOT_NULL(cc1);
	VERIFY_ARE_EQUAL(U("234"), cc1->get_cvv());

	VERIFY_ARE_EQUAL(U("http://odatae2etest.azurewebsites.net/cpptest/DefaultService/Accounts(101)/MyPaymentInstruments(101902)/Microsoft.Test.OData.Services.ODataWCFService.CreditCardPI"), cc1->get_edit_link());
	auto cc2 = std::dynamic_pointer_cast<CreditCardPI>(pis[2]);
	VERIFY_IS_NOT_NULL(cc2);
	VERIFY_ARE_EQUAL(U("012"), cc2->get_cvv());
	VERIFY_ARE_EQUAL(U("http://odatae2etest.azurewebsites.net/cpptest/DefaultService/Accounts(101)/MyPaymentInstruments(101903)/Microsoft.Test.OData.Services.ODataWCFService.CreditCardPI"), cc2->get_edit_link());

	cc1->load_creditrecords().get();
	auto credit_records = cc1->get_creditrecords();
	VERIFY_ARE_EQUAL(2, credit_records.size());

	auto credit_record = credit_records[0];
	VERIFY_ARE_EQUAL(U("Shopping"), credit_record->get_reason());
	VERIFY_ARE_EQUAL(U("http://odatae2etest.azurewebsites.net/cpptest/DefaultService/Accounts(101)/MyPaymentInstruments(101902)/Microsoft.Test.OData.Services.ODataWCFService.CreditCardPI/CreditRecords(1)"), credit_record->get_edit_link());

}

}

}}}