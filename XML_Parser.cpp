#include "XML_Parser.h"


XML_Parser::XML_Parser()
{
    this->s_xml = "No String Entered";
    this->validStackCap = 100;
}

XML_Parser::XML_Parser(string s)
{
    this->s_xml = s;
    this->validStackCap = 100;
}

void XML_Parser::SetXML(string s_xml)
{
    this->s_xml = s_xml;
}

string XML_Parser::GetXML()
{
    return s_xml;
}


bool XML_Parser::ValidateXML()
{
    MyStack<string> validStack("", validStackCap);
    bool closingTag = false;
    int elementNr = 0;

    for (int i = 0; i < s_xml.length(); i++) {

        closingTag = false;
        //To-Do: Check if first Element is <root>

        //If Tag opens
        if (s_xml[i] == '<') 
        {
            string tag = "";

            //if next character is a "/", its a closing tag
            if (s_xml[i + 1] == '/')
            {
                closingTag = true;
                i++;
            }

            //Add all characters of Tag into "tag" string
            for (i += 1; s_xml[i] != '>'; i++) 
            {   
                tag += s_xml[i];
            }

            //if the tag is empty, return invalid
            if (tag == "") 
            {
                return false;
            }

            //check if first element is not root, return invalid
            if (elementNr == 0 && tag != "root") 
            {
                return false;
            }
            else 
            {
                elementNr++;
            }
            

            //if the tag is an opening tag, push it onto the stack
            if(!closingTag) 
            {
                validStack.push(tag);
            }
            //if it is a closing tag, check if it corresponds with the previous opening tag
            else 
            {
                if (tag == validStack.top()) 
                {
                    validStack.pop();
                }
                //if it is not the same tag, return false: invalid stack
                else 
                {
                    return false;
                }
            }

            //Test Print
            cout << "TEST:" << tag << " | " << closingTag << endl;
            
        }
    }

    if (validStack.size() != 0) 
    {
        return false;
    }

    return true;
}

bool XML_Parser::XMLtoString()
{
    //Parse real XML file into string
    return false;
}
