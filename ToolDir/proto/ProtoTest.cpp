#include <iostream>
#include <vector>
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
	/*
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
	*/
}

void testMapReflection(google::protobuf::Message& message)
{
	using namespace google::protobuf;
	// map反射测试 参考官方写法
	const Descriptor* descriptor = test::User::descriptor();
	const Reflection* reflection = message.GetReflection();
	const FieldDescriptor* field = descriptor->FindFieldByName("u_map"); 
	if(field && field->is_map())
	{
		std::cout << "test map reflection is map" << std::endl;
		// private 暂不可用 InsertOrLookupMapValue
		// const google::protobuf::internal::MapFieldBase* map_field = reflection->GetMapData(*message, field);
		
		std::cout << "size: " << reflection->FieldSize(message, field) << std::endl;
		const Message* ret = &reflection->GetRepeatedMessage(message, field, 0);
		std::cout << ret->DebugString() << std::endl;
		ret = &reflection->GetRepeatedMessage(message, field, 1);
		std::cout << ret->DebugString() << std::endl;

		// 越界则异常
		//ret = &reflection->GetRepeatedMessage(message, field, 2);
		//std::cout << ret->DebugString() << std::endl;
	
		// 反射
		/*
		std::vector<const FieldDescriptor*> output;
		ret->GetReflection()->ListFields(*ret, &output);
		for (int i = 0; i < output.size(); ++i) {
			const FieldDescriptor* field = output[i];
			std::cout << field->name() << std::endl;
		}
		*/
		
		int32 key = ret->GetReflection()->GetInt32(*ret, ret->GetDescriptor()->FindFieldByName("key"));
		int32 val = ret->GetReflection()->GetInt32(*ret, ret->GetDescriptor()->FindFieldByName("value"));
		std::cout << "int 32 key: " << key << std::endl;
		std::cout << "int 32 value: " << val << std::endl;
		// map_int32_int32_key_
		/*
		ret->GetReflection()->SetInt32(const_cast<Message*>(ret), ret->GetDescriptor()->FindFieldByName("value"), 100);
		key = ret->GetReflection()->GetInt32(*ret, ret->GetDescriptor()->FindFieldByName("key"));
		val = ret->GetReflection()->GetInt32(*ret, ret->GetDescriptor()->FindFieldByName("value"));
		std::cout << "change : int 32 key: " << key << std::endl;
		std::cout << "change : int 32 value: " << val << std::endl;
		*/

		/*
		std::cout << "insert reflection" << std::endl;
		Message* sub_message = reflection->AddMessage(&message, field);
		sub_message->GetReflection()->SetInt32(sub_message, sub_message->GetDescriptor()->FindFieldByName("key"), 50);
		sub_message->GetReflection()->SetInt32(sub_message, sub_message->GetDescriptor()->FindFieldByName("value"), 50);
		*/
	}
}

int main()
{
	test::User u;
	u.set_id(1);
	u.set_username("hehe");
	u.set_pass_word("123");

	//std::cout << u.id() << std::endl;
	//std::cout << u.username() << std::endl;

	// 反射
	//testReflact(u);
	(*u.mutable_u_map())[1] = 1;
	(*u.mutable_u_map())[2] = 1;

	testMapReflection(u);

	(*u.mutable_u_map())[3] = 1;
	(*u.mutable_u_map())[4] = 1;
	
	for(const auto& item : u.u_map())
	{
		std::cout << item.first << " : ";
		std::cout << item.second << std::endl;
	}
}

