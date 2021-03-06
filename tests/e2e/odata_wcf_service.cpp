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
 
 #include "odata_wcf_service.h"

namespace tests { namespace e2e { namespace odata { namespace odata_wcf_service {

#include "odata/codegen/odata_function_param_formatter.h"

IMPLEMENT_GET_ENUM_TYPE_NAMESPACE(AccessLevel, Microsoft.Test.OData.Services.ODataWCFService);
BGEIN_IMPLEMENT_FUNCTION_ENUM_TYPE_FROM_STRING(AccessLevel)
    ON_IMPLEMENT_FUNCTION_ENUM_TYPE_FROM_STRING(None, AccessLevel::None)
    ON_IMPLEMENT_FUNCTION_ENUM_TYPE_FROM_STRING(Read, AccessLevel::Read)
    ON_IMPLEMENT_FUNCTION_ENUM_TYPE_FROM_STRING(Write, AccessLevel::Write)
    ON_IMPLEMENT_FUNCTION_ENUM_TYPE_FROM_STRING(Execute, AccessLevel::Execute)
    ON_IMPLEMENT_FUNCTION_ENUM_TYPE_FROM_STRING(ReadWrite, AccessLevel::ReadWrite)
END_IMPLEMENT_FUNCTION_ENUM_TYPE_FROM_STRING(AccessLevel)

BGEIN_IMPLEMENT_FUNCTION_STRING_FROM_ENUM_TYPE(AccessLevel)
    ON_IMPLEMENT_FUNCTION_STRING_FROM_ENUM_TYPE(AccessLevel::None, None)
    ON_IMPLEMENT_FUNCTION_STRING_FROM_ENUM_TYPE(AccessLevel::Read, Read)
    ON_IMPLEMENT_FUNCTION_STRING_FROM_ENUM_TYPE(AccessLevel::Write, Write)
    ON_IMPLEMENT_FUNCTION_STRING_FROM_ENUM_TYPE(AccessLevel::Execute, Execute)
    ON_IMPLEMENT_FUNCTION_STRING_FROM_ENUM_TYPE(AccessLevel::ReadWrite, ReadWrite)
END_IMPLEMENT_FUNCTION_STRING_FROM_ENUM_TYPE(AccessLevel)

IMPLEMENT_GET_ENUM_TYPE_NAMESPACE(Color, Microsoft.Test.OData.Services.ODataWCFService);
BGEIN_IMPLEMENT_FUNCTION_ENUM_TYPE_FROM_STRING(Color)
    ON_IMPLEMENT_FUNCTION_ENUM_TYPE_FROM_STRING(Red, Color::Red)
    ON_IMPLEMENT_FUNCTION_ENUM_TYPE_FROM_STRING(Green, Color::Green)
    ON_IMPLEMENT_FUNCTION_ENUM_TYPE_FROM_STRING(Blue, Color::Blue)
END_IMPLEMENT_FUNCTION_ENUM_TYPE_FROM_STRING(Color)

BGEIN_IMPLEMENT_FUNCTION_STRING_FROM_ENUM_TYPE(Color)
    ON_IMPLEMENT_FUNCTION_STRING_FROM_ENUM_TYPE(Color::Red, Red)
    ON_IMPLEMENT_FUNCTION_STRING_FROM_ENUM_TYPE(Color::Green, Green)
    ON_IMPLEMENT_FUNCTION_STRING_FROM_ENUM_TYPE(Color::Blue, Blue)
END_IMPLEMENT_FUNCTION_STRING_FROM_ENUM_TYPE(Color)

IMPLEMENT_GET_ENUM_TYPE_NAMESPACE(CompanyCategory, Microsoft.Test.OData.Services.ODataWCFService);
BGEIN_IMPLEMENT_FUNCTION_ENUM_TYPE_FROM_STRING(CompanyCategory)
    ON_IMPLEMENT_FUNCTION_ENUM_TYPE_FROM_STRING(IT, CompanyCategory::IT)
    ON_IMPLEMENT_FUNCTION_ENUM_TYPE_FROM_STRING(Communication, CompanyCategory::Communication)
    ON_IMPLEMENT_FUNCTION_ENUM_TYPE_FROM_STRING(Electronics, CompanyCategory::Electronics)
    ON_IMPLEMENT_FUNCTION_ENUM_TYPE_FROM_STRING(Others, CompanyCategory::Others)
END_IMPLEMENT_FUNCTION_ENUM_TYPE_FROM_STRING(CompanyCategory)

BGEIN_IMPLEMENT_FUNCTION_STRING_FROM_ENUM_TYPE(CompanyCategory)
    ON_IMPLEMENT_FUNCTION_STRING_FROM_ENUM_TYPE(CompanyCategory::IT, IT)
    ON_IMPLEMENT_FUNCTION_STRING_FROM_ENUM_TYPE(CompanyCategory::Communication, Communication)
    ON_IMPLEMENT_FUNCTION_STRING_FROM_ENUM_TYPE(CompanyCategory::Electronics, Electronics)
    ON_IMPLEMENT_FUNCTION_STRING_FROM_ENUM_TYPE(CompanyCategory::Others, Others)
END_IMPLEMENT_FUNCTION_STRING_FROM_ENUM_TYPE(CompanyCategory)

BEGIN_COMPLEX_CONSTRUCTOR(AccountInfo, type_base)
END_COMPLEX_CONSTRUCTOR(AccountInfo, type_base)

BEGIN_COMPLEX_DESTRUCTOR(AccountInfo)
END_COMPLEX_DESTRUCTOR(AccountInfo)

IMPLEMENT_PRIMITIVE_PROPERTY_IN_COMPLEX_MAPPING(AccountInfo, lastname, LastName, ::utility::string_t);
IMPLEMENT_PRIMITIVE_PROPERTY_IN_COMPLEX_MAPPING(AccountInfo, firstname, FirstName, ::utility::string_t);

IMPLEMENT_EDM_INFO(AccountInfo, Microsoft.Test.OData.Services.ODataWCFService, AccountInfo)

BEGIN_PROPERTY_IN_COMPLEX_MAPPING(AccountInfo)
    ON_PROPERTY_IN_COMPLEX_MAPPING(AccountInfo, lastname)
    ON_PROPERTY_IN_COMPLEX_MAPPING(AccountInfo, firstname)
END_PROPERTY_IN_COMPLEX_MAPPING(AccountInfo)

BEGIN_SERIALIZE_PROPERTY_IN_COMPLEX_MAPPING(AccountInfo)
    ON_SERIALIZE_PROPERTY_IN_COMPLEX_MAPPING(AccountInfo, lastname)
    ON_SERIALIZE_PROPERTY_IN_COMPLEX_MAPPING(AccountInfo, firstname)
END_SERIALIZE_PROPERTY_IN_COMPLEX_MAPPING(AccountInfo)

BEGIN_COMPLEX_CONSTRUCTOR(Address, type_base)
END_COMPLEX_CONSTRUCTOR(Address, type_base)

BEGIN_COMPLEX_DESTRUCTOR(Address)
END_COMPLEX_DESTRUCTOR(Address)

IMPLEMENT_PRIMITIVE_PROPERTY_IN_COMPLEX_MAPPING(Address, street, Street, ::utility::string_t);
IMPLEMENT_PRIMITIVE_PROPERTY_IN_COMPLEX_MAPPING(Address, city, City, ::utility::string_t);
IMPLEMENT_PRIMITIVE_PROPERTY_IN_COMPLEX_MAPPING(Address, postalcode, PostalCode, ::utility::string_t);

IMPLEMENT_EDM_INFO(Address, Microsoft.Test.OData.Services.ODataWCFService, Address)

BEGIN_PROPERTY_IN_COMPLEX_MAPPING(Address)
    ON_PROPERTY_IN_COMPLEX_MAPPING(Address, street)
    ON_PROPERTY_IN_COMPLEX_MAPPING(Address, city)
    ON_PROPERTY_IN_COMPLEX_MAPPING(Address, postalcode)
END_PROPERTY_IN_COMPLEX_MAPPING(Address)

BEGIN_SERIALIZE_PROPERTY_IN_COMPLEX_MAPPING(Address)
    ON_SERIALIZE_PROPERTY_IN_COMPLEX_MAPPING(Address, street)
    ON_SERIALIZE_PROPERTY_IN_COMPLEX_MAPPING(Address, city)
    ON_SERIALIZE_PROPERTY_IN_COMPLEX_MAPPING(Address, postalcode)
END_SERIALIZE_PROPERTY_IN_COMPLEX_MAPPING(Address)

BEGIN_COMPLEX_CONSTRUCTOR(HomeAddress, Address)
    ON_PROPERTY_IN_COMPLEX_CONSTRUCTOR(familyname, nullptr)
END_COMPLEX_CONSTRUCTOR(HomeAddress, Address)

BEGIN_COMPLEX_DESTRUCTOR(HomeAddress)
    ON_PROPERTY_IN_COMPLEX_DESTRUCTOR(familyname)
END_COMPLEX_DESTRUCTOR(HomeAddress)

IMPLEMENT_NULLABLE_PRIMITIVE_PROPERTY_IN_COMPLEX_MAPPING(HomeAddress, familyname, FamilyName, ::utility::string_t);

IMPLEMENT_EDM_INFO(HomeAddress, Microsoft.Test.OData.Services.ODataWCFService, HomeAddress)

BEGIN_PROPERTY_IN_COMPLEX_MAPPING_WITH_BASE_CLASS(HomeAddress, Address)
    ON_PROPERTY_IN_COMPLEX_MAPPING(HomeAddress, familyname)
END_PROPERTY_IN_COMPLEX_MAPPING_WITH_BASE_CLASS(HomeAddress, Address)
BEGIN_SERIALIZE_PROPERTY_IN_COMPLEX_MAPPING(HomeAddress)
    ON_SERIALIZE_PROPERTY_IN_COMPLEX_MAPPING(HomeAddress, familyname)
END_SERIALIZE_PROPERTY_IN_COMPLEX_MAPPING(HomeAddress)

BEGIN_COMPLEX_CONSTRUCTOR(CompanyAddress, Address)
END_COMPLEX_CONSTRUCTOR(CompanyAddress, Address)

BEGIN_COMPLEX_DESTRUCTOR(CompanyAddress)
END_COMPLEX_DESTRUCTOR(CompanyAddress)

IMPLEMENT_PRIMITIVE_PROPERTY_IN_COMPLEX_MAPPING(CompanyAddress, companyname, CompanyName, ::utility::string_t);

IMPLEMENT_EDM_INFO(CompanyAddress, Microsoft.Test.OData.Services.ODataWCFService, CompanyAddress)

BEGIN_PROPERTY_IN_COMPLEX_MAPPING_WITH_BASE_CLASS(CompanyAddress, Address)
    ON_PROPERTY_IN_COMPLEX_MAPPING(CompanyAddress, companyname)
END_PROPERTY_IN_COMPLEX_MAPPING_WITH_BASE_CLASS(CompanyAddress, Address)
BEGIN_SERIALIZE_PROPERTY_IN_COMPLEX_MAPPING(CompanyAddress)
    ON_SERIALIZE_PROPERTY_IN_COMPLEX_MAPPING(CompanyAddress, companyname)
END_SERIALIZE_PROPERTY_IN_COMPLEX_MAPPING(CompanyAddress)

BEGIN_ENTITY_CONSTRUCTOR(Person, type_base)
    ON_PROPERTY_IN_ENTITY_CONSTRUCTOR(personid, 0)
    ON_PROPERTY_IN_ENTITY_CONSTRUCTOR(middlename, nullptr)
    ON_PROPERTY_IN_ENTITY_CONSTRUCTOR(homeaddress, nullptr)
END_ENTITY_CONSTRUCTOR(Person, type_base)

BEGIN_ENTITY_DESTRUCTOR(Person)
    ON_PROPERTY_IN_ENTITY_DESTRUCTOR(middlename)
    ON_PROPERTY_IN_ENTITY_DESTRUCTOR(homeaddress)
END_ENTITY_DESTRUCTOR(Person)

IMPLEMENT_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(Person, personid, PersonID, int32_t);
IMPLEMENT_COLLECTION_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(Person, numbers, Numbers, ::utility::string_t);
IMPLEMENT_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(Person, lastname, LastName, ::utility::string_t);
IMPLEMENT_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(Person, firstname, FirstName, ::utility::string_t);
IMPLEMENT_NULLABLE_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(Person, middlename, MiddleName, ::utility::string_t);
IMPLEMENT_NULLABLE_COMPLEX_PROPERTY_IN_ENTITY_MAPPING(Person, homeaddress, HomeAddress, Address);
IMPLEMENT_COLLECTION_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(Person, emails, Emails, ::utility::string_t);
IMPLEMENT_NAVIGATION_PROPERTY_IN_ENTITY_MAPPING(Person, parent, Parent, Person);
IMPLEMENT_ACTION_P2(Person, ResetAddress, odata_entityset_query_executor<Person>, addresses, std::vector<Address>, addresses, index, int32_t, index);
IMPLEMENT_FUNCTION_P0(Person, GetHomeAddress, odata_complex_query_executor<HomeAddress>);

IMPLEMENT_EDM_INFO(Person, Microsoft.Test.OData.Services.ODataWCFService, Person)

BEGIN_PROPERTY_IN_ENTITY_MAPPING(Person)
    ON_PROPERTY_IN_ENTITY_MAPPING(Person, personid)
    ON_PROPERTY_IN_ENTITY_MAPPING(Person, numbers)
    ON_PROPERTY_IN_ENTITY_MAPPING(Person, lastname)
    ON_PROPERTY_IN_ENTITY_MAPPING(Person, firstname)
    ON_PROPERTY_IN_ENTITY_MAPPING(Person, middlename)
    ON_PROPERTY_IN_ENTITY_MAPPING(Person, homeaddress)
    ON_PROPERTY_IN_ENTITY_MAPPING(Person, emails)
    ON_PROPERTY_IN_ENTITY_MAPPING(Person, parent)
END_PROPERTY_IN_ENTITY_MAPPING(Person)

BEGIN_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Person)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Person, personid)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Person, numbers)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Person, lastname)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Person, firstname)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Person, middlename)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Person, homeaddress)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Person, emails)
END_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Person)

BEGIN_ENTITY_CONSTRUCTOR(Statement, type_base)
    ON_PROPERTY_IN_ENTITY_CONSTRUCTOR(statementid, 0)
    ON_PROPERTY_IN_ENTITY_CONSTRUCTOR(amount, 0.0)
END_ENTITY_CONSTRUCTOR(Statement, type_base)

BEGIN_ENTITY_DESTRUCTOR(Statement)
END_ENTITY_DESTRUCTOR(Statement)

IMPLEMENT_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(Statement, statementid, StatementID, int32_t);
IMPLEMENT_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(Statement, amount, Amount, double);
IMPLEMENT_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(Statement, transactiontype, TransactionType, ::utility::string_t);
IMPLEMENT_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(Statement, transactiondescription, TransactionDescription, ::utility::string_t);

IMPLEMENT_EDM_INFO(Statement, Microsoft.Test.OData.Services.ODataWCFService, Statement)

BEGIN_PROPERTY_IN_ENTITY_MAPPING(Statement)
    ON_PROPERTY_IN_ENTITY_MAPPING(Statement, statementid)
    ON_PROPERTY_IN_ENTITY_MAPPING(Statement, amount)
    ON_PROPERTY_IN_ENTITY_MAPPING(Statement, transactiontype)
    ON_PROPERTY_IN_ENTITY_MAPPING(Statement, transactiondescription)
END_PROPERTY_IN_ENTITY_MAPPING(Statement)

BEGIN_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Statement)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Statement, statementid)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Statement, amount)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Statement, transactiontype)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Statement, transactiondescription)
END_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Statement)

BEGIN_ENTITY_CONSTRUCTOR(Department, type_base)
    ON_PROPERTY_IN_ENTITY_CONSTRUCTOR(departmentid, 0)
    ON_PROPERTY_IN_ENTITY_CONSTRUCTOR(departmentno, nullptr)
END_ENTITY_CONSTRUCTOR(Department, type_base)

BEGIN_ENTITY_DESTRUCTOR(Department)
    ON_PROPERTY_IN_ENTITY_DESTRUCTOR(departmentno)
END_ENTITY_DESTRUCTOR(Department)

IMPLEMENT_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(Department, departmentid, DepartmentID, int32_t);
IMPLEMENT_NAVIGATION_PROPERTY_IN_ENTITY_MAPPING(Department, company, Company, Company);
IMPLEMENT_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(Department, name, Name, ::utility::string_t);
IMPLEMENT_NULLABLE_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(Department, departmentno, DepartmentNO, ::utility::string_t);

IMPLEMENT_EDM_INFO(Department, Microsoft.Test.OData.Services.ODataWCFService, Department)

BEGIN_PROPERTY_IN_ENTITY_MAPPING(Department)
    ON_PROPERTY_IN_ENTITY_MAPPING(Department, departmentid)
    ON_PROPERTY_IN_ENTITY_MAPPING(Department, company)
    ON_PROPERTY_IN_ENTITY_MAPPING(Department, name)
    ON_PROPERTY_IN_ENTITY_MAPPING(Department, departmentno)
END_PROPERTY_IN_ENTITY_MAPPING(Department)

BEGIN_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Department)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Department, departmentid)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Department, name)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Department, departmentno)
END_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Department)

BEGIN_ENTITY_CONSTRUCTOR(Customer, Person)
END_ENTITY_CONSTRUCTOR(Customer, Person)

BEGIN_ENTITY_DESTRUCTOR(Customer)
END_ENTITY_DESTRUCTOR(Customer)

IMPLEMENT_NAVIGATION_PROPERTY_IN_ENTITY_MAPPING(Customer, company, Company, Company);
IMPLEMENT_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(Customer, city, City, ::utility::string_t);
IMPLEMENT_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(Customer, birthday, Birthday, ::utility::datetime);
IMPLEMENT_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(Customer, timebetweenlasttwoorders, TimeBetweenLastTwoOrders, ::utility::seconds);
IMPLEMENT_COLLECTION_NAVIGATION_PROPERTY_IN_ENTITY_MAPPING(Customer, orders, Orders, Order);

IMPLEMENT_EDM_INFO(Customer, Microsoft.Test.OData.Services.ODataWCFService, Customer)

BEGIN_PROPERTY_IN_ENTITY_MAPPING_WITH_BASE_CLASS(Customer, Person)
    ON_PROPERTY_IN_ENTITY_MAPPING(Customer, company)
    ON_PROPERTY_IN_ENTITY_MAPPING(Customer, city)
    ON_PROPERTY_IN_ENTITY_MAPPING(Customer, birthday)
    ON_PROPERTY_IN_ENTITY_MAPPING(Customer, timebetweenlasttwoorders)
    ON_PROPERTY_IN_ENTITY_MAPPING(Customer, orders)
END_PROPERTY_IN_ENTITY_MAPPING_WITH_BASE_CLASS(Customer, Person)
BEGIN_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Customer)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Customer, city)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Customer, birthday)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Customer, timebetweenlasttwoorders)
END_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Customer)

BEGIN_ENTITY_CONSTRUCTOR(ProductDetail, type_base)
    ON_PROPERTY_IN_ENTITY_CONSTRUCTOR(productid, 0)
    ON_PROPERTY_IN_ENTITY_CONSTRUCTOR(productdetailid, 0)
    ON_PROPERTY_IN_ENTITY_CONSTRUCTOR(relatedproduct, nullptr)
END_ENTITY_CONSTRUCTOR(ProductDetail, type_base)

BEGIN_ENTITY_DESTRUCTOR(ProductDetail)
END_ENTITY_DESTRUCTOR(ProductDetail)

IMPLEMENT_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(ProductDetail, description, Description, ::utility::string_t);
IMPLEMENT_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(ProductDetail, productid, ProductID, int32_t);
IMPLEMENT_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(ProductDetail, productdetailid, ProductDetailID, int32_t);
IMPLEMENT_NAVIGATION_PROPERTY_IN_ENTITY_MAPPING(ProductDetail, relatedproduct, RelatedProduct, Product);
IMPLEMENT_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(ProductDetail, productname, ProductName, ::utility::string_t);
IMPLEMENT_COLLECTION_NAVIGATION_PROPERTY_IN_ENTITY_MAPPING(ProductDetail, reviews, Reviews, ProductReview);
IMPLEMENT_FUNCTION_P0(ProductDetail, GetRelatedProduct, odata_entityset_query_executor<Product>);

IMPLEMENT_EDM_INFO(ProductDetail, Microsoft.Test.OData.Services.ODataWCFService, ProductDetail)

BEGIN_PROPERTY_IN_ENTITY_MAPPING(ProductDetail)
    ON_PROPERTY_IN_ENTITY_MAPPING(ProductDetail, description)
    ON_PROPERTY_IN_ENTITY_MAPPING(ProductDetail, productid)
    ON_PROPERTY_IN_ENTITY_MAPPING(ProductDetail, productdetailid)
    ON_PROPERTY_IN_ENTITY_MAPPING(ProductDetail, relatedproduct)
    ON_PROPERTY_IN_ENTITY_MAPPING(ProductDetail, productname)
    ON_PROPERTY_IN_ENTITY_MAPPING(ProductDetail, reviews)
END_PROPERTY_IN_ENTITY_MAPPING(ProductDetail)

BEGIN_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(ProductDetail)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(ProductDetail, description)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(ProductDetail, productid)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(ProductDetail, productdetailid)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(ProductDetail, productname)
END_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(ProductDetail)

BEGIN_ENTITY_CONSTRUCTOR(Employee, Person)
END_ENTITY_CONSTRUCTOR(Employee, Person)

BEGIN_ENTITY_DESTRUCTOR(Employee)
END_ENTITY_DESTRUCTOR(Employee)

IMPLEMENT_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(Employee, datehired, DateHired, ::utility::datetime);
IMPLEMENT_NAVIGATION_PROPERTY_IN_ENTITY_MAPPING(Employee, company, Company, Company);

IMPLEMENT_EDM_INFO(Employee, Microsoft.Test.OData.Services.ODataWCFService, Employee)

BEGIN_PROPERTY_IN_ENTITY_MAPPING_WITH_BASE_CLASS(Employee, Person)
    ON_PROPERTY_IN_ENTITY_MAPPING(Employee, datehired)
    ON_PROPERTY_IN_ENTITY_MAPPING(Employee, company)
END_PROPERTY_IN_ENTITY_MAPPING_WITH_BASE_CLASS(Employee, Person)
BEGIN_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Employee)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Employee, datehired)
END_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Employee)

BEGIN_ENTITY_CONSTRUCTOR(Product, type_base)
    ON_PROPERTY_IN_ENTITY_CONSTRUCTOR(productid, 0)
    ON_PROPERTY_IN_ENTITY_CONSTRUCTOR(skincolor, nullptr)
    ON_PROPERTY_IN_ENTITY_CONSTRUCTOR(unitprice, 0.0)
    ON_PROPERTY_IN_ENTITY_CONSTRUCTOR(discontinued, false)
    ON_PROPERTY_IN_ENTITY_CONSTRUCTOR(quantityinstock, 0)
    ON_PROPERTY_IN_ENTITY_CONSTRUCTOR(useraccess, nullptr)
END_ENTITY_CONSTRUCTOR(Product, type_base)

BEGIN_ENTITY_DESTRUCTOR(Product)
    ON_PROPERTY_IN_ENTITY_DESTRUCTOR(skincolor)
    ON_PROPERTY_IN_ENTITY_DESTRUCTOR(useraccess)
END_ENTITY_DESTRUCTOR(Product)

IMPLEMENT_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(Product, productid, ProductID, int32_t);
IMPLEMENT_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(Product, name, Name, ::utility::string_t);
IMPLEMENT_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(Product, quantityperunit, QuantityPerUnit, ::utility::string_t);
IMPLEMENT_NULLABLE_ENUM_PROPERTY_IN_ENTITY_MAPPING(Product, skincolor, SkinColor, Color);
IMPLEMENT_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(Product, unitprice, UnitPrice, float);
IMPLEMENT_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(Product, discontinued, Discontinued, bool);
IMPLEMENT_COLLECTION_ENUM_PROPERTY_IN_ENTITY_MAPPING(Product, covercolors, CoverColors, Color);
IMPLEMENT_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(Product, quantityinstock, QuantityInStock, int32_t);
IMPLEMENT_NULLABLE_ENUM_PROPERTY_IN_ENTITY_MAPPING(Product, useraccess, UserAccess, AccessLevel);
IMPLEMENT_COLLECTION_NAVIGATION_PROPERTY_IN_ENTITY_MAPPING(Product, details, Details, ProductDetail);
IMPLEMENT_ACTION_P1(Product, AddAccessRight, Product::enum_AddAccessRight_excecutor, accessRight, AccessLevel, accessRight);
IMPLEMENT_FUNCTION_P1(Product, GetProductDetails, odata_entityset_query_executor<ProductDetail>, count, int32_t, count);

IMPLEMENT_EDM_INFO(Product, Microsoft.Test.OData.Services.ODataWCFService, Product)

BEGIN_PROPERTY_IN_ENTITY_MAPPING(Product)
    ON_PROPERTY_IN_ENTITY_MAPPING(Product, productid)
    ON_PROPERTY_IN_ENTITY_MAPPING(Product, name)
    ON_PROPERTY_IN_ENTITY_MAPPING(Product, quantityperunit)
    ON_PROPERTY_IN_ENTITY_MAPPING(Product, skincolor)
    ON_PROPERTY_IN_ENTITY_MAPPING(Product, unitprice)
    ON_PROPERTY_IN_ENTITY_MAPPING(Product, discontinued)
    ON_PROPERTY_IN_ENTITY_MAPPING(Product, covercolors)
    ON_PROPERTY_IN_ENTITY_MAPPING(Product, quantityinstock)
    ON_PROPERTY_IN_ENTITY_MAPPING(Product, useraccess)
    ON_PROPERTY_IN_ENTITY_MAPPING(Product, details)
END_PROPERTY_IN_ENTITY_MAPPING(Product)

BEGIN_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Product)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Product, productid)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Product, name)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Product, quantityperunit)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Product, skincolor)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Product, unitprice)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Product, discontinued)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Product, covercolors)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Product, quantityinstock)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Product, useraccess)
END_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Product)

BEGIN_ENTITY_CONSTRUCTOR(ProductReview, type_base)
    ON_PROPERTY_IN_ENTITY_CONSTRUCTOR(revisionid, 0)
    ON_PROPERTY_IN_ENTITY_CONSTRUCTOR(productid, 0)
    ON_PROPERTY_IN_ENTITY_CONSTRUCTOR(productdetailid, 0)
END_ENTITY_CONSTRUCTOR(ProductReview, type_base)

BEGIN_ENTITY_DESTRUCTOR(ProductReview)
END_ENTITY_DESTRUCTOR(ProductReview)

IMPLEMENT_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(ProductReview, revisionid, RevisionID, int32_t);
IMPLEMENT_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(ProductReview, productid, ProductID, int32_t);
IMPLEMENT_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(ProductReview, productdetailid, ProductDetailID, int32_t);
IMPLEMENT_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(ProductReview, reviewtitle, ReviewTitle, ::utility::string_t);
IMPLEMENT_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(ProductReview, comment, Comment, ::utility::string_t);
IMPLEMENT_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(ProductReview, author, Author, ::utility::string_t);

IMPLEMENT_EDM_INFO(ProductReview, Microsoft.Test.OData.Services.ODataWCFService, ProductReview)

BEGIN_PROPERTY_IN_ENTITY_MAPPING(ProductReview)
    ON_PROPERTY_IN_ENTITY_MAPPING(ProductReview, revisionid)
    ON_PROPERTY_IN_ENTITY_MAPPING(ProductReview, productid)
    ON_PROPERTY_IN_ENTITY_MAPPING(ProductReview, productdetailid)
    ON_PROPERTY_IN_ENTITY_MAPPING(ProductReview, reviewtitle)
    ON_PROPERTY_IN_ENTITY_MAPPING(ProductReview, comment)
    ON_PROPERTY_IN_ENTITY_MAPPING(ProductReview, author)
END_PROPERTY_IN_ENTITY_MAPPING(ProductReview)

BEGIN_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(ProductReview)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(ProductReview, revisionid)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(ProductReview, productid)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(ProductReview, productdetailid)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(ProductReview, reviewtitle)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(ProductReview, comment)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(ProductReview, author)
END_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(ProductReview)

BEGIN_ENTITY_CONSTRUCTOR(Order, type_base)
    ON_PROPERTY_IN_ENTITY_CONSTRUCTOR(orderid, 0)
    ON_PROPERTY_IN_ENTITY_CONSTRUCTOR(shelflife, nullptr)
END_ENTITY_CONSTRUCTOR(Order, type_base)

BEGIN_ENTITY_DESTRUCTOR(Order)
    ON_PROPERTY_IN_ENTITY_DESTRUCTOR(shelflife)
END_ENTITY_DESTRUCTOR(Order)

IMPLEMENT_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(Order, orderid, OrderID, int32_t);
IMPLEMENT_NULLABLE_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(Order, shelflife, ShelfLife, ::utility::seconds);
IMPLEMENT_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(Order, orderdate, OrderDate, ::utility::datetime);
IMPLEMENT_NAVIGATION_PROPERTY_IN_ENTITY_MAPPING(Order, loggedinemployee, LoggedInEmployee, Employee);
IMPLEMENT_COLLECTION_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(Order, ordershelflifes, OrderShelfLifes, ::utility::seconds);
IMPLEMENT_NAVIGATION_PROPERTY_IN_ENTITY_MAPPING(Order, customerfororder, CustomerForOrder, Customer);
IMPLEMENT_COLLECTION_NAVIGATION_PROPERTY_IN_ENTITY_MAPPING(Order, orderdetails, OrderDetails, OrderDetail);

IMPLEMENT_EDM_INFO(Order, Microsoft.Test.OData.Services.ODataWCFService, Order)

BEGIN_PROPERTY_IN_ENTITY_MAPPING(Order)
    ON_PROPERTY_IN_ENTITY_MAPPING(Order, orderid)
    ON_PROPERTY_IN_ENTITY_MAPPING(Order, shelflife)
    ON_PROPERTY_IN_ENTITY_MAPPING(Order, orderdate)
    ON_PROPERTY_IN_ENTITY_MAPPING(Order, loggedinemployee)
    ON_PROPERTY_IN_ENTITY_MAPPING(Order, ordershelflifes)
    ON_PROPERTY_IN_ENTITY_MAPPING(Order, customerfororder)
    ON_PROPERTY_IN_ENTITY_MAPPING(Order, orderdetails)
END_PROPERTY_IN_ENTITY_MAPPING(Order)

BEGIN_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Order)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Order, orderid)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Order, shelflife)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Order, orderdate)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Order, ordershelflifes)
END_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Order)

BEGIN_ENTITY_CONSTRUCTOR(OrderDetail, type_base)
    ON_PROPERTY_IN_ENTITY_CONSTRUCTOR(unitprice, 0.0)
    ON_PROPERTY_IN_ENTITY_CONSTRUCTOR(quantity, 0)
    ON_PROPERTY_IN_ENTITY_CONSTRUCTOR(orderid, 0)
    ON_PROPERTY_IN_ENTITY_CONSTRUCTOR(productid, 0)
END_ENTITY_CONSTRUCTOR(OrderDetail, type_base)

BEGIN_ENTITY_DESTRUCTOR(OrderDetail)
END_ENTITY_DESTRUCTOR(OrderDetail)

IMPLEMENT_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(OrderDetail, unitprice, UnitPrice, float);
IMPLEMENT_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(OrderDetail, quantity, Quantity, int32_t);
IMPLEMENT_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(OrderDetail, orderid, OrderID, int32_t);
IMPLEMENT_NAVIGATION_PROPERTY_IN_ENTITY_MAPPING(OrderDetail, associatedorder, AssociatedOrder, Order);
IMPLEMENT_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(OrderDetail, productid, ProductID, int32_t);
IMPLEMENT_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(OrderDetail, orderplaced, OrderPlaced, ::utility::datetime);
IMPLEMENT_COLLECTION_NAVIGATION_PROPERTY_IN_ENTITY_MAPPING(OrderDetail, productordered, ProductOrdered, Product);

IMPLEMENT_EDM_INFO(OrderDetail, Microsoft.Test.OData.Services.ODataWCFService, OrderDetail)

BEGIN_PROPERTY_IN_ENTITY_MAPPING(OrderDetail)
    ON_PROPERTY_IN_ENTITY_MAPPING(OrderDetail, unitprice)
    ON_PROPERTY_IN_ENTITY_MAPPING(OrderDetail, quantity)
    ON_PROPERTY_IN_ENTITY_MAPPING(OrderDetail, orderid)
    ON_PROPERTY_IN_ENTITY_MAPPING(OrderDetail, associatedorder)
    ON_PROPERTY_IN_ENTITY_MAPPING(OrderDetail, productid)
    ON_PROPERTY_IN_ENTITY_MAPPING(OrderDetail, orderplaced)
    ON_PROPERTY_IN_ENTITY_MAPPING(OrderDetail, productordered)
END_PROPERTY_IN_ENTITY_MAPPING(OrderDetail)

BEGIN_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(OrderDetail)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(OrderDetail, unitprice)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(OrderDetail, quantity)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(OrderDetail, orderid)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(OrderDetail, productid)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(OrderDetail, orderplaced)
END_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(OrderDetail)

BEGIN_ENTITY_CONSTRUCTOR(Company, type_base)
    ON_PROPERTY_IN_ENTITY_CONSTRUCTOR(companyid, 0)
    ON_PROPERTY_IN_ENTITY_CONSTRUCTOR(revenue, 0)
    ON_PROPERTY_IN_ENTITY_CONSTRUCTOR(companycategory, nullptr)
    ON_PROPERTY_IN_ENTITY_CONSTRUCTOR(name, nullptr)
    ON_PROPERTY_IN_ENTITY_CONSTRUCTOR(address, nullptr)
END_ENTITY_CONSTRUCTOR(Company, type_base)

BEGIN_ENTITY_DESTRUCTOR(Company)
    ON_PROPERTY_IN_ENTITY_DESTRUCTOR(companycategory)
    ON_PROPERTY_IN_ENTITY_DESTRUCTOR(name)
    ON_PROPERTY_IN_ENTITY_DESTRUCTOR(address)
END_ENTITY_DESTRUCTOR(Company)

IMPLEMENT_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(Company, companyid, CompanyID, int32_t);
IMPLEMENT_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(Company, revenue, Revenue, int64_t);
IMPLEMENT_NULLABLE_ENUM_PROPERTY_IN_ENTITY_MAPPING(Company, companycategory, CompanyCategory, CompanyCategory);
IMPLEMENT_NULLABLE_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(Company, name, Name, ::utility::string_t);
IMPLEMENT_COLLECTION_NAVIGATION_PROPERTY_IN_ENTITY_MAPPING(Company, departments, Departments, Department);
IMPLEMENT_NAVIGATION_PROPERTY_IN_ENTITY_MAPPING(Company, coredepartment, CoreDepartment, Department);
IMPLEMENT_NULLABLE_COMPLEX_PROPERTY_IN_ENTITY_MAPPING(Company, address, Address, Address);
IMPLEMENT_COLLECTION_NAVIGATION_PROPERTY_IN_ENTITY_MAPPING(Company, employees, Employees, Employee);
IMPLEMENT_NAVIGATION_PROPERTY_IN_ENTITY_MAPPING(Company, vipcustomer, VipCustomer, Customer);
IMPLEMENT_ACTION_P1(Company, IncreaseRevenue, odata_primitive_query_executor<int64_t>, IncreaseValue, int64_t, IncreaseValue);
IMPLEMENT_FUNCTION_P0(Company, GetEmployeesCount, odata_primitive_query_executor<int32_t>);

IMPLEMENT_EDM_INFO(Company, Microsoft.Test.OData.Services.ODataWCFService, Company)

BEGIN_PROPERTY_IN_ENTITY_MAPPING(Company)
    ON_PROPERTY_IN_ENTITY_MAPPING(Company, companyid)
    ON_PROPERTY_IN_ENTITY_MAPPING(Company, revenue)
    ON_PROPERTY_IN_ENTITY_MAPPING(Company, companycategory)
    ON_PROPERTY_IN_ENTITY_MAPPING(Company, name)
    ON_PROPERTY_IN_ENTITY_MAPPING(Company, departments)
    ON_PROPERTY_IN_ENTITY_MAPPING(Company, coredepartment)
    ON_PROPERTY_IN_ENTITY_MAPPING(Company, address)
    ON_PROPERTY_IN_ENTITY_MAPPING(Company, employees)
    ON_PROPERTY_IN_ENTITY_MAPPING(Company, vipcustomer)
END_PROPERTY_IN_ENTITY_MAPPING(Company)

BEGIN_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Company)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Company, companyid)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Company, revenue)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Company, companycategory)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Company, name)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Company, address)
END_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Company)

BEGIN_ENTITY_CONSTRUCTOR(PublicCompany, Company)
    ON_PROPERTY_IN_ENTITY_CONSTRUCTOR(stockexchange, nullptr)
END_ENTITY_CONSTRUCTOR(PublicCompany, Company)

BEGIN_ENTITY_DESTRUCTOR(PublicCompany)
    ON_PROPERTY_IN_ENTITY_DESTRUCTOR(stockexchange)
END_ENTITY_DESTRUCTOR(PublicCompany)

IMPLEMENT_COLLECTION_NAVIGATION_PROPERTY_IN_ENTITY_MAPPING(PublicCompany, assets, Assets, Asset);
IMPLEMENT_NULLABLE_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(PublicCompany, stockexchange, StockExchange, ::utility::string_t);
IMPLEMENT_NAVIGATION_PROPERTY_IN_ENTITY_MAPPING(PublicCompany, club, Club, Club);
IMPLEMENT_NAVIGATION_PROPERTY_IN_ENTITY_MAPPING(PublicCompany, labourunion, LabourUnion, LabourUnion);

IMPLEMENT_EDM_INFO(PublicCompany, Microsoft.Test.OData.Services.ODataWCFService, PublicCompany)

BEGIN_PROPERTY_IN_ENTITY_MAPPING_WITH_BASE_CLASS(PublicCompany, Company)
    ON_PROPERTY_IN_ENTITY_MAPPING(PublicCompany, assets)
    ON_PROPERTY_IN_ENTITY_MAPPING(PublicCompany, stockexchange)
    ON_PROPERTY_IN_ENTITY_MAPPING(PublicCompany, club)
    ON_PROPERTY_IN_ENTITY_MAPPING(PublicCompany, labourunion)
END_PROPERTY_IN_ENTITY_MAPPING_WITH_BASE_CLASS(PublicCompany, Company)
BEGIN_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(PublicCompany)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(PublicCompany, stockexchange)
END_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(PublicCompany)

BEGIN_ENTITY_CONSTRUCTOR(Asset, type_base)
    ON_PROPERTY_IN_ENTITY_CONSTRUCTOR(assetid, 0)
    ON_PROPERTY_IN_ENTITY_CONSTRUCTOR(name, nullptr)
    ON_PROPERTY_IN_ENTITY_CONSTRUCTOR(number, 0)
END_ENTITY_CONSTRUCTOR(Asset, type_base)

BEGIN_ENTITY_DESTRUCTOR(Asset)
    ON_PROPERTY_IN_ENTITY_DESTRUCTOR(name)
END_ENTITY_DESTRUCTOR(Asset)

IMPLEMENT_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(Asset, assetid, AssetID, int32_t);
IMPLEMENT_NULLABLE_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(Asset, name, Name, ::utility::string_t);
IMPLEMENT_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(Asset, number, Number, int32_t);

IMPLEMENT_EDM_INFO(Asset, Microsoft.Test.OData.Services.ODataWCFService, Asset)

BEGIN_PROPERTY_IN_ENTITY_MAPPING(Asset)
    ON_PROPERTY_IN_ENTITY_MAPPING(Asset, assetid)
    ON_PROPERTY_IN_ENTITY_MAPPING(Asset, name)
    ON_PROPERTY_IN_ENTITY_MAPPING(Asset, number)
END_PROPERTY_IN_ENTITY_MAPPING(Asset)

BEGIN_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Asset)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Asset, assetid)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Asset, name)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Asset, number)
END_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Asset)

BEGIN_ENTITY_CONSTRUCTOR(GiftCard, type_base)
    ON_PROPERTY_IN_ENTITY_CONSTRUCTOR(giftcardid, 0)
    ON_PROPERTY_IN_ENTITY_CONSTRUCTOR(amount, 0.0)
    ON_PROPERTY_IN_ENTITY_CONSTRUCTOR(ownername, nullptr)
END_ENTITY_CONSTRUCTOR(GiftCard, type_base)

BEGIN_ENTITY_DESTRUCTOR(GiftCard)
    ON_PROPERTY_IN_ENTITY_DESTRUCTOR(ownername)
END_ENTITY_DESTRUCTOR(GiftCard)

IMPLEMENT_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(GiftCard, giftcardid, GiftCardID, int32_t);
IMPLEMENT_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(GiftCard, giftcardno, GiftCardNO, ::utility::string_t);
IMPLEMENT_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(GiftCard, amount, Amount, double);
IMPLEMENT_FUNCTION_P1(GiftCard, GetActualAmount, odata_primitive_query_executor<double>, bonusRate, double, bonusRate);
IMPLEMENT_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(GiftCard, experationdate, ExperationDate, ::utility::datetime);
IMPLEMENT_NULLABLE_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(GiftCard, ownername, OwnerName, ::utility::string_t);

IMPLEMENT_EDM_INFO(GiftCard, Microsoft.Test.OData.Services.ODataWCFService, GiftCard)

BEGIN_PROPERTY_IN_ENTITY_MAPPING(GiftCard)
    ON_PROPERTY_IN_ENTITY_MAPPING(GiftCard, giftcardid)
    ON_PROPERTY_IN_ENTITY_MAPPING(GiftCard, giftcardno)
    ON_PROPERTY_IN_ENTITY_MAPPING(GiftCard, amount)
    ON_PROPERTY_IN_ENTITY_MAPPING(GiftCard, experationdate)
    ON_PROPERTY_IN_ENTITY_MAPPING(GiftCard, ownername)
END_PROPERTY_IN_ENTITY_MAPPING(GiftCard)

BEGIN_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(GiftCard)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(GiftCard, giftcardid)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(GiftCard, giftcardno)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(GiftCard, amount)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(GiftCard, experationdate)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(GiftCard, ownername)
END_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(GiftCard)

BEGIN_ENTITY_CONSTRUCTOR(Club, type_base)
    ON_PROPERTY_IN_ENTITY_CONSTRUCTOR(clubid, 0)
    ON_PROPERTY_IN_ENTITY_CONSTRUCTOR(name, nullptr)
END_ENTITY_CONSTRUCTOR(Club, type_base)

BEGIN_ENTITY_DESTRUCTOR(Club)
    ON_PROPERTY_IN_ENTITY_DESTRUCTOR(name)
END_ENTITY_DESTRUCTOR(Club)

IMPLEMENT_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(Club, clubid, ClubID, int32_t);
IMPLEMENT_NULLABLE_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(Club, name, Name, ::utility::string_t);

IMPLEMENT_EDM_INFO(Club, Microsoft.Test.OData.Services.ODataWCFService, Club)

BEGIN_PROPERTY_IN_ENTITY_MAPPING(Club)
    ON_PROPERTY_IN_ENTITY_MAPPING(Club, clubid)
    ON_PROPERTY_IN_ENTITY_MAPPING(Club, name)
END_PROPERTY_IN_ENTITY_MAPPING(Club)

BEGIN_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Club)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Club, clubid)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Club, name)
END_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Club)

BEGIN_ENTITY_CONSTRUCTOR(LabourUnion, type_base)
    ON_PROPERTY_IN_ENTITY_CONSTRUCTOR(labourunionid, 0)
    ON_PROPERTY_IN_ENTITY_CONSTRUCTOR(name, nullptr)
END_ENTITY_CONSTRUCTOR(LabourUnion, type_base)

BEGIN_ENTITY_DESTRUCTOR(LabourUnion)
    ON_PROPERTY_IN_ENTITY_DESTRUCTOR(name)
END_ENTITY_DESTRUCTOR(LabourUnion)

IMPLEMENT_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(LabourUnion, labourunionid, LabourUnionID, int32_t);
IMPLEMENT_NULLABLE_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(LabourUnion, name, Name, ::utility::string_t);

IMPLEMENT_EDM_INFO(LabourUnion, Microsoft.Test.OData.Services.ODataWCFService, LabourUnion)

BEGIN_PROPERTY_IN_ENTITY_MAPPING(LabourUnion)
    ON_PROPERTY_IN_ENTITY_MAPPING(LabourUnion, labourunionid)
    ON_PROPERTY_IN_ENTITY_MAPPING(LabourUnion, name)
END_PROPERTY_IN_ENTITY_MAPPING(LabourUnion)

BEGIN_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(LabourUnion)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(LabourUnion, labourunionid)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(LabourUnion, name)
END_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(LabourUnion)

BEGIN_ENTITY_CONSTRUCTOR(Account, type_base)
    ON_PROPERTY_IN_ENTITY_CONSTRUCTOR(accountid, 0)
    ON_PROPERTY_IN_ENTITY_CONSTRUCTOR(mygiftcard, nullptr)
    ON_PROPERTY_IN_ENTITY_CONSTRUCTOR(accountinfo, nullptr)
END_ENTITY_CONSTRUCTOR(Account, type_base)

BEGIN_ENTITY_DESTRUCTOR(Account)
    ON_PROPERTY_IN_ENTITY_DESTRUCTOR(accountinfo)
END_ENTITY_DESTRUCTOR(Account)

IMPLEMENT_FUNCTION_P0(Account, GetDefaultPI, odata_entityset_query_executor<PaymentInstrument>);
IMPLEMENT_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(Account, accountid, AccountID, int32_t);
IMPLEMENT_NAVIGATION_PROPERTY_IN_ENTITY_MAPPING(Account, mygiftcard, MyGiftCard, GiftCard);
IMPLEMENT_COLLECTION_NAVIGATION_PROPERTY_IN_ENTITY_MAPPING(Account, activesubscriptions, ActiveSubscriptions, Subscription);
IMPLEMENT_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(Account, country, Country, ::utility::string_t);
IMPLEMENT_COLLECTION_NAVIGATION_PROPERTY_IN_ENTITY_MAPPING(Account, mypaymentinstruments, MyPaymentInstruments, PaymentInstrument);
IMPLEMENT_ACTION_P1(Account, RefreshDefaultPI, odata_entityset_query_executor<PaymentInstrument>, newDate, ::utility::datetime, newDate);
IMPLEMENT_NULLABLE_COMPLEX_PROPERTY_IN_ENTITY_MAPPING(Account, accountinfo, AccountInfo, AccountInfo);
IMPLEMENT_COLLECTION_NAVIGATION_PROPERTY_IN_ENTITY_MAPPING(Account, availablesubscriptiontemplatess, AvailableSubscriptionTemplatess, Subscription);
IMPLEMENT_FUNCTION_P0(Account, GetAccountInfo, odata_complex_query_executor<AccountInfo>);

IMPLEMENT_EDM_INFO(Account, Microsoft.Test.OData.Services.ODataWCFService, Account)

BEGIN_PROPERTY_IN_ENTITY_MAPPING(Account)
    ON_PROPERTY_IN_ENTITY_MAPPING(Account, accountid)
    ON_PROPERTY_IN_ENTITY_MAPPING(Account, mygiftcard)
    ON_PROPERTY_IN_ENTITY_MAPPING(Account, activesubscriptions)
    ON_PROPERTY_IN_ENTITY_MAPPING(Account, country)
    ON_PROPERTY_IN_ENTITY_MAPPING(Account, mypaymentinstruments)
    ON_PROPERTY_IN_ENTITY_MAPPING(Account, accountinfo)
    ON_PROPERTY_IN_ENTITY_MAPPING(Account, availablesubscriptiontemplatess)
END_PROPERTY_IN_ENTITY_MAPPING(Account)

BEGIN_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Account)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Account, accountid)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Account, country)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Account, accountinfo)
END_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Account)

BEGIN_ENTITY_CONSTRUCTOR(PaymentInstrument, type_base)
    ON_PROPERTY_IN_ENTITY_CONSTRUCTOR(paymentinstrumentid, 0)
END_ENTITY_CONSTRUCTOR(PaymentInstrument, type_base)

BEGIN_ENTITY_DESTRUCTOR(PaymentInstrument)
END_ENTITY_DESTRUCTOR(PaymentInstrument)

IMPLEMENT_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(PaymentInstrument, paymentinstrumentid, PaymentInstrumentID, int32_t);
IMPLEMENT_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(PaymentInstrument, friendlyname, FriendlyName, ::utility::string_t);
IMPLEMENT_NAVIGATION_PROPERTY_IN_ENTITY_MAPPING(PaymentInstrument, backupstoredpi, BackupStoredPI, StoredPI);
IMPLEMENT_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(PaymentInstrument, createddate, CreatedDate, ::utility::datetime);
IMPLEMENT_NAVIGATION_PROPERTY_IN_ENTITY_MAPPING(PaymentInstrument, thestoredpi, TheStoredPI, StoredPI);
IMPLEMENT_COLLECTION_NAVIGATION_PROPERTY_IN_ENTITY_MAPPING(PaymentInstrument, billingstatements, BillingStatements, Statement);

IMPLEMENT_EDM_INFO(PaymentInstrument, Microsoft.Test.OData.Services.ODataWCFService, PaymentInstrument)

BEGIN_PROPERTY_IN_ENTITY_MAPPING(PaymentInstrument)
    ON_PROPERTY_IN_ENTITY_MAPPING(PaymentInstrument, paymentinstrumentid)
    ON_PROPERTY_IN_ENTITY_MAPPING(PaymentInstrument, friendlyname)
    ON_PROPERTY_IN_ENTITY_MAPPING(PaymentInstrument, backupstoredpi)
    ON_PROPERTY_IN_ENTITY_MAPPING(PaymentInstrument, createddate)
    ON_PROPERTY_IN_ENTITY_MAPPING(PaymentInstrument, thestoredpi)
    ON_PROPERTY_IN_ENTITY_MAPPING(PaymentInstrument, billingstatements)
END_PROPERTY_IN_ENTITY_MAPPING(PaymentInstrument)

BEGIN_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(PaymentInstrument)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(PaymentInstrument, paymentinstrumentid)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(PaymentInstrument, friendlyname)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(PaymentInstrument, createddate)
END_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(PaymentInstrument)

BEGIN_ENTITY_CONSTRUCTOR(CreditRecord, type_base)
    ON_PROPERTY_IN_ENTITY_CONSTRUCTOR(creditrecordid, 0)
    ON_PROPERTY_IN_ENTITY_CONSTRUCTOR(isgood, false)
END_ENTITY_CONSTRUCTOR(CreditRecord, type_base)

BEGIN_ENTITY_DESTRUCTOR(CreditRecord)
END_ENTITY_DESTRUCTOR(CreditRecord)

IMPLEMENT_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(CreditRecord, creditrecordid, CreditRecordID, int32_t);
IMPLEMENT_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(CreditRecord, isgood, IsGood, bool);
IMPLEMENT_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(CreditRecord, createddate, CreatedDate, ::utility::datetime);
IMPLEMENT_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(CreditRecord, reason, Reason, ::utility::string_t);

IMPLEMENT_EDM_INFO(CreditRecord, Microsoft.Test.OData.Services.ODataWCFService, CreditRecord)

BEGIN_PROPERTY_IN_ENTITY_MAPPING(CreditRecord)
    ON_PROPERTY_IN_ENTITY_MAPPING(CreditRecord, creditrecordid)
    ON_PROPERTY_IN_ENTITY_MAPPING(CreditRecord, isgood)
    ON_PROPERTY_IN_ENTITY_MAPPING(CreditRecord, createddate)
    ON_PROPERTY_IN_ENTITY_MAPPING(CreditRecord, reason)
END_PROPERTY_IN_ENTITY_MAPPING(CreditRecord)

BEGIN_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(CreditRecord)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(CreditRecord, creditrecordid)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(CreditRecord, isgood)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(CreditRecord, createddate)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(CreditRecord, reason)
END_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(CreditRecord)

BEGIN_ENTITY_CONSTRUCTOR(CreditCardPI, PaymentInstrument)
    ON_PROPERTY_IN_ENTITY_CONSTRUCTOR(balance, 0.0)
END_ENTITY_CONSTRUCTOR(CreditCardPI, PaymentInstrument)

BEGIN_ENTITY_DESTRUCTOR(CreditCardPI)
END_ENTITY_DESTRUCTOR(CreditCardPI)

IMPLEMENT_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(CreditCardPI, holdername, HolderName, ::utility::string_t);
IMPLEMENT_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(CreditCardPI, cardnumber, CardNumber, ::utility::string_t);
IMPLEMENT_COLLECTION_NAVIGATION_PROPERTY_IN_ENTITY_MAPPING(CreditCardPI, creditrecords, CreditRecords, CreditRecord);
IMPLEMENT_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(CreditCardPI, experationdate, ExperationDate, ::utility::datetime);
IMPLEMENT_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(CreditCardPI, cvv, CVV, ::utility::string_t);
IMPLEMENT_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(CreditCardPI, balance, Balance, double);

IMPLEMENT_EDM_INFO(CreditCardPI, Microsoft.Test.OData.Services.ODataWCFService, CreditCardPI)

BEGIN_PROPERTY_IN_ENTITY_MAPPING_WITH_BASE_CLASS(CreditCardPI, PaymentInstrument)
    ON_PROPERTY_IN_ENTITY_MAPPING(CreditCardPI, holdername)
    ON_PROPERTY_IN_ENTITY_MAPPING(CreditCardPI, cardnumber)
    ON_PROPERTY_IN_ENTITY_MAPPING(CreditCardPI, creditrecords)
    ON_PROPERTY_IN_ENTITY_MAPPING(CreditCardPI, experationdate)
    ON_PROPERTY_IN_ENTITY_MAPPING(CreditCardPI, cvv)
    ON_PROPERTY_IN_ENTITY_MAPPING(CreditCardPI, balance)
END_PROPERTY_IN_ENTITY_MAPPING_WITH_BASE_CLASS(CreditCardPI, PaymentInstrument)
BEGIN_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(CreditCardPI)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(CreditCardPI, holdername)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(CreditCardPI, cardnumber)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(CreditCardPI, experationdate)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(CreditCardPI, cvv)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(CreditCardPI, balance)
END_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(CreditCardPI)

BEGIN_ENTITY_CONSTRUCTOR(StoredPI, type_base)
    ON_PROPERTY_IN_ENTITY_CONSTRUCTOR(storedpiid, 0)
END_ENTITY_CONSTRUCTOR(StoredPI, type_base)

BEGIN_ENTITY_DESTRUCTOR(StoredPI)
END_ENTITY_DESTRUCTOR(StoredPI)

IMPLEMENT_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(StoredPI, storedpiid, StoredPIID, int32_t);
IMPLEMENT_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(StoredPI, piname, PIName, ::utility::string_t);
IMPLEMENT_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(StoredPI, pitype, PIType, ::utility::string_t);
IMPLEMENT_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(StoredPI, createddate, CreatedDate, ::utility::datetime);

IMPLEMENT_EDM_INFO(StoredPI, Microsoft.Test.OData.Services.ODataWCFService, StoredPI)

BEGIN_PROPERTY_IN_ENTITY_MAPPING(StoredPI)
    ON_PROPERTY_IN_ENTITY_MAPPING(StoredPI, storedpiid)
    ON_PROPERTY_IN_ENTITY_MAPPING(StoredPI, piname)
    ON_PROPERTY_IN_ENTITY_MAPPING(StoredPI, pitype)
    ON_PROPERTY_IN_ENTITY_MAPPING(StoredPI, createddate)
END_PROPERTY_IN_ENTITY_MAPPING(StoredPI)

BEGIN_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(StoredPI)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(StoredPI, storedpiid)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(StoredPI, piname)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(StoredPI, pitype)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(StoredPI, createddate)
END_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(StoredPI)

BEGIN_ENTITY_CONSTRUCTOR(Subscription, type_base)
    ON_PROPERTY_IN_ENTITY_CONSTRUCTOR(subscriptionid, 0)
END_ENTITY_CONSTRUCTOR(Subscription, type_base)

BEGIN_ENTITY_DESTRUCTOR(Subscription)
END_ENTITY_DESTRUCTOR(Subscription)

IMPLEMENT_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(Subscription, subscriptionid, SubscriptionID, int32_t);
IMPLEMENT_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(Subscription, templateguid, TemplateGuid, ::utility::string_t);
IMPLEMENT_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(Subscription, category, Category, ::utility::string_t);
IMPLEMENT_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(Subscription, title, Title, ::utility::string_t);
IMPLEMENT_PRIMITIVE_PROPERTY_IN_ENTITY_MAPPING(Subscription, createddate, CreatedDate, ::utility::datetime);

IMPLEMENT_EDM_INFO(Subscription, Microsoft.Test.OData.Services.ODataWCFService, Subscription)

BEGIN_PROPERTY_IN_ENTITY_MAPPING(Subscription)
    ON_PROPERTY_IN_ENTITY_MAPPING(Subscription, subscriptionid)
    ON_PROPERTY_IN_ENTITY_MAPPING(Subscription, templateguid)
    ON_PROPERTY_IN_ENTITY_MAPPING(Subscription, category)
    ON_PROPERTY_IN_ENTITY_MAPPING(Subscription, title)
    ON_PROPERTY_IN_ENTITY_MAPPING(Subscription, createddate)
END_PROPERTY_IN_ENTITY_MAPPING(Subscription)

BEGIN_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Subscription)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Subscription, subscriptionid)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Subscription, templateguid)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Subscription, category)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Subscription, title)
    ON_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Subscription, createddate)
END_SERIALIZE_PROPERTY_IN_ENTITY_MAPPING(Subscription)

IMPLEMENT_ACTION_IMPORT_P1(InMemoryEntities, ResetBossEmail, odata_primitive_query_executor<::utility::string_t>, emails, std::vector<::utility::string_t>, emails);

IMPLEMENT_FUNCTION_IMPORT_P2(InMemoryEntities, GetBossEmails, odata_primitive_query_executor<::utility::string_t>, start, int32_t, start, count, int32_t, count);

IMPLEMENT_ACTION_IMPORT_P1(InMemoryEntities, Discount, odata_void_query_executor, percentage, int32_t, percentage);

IMPLEMENT_FUNCTION_IMPORT_P0(InMemoryEntities, GetAllProducts, odata_entityset_query_executor<Product>);

IMPLEMENT_ACTION_IMPORT_P1(InMemoryEntities, ResetBossAddress, odata_complex_query_executor<Address>, address, Address, address);

IMPLEMENT_FUNCTION_IMPORT_P0(InMemoryEntities, GetDefaultColor, InMemoryEntities::enum_GetDefaultColor_excecutor);

IMPLEMENT_ACTION_IMPORT_P0(InMemoryEntities, ResetDataSource, odata_void_query_executor);

IMPLEMENT_FUNCTION_IMPORT_P1(InMemoryEntities, GetPerson, odata_entityset_query_executor<Person>, address, Address, address);

IMPLEMENT_FUNCTION_IMPORT_P1(InMemoryEntities, GetPerson2, odata_entityset_query_executor<Person>, city, ::utility::string_t, city);

IMPLEMENT_FUNCTION_IMPORT_P1(InMemoryEntities, GetProductsByAccessLevel, odata_primitive_query_executor<::utility::string_t>, accessLevel, AccessLevel, accessLevel);

DECLARE_DERIVED_COMPLEX_CREATOR_FUNC(HomeAddress, homeaddress)
DECLARE_DERIVED_COMPLEX_CREATOR_FUNC(CompanyAddress, companyaddress)
IMPLEMENT_COMPLEX_DERIVED_TYPE_CREATOR_MAP(AccountInfo)

BEGIN_IMPLEMENT_COMPLEX_DERIVED_TYPE_CREATOR_MAP(Address)
    ON_IMPLEMENT_COMPLEX_DERIVED_TYPE_CREATOR_MAP(HomeAddress, homeaddress)
    ON_IMPLEMENT_COMPLEX_DERIVED_TYPE_CREATOR_MAP(CompanyAddress, companyaddress)
END_IMPLEMENT_COMPLEX_DERIVED_TYPE_CREATOR_MAP(Address)

IMPLEMENT_COMPLEX_DERIVED_TYPE_CREATOR_MAP(HomeAddress)
IMPLEMENT_COMPLEX_DERIVED_TYPE_CREATOR_MAP(CompanyAddress)

DECLARE_DERIVED_ENTITY_CREATOR_FUNC(Customer, customer)
DECLARE_DERIVED_ENTITY_CREATOR_FUNC(Employee, employee)
DECLARE_DERIVED_ENTITY_CREATOR_FUNC(PublicCompany, publiccompany)
DECLARE_DERIVED_ENTITY_CREATOR_FUNC(CreditCardPI, creditcardpi)

BEGIN_IMPLEMENT_ENTITY_DERIVED_TYPE_CREATOR_MAP(Person)
    ON_IMPLEMENT_ENTITY_DERIVED_TYPE_CREATOR_MAP(Customer, customer)
    ON_IMPLEMENT_ENTITY_DERIVED_TYPE_CREATOR_MAP(Employee, employee)
END_IMPLEMENT_ENTITY_DERIVED_TYPE_CREATOR_MAP(Person)

IMPLEMENT_EMPTY_DERIVED_TYPE_CREATOR_MAP(Statement)
IMPLEMENT_EMPTY_DERIVED_TYPE_CREATOR_MAP(Department)
IMPLEMENT_EMPTY_DERIVED_TYPE_CREATOR_MAP(Customer)
IMPLEMENT_EMPTY_DERIVED_TYPE_CREATOR_MAP(ProductDetail)
IMPLEMENT_EMPTY_DERIVED_TYPE_CREATOR_MAP(Employee)
IMPLEMENT_EMPTY_DERIVED_TYPE_CREATOR_MAP(Product)
IMPLEMENT_EMPTY_DERIVED_TYPE_CREATOR_MAP(ProductReview)
IMPLEMENT_EMPTY_DERIVED_TYPE_CREATOR_MAP(Order)
IMPLEMENT_EMPTY_DERIVED_TYPE_CREATOR_MAP(OrderDetail)

BEGIN_IMPLEMENT_ENTITY_DERIVED_TYPE_CREATOR_MAP(Company)
    ON_IMPLEMENT_ENTITY_DERIVED_TYPE_CREATOR_MAP(PublicCompany, publiccompany)
END_IMPLEMENT_ENTITY_DERIVED_TYPE_CREATOR_MAP(Company)

IMPLEMENT_EMPTY_DERIVED_TYPE_CREATOR_MAP(PublicCompany)
IMPLEMENT_EMPTY_DERIVED_TYPE_CREATOR_MAP(Asset)
IMPLEMENT_EMPTY_DERIVED_TYPE_CREATOR_MAP(GiftCard)
IMPLEMENT_EMPTY_DERIVED_TYPE_CREATOR_MAP(Club)
IMPLEMENT_EMPTY_DERIVED_TYPE_CREATOR_MAP(LabourUnion)
IMPLEMENT_EMPTY_DERIVED_TYPE_CREATOR_MAP(Account)

BEGIN_IMPLEMENT_ENTITY_DERIVED_TYPE_CREATOR_MAP(PaymentInstrument)
    ON_IMPLEMENT_ENTITY_DERIVED_TYPE_CREATOR_MAP(CreditCardPI, creditcardpi)
END_IMPLEMENT_ENTITY_DERIVED_TYPE_CREATOR_MAP(PaymentInstrument)

IMPLEMENT_EMPTY_DERIVED_TYPE_CREATOR_MAP(CreditRecord)
IMPLEMENT_EMPTY_DERIVED_TYPE_CREATOR_MAP(CreditCardPI)
IMPLEMENT_EMPTY_DERIVED_TYPE_CREATOR_MAP(StoredPI)
IMPLEMENT_EMPTY_DERIVED_TYPE_CREATOR_MAP(Subscription)


}}}}
