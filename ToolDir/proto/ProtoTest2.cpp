#include <iostream>
#include <google/protobuf/message.h>
#include <google/protobuf/descriptor.pb.h>
#include <google/protobuf/dynamic_message.h>


int main()
{
	using namespace google::protobuf;
	FileDescriptorProto file_proto;
	file_proto.set_name("foo.proto");
	DescriptorProto *message_proto = file_proto.add_message_type();
	message_proto->set_name("Pair");

	FieldDescriptorProto *field_proto = NULL;

	field_proto = message_proto->add_field();
	field_proto->set_name("key");
	field_proto->set_type(FieldDescriptorProto::TYPE_STRING);
	field_proto->set_number(1);
	field_proto->set_label(FieldDescriptorProto::LABEL_REQUIRED);


	field_proto = message_proto->add_field();
	field_proto->set_name("value");
	field_proto->set_type(FieldDescriptorProto::TYPE_UINT32);
	field_proto->set_number(2);
	field_proto->set_label(FieldDescriptorProto::LABEL_REQUIRED);
	DescriptorPool pool;
	const FileDescriptor *file_descriptor = pool.BuildFile(file_proto);
	const Descriptor *descriptor = file_descriptor->FindMessageTypeByName("Pair");
	
	DynamicMessageFactory factory(&pool);
	const Message *message = factory.GetPrototype(descriptor);

	Message *pair = message->New();
	
	const Reflection *reflection = pair->GetReflection();
	const FieldDescriptor *field = NULL;
	field = descriptor->FindFieldByName("key");
	reflection->SetString(pair, field, "my key");
	field = descriptor->FindFieldByName("value");
	reflection->SetUInt32(pair, field, 1234);
}

