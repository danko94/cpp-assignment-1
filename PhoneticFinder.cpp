#include <iostream>
#include <stdexcept>
#include "PhoneticFinder.hpp"
using namespace std;





string phonetic::find(string text, string keyword)
{
    int i;
    int textLength = text.length();
    int keywordLength = keyword.length();
    

    string word;

    for(i=0;i<textLength;i++)
    {
        char c = text[i];
        if((c>='a'&&c<='z')||(c>='A'&&c<='Z'))  word+=text[i];
        else 
        {
            int wordLength = word.length();

            string result;
            
            if(keywordLength==wordLength)
            {
                result = compareWords(keyword, word);
            }

            word="";
        }
    }

    
    return "hello world";
}

string compareWords(string keyword, string textword)
{
    int i;
    bool flag = false;

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

            if(text!='d'||text!='D'||text!='t'||text!='T') flag = true;
            break;

        case 'u':
        case 'U':
        case 'o':
        case 'O':

            if(text!='u'||text!='U'||text!='o'||text!='O') flag = true;
            break;
        
        case 'v':
        case 'V':
        case 'W':
        case 'w':
            
            if(text!='v'||text!='V'||text!='w'||text!='W') flag = true;

        case 'c':
        case 'C':
        case 'k':
        case 'K':
        case 'q':
        case 'Q':

            if(text!='c'||text!='C'||text!='k'||text!='K'||text!='q'||text!='Q') flag = true;
            break;

        case 'g':
        case 'G':
        case 'j':
        case 'J':

            if(text!='g'||text!='G'||text!='j'||text!='J') flag = true;
            break;

        case 'i':
        case 'I':
        case 'y':
        case 'Y':

            if(text!='i'||text!='I'||text!='y'||text!='Y') flag = true;
            break;

        case 's':
        case 'S':
        case 'z':
        case 'Z':

            if(text!='s'||text!='S'||text!='z'||text!='Z') flag = true;
            break;   

        case 'b':
        case 'B':
        case 'f':
        case 'F':
        case 'p':
        case 'P':

            if(text!='b'||text!='B'||text!='f'||text!='F'||text!='p'||text!='P') flag = true;
            break;

        default:

            if(text!=key+'a') flag = true; //need change
            break;
        }

    }
}

