#include <iostream>
#include <fstream>

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
				for(const auto& msg : file.message_type())
				{
					std::cout << "msg name: " << msg.name() << std::endl;
				}
			}
		}
	private:
		test::SelfDescribingMessage selfMsg;
		bool parseFlag = false;
};

int main()
{
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
	

}

