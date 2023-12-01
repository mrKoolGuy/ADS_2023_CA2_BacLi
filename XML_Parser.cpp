#include "XML_Parser.h"

XML_Parser::XML_Parser()
{
    this->s_xml = "No String Entered";
}

XML_Parser::XML_Parser(string s)
{
    this->s_xml = s;
}

void XML_Parser::SetXML(string s_xml)
{
    this->s_xml = s_xml;
}

string XML_Parser::GetXML()
{
    return s_xml;
}

bool XML_Parser::validateXML()
{
    Stack<string> validStack("");

    for (int i = 0; i < s_xml.length(); i++) {

    }

    return false;
}
