#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include<vector>
#include<ctime>
#include<cctype>
using namespace std;

void Draw(int attempts, int life){
    cout << endl;
    cout << "    ----------" << endl;
    cout << "    |        |" << endl;
    cout << "    |"; if (attempts >= (life - 6)) cout << "        @        "; cout << endl;
    cout << "    |"; if (attempts >= (life - 5)) cout << "      / | \\     "; cout << endl;
    cout << "    |"; if (attempts >= (life - 4)) cout << "        |      "; cout << endl;
    cout << "    |"; if (attempts >= (life - 3)) cout << "        |      "; cout << endl;
    cout << "    |"; if (attempts >= (life - 1)) cout << "       / \\     "; cout << endl;
    cout << "    |"; cout << endl;
    cout << "    |"; cout << endl;
    cout << "    |"; cout << endl;
    cout << "    |"; cout << endl;
    cout << "    |"; cout << endl;
    cout << "    ################" << endl;

}

char letter; 


string randomWord(){
    srand(time(NULL));
    fstream file;
    file.open("words.txt");

    vector<string> words;
    words.reserve(854);
    string temp;
    while(file >> temp){
        words.push_back(temp);
    }
    file.close();
    srand(time(NULL));

    int index = rand() % words.size();
    string randWord = words[index];

    return randWord;
};

void characterGuess(string randWord, char letter, string& unknown){
    for (int i = 0; i <= randWord.length(); i++){
        if (letter == randWord[i] || letter-32 == randWord[i] || letter + 32 == randWord[i]){
            unknown[i] = randWord[i];
            //cout << randWord[i] << endl;
    }
    //cout << randWord << endl;
}
    cout << unknown << endl;
}

void start(){
    cout << "*************************\n";
    cout << "WELCOME TO EVIL HANGMAN!!\n";
    cout << "*************************\n";
}


int main(){
    start();
    string r = randomWord();
    int guesses = 0;
    int lives = r.length() + 2;
    string unknown(r.length(), '-');
    Draw(guesses, lives);
    cout << "You have " << lives << " lives to start with!\n";
    cout << "GOOD LUCK!\n";
    cout << "Word to guess: " << unknown << endl;

    bool present = false;
    bool won = false;
    string usedLetters;

    while(guesses < lives){
        present = false;
        cout << "Guess a letter: ";
        cin >> letter;
        for(int j = 0; j < usedLetters.length();j++){
            if(letter == usedLetters[j]){
                cout << "Letter already used" << endl;
                present = true;
                guesses--;
                cout << "You have " << lives - guesses << " lives left\n";
                Draw(guesses, lives);
            }
        }
        if(present == false){
            usedLetters.push_back(letter);
            cout << "You have " << lives - guesses << " lives left\n";
            Draw(guesses, lives);
        }
        cout << "used letters: " << usedLetters << " " << "\n";
        characterGuess(r,letter,unknown);
        if (unknown == r){
            cout << "YOU WON!!\n";
            won = true;
            break;
        }
        guesses++;
    } 
    if(won == false){
        cout << "You Loss: The word was " << r << "\n";
    }
    return 0; 
}