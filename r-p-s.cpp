#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <random>
#include <algorithm>
using namespace std;
string toLower(string str)
{
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}
int main()
{
    int times;
    cout << "Enter number of matches to play" << endl;
    cout << "ODD NUMBER ONLY!"<<endl;
    
    while (true)
    {
        cin >> times;
        if (times % 2!= 0)
            break;
        cout << "ODD NUMBER ONLY!";
    }
        cout << "Starting rock-paper-scissors game" << endl;
        cout << "Enter you choices from rock/paper/scissors :  "<<endl;
    int user_count = 0;
    int computer_count = 0;
    while (times--)
    {
        cout<<"Your turn : ";
        string user_input;
        cin >> user_input;
        string outcomes[3] = {"rock", "paper", "scissors"};
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(0, 2);
        int random = dis(gen);
        string computer_input = outcomes[random];
        cout << "Computer's choice- " << computer_input<<endl;
        user_input = toLower(user_input);
        if (user_input == computer_input)
            cout << "Its a draw" << endl;
        else if ((user_input == "rock" && computer_input == "paper") || (user_input == "paper" && computer_input == "scissors") || (user_input == "scissors" && computer_input == "rock"))
        {
            cout << "Computer win" << endl;
            computer_count++;
        }
        else if ((user_input == "paper" && computer_input == "rock") || (user_input == "scissors" && computer_input == "paper") || (user_input == "rock" && computer_input == "scissors"))
        {
            cout << "You win" << endl;
            user_count++;
        }
        else
        {
            std::cout << "INVALID INPUT!";
            times++;
        }
    }
    cout << "FINAL SCORE::" << endl;
    cout << "Your score : " << user_count << endl
              << "Computer's score : " << computer_count<<endl;
    if (user_count > computer_count)
    {
        cout << "YOU WIN!!";
    }
    else if(user_count<computer_count)
    {
        cout << "YOU LOSE!!";
    }
    else{cout<<"Its is draw !!";}
return  0;
}
