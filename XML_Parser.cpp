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

string XML_Parser::GetTag(int& i)
{
    string tag = "";

    //Add all characters of Tag into "tag" string
    for (i += 1; s_xml[i] != '>'; i++)
    {
        tag += s_xml[i];
    }

    return tag;
}

string XML_Parser::GetData(int& i)
{
    string data = "";

    for (i; s_xml[i] != '<'; i++) 
    {
        data += s_xml[i];
    }

    return data;
}



bool XML_Parser::ValidateXML()
{
    MyStack<string> validStack("", validStackCap);
    bool closingTag = false;
    int elementNr = 0;

    for (int i = 0; i < s_xml.length(); i++) {

        closingTag = false;

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
            tag = GetTag(i);

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

void XML_Parser::CreateTree(Tree<string> *& root)
{

    if (ValidateXML()) 
    {
        bool closingTag = false;
        Tree<string>* previousParent = nullptr;

        for (int i = 0; i < s_xml.length(); i++) {

            closingTag = false;

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

                //get the tag
                tag = GetTag(i);


                //until here, everything is fine



                //If it is not a closing Tag, check what tag it is and enter something
                if (!closingTag)
                {
                    string nameTag = s_xml.substr(i, 6);

                    //check what the string says, and create tree node based on that

                    if (tag == "name") 
                    {
                        i++;
                        nameTag = GetData(i);
                        cout << "TEST Name: " << nameTag << endl;
                    }
                    else if (tag == "root")
                    {
                        //not sure if i need this
                    }
                    else if (tag == "dir")
                    {
                        Tree<string>* dir = new Tree<string>(nameTag);
                        dir->parent = previousParent;
                        if (previousParent != nullptr)
                        {
                            previousParent->children->append(dir);
                        }
                        previousParent = dir;
                        cout << "SUCCESS: Created dir" << endl;
                    }
                    else if (tag == "file")
                    {
                        int length = 0;
                        string type = "";
                        
                        
                        string data = s_xml.substr(i, 6);

                        if (GetTag(i) == "length") 
                        {
                            length = stoi(GetData(i));
                            cout << "TEST length: " << length << endl;
                        }
                        else 
                        {
                            //Invalid
                            return;
                        }
                        GetTag(i);
                        if (GetTag(i) == "type")
                        {
                            type = GetData(i);
                            cout << "TEST type: " << type << endl;
                        }
                        else
                        {
                            //Invalid
                            return;
                        }

                        Tree<string>* file = new Tree<string>(nameTag, length, type);
                        file->parent = previousParent;
                        if (previousParent != nullptr)
                        {
                            previousParent->children->append(file);
                        }
                        cout << "SUCCESS: Created file" << endl;
                    }
                    else
                    {
                        //Invalid
                        //return;

                        cout << "Invalid Tag" << endl;
                    }
                }
                else
                {
                    cout << "TEST closingTag: " << closingTag << endl;
                }
            }
            //if the next character is not a tag opening
            else
            {
                cout << "TEST: Is not opening tag" << endl;
            }
        }
    }
    else 
    {
        cout << "false" << endl;
    }
}
