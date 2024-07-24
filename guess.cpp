#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{

  srand(static_cast<unsigned int>(time(0)));

  int randomNumber = rand() % 100 + 1;

  int guess;

  do
  {
    cout << "Enter your guess (1-100): ";
    cin >> guess;

    if (guess > randomNumber)
    {
      cout << "Too high! Try again." << endl;
    }
    else if (guess < randomNumber)
    {
      cout << "Too low! Try again." << endl;
    }
  } while (guess != randomNumber);

  cout << "Congratulations! You guessed the number: " << randomNumber << endl;

  return 0;
}
