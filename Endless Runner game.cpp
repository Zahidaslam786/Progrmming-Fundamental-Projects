


#include<iostream>
#include<string>
#include<iomanip>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<windows.h>
using namespace std;
//Declaring  variables Globally.
const int maxlength = 30, maxheight = 30;
const int maxDistance = 150;
char Map[maxheight][maxlength];
bool gameover = false;
int live = 3, Coins = 0, Score = 0, Distance = 0;
int length = maxlength;
int height = maxheight;

//This is a Position of Player
int x_Player = height - 4;
int y_Player = length / 2;
void InitializeMAP()
{

for (int i = 0; i < height; i++)
{
for (int j = 0; j < length; j++)
{
if (j == 0 || j == length - 1)
{
Map[i][j] = '#';
}
else
{
Map[i][j] = ' ';
}
}
}
}

void PrintMap()
{

system("cls");
for (int i = 0; i < height; i++)
{
for (int j = 0; j < length; j++)
{

Map[x_Player][y_Player] = '/';
Map[x_Player][y_Player + 1] = '^';
Map[x_Player][y_Player + 2] = '\\';
//Distanceplay Boarder

if (Map[i][j] == '0')
{
printf("\033[1;34m");
cout << Map[i][j];
}
else if (Map[i][j] == 'x')
{
printf("\033[1;31m");
cout << Map[i][j];
}
else if (Map[i][j] == '#')
{
printf("\033[1;33m");
cout << Map[i][j];
}
else
{
printf("\033[0;37m");
cout << Map[i][j];
}


}
cout << endl;
}
//printf("\033[1;31m");
printf("\033[0;32m");
printf("\033[1m");
cout << "\n\n\tDistanceTANCE COVERD: " << Distance << "m";
printf("\033[1;31m");
cout << "\n\tCoins COLLECTED: " << Coins;
printf("\033[1;34m");
cout << "\n\tYOUR SCORE: " << Score;

}
void PlayerMovement()
{
Distance++;
switch (GetKeyState('A'))
{
case 0:
case 1:
break;
default:
int Newy_Player = y_Player - 1;
if (Newy_Player < length - 1 && Newy_Player > 0)
{
Map[x_Player][y_Player] = ' ';
Map[x_Player][y_Player + 1] = ' ';
Map[x_Player][y_Player + 2] = ' '; // Erase old position
y_Player = Newy_Player; // update player New position
// draw new position
Map[x_Player][y_Player] = '/';
Map[x_Player][y_Player + 1] = '^';
Map[x_Player][y_Player + 2] = '\\';
}
else
{//player hitawg the wall
live--;
if (live > 0)
{
Map[x_Player][y_Player] = ' ';
Map[x_Player][y_Player + 1] = ' ';
Map[x_Player][y_Player + 2] = ' ';
x_Player = height - 4;
y_Player = length / 2;
Map[x_Player][y_Player] = '/';
Map[x_Player][y_Player + 1] = '^';
Map[x_Player][y_Player + 2] = '\\';
}
else
{
gameover = true;
}
}
break;
}

switch (GetKeyState('D'))
{
case 0:
case 1:
break;
default:
int Newy_Player = y_Player + 1;
int Check = y_Player + 3;
if (Check < length - 1 && Check > 0)
{
Map[x_Player][y_Player] = ' ';
Map[x_Player][y_Player + 1] = ' ';
Map[x_Player][y_Player + 2] = ' '; // Erase old position
y_Player = Newy_Player; // update player New position
Map[x_Player][y_Player] = '/';
Map[x_Player][y_Player + 1] = '^';
Map[x_Player][y_Player + 2] = '\\'; // draw new position
}
else
{
live--;
if (live > 0)
{
//set new position
Map[x_Player][y_Player] = ' ';
Map[x_Player][y_Player + 1] = ' ';
Map[x_Player][y_Player + 2] = ' ';
x_Player = height - 4;
y_Player = length / 2;
Map[x_Player][y_Player] = '/';
Map[x_Player][y_Player + 1] = '^';
Map[x_Player][y_Player + 2] = '\\';
}
else
{
gameover = true;
}
}
break;
}

switch (GetKeyState('W'))
{
case 0:
case 1:
break;
default:
int Newx_Player = x_Player - 1;
if (Newx_Player > 0 && Newx_Player < height - 1)
{
Map[x_Player][y_Player] = ' ';
Map[x_Player][y_Player + 1] = ' ';
Map[x_Player][y_Player + 2] = ' ';
x_Player = Newx_Player;
Map[x_Player][y_Player] = '/';
Map[x_Player][y_Player + 1] = '^';
Map[x_Player][y_Player + 2] = '\\';
}
}
switch (GetKeyState('S'))
{
case 0:
case 1:
break;
default:
int Newx_Player = x_Player + 1;
if (Newx_Player < height - 1 && Newx_Player > 0)
{
Map[x_Player][y_Player] = ' ';
Map[x_Player][y_Player + 1] = ' ';
Map[x_Player][y_Player + 2] = ' ';
x_Player = Newx_Player;
Map[x_Player][y_Player] = '/';
Map[x_Player][y_Player + 1] = '^';
Map[x_Player][y_Player + 2] = '\\';
}
}
//Jumping Upward
if (GetAsyncKeyState(32))
{
int Newx_Player = x_Player - 5;
if (Newx_Player < height - 1 && Newx_Player > 0)
{
Map[x_Player][y_Player] = ' ';
Map[x_Player][y_Player + 1] = ' ';
Map[x_Player][y_Player + 2] = ' ';
x_Player = Newx_Player;
Map[x_Player][y_Player] = '/';
Map[x_Player][y_Player + 1] = '^';
Map[x_Player][y_Player + 2] = '\\';
}
}
//Jumped Downward
if (GetAsyncKeyState(16))
{
int Newx_Player = x_Player + 5;
if (Newx_Player < height - 1 && Newx_Player > 0)
{
Map[x_Player][y_Player] = ' ';
Map[x_Player][y_Player + 1] = ' ';
Map[x_Player][y_Player + 2] = ' ';
x_Player = Newx_Player;
Map[x_Player][y_Player] = '/';
Map[x_Player][y_Player + 1] = '^';
Map[x_Player][y_Player + 2] = '\\';
}
}

}

void Coin()
{
if (Distance % 10 == 0)
{
int y_coin = rand() % (length - 1);
//printf("\033[1;34m");
Map[0][y_coin] = '0';
//printf("\033[0;32m");
}
else if (Distance >= maxDistance)
{
//increase Coins if Distance is max
int x_coin = rand() % height / 4;
int y_coin = rand() % (length - 2) + 1;
Map[x_coin][y_coin] = '0';
}

for (int i = height - 1; i >= 0; i--)
{
for (int j = 1; j < length - 1; j++)//In Last Row remove all coins
{
if (Map[height - 1][j] == '0')
{
Map[i][j] = ' ';
}
else if (Map[i][j] == '0')
{
Map[i][j] = ' '; //erase Previous coin
Map[i + 1][j] = '0';
}
}
}
//After colision coin score count
if (Map[x_Player][y_Player] == '0' || Map[x_Player][y_Player + 1] == '0' || Map[x_Player][y_Player + 2] == '0')
{
Coins++;
Map[x_Player][y_Player] = ' ';
Map[x_Player][y_Player + 1] = ' ';
Map[x_Player][y_Player + 2] = ' ';
Score += 10;
}
}

void Obstacles()
{
if (Distance % 10 == 0)
{
int y_obstacle = rand() % length - 1;
//printf("\033[1;31m");
Map[0][y_obstacle] = 'x';
//system("color 0");
//printf("\033[0;32m");

}

//Obstacle Movement increase if dis is maximum
else if (Distance >= maxDistance)
{
int x_obstacle = rand() % height / 4;
int y_obstacle = rand() % (length - 2) + 1;
//printf("\033[1;31m");
Map[x_obstacle][y_obstacle] = 'x';
//printf("\033[0;32m"); //system("color 0");
}
//obstacle Movement
for (int i = height - 1; i >= 0; i--)
{
for (int j = 1; j < length - 1; j++)
{
if (Map[height - 1][j] == 'x')//In last row remove all chracter
{
Map[i][j] = ' ';
}
else if (Map[i][j] == 'x')
{
Map[i][j] = ' ';
printf("\033[1;31m");
Map[i + 1][j] = 'x';
printf("\033[0;32m");//system("color 0");
}
}
}
//Collision between player and obstacle 1 live loss
if (Map[x_Player][y_Player] == 'x' || Map[x_Player][y_Player + 1] == 'x' || Map[x_Player][y_Player + 2] == 'x')
{
live--;
if (live > 0)
{
//set new position(middle)
Map[x_Player][y_Player] = ' ';
Map[x_Player][y_Player + 1] = ' ';
Map[x_Player][y_Player + 2] = ' ';
y_Player = length / 2;
x_Player = height - 3;
Map[x_Player][y_Player] = '|';
Map[x_Player][y_Player + 1] = '^';
Map[x_Player][y_Player + 2] = '|';
}
else
{
gameover = true;
}
}
printf("\033[1;37m");
cout << "\n\tLive : " << live << endl;
}
void Instruction()
{
//system("color 0");
printf("\033[1;97m");
cout << setw(80) << "These are Game Instruction. You should follow" << endl;
cout << setw(72) << "These Instruction while playing game." << endl;
cout << setw(67) << "     Otherwise your game will be over" << endl << endl;
cout << setw(87) << "RULE NO 1;_   You have only three lives in your hand" << endl;
cout << setw(86) << "RULE NO 2:_    For Movement you should use A,S,D,W " << endl;
cout << setw(65) << "||A For left ||" << endl;
cout << setw(65) << "||D For Right||" << endl;
cout << setw(65) << "||S For Down ||" << endl;
cout << setw(65) << "||W For Up   ||" << endl;
cout << setw(88) << "RULE NO 3:_  For Jumping (Up and Down) you should use" << endl;
cout << setw(55) << "These two Button" << endl;
cout << setw(51) << "\t\t\t||Space for UP  ||" << endl;
cout << setw(55) << " \t\t||Shift for down||" << endl;
cout << setw(89) << "RULE NO 4:_  You are Restricted for input anyother key" << endl;
cout << setw(60) << "excep those are Allowed" << endl << endl;
cout << setw(70) << "\t||That it's.  THANKYOU||" << endl;
system("pause");
system("cls");
}
void Endgame()
{
system("color 0");
cout << endl << endl << endl << endl << endl;
printf("\033[1;92m");
cout << setw(75) << "Instuction for Endgame" << endl;
cout << setw(94) << " ||You die only when you hit obstacles or Borders of game||" << endl;
cout << setw(95) << " ||When your lives reach to zero your game will end      || " << endl;
cout << setw(73) << "||That it's.  THANKYOU||" << endl;
system("pause");
system("cls");
}
void PlayerID(string Name)
{
system("color 0");
bool check = true;
int ID;
srand(time(0));
ID = rand() % 10000;
cout << endl << endl << endl << endl;
printf("\033[1;93m");
cout << setw(62) << " Welcome In game" << endl;
cout << setw(71) << "We Hope You Will Enjoy This Game" << endl << endl;
cout << setw(60) << "||Your Name is : " << Name << "||" << endl << endl;
cout << setw(60) << " ||Your ID is : " << ID << "||" << endl;
Sleep(2000);
system("cls");
}
void UserData(string Name)
{
PlayerID(Name);
system("cls");
cout << endl << endl << endl << endl << endl;
printf("\033[1;95m");
cout << setw(67) << "BE READY TO PLAY" << endl;
Sleep(1500);
cout << setw(68) << " ENDLESS RUNNER GAME" << endl;
Sleep(2000);
system("cls");
//system("pause");
}
void Speed()
{
if (Distance >= 500)
{
Sleep(100);
}
else if (Distance >= 400)
{
Sleep(150);
}
else if (Distance >= 300)
{
Sleep(200);
}
else if (Distance >= 200)
{

Sleep(250);
}
else if (Distance >= 100)
{
Sleep(300);
}
else if (Distance < 100)
{
Sleep(400);
}
}
void readdata()
{
////Read the game data to a File
ifstream infile;
infile.open("game.txt");
printf("\033[1;94m");
cout << "\nThe File Contains:" << endl;
while (infile)
{
string data;
getline(infile, data);
cout << data << endl;
}
infile.close();
}
void StartGame(string Name)
{
int Choice;
//bool Check1 = true;
printf("\033[1;90m");
cout << endl << endl << endl << endl << endl;

bool Check = true;
// Input validation loop
do {
cout << setw(76) << "Enter your choice where you want to go" << endl;
cout << setw(65) << " 1:_ for Instruction" << endl;
cout << setw(76) << "2:_ for Instruction of Endgame" << endl;
cout << setw(73) << " 3:_ for Readdata from file " << endl;
cout << "\t\t\t\t\t\t";
cin >> Choice;
if (Choice == 1 || Choice == 2 || Choice == 3)
{
Check = false;
break;
}
else
{
cout << setw(80) << "Invalid input. Please enter 1, 2, or 3: ";
cin.clear();
cin.ignore(10000, '\n');
system("cls");
}
} while (Check);

system("cls");
if (Choice == 1)
Instruction();
else if (Choice == 2)
Endgame();
else if (Choice == 3)
readdata();
system("pause");
system("cls");
}
void YourProgress(string Name)
{
ofstream outfile;
outfile.open("game.txt", ios::app);
outfile << endl << endl << endl << endl;
outfile << setw(42) << "\t\t" << Name << "'s  Progress:" << endl;
outfile << setw(70) << "Total Distancetance Cover: " << Distance << endl;
outfile << setw(71) << "Total Coins Collect: " << Coins << endl;
outfile << setw(65) << "Total Score: " << Score << endl;
outfile.close();

cout << endl << endl << endl << endl << endl;
printf("\033[1;36m");
cout << setw(64) << "|| Gave over!" << endl;
cout << setw(64) << "|| Live left:" << live << endl;
cout << setw(75) << "|| Total Distance Cover:" << Distance << endl;
cout << setw(74) << "|| Total Coins Collect:" << Coins << endl;
cout << setw(67) << "|| Total Score: " << Score << endl;
cout << endl;
system("pause");
}

void Gameover()
{
while (!gameover)
{
PrintMap();
PlayerMovement();
Coin();
Obstacles();
//Computer();
Speed();
}

}

void SignIn()
{
cout << endl;
printf("\033[1;37m");
string UserName = "zahid";
string Password = "3394";
string username, password;
bool check = true;
cout << endl << endl << endl << endl;
while (check)
{

cout << setw(65) << "Enter UseName and Password" << endl;
cout << setw(48) << "USERNAME" << "   ";
getline(cin, username);
cout << setw(48) << "PASSWORD" << "   ";
getline(cin, password);
if (UserName == username && Password == password)
check = false;
else
{
system("cls");
cout << endl << endl << endl << endl;
cout << setw(65) << "Invalid UserName or Password" << endl;
}
}
system("cls");

}

void OverView()
{
cout << endl << endl << endl << endl << endl;
printf("\033[1;37m");
cout << setw(74) << "||   HERE IS OWERVIEW OF GAME   ||" << endl;
cout << endl;
cout << setw(74) << "||This is an endless runner game||" << endl;
cout << setw(74) << "||Several functions are used in ||" << endl;
cout << setw(74) << "||in this game . File handling  ||" << endl;
cout << setw(74) << "||also included for store data  ||" << endl;
cout << setw(67) << "||permanently.||" << endl;
cout << setw(74) << "||Total 17 Functions are used   ||" << endl;
Sleep(4000);
system("cls");
}

void Name(string Name)
{
system("cls");
UserData(Name);
OverView();
StartGame(Name);
InitializeMAP();
Gameover();
system("cls");
system("color 0");
YourProgress(Name);
}

int main()
{
SignIn();
string name;
cout << endl << endl << endl << endl;
printf("\033[1;35m");
cout << setw(65) << "Enter Your Name:" << endl;
cout << "\t\t\t\t\t\t ";
getline(cin, name);
//system("color 0");
Name(name);

system("pause");
return 0;
}
