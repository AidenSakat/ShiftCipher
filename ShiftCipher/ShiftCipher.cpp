// ShiftCipher.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Chapter 4 Computer Project - Aiden Sakat - C++


#include <iostream>
#include <string>

std::string Encrypt(std::string, int);
std::string Decrypt(std::string, int);
void WelcomeMessage();
void options(std::string , int );

int main()
{
    std::string message;
    int k = 0;
    // gets users message
    WelcomeMessage();
    getline(std::cin, message);
    // inputs user message and target then outputs the encryption or decryption
    options(message, k);

    return 0;
}

// welcome!!!
void WelcomeMessage()
{
    std::cout << "Welcome to the encrypted text generator!" << std::endl;
    std::cout << "Please enter a message: ";
}

// created a seperate function to make code more organized
void options(std::string message, int k)
{
    // total encrypted variable to add every encryption k together to decrypt at once
    int totalEncrypted = 0;
    char option;

    // while loop so user can encrypt as much as theyd like
    while (true) {

        std::cout << "\nWould you like to encrypt or decrypt this message or leave? (e/d/l) ";
        std::cin >> option;

        if (option == 'e' || option == 'E') {
            std::cout << "By how many letters would you like to encrypt the message? : ";
            std::cin >> k;
            // if k is greater than 26 or less than 1 will prompt user again until they input anywhere between 1-26
            while (k > 26 || k < 1) {
                std::cout << "Please enter a number between 1-26 :";
                std::cin >> k;
            }
            // adds k to totalencrypted
            totalEncrypted += k;
            // sends to Encrypt function then returns string
            message = Encrypt(message, k);
            std::cout << message;
        }

        else if (option == 'd' || option == 'D') {
            // decrypts message by taking totalencrypted the subtracts it
            std::string decrypt = Decrypt(message, totalEncrypted);
            std::cout << decrypt;
        }
        // breaks out of loop / closes app
        else if (option == 'l' || option == 'L') {
            std::cout << "\n\nGoodbye!";
            break;
        }
        // if user inputs something other than given options, will ask for input again
        else {
            std::cout << "\nPlease enter (e) for Encryption or (d) for Decryption or (l) to leave application" << std::endl;
        }
    }
}


// Function to take in string message and how much to shift with int 
std::string Encrypt(std::string message, int k)
{
    // creating new string to store the encrypted text
    std::string encryptedMessage;
    //std::string gibberish = "&*$@#%#!@^%#*&$!@^*#$^!";
    // created a character converter to store a character and increase the cipher by k
    char characterConverter;
    // for loop to loop through each character in the message and increase cipher by k * 10 instead of just one cause you get cooler characters (:
    for (auto x : message) {
        characterConverter = x + k * 10;
        encryptedMessage.push_back(characterConverter);
    }
    // returns the encrypted message
    return encryptedMessage;
}

std::string Decrypt(std::string message, int totalEncrypted)
{       

        std::string decryptedMessage;
        char characterConverter;

        // for loop that subtracts total cipher to get original message
        for (auto x : message) {
            characterConverter = x - totalEncrypted * 10;
            decryptedMessage.push_back(characterConverter);
        }
        // returns the Decrypted message
        return decryptedMessage;
}


