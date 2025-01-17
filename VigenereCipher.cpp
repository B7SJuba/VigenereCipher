// vigenereCypher.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <string>
#include <stdio.h>
#include <windows.h>


using namespace std;

class VigCi //Vigenere Cipher
{

public:
    string k; //To hold key string
    VigCi(string k)
    {
        for (int i = 0; i < k.size(); i++) 
        {
            if (k[i] >= 'A' && k[i] <= 'Z')//to check if the inserted text is uppercase.
                this->k += k[i];

            else if (k[i] >= 'a' && k[i] <= 'z')
                this->k += k[i] + 'A' - 'a'; //replacing lowercase letters into uppercase.
        }
    }


    string encryption(string t)//encryption function
    {
       
        string output;
        for (int i = 0, j = 0; i < t.length(); i++)
        {
            char c = t[i];
            if (c >= 'a' && c <= 'z')
                c += 'A' - 'a';
            else if (c < 'A' || c>'Z')
                continue;
            output += (c + k[j] - 2 * 'A') % 26 + 'A';//Added 'A' to bring it within ASCII alphabet range [65-90 | A-Z]
            j = (j + 1) % k.length();
        }
        return output;
    }

    string decryption(string t)
    {
        string output;
        for (int i = 0, j = 0; i < t.length(); i++) 
        {
            char c = t[i];
            if (c >= 'a' && c <= 'z') //Cheking if the input encypted message is lowercase letters on uppercase again
                c += 'A' - 'a';
            else if (c < 'A' || c > 'Z')
                continue;
            output += (c - k[j] + 26) % 26 + 'A';//same reason for adding the 'A' above.
            j = (j + 1) % k.length();
        }
        return output;
    }

};


void type(string x) //An extra unnecessary function I added to make the code more fun. 
{

    for (int i = 0; i < x[i]; i++) 
    {
        cout << x[i];
        Sleep(20);
    }

}


int main()
{   

    int option;

    string input, key;
   


      type("*********************************************");cout << endl;
      type("**************Vigenère Cipher****************"); cout << endl;
      type("*********************************************");cout << endl;
    
  start:
    cout << "\nEnter 1 for encryption, 2 for decryption(0 to exit): ";
    cin >> option; 
   
    if (cin.fail()) {
        //To avoid non-int input 
        cout << "\nWrong input only 1, 2 and 0 are accepted please try again." << endl;
        cin.clear();
        cin.ignore(256, '\n');
        goto start;
    }

    if (option > 2 && option < 0)
    {
        cout << "\nWrong input only 1, 2 and 0 are accepted please try again." << endl;
        goto start;
    }
   
    else if (option == 1)
    {
        cin.ignore(); //putting a getline() after a cin would require this command from me otherwise some lines of the code won't execute.
        cout << "Enter a message to encrypt: ";
        getline(cin, input);
        
        

        cout << "Enter the Key(Same length as the your message!): ";
        getline(cin, key);
       

        VigCi v = key;
        string encrypt = v.encryption(input);
        string decrypt = v.decryption(encrypt);
      
        cout << "\nOriginal message: " << input << endl; 
        cout << "Encrypted message: " << encrypt << endl; 
        cout << "Decrypted message: " << decrypt << endl; 
        cout << "Your key: " << key << endl;
    
    }
  
    else if (option == 2)
    {

        string encrypt;
        cin.ignore();
        cout << "\nEnter the Key(Same length as the your message!): ";
        getline(cin, key);

        cout << "Enter the decrypted message: ";
        getline(cin, input);

        VigCi v = key;




        string decrypt = v.decryption(input);     
        cout << "Encrypted message: " << input << endl;
        cout << "Decrypted message: " << decrypt << endl;
        cout << "Your key: " << key << endl;

    }
    else if (option == 0) 
    {
        return 3; //To terminate the execution of the program.

    }
    goto start;
    system("PAUSE");
    return 0;
}
