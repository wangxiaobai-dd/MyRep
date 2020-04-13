#include <iostream>
#include "message.pb.h"
#include <google/protobuf/message.h>

void testReflact(google::protobuf::Message& message)
{
	const google::protobuf::Descriptor* pDescriptor = message.GetDescriptor();
	const google::protobuf::Reflection* pReflection = message.GetReflection();

	for(int i = 0; i < pDescriptor->field_count(); i++)
	{
		const google::protobuf::FieldDescriptor* pFieldDescriptor = pDescriptor->field(i);
		const std::string& strFieldName = pFieldDescriptor->name();
		if(pFieldDescriptor->type() == google::protobuf::FieldDescriptor::TYPE_INT32)
		{
			std::cout << "filed Name: " << strFieldName << std::endl;
			std::cout << "filed Value: " << pReflection->GetInt32(message, pFieldDescriptor) << std::endl;
			pReflection->SetInt32(&message, pFieldDescriptor, 10);
		}
	}
	auto pField = pDescriptor->FindFieldByName("pass_word");
	if(pField)
		std::cout << "filed Name: " << pField->name() << std::endl;
	auto pField2 = pDescriptor->FindFieldByLowercaseName("pass_word");
	if(pField2)
		std::cout << "filed2 Name: " << pField->name() << std::endl;
}

int main()
{
	test::User u;
	u.set_id(1);
	u.set_username("hehe");
	u.set_pass_word("123");

	std::cout << u.id() << std::endl;
	std::cout << u.username() << std::endl;

	// ·´Éä
	testReflact(u);
	std::cout << u.id() << std::endl;
}

