#include <iostream>
#include <algorithm>
#include <random>
#include <cstdlib>
using namespace std;
int main()
{
    int mode;
    int range;
    cout << "Welcome To Guess The Game" << endl
         << "Here you have to guess the number from a range depending on your game mode" << endl;
    cout << "Select the game mode " << "Enter the Number correponding to he game mode" << endl
         << "DIfficulty \t\t Range" << endl
         << "1.Easy \t\t    0-10" << endl
         << "2.Medium\t\t0-100" << endl
         << "3.Hard\t\t\t0-1000" << endl;
    cout << "If you want to give up give 1001 " << endl;
    while(true){
    cin >> mode;
        if((mode<1)||(mode>3)){
        cout<<"INVALID INPUT!!PLEASE TRY AGAIN!!"<<endl;
        
        }
        if((mode>1)||(mode<3)){
        break;}
    }
    range = pow(10, mode);
    cout << "Make a guess : ";
    int user_guess;
    int computer_generated;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, range);
    int random = dis(gen);
    while (true)
    {
        cin >> user_guess;
        if (user_guess == 1001)
        {

            cout << "YOU LOST!YOU GAVE UP!" << endl
                 << "The answer is : " << random;
            break;
        }
        if ((user_guess > range) || (user_guess < 0))
        {
            cout << "Invalid input";
            continue;
        }
        if (user_guess == random)
        {
            cout << "CONGRATULATION !!YOU WIN !!";
            break;
        }
        if (user_guess > random)
        {
            if (user_guess < random + 0.5 * range / 10)
            {
                cout << "You are much close so dont falter we know you can do it" << endl;
            }
            else if (user_guess < random + range / 10)
            {
                cout << "You are close but dont be happy you have to try harder." << endl;
            }
            else if ((user_guess < 2 * random - range / 10) && (range != 1000))
            {
                cout << "range isn't that large! You can do better ." << endl;
            }
            else if ((user_guess < 2 * random - range / 10) && (range == 1000))
            {
                cout << "range  is quite large but dont falter!" << endl;
            }
            else
            {
                if (range != 1000)
                {
                    cout << "You aren't that close for me to give you any comment " << endl;
                }
                else
                {
                    cout << "We all know that the distance in high but you dont  have need to continue " << endl;
                }
            }
            cout << "The number is less than your guess" << endl;
        }
        if (user_guess < random)
        {
            if (user_guess > random - 0.5 * range / 10)
            {
                cout << "You are much close so dont falter we know you can do it" << endl;
            }
            else if (user_guess > random - range / 10)
            {
                cout << "You are close but dont be happy you have to try harder." << endl;
            }
            else if ((user_guess > 2 * random - range / 10) && (range != 1000))
            {
                cout << "range isn't that large! You can do better ." << endl;
            }
            else if ((user_guess > 2 * random - range / 10) && (range == 1000))
            {
                cout << "range  is quite large but dont falter!" << endl;
            }
            else
            {
                if (range != 1000)
                {
                    cout << "You aren't that close for me to give you any comment " << endl;
                }
                else
                {
                    cout << "We all know that the distance in high but you dont  have need to continue " << endl;
                }
            }
            cout << "The number is more than your guess" << endl;
        }
    }
}
