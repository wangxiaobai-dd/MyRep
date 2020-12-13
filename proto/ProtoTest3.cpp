#include <iostream>
#include <fstream>
// #include <gtest/gtest.h>

#include "selfMessage.pb.h"

class TestSelfDescribingMsg
{
	public:
		TestSelfDescribingMsg(std::ifstream& fstream)
		{
			parseFlag = selfMsg.mutable_descriptor_set()->ParseFromIstream(&fstream);
		}

		bool parseSuccess(){ return parseFlag; }

		void showAllFileInfo()
		{
			for(const auto& file : selfMsg.descriptor_set().file())
			{
				std::cout << "file name: " << file.name() << std::endl;
				std::cout << "file package: " << file.package() << std::endl;
			}
		}

		void showAllMessageInfo()
		{
			for(const auto& file : selfMsg.descriptor_set().file())
			{
				std::cout << "----" << std::endl;
				for(const auto& msg : file.message_type())
				{
					std::cout << "msg name: " << msg.name() << std::endl;
					for(const auto& field : msg.field())
					{
						std::cout << "name: " << field.name() << std::endl;
					}
				}
			}
		}
	private:
		test::SelfDescribingMessage selfMsg;
		bool parseFlag = false;
};

int main()
{
	// des.set 保存自定义(这里是message.proto)文件信息
	// message User 
	// message Person
	// message PhoneNumber
	std::ifstream desFileStream("des.set");
	if(!desFileStream.is_open())
	{
		std::cout << "Could not open" << std::endl;
		return 0;
	}
	
	TestSelfDescribingMsg testCase(desFileStream);
	if(!testCase.parseSuccess())
		std::cout << "Could not parse file contents" << std::endl;

	testCase.showAllFileInfo();
	testCase.showAllMessageInfo();

	// 生产者:
	// 自描述信息 1 保存文件内容，2 msg type，3 raw data 
	
	// 消费者:
	// 1 解析SelfDescribingMessage 得到FileDescriptorSet，2 DescriptorPool 通过message type 得到Message的Descriptor 
	// 3 DynamicMessageFactory 得到 message ， 4 反序列化raw data 

}

