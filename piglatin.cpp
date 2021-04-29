//
//  main.cpp
//  piglatin
//
//  Created by Eliott on 29/4/21.
//

#include <iostream>
#include <string>


void pigLatinify(std::string input);
void checkFirstLetter(std::string input);
void checkThirdLastLetter(std::string input);
void englishify(std::string input);

/*
 Pig Latin takes the first word consonant(or consonant cluster) of an english word and moves it to the end of the word and suffixes an ay, or if a word begins with a vowel you just add way to the end. For example, pig become igpay, banana becomes ananabay, and aardvark becomes aardvarkway. Write a function that uses strings called PigLatinify that takes in a c++ string and returns the Pig Latin version
 */

/*
 ask for user input
 check if the word starts with a vowel or a consonant.
 if it starts with a consonant, move the first letter to the end of the word and
 add "ay" to it.
 if it starts with a vowel, add "way" to the end.
 output the result.
*/


int main()
{
    char answer, translateAgain;
    std::string translate = ""; //creates an empty string
    
   /* std::cout<<"Would you like to translate a word in english to piglatin or piglatin to english?\n(y). piglatin to english\n(n). english to piglatin\nWhat is your answer?: ";
    std::cin>>answer;*/
    
    do
    {
        std::cout<<"Would you like to translate a word in english to piglatin or piglatin to english?\n(y). english to piglatin\n(n). piglatin to english\nWhat is your answer?: ";
        std::cin>>answer;
        
        if(answer == 'y')
        {
            std::cout<<"Please enter an english word you would like translated: ";
            std::cin>>translate;
            checkFirstLetter(translate);
        }
        else if(answer == 'n')
        {
            std::cout<<"Please enter a piglatin word you would like translated: ";
            std::cin>>translate;
            checkThirdLastLetter(translate);
        }
        else
        {
            std::cout<<"Would you like to translate a word?\n(y). yes\n(n). No\nWhat is your answer: ";
            std::cin>>translateAgain;
            return 0;
        }
    
        std::cout<<"Would you like to translate another word?\n(y). yes\n(n). No\nWhat is your answer: ";
        std::cin>>translateAgain;
        
    }while(translateAgain == 'y');
    
    return 0;
}




/*------------------------FUNCTIONS-----------------------------*/


void checkFirstLetter(std::string input)
{
    char firstLetter;
    firstLetter = input.at(0);
    
    switch(firstLetter)
    {
        case 'a':
            std::cout<<"\nIn Pig Latin that word would be "<<input<<"way\n"<<std::endl;
            break;
        case 'e':
            std::cout<<"\nIn Pig Latin that word would be "<<input<<"way\n"<<std::endl;
            break;
        case 'i':
            std::cout<<"\nIn Pig Latin that word would be "<<input<<"way\n"<<std::endl;
            break;
        case 'o':
            std::cout<<"\nIn Pig Latin that word would be "<<input<<"way\n"<<std::endl;
            break;
        case 'u':
            std::cout<<"\nIn Pig Latin that word would be "<<input<<"way\n"<<std::endl;
            break;
        default:
            pigLatinify(input);
            
    }
}

/*--------*/

void checkThirdLastLetter(std::string input)
{
    char lastLetter, letter;
    std::string englishWord, restOfWord;
    lastLetter = input.length();
    letter = input.at(lastLetter-3);
    restOfWord = input.substr(0, lastLetter-3);
    
    englishWord = restOfWord;
    
    switch(letter)
    {
        case 'w':
            std::cout<<"\nIn english that word would be "<<englishWord<<std::endl;
            break;
        default:
            englishify(input);
            break;
    }
}

/*-------*/

void pigLatinify(std::string input)
{
    std::string pigLatin, restOfWord;
    std::string ayString = "ay";
    char letter, lastLetter;
    
    lastLetter = input.length();//gets the length of the string
    letter = input.at(0); // access the first letter from the string.
    restOfWord = input.substr(1, lastLetter); // takes the letters from 1 up until the last letter. so for word pony it takes 'ony' remember strings/array all start from 0.
    pigLatin = letter + ayString;//you can add two strings together.
    
    std::cout<<"\nIn Pig Latin that word would be: "<<restOfWord<<pigLatin<<std::endl<<std::endl;
}

/*----------*/

void englishify(std::string input)
{
    std::string english, restOfWord;
    char letter, lastLetter;
    
    lastLetter = input.length();
    letter = input.at((lastLetter - 3));//takes the letter that is three from last, so if it was orsehay, it takes the letter 'h'
    restOfWord = input.substr(0, lastLetter-3);//takes the rest of the word from 0 to 3, so for orsehay it takes 'orse'
    
    english = letter + restOfWord;
    
    std::cout<<"\nIn English that word would be: "<<english<<std::endl<<std::endl;
}

