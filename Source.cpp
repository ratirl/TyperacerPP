#include <iostream>
#include <string>
#include <random>    //https://en.cppreference.com/w/cpp/header/random
#include <windows.h> 

using namespace std;

int main()
{
    // Array with a few predetermined random sentences
    string sentences[] = {
        "The quick brown fox jumps over the lazy dog.",
        "Tomorrow is another day.",
        "Coding is fun and challenging.",
        "Life is like a box of chocolates.",
        "Keep calm and carry on.",
        "To be or not to be, that is the question.",
        "All that glitters is not gold.",
        "A journey of a thousand miles begins with a single step.",
        "Actions speak louder than words.",
        "Fortune favors the bold.",
        "The early bird catches the worm.",
        "Beauty is in the eye of the beholder."};

    // Size of whole array in bytes / size of first item in array = size of array
    int num_sentences = sizeof(sentences) / sizeof(sentences[0]);

    // Create a random device + generator and then seed the generator
    random_device seed;
    mt19937 gen(seed());
    uniform_int_distribution<> dist(0, num_sentences - 1); // Setting min and max aka uniform distribution of all the items
                                                           // so that each item has the same chance to be picked

    char play_again = 'y';

    while (play_again == 'y' || play_again == 'Y')
    {

        // Create the random index finally
        int random_index = dist(gen);
        string target_sentence = sentences[random_index];

        cout << "Welcome to TyperacerPP!" << endl
             << endl;
        cout << "Type the following sentence: " << endl;
        cout << "Random sentence: " << target_sentence << endl;

        // Ask user to type the sentence
        string user_input;
        cout << "Your input: ";
        getline(cin, user_input);

        // Check if the input matches the target sentence
        if (user_input == target_sentence)
        {
            cout << "Correct!" << endl;
        }
        else
        {
            cout << "Sorry, try again... it's not completely correct." << endl;
        }

        // Ask if the user wants to try again
        cout << "Do you want to try again? (y/n): ";
        cin >> play_again;
        cin.ignore(); // Ignore remaining newline character
        system("cls");
    }

    // End of program message
    cout << "Thank you for playing TyperacerPP! Goodbye." << endl;

    return 0;
}
