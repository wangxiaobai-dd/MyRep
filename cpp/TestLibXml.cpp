/* 
 * Copyright (C) 2023 Meepo All Rights Reserved.
 * 
 * File Name     : TestLibXml.cpp
 * Author        : Meepo
 * Creation Date : 2023-07-11
 * INFO          :
 *
 */


#include <iostream>
#include <string>
#include <libxml/parser.h>
#include <libxml/tree.h>


using namespace std;

int main()
{
	auto doc = xmlParseFile("test.xml");
	auto root = xmlDocGetRootElement(doc);
	for(auto cur_node = root->children; cur_node; cur_node = cur_node->next)
	{
		//std::cout << "type:" << cur_node->type << " name:" << cur_node->name << " children:" << cur_node->children << std::endl;
		if(cur_node->type == XML_TEXT_NODE)
			printf("content:%s\n", xmlNodeGetContent(cur_node));
		//if(cur_node->type == XML_ELEMENT_NODE)
		//	std::cout << "child name:" << cur_node->children->content << std::endl << std::endl;
	}
	std::cout << doc->encoding << std::endl;

	char* a = 'a';
	unsigned char* b = 'a';
	
	return 0;
}

