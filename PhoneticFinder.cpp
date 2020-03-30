#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>
#include "PhoneticFinder.hpp"
using namespace std;


string compareWords(string, string);


class MyException : public exception{

    string message;

    public:
        MyException(string word)
        {
            ostringstream oss;
            oss << "Did not find the word '" << word << "' in the text";
            message = oss.str();
            //cout << message << endl;
            
        
        }
        const char* what() const throw(){
            
            return message.c_str();
        }
};


string phonetic::find(string text, string keyword)
{
    int i;
    int textLength = text.length();
    int keywordLength = keyword.length();
    

    string word;
    string result;


    //cout << textLength << endl;

    for(i=0;i<textLength;i++)
    {
        char c = text[i];
        if((c>='a'&&c<='z')||(c>='A'&&c<='Z'))  word+=c;
       
        else 
        {
            int wordLength = word.length();

            
            if(keywordLength==wordLength)
            {
                result = compareWords(keyword, word);
            }

            //cout << result << endl;
            if(result!="") return result;

            word="";
        }
        //cout << keyword << "  " << word << endl;
        if(i==textLength-1&&keywordLength==word.length()) result=compareWords(keyword, word);
        if(result!="") return result;
    }

    MyException ex(keyword);
    //cout << "exception thrown" << endl;
    throw ex;
        

    
    return "hello world";
}

string compareWords(string keyword, string textword)
{
    int i;
    bool flag = false;

    //cout << keyword << "    " << textword << endl;

    for(i=0;i<keyword.length();i++)
    {
        if(flag) break;

        char key = keyword[i];
        char text = textword[i];
        


        switch (key)
        {
        case 'd':
        case 'D':
        case 't':
        case 'T':

            if(text!='d'&&text!='D'&&text!='t'&&text!='T')  flag = true;
            break;

        case 'u':
        case 'U':
        case 'o':
        case 'O':

            if(text!='u'&&text!='U'&&text!='o'&&text!='O') flag = true;
            break;
        
        case 'v':
        case 'V':
        case 'w':
        case 'W':
            
            if(text!='v'&&text!='V'&&text!='w'&&text!='W') flag = true;
            break;

        case 'c':
        case 'C':
        case 'k':
        case 'K':
        case 'q':
        case 'Q':

            if(text!='c'&&text!='C'&&text!='k'&&text!='K'&&text!='q'&&text!='Q') flag = true;
            break;

        case 'g':
        case 'G':
        case 'j':
        case 'J':

            if(text!='g'&&text!='G'&&text!='j'&&text!='J') flag = true;
            break;

        case 'i':
        case 'I':
        case 'y':
        case 'Y':

            if(text!='i'&&text!='I'&&text!='y'&&text!='Y') flag = true;
            break;

        case 's':
        case 'S':
        case 'z':
        case 'Z':

            if(text!='s'&&text!='S'&&text!='z'&&text!='Z') flag = true;
            break;   

        case 'b':
        case 'B':
        case 'f':
        case 'F':
        case 'p':
        case 'P':

            if(text!='b'&&text!='B'&&text!='f'&&text!='F'&&text!='p'&&text!='P') flag = true;
            break;

        default:

            if(text!=key+32&&text!=key-32&&text!=key)   flag = true;

            break;
        }

    }
    if(flag==true) return "";
    return textword;
}

