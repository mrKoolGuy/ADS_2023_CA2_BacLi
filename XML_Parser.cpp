#include "XML_Parser.h"


XML_Parser::XML_Parser()
{
    this->s_xml = "No String Entered";
    this->validStackCap = 100;
}

XML_Parser::XML_Parser(string filePath)
{
    this->s_xml = XMLtoString(filePath);
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
    string prevTag = "";

    //Check is string is empty
    if (s_xml == "") {
        return false;
    }

    if (s_xml.find('<') == string::npos) {
        return false;
    }

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
            if ((elementNr == 0 && tag != "root") && (elementNr == 0 && tag != "dir"))
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
                if (validStack.top() != "" && prevTag != "")
                {
                    if (tag != prevTag)
                    {
                        validStack.push(tag);
                        prevTag = validStack.top();
                    }
                    else
                    {
                        return false;
                    }
                }
                else 
                {                   
                    validStack.push(tag);
                    prevTag = validStack.top();
                    //cout << "TEST: validStack.top() = " << validStack.top() << endl;
                }
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
            //cout << "TEST:" << tag << " | " << closingTag << endl;
            
        }
        
    }

    if (validStack.size() != 0) 
    {
        return false;
    }

    return true;
}

string XML_Parser::XMLtoString(string filePath)
{
    //Parse real XML file into string
    ifstream file(filePath);

    if (!file.is_open()) cout << "Error opening file: " << filePath << endl;

    stringstream stream;
    stream << file.rdbuf();

    file.close();

    return stream.str();
}

void XML_Parser::CreateTree(Tree<string> *& root)
{

    if (ValidateXML()) 
    {
        bool closingTag = false;
        Tree<string>* previousParent = root;
        string tag = "";

        for (int i = 0; i < s_xml.length(); i++) {

            closingTag = false;

            if (s_xml[i] == '\n')
            {
                i++;
            }
            //If Tag opens
            if (s_xml[i] == '<')
            {              
                //if next character is a "/", its a closing tag
                if (s_xml[i + 1] == '/')
                {
                    closingTag = true;
                    i++;
                }

                //get the tag
                tag = GetTag(i);
            }
            //if the next character is not a tag opening
            else
            {
                //do something
            }
            //If it is not a closing Tag, check what tag it is and enter something
            if (!closingTag)
            {
                string nameTag = "";

                //check what the string says, and create tree node based on that
                if (tag == "root")
                {
                    //not sure if i need this
                }
                else if (tag == "dir")
                {
                    //find name 
                    i = s_xml.find('<', i - 1);
                    if (GetTag(i) == "name") 
                    {
                        nameTag = s_xml.substr(++i, s_xml.find('<', i) - i);
                    }

                    //create dir in tree
                    Tree<string>* dir = new Tree<string>(nameTag);
                    if (previousParent == nullptr) 
                    {
                        root = dir;
                    }
                    else {
                        dir->parent = previousParent;
                        previousParent->children->append(dir);
                    }                  
                    previousParent = dir;

                    tag = "";
                }
                else if (tag == "file")
                {
                    int length = 0;
                    string type = "";

                    i = s_xml.find('<', i);
                    if (GetTag(i) == "name")
                    {
                        nameTag = s_xml.substr(++i, s_xml.find('<', i) - i);
                    }
                    i = s_xml.find('>', i);
                    i = s_xml.find('<', i - 1);
                    if (GetTag(i) == "length")
                    {
                        length = stoi(s_xml.substr(++i, s_xml.find('<', i) - i));
                    }
                    else
                    {
                        //File without Length -> Invalid
                        return;
                    }
                    i = s_xml.find('>', i);
                    i = s_xml.find('<', i - 1);
                    if (GetTag(i) == "type")
                    {
                        type = s_xml.substr(++i, s_xml.find('<', i) - i);
                    }
                    else
                    {
                        //File without type -> Invalid
                        return;
                    }
                    i = s_xml.find('>', i);
                    Tree<string>* file = new Tree<string>(nameTag, length, type);
                    file->parent = previousParent;
                    if (previousParent != nullptr)
                    {
                        previousParent->children->append(file);
                    }

                    tag = "";
                }
                else
                {
                    //Invalid
                    //return;
                }
            }
            else
            {
                //it is a closing tag
                if (tag == "dir") {
                    previousParent = previousParent->parent;
                }
            }
        }
    }
    else 
    {
        cout << "ERROR: Tree Invalid" << endl;
    }
}
