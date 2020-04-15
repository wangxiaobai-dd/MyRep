#include <iostream>
#include "message.pb.h"
#include <google/protobuf/message.h>

void testReflact(google::protobuf::Message& message)
{
	using namespace google::protobuf;
	const google::protobuf::Descriptor* pDescriptor = message.GetDescriptor();
	const google::protobuf::Reflection* pReflection = message.GetReflection();

	for(int i = 0; i < pDescriptor->field_count(); i++)
	{
		const google::protobuf::FieldDescriptor* pFieldDescriptor = pDescriptor->field(i);
		const std::string& strFieldName = pFieldDescriptor->name();
		if(pFieldDescriptor->cpp_type() == google::protobuf::FieldDescriptor::CPPTYPE_INT32)
		{
			std::cout << "filed Name: " << strFieldName << std::endl;
			std::cout << "filed Value: " << pReflection->GetInt32(message, pFieldDescriptor) << std::endl;
			pReflection->SetInt32(&message, pFieldDescriptor, 10);
		}
	}
	const google::protobuf::FieldDescriptor* pField = pDescriptor->FindFieldByName("pass_word");
	if(pField)
		std::cout << "filed Name: " << pField->name() << std::endl;
	auto pField2 = pDescriptor->FindFieldByLowercaseName("u_map");
	if(pField2)
	{
		std::cout << "filed2 Name: " << pField2->name() << std::endl;
		if(pField2->is_map())
		{
			std::cout << "is map ==> insert" << std::endl;

			Message* sub_message = pReflection->AddMessage(&message, pField2);
			if(sub_message)
			{
				const google::protobuf::FieldDescriptor* key_field =
					sub_message->GetDescriptor()->FindFieldByNumber(1);
				const google::protobuf::FieldDescriptor* value_field =
					sub_message->GetDescriptor()->FindFieldByNumber(2);
				const google::protobuf::Reflection* reflection = sub_message->GetReflection();

				reflection->SetInt32(sub_message, key_field, 123);
				reflection->SetInt32(sub_message, value_field, 123);
			}
		}
	}
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

	for(const auto& item : u.u_map())
	{
		std::cout << item.first << std::endl;
		std::cout << item.second << std::endl;
	}
}

