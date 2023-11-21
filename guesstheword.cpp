//program for user to guess words
//goals = 1. user inputs numbers of words 2. user guesses the words 3. use dynamic memory for the user input 4. maximize function use
//goals = 5. put a brief definition for each word 6. try to randomize the output 7. try to add more words in the future
//goals = 8. place hints via word count for each word
#include<algorithm>
#include<iostream>
#include<string>
#include<ctime>
#include<cctype>
using std::string; using std::cin; using std::cout; using std::endl;

void wordPop(string *wordsize,string *wordsinput, int inputsize);
int main()
{
    srand(time(0));
    string *pWords = nullptr;
    string player_guess;
    string wordBase[10] = {"unanimous","exasperate","frolic","dynamic","listless","tremulous","humanism","volunteer","denote","observe"};
    int word_size, word_guesses;
    bool check;

    do
    {
        cout<<"Enter size of words you want to guess[min. 1 - max. 10]: ";
        cin>>word_size;
        cin.clear();
    }while(word_size<=0||word_size>=11);

    pWords = new string[word_size];

    wordPop(wordBase,pWords,word_size);

    for (int i=0;i<word_size;i++)
        cout<<i+1<<". "<<pWords[i]<<endl;
    cout<<endl;

    for (int i=0;i<word_size;i++)
    {
        cout<<"The word has "<<pWords[i].length()<<" letters and starts with "<<pWords[i].at(0)<<endl;
        cin>>player_guess;
        transform(player_guess.begin(),player_guess.end(),player_guess.begin(),tolower);
        if (player_guess==pWords[i])
        {
            cout<<"correct"<<endl;
        }

        else
            word_guesses=3;
            while (word_guesses>0&&player_guess!=pWords[i])
            {
                word_guesses--;
                cout<<"not quite correct"<<endl;
                cin>>player_guess;

                if (player_guess==pWords[i])
                    cout<<"correct"<<endl;

                if (word_guesses==0)
                    cout<<"wrong"<<endl;
            }

        if (i!=word_size-1)
            cout<<"Next word"<<endl;
    }
    cout<<endl;
    cout<<"==END OF THE GAME==";


    delete[] pWords;
    return 0;
}
void wordPop(string *wordsize,string *wordsinput, int inputsize)
{
    for (int i=0;i<inputsize;i++)
    {
        wordsinput[i] = wordsize[i];
    }
}
void randomCheck()
{

}
void wordHint(string *wordsize, int inputsize)
{

}
