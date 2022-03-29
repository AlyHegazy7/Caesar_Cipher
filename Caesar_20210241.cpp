// FCAI – Programming 1 – 2022 - Assignment 2
// Program Name: CaesarCipher.cpp
// Program Description: It is a casar cipher program
// Last Modification Date: 29/3/2022
// Author1 and ID and Group: Aly Ahmed Salah Hegazy-20210241-Group A
// Teaching Assistant: Afaf Abdelmonem
// Purpose:It was used in sending secret messages
#include <iostream>
#include <cstring>
#include <string>
#include <limits>
#include <ios>

using namespace std;

int main()
{
  int choice, nShifts;
  string message;  

  //a while that keeps looping until the user quits
  while(choice != 3){
    cout << "\nWhat do you like to do today?" << endl;
    cout << "1-Cipher a message." << endl;
    cout << "2-Decipher a message." << endl;
    cout << "3-End." << endl;
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    if(choice == 1){
        cout << "Enter the message you want to cipher." << endl;
        getline(cin, message);
        cout << "How many shifts do you want in your code?" << endl;
        cin >> nShifts;
        //a for loop that loops through the message letter by letter
        for(int i = 0; i < message.length(); i++){
          //check if the letter is from the alphabet
          if(isalpha(message[i])){
            int beginningOfAsciiLetters = 65;

            //check if the letter is lowercase letter
            if(islower(message[i])){
              beginningOfAsciiLetters = 97;
            }
            //ciphering the message according to the number of shifts the user entered
            int ciphered = (((int)message[i] - beginningOfAsciiLetters + nShifts) % 26) + beginningOfAsciiLetters;
            cout << (char)ciphered ;
          } else{
            //if the letter wasn't from the alphabet, it is printed as it is
            cout << message[i]  ;
          }
        }  
    } else if(choice == 2){
        cout << "Enter the message you want to decipher." << endl;
        getline(cin, message);
        cout << "How many shifts was used  in your code?" << endl;
        cin >> nShifts;
        // a for loop that loops through the message letter by letter
        for(int i = 0; i < message.length(); i++){
          //check if the letter is from the alphabet
          if(isalpha(message[i])){
            int beginningOfAsciiLetters = 65;
            
            //check if the letter is lowercase letter
            if(islower(message[i])){
              beginningOfAsciiLetters = 97;
            }
            //deciphering the message according to the number of shifts that was used
            int ciphered = (((int)message[i] - beginningOfAsciiLetters - nShifts) % 26) + beginningOfAsciiLetters;
            cout << (char)ciphered ;
          } else{
            //if the letter wasn't from the alphabet, it is printed as it is
            cout << message[i]  ;
          }
        }
    } else if(choice == 3){
        //if the user chooses the choice 3, he quits the program
        break;
    } else{
        cout << "Please enter a number from the choices." << endl;
    }
  }
    return 0;
}
