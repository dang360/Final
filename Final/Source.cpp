#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <future>
using namespace std;

bool cond = 0, cond2 = 0, cond3 = 0;
bool crowbar = 0, taser = 0, Knife = 0;

bool cabinet = 0, code = 0;

bool keyDang = 0, key2 = 0, key3 = 0;

int passCode = 0;

bool Yes = 0;

bool computer = 0, pda = 0;

bool timeLoss = 0;

int wobbly = 5;

void nuGame();
void controls();
void timer();

void abandonedRoom();

void hall1SKev();
void hall1N();
void hall1WAlex();
void hall1E();

void cafe();
void medBay();

void rm1();
void rm2();
void rm3();
void rm4();

void engineRm();
void weaponsRm();
void commsRm();

void bridge();
void bridgeKeys();

void endGame();

int main()
{
	char menuChoice;

	cout << "Welcome to our Adventure Game! \n"; //need a name
	cout << "Would you like to: \n";
	cout << "\t 1. Start a New Game\n";
	cout << "\t 2. Look at the Game Controls\n";
	cout << "\t 3. Quit \n";
	cout << "Please choose between options 1, 2, and 3. \n";
	cin >> menuChoice;
	switch (menuChoice)
	{
	case '1':
		nuGame();

		break;
	case '2':
		controls();
		break;
	case '3':
		exit(0);
	default:
		cout << "Please choose between options 1, 2, and 3. \n \n";
		main();
		break;
	}

	return 0;
}

void nuGame() //function to start a new game, can't be void
{
	string name;

	cout << "Starting a New Game. \n";
	cout << "Please enter the name you'd like to be called. \n"; //name
	cin.ignore();
	getline(cin, name);

	cout << "\nThis game does not save at any point. Good Luck " << name << endl;

	abandonedRoom();

}

void controls() //function to show the various controls
{
	char next;

	cout << "Press L to look around the area. \n";
	cout << "\t After pressing 'L', the game will tell you what's in the room. \n \n";

	cout << "Press N, S, E, or W to head in the \n respective North, South, East, or West direction. \n";
	cout << "\t After pressing 'N', you would head through the door to the N but \n if there isn't a door";
	cout << " the game will tell you there's nothing to pass through there. \n \n";

	cout << "Press G to interact with the environment around you. \n";
	cout << "\t After pressing 'G', the game will ask you what you want to pick up. \n";
	cout << "\t At this point, you can type in 'crowbar' for example, and the crowbar will be added to your inventory. \n \n";
	cout << "\t Typing in 'lightswitch', would for instance flip the lightswitch. \n";

	cout << "Press I to show your Inventory. \n";

	cout << "Press M to return to the Main Menu. \n \n";

	cout << "Press Q to Quit. \n \n";

	cout << "Press any key and hit enter to return to the main menu. \n";
	cin >> next;
	cout << " \n";
	main();
}

void timer() { //function for the background timer
	for (wobbly; wobbly > 2; --wobbly)
	{
		this_thread::sleep_for(chrono::minutes(1));
	}
	cout << "You've got two minutes left! \n";
	for (wobbly = 120; wobbly != 0; --wobbly)
	{
		this_thread::sleep_for(chrono::seconds(1));
	}
	timeLoss = 1;
	endGame();
}

void abandonedRoom()
{
	char move;
	string pickup;

	auto future = std::async(timer);

	if (cond2 == 0)
	{
		cout << "\n \nYou wake up to a blaring alarm and red flashing lights. \n";
		cout << "You appear to be on the floor. \n";
		cout << "As you stand up, you see a door in front of you.\n";
		cout << "All of a sudden, a robotic, female voice comes on the speaker system 'Captain required on bridge prior to collision.' \n";
	}
	cond2 = 1;

	do
	{
		cout << "What do you want to do? \n";
		cin >> move;
		switch (move)
		{
		case 'L':
		case 'l':
			if (crowbar == 0)
				cout << "As you look around, you notice a crowbar in the corner of the room. \n";
			else
				cout << "The room is pretty bare with some shelves to your left, and the flashing red lights. \n You have already picked up the crowbar. \n";
			break;
		case 'N':
		case 'n':
		{
			if (crowbar == 0)
				cout << "You try to open the door, but it won't budge. \n";
			else
			{
				cout << "You used the crowbar to pry open the door and walked through. \n";
				hall1SKev();
			}
			break;
		}
		case 'S':
		case 's':
			cout << "There's some shelves there but no door. \n";
			break;
		case 'W':
		case 'w':
			cout << "Push as you might. The wall seems solid. \n";
			break;
		case 'E':
		case 'e':
			cout << "There's a wall there. You can't walk through walls. \n";
			break;
		case 'G':
		case 'g':
			cout << "What would you like to pick up? \n";
			cin.ignore();
			getline(cin, pickup);
			if (pickup == "Crowbar" || pickup == "crowbar")
			{
				crowbar = 1;
				cout << "You've picked up the crowbar. It has been added to your inventory. \n";
			}
			else
				cout << "That's not here. \n";
			break;
		case 'I':
		case 'i':
					cout << "You're carrying: \n";
				if (crowbar == 1)
						cout << "The crowbar \n";
				if (taser == 1)
						cout << "The taser \n";
				if (Knife == 1)
					cout << "The knife \n";
				if (code == 1)
						cout << "The code in the diary: '1CqM2MvB3EoR' \n";
				if (keyDang == 1)
						cout << "The First Key \n";
				if (key2 == 1)
						cout << "The Second Key \n";
				if (key3 == 1)
						cout << "The Third Key \n";
				if (Yes == 1)
						cout << "The alien object \n";
				if (pda == 1)
						cout << "The PDA \n";
			break;
		case 'p':
		case 'P':
			if (pda == 1)
			{
				cout << "You are in good health. \n";
				if (wobbly > 2)
					cout << wobbly << " minutes \n";
				else
					cout << wobbly << " minute remaining. Please hurry!\n";
				break;
			}
			else
				cout << "Did not recognize that command. Please try something else. \n";
			break;
		case 'M':
		case 'm':
			main();
		case 'Q':
		case 'q':
			exit(0);
		default:
			cout << "Did not recognize that command. Please try something else. \n";
		}

	} while (cond != 1);

}

void hall1SKev()
{
	char move;
	char move2;

	cout << "\nYou moved into the hallway after breaking open the door. \n";
	cout << "There are four rooms in front of you. \n";
	cout << "And a hallway to the west and east sides. \n \n";
	cout << "A small sign in between the doors identifies the doors as Crew Quarters. \n";
	cout << "The sign also says Bridge, Comms Room, and Weapons Room to the West and Engine Room to the East. \n";
	do {
		cout << "What do you want to do? \n";
		cin >> move;

		switch (move)
		{
		case 'L':
		case 'l':
			cout << "It's an empty hallway, with a doors in front of you and a sign. \n";
			cout << "The small sign identifies the doors as Crew Quarters. \n";
			cout << "And the sign also reads Bridge, Comms Room, and Weapons Room to the West and Engine Room to the East. \n";
			break;
		case 'N':
		case 'n':
			cout << "\nThere are 4 rooms. \n";
			cout << "Which room did you want to go into? Choose between 1-4. \n";
			cin >> move2;
			switch (move2)
			{
			case '1':
				rm1(); //syed
				break;
			case '2':
				rm2(); //syed
				break;
			case '3':
				rm3(); //kevin
				break;
			case '4': //alex
				rm4();
				break;
			default:
				cout << "Didn't understand your command. \n";
			}
			break;
		case 'S':
		case 's':
			cout << "\nYou head back to the closet you broke out of. \n";
			abandonedRoom();
			break;
		case 'W':
		case 'w':
			cout << "\nYou head to the West door. \n";
			hall1WAlex();
			break;
		case 'e':
		case 'E':
			cout << "\nYou head to the East door. \n";
			hall1E();
			break;
		case 'G':
		case 'g':
			cout << "\nThere is nothing to pick up here. \n";
			break;
		case 'I':
		case 'i':
			cout << "You're carrying: \n";
			if (crowbar == 1)
				cout << "The crowbar \n";
			if (taser == 1)
				cout << "The taser \n";
			if (Knife == 1)
				cout << "The knife \n";
			if (code == 1)
				cout << "The code in the diary: '1CqM2MvB3EoR' \n";
			if (keyDang == 1)
				cout << "The First Key \n";
			if (key2 == 1)
				cout << "The Second Key \n";
			if (key3 == 1)
				cout << "The Third Key \n";
			if (Yes == 1)
				cout << "The alien object \n";
			if (pda == 1)
				cout << "The PDA \n";
			break;
		case 'p':
		case 'P':
			if (pda == 1)
			{
				cout << "You are in good health. \n";
				if (wobbly > 1)
					cout << wobbly << " minutes \n";
				else
					cout << wobbly << " minute remaining. Please hurry!\n";
				break;
			}
			else
				cout << "Did not recognize that command. Please try something else. \n";
			break;
		case 'M':
		case 'm':
			main();
		case 'Q':
		case 'q':
			exit(0);
		default:
			cout << "Did not recognize that command. Please try something else. \n";
		}
	} while (cond != 1);
}

void hall1WAlex()
{
	char move;
	char move2;

	cout << "\nYou move into the West hallway. \n";
	cout << "Behind you is the South Hallway. \n";
	cout << "Up ahead is the North Hallway. \n";
	cout << "There are two doors to the West named Weapons Room and Communications Room. \n";
	cout << "There is a sign between the doors that reads 'Bridge past Weapons and Communications Room. \n";

	do {
		cout << "What do you want to do? \n";
		cin >> move;
		switch (move)
		{
		case 'L':
		case 'l':
			cout << " There are two doors to the West and hallway entrances on either side of the hallways.\n";
			cout << "The entrance to the cafeteria is to the East. \n";
			break;
		case 'N':
		case 'n':
			cout << " You head to the North Hallway.\n";
			hall1N();
			break;
		case 'S':
		case 's':
			cout << " You head back to the South Hallway.\n";
			hall1SKev();
			break;
		case 'W':
		case 'w':
			cout << "There are 2 doors. \n";
			cout << "Which room did you want to go into? Choose between C for the Comms Room and W for the Weapons Room. \n";
			cin >> move2;
			switch (move2)
			{
			case 'c':
			case 'C':
				commsRm();
				break;
			case 'w':
			case 'W':
				weaponsRm();
				break;
			case 'M':
			case 'm':
				main();
			case 'Q':
			case 'q':
				return;
			default:
				cout << "Didn't understand your command. \n";
			}
			break;

			break;
		case 'E':
		case 'e':
			cout << "You walk into the Cafeteria. \n";
			cafe();
			break;
		case 'G':
		case 'g':
			cout << "There is nothing to pick up here. \n";
			break;
		case 'I':
		case 'i':
			cout << "You're carrying: \n";
			if (crowbar == 1)
				cout << "The crowbar \n";
			if (taser == 1)
				cout << "The taser \n";
			if (Knife == 1)
				cout << "The knife \n";
			if (code == 1)
				cout << "The code in the diary: '1CqM2MvB3EoR' \n";
			if (keyDang == 1)
				cout << "The First Key \n";
			if (key2 == 1)
				cout << "The Second Key \n";
			if (key3 == 1)
				cout << "The Third Key \n";
			if (Yes == 1)
				cout << "The alien object \n";
			if (pda == 1)
				cout << "The PDA \n";
			break;
		case 'p':
		case 'P':
			if (pda == 1)
			{
				cout << "You are in good health. \n";
				if (wobbly > 1)
					cout << wobbly << " minutes \n";
				else
					cout << wobbly << " minute remaining. Please hurry!\n";
				break;
			}
			else
				cout << "Did not recognize that command. Please try something else. \n";
			break;
		case 'M':
		case 'm':
			main();
		case 'Q':
		case 'q':
			exit(0);
		default:
			cout << "Did not recognize that command. Please try something else. \n";
		}
	} while (cond != 1);
}

void hall1E()
{
	char move;
	string pickup;

	cout << "\nYou've come to the East Hallway. \n";
	cout << "There are hallways at each end of the hall. \n";
	cout << "The entrance to the medBay is to the West. \n";
	cout << "And the entrance to the Engine Room is to the East. \n";

	do
	{
		cout << "What do you want to do? \n";
		cin >> move;
		switch (move)
		{
		case 'L':
		case 'l':
			cout << "The entrance to the Engine Room is here, to the East. \n";
			cout << "The Med Bay is to the West. \n";
			break;
		case 'N':
		case 'n':
			cout << "You move into the North Hallway. \n";
			hall1N();
			break;
		case 'S':
		case 's':
			cout << "You return to the South Hallway.\n";
			hall1SKev();
			break;
		case 'W':
		case 'w':
			cout << "You walk into the Med Bay. \n";
			medBay();
			break;
		case 'e':
		case 'E':
			cout << "You move into the Engine Room. \n";
			engineRm();
			break;
		case 'G':
		case 'g':
			cout << "There isn't anything to grab here. ";
			break;
		case 'I':
		case 'i':
			cout << "You're carrying: \n";
			if (crowbar == 1)
				cout << "The crowbar \n";
			if (taser == 1)
				cout << "The taser \n";
			if (Knife == 1)
				cout << "The knife \n";
			if (code == 1)
				cout << "The code in the diary: '1CqM2MvB3EoR' \n";
			if (keyDang == 1)
				cout << "The First Key \n";
			if (key2 == 1)
				cout << "The Second Key \n";
			if (key3 == 1)
				cout << "The Third Key \n";
			if (Yes == 1)
				cout << "The alien object \n";
			if (pda == 1)
				cout << "The PDA \n";
			break;
		case 'p':
		case 'P':
			if (pda == 1)
			{
				cout << "You are in good health. \n";
				if (wobbly > 1)
					cout << wobbly << " minutes \n";
				else
					cout << wobbly << " minute remaining. Please hurry!\n";
				break;
			}
			else
				cout << "Did not recognize that command. Please try something else. \n";
			break;
		case 'M':
		case 'm':
			main();
		case 'Q':
		case 'q':
			exit(0);
		default:
			cout << "Did not recognize that command. Please try something else. \n";
		}

	} while (cond != 1);
}

void hall1N()
{
	char move;
	char move2;
	string pickup;

	cout << "You moved into the North Hallway. \n";
	cout << "There are two doors to the South. One is marked as Cafeteria and the other as Med Bay. \n";
	cout << "There are also hallways to the West and East . \n";
	cout << "A sign between the doors again reads 'Bridge to the West. Engine Room to the East' ";
	do {
		cout << "What do you want to do? \n";
		cin >> move;
		switch (move)
		{
		case 'L':
		case 'l':
			cout << "After looking around, you notice an airlock at the North side of the hallway. \n";
			break;
		case 'N':
		case 'n':
			cout << "You enter the airlock.\n";
			cout << "Nothing here yet.\n";
			//airLock();
			break;
		case 'S':
		case 's':
			cout << "There are 2 rooms.\n";
			cout << "Which room did you want to go into? Enter C for the Cafeteria and M for the Med Bay.";
			cin >> move2;
			switch (move2)
			{
			case 'c':
			case 'C':
				cafe();
				break;
			case 'm':
			case 'M':
				medBay();
				break;
			default:
				cout << "Didn't understand your command.\n";
			}
			break;
			break;
		case 'W':
		case 'w':
			cout << "You head towards the West Hallway. \n";
			hall1WAlex();
			break;
		case 'e':
		case 'E':
			cout << "You head towards the East Hallway. \n";
			hall1E();
			break;
		case 'G':
		case 'g':
			cout << "There is nothing to pick up here. \n";
			break;
		case 'I':
		case 'i':
			cout << "You're carrying: \n";
			if (crowbar == 1)
				cout << "The crowbar \n";
			if (taser == 1)
				cout << "The taser \n";
			if (Knife == 1)
				cout << "The knife \n";
			if (code == 1)
				cout << "The code in the diary: '1CqM2MvB3EoR' \n";
			if (keyDang == 1)
				cout << "The First Key \n";
			if (key2 == 1)
				cout << "The Second Key \n";
			if (key3 == 1)
				cout << "The Third Key \n";
			if (Yes == 1)
				cout << "The alien object \n";
			if (pda == 1)
				cout << "The PDA \n";
			break;
		case 'p':
		case 'P':
			if (pda == 1)
			{
				cout << "You are in good health. \n";
				if (wobbly > 1)
					cout << wobbly << " minutes \n";
				else
					cout << wobbly << " minute remaining. Please hurry!\n";
				break;
			}
			else
				cout << "Did not recognize that command. Please try something else. \n";
			break;
		case 'M':
		case 'm':
			main();
		case 'Q':
		case 'q':
			exit(0);
		default:
			cout << "Did not recognize that command. Please try something else. \n";
		}

	} while (cond != 1);
}

void cafe()
{
	char move;
	string pickup;
	cout << "You enter the cafeteria of the ship. \n";

	do {
		cout << "What do you want to do? \n";
		cin >> move;
		switch (move)
		{
		case 'L':
		case 'l':
			cout << "You look around and it seems to be a normal cafeteria just more advanced than what you're used too. \n";
			cout << "You also see different kitchen utensils inlcuding a knife.\n";
			break;
		case 'N':
		case 'n':
			cout << "You head up to the North Hallway \n";
			hall1N();
			break;
		case 'S':
		case 's':
			cout << "That there's a wall. \n";
			break;
		case 'W':
		case 'w':
			cout << "You go to the West Hallway. \n";
			hall1WAlex();
			break;
		case 'e':
		case 'E':
			cout << "Sorry, you can't walk through walls. Yet. \n";
			break;
		case 'G':
		case 'g':
			cout << "What would you like to pick up? \n";
			cin.ignore(); //ignores other things that were typed before here
			getline(cin, pickup); //so this only accepts stuff after the line
			if (pickup == "Knife" || pickup == "knife") //two spellings in case the user doesn't want to use capital letters
			{
				Knife = 1;
				cout << "You've picked up the Knife. It has been added to your inventory. \n";
			}
			else
				cout << "That's not here. \n";
			break;
		case 'I':
		case 'i':
			cout << "You're carrying: \n";
			if (crowbar == 1)
				cout << "The crowbar \n";
			if (taser == 1)
				cout << "The taser \n";
			if (Knife == 1)
				cout << "The knife \n";
			if (code == 1)
				cout << "The code in the diary: '1CqM2MvB3EoR' \n";
			if (keyDang == 1)
				cout << "The First Key \n";
			if (key2 == 1)
				cout << "The Second Key \n";
			if (key3 == 1)
				cout << "The Third Key \n";
			if (Yes == 1)
				cout << "The alien object \n";
			if (pda == 1)
				cout << "The PDA \n";
			break;
		case 'p':
		case 'P':
			if (pda == 1)
			{
				cout << "You are in good health. \n";
				if (wobbly > 1)
					cout << wobbly << " minutes \n";
				else
					cout << wobbly << " minute remaining. Please hurry!\n";
				break;
			}
			else
				cout << "Did not recognize that command. Please try something else. \n";
			break;
		case 'M':
		case 'm':
			main();
		case 'Q':
		case 'q':
			exit(0);
		default:
			cout << "Did not recognize that command. Please try something. \n";
		}

	} while (cond != 1);
}

void medBay()
{
	char move;
	string pickup;
	cout << "This ship's Medical Bay seems quite advanced. \n";

	do {
		cout << "What do you want to do? \n";
		cin >> move;
		switch (move)
		{
		case 'L':
		case 'l':
			cout << " \n";
			break;
		case 'N':
		case 'n':
			cout << " \n";
			hall1N();
			break;
		case 'S':
		case 's':
			cout << "Watch out for the wall. \n";
			break;
		case 'W':
		case 'w':
			cout << "Running into walls is not healthy for you. \n";
			break;
		case 'e':
		case 'E':
			cout << "You walk out into the East Hallway. \n";
			hall1E();
			break;
		case 'G':
		case 'g':
			cout << " ";
			break;
		case 'I':
		case 'i':
			cout << "You're carrying: \n";
			if (crowbar == 1)
				cout << "The crowbar \n";
			if (taser == 1)
				cout << "The taser \n";
			if (Knife == 1)
				cout << "The knife \n";
			if (code == 1)
				cout << "The code in the diary: '1CqM2MvB3EoR' \n";
			if (keyDang == 1)
				cout << "The First Key \n";
			if (key2 == 1)
				cout << "The Second Key \n";
			if (key3 == 1)
				cout << "The Third Key \n";
			if (Yes == 1)
				cout << "The alien object \n";
			if (pda == 1)
				cout << "The PDA \n";
			break;
		case 'p':
		case 'P':
			if (pda == 1)
			{
				cout << "You are in good health. \n";
				if (wobbly > 1)
					cout << wobbly << " minutes \n";
				else
					cout << wobbly << " minute remaining. Please hurry!\n";
				break;
			}
			else
				cout << "Did not recognize that command. Please try something else. \n";
			break;
		case 'M':
		case 'm':
			main();
		case 'Q':
		case 'q':
			exit(0);
		default:
			cout << "Did not recognize that command. Please try something. \n";
		}

	} while (cond != 1);
}

void rm1() //syed
{
	char move;
	string pickup;
	cout << "You enter the first room. \n";

	do {
		cout << "What do you want to do? \n";
		cin >> move;
		switch (move)
		{
		case 'L':
		case 'l':
			cout << "There is a rotten dead body on the floor. It is too stinky!\n";
			cout << "There's also a desk with a diary beneath it. \n";
			break;
		case 'N':
		case 'n':
			cout << "It looked like a door but it's actually a wall. \n";
			break;
		case 'S':
		case 's':
			cout << "You head back to the South Hallway. \n";
			hall1SKev();
			break;
		case 'W':
		case 'w':
			cout << "Oh snap, you walked into a wall. \n";
			break;
		case 'e':
		case 'E':
			cout << "Nothing but wall. \n";
			break;
		case 'G':
		case 'g':
			cout << "What would you like to do? \n";
			cin.ignore();
			getline(cin, pickup);
			 if (pickup == "diary" || pickup == "Diary")
		{
			cout << "A piece of paper falls out of the diary. \n";
			cout << "It has a set of letters and numbers written on it. \n";
			cout << "\n*** 1CqM2MvB3EoR ***\n";
			code = 1;

		}
		else
		{
			cout << "That item isn't in this room.";
		}
		break;
		case 'I':
		case 'i':
			cout << "You're carrying: \n";
			if (crowbar == 1)
				cout << "The crowbar \n";
			if (taser == 1)
				cout << "The taser \n";
			if (Knife == 1)
				cout << "The knife \n";
			if (code == 1)
				cout << "The code in the diary: '1CqM2MvB3EoR' \n";
			if (keyDang == 1)
				cout << "The First Key \n";
			if (key2 == 1)
				cout << "The Second Key \n";
			if (key3 == 1)
				cout << "The Third Key \n";
			if (Yes == 1)
				cout << "The alien object \n";
			if (pda == 1)
				cout << "The PDA \n";
			break;
		case 'p':
		case 'P':
			if (pda == 1)
			{
				cout << "You are in good health. \n";
				if (wobbly > 1)
					cout << wobbly << " minutes \n";
				else
					cout << wobbly << " minute remaining. Please hurry!\n";
				break;
			}
			else
				cout << "Did not recognize that command. Please try something else. \n";
			break;
		case 'M':
		case 'm':
			main();
		case 'Q':
		case 'q':
			exit(0);
		default:
			cout << "Did not recognize that command. Please try something. \n";
		}

	} while (cond != 1);
}

void rm2() //syed
{
	char move;
	string pickup;
	cout << "There is a nothing inside. Looks like no one comes in this room for a while. \n";


	do {
		cout << "What do you want to do? \n";
		cin >> move;
		switch (move)
		{
		case 'L':
		case 'l':
			cout << "There's a few boxes scattered around but they look like they've been ransacked. \n";
			break;
		case 'N':
		case 'n':
			cout << "That's a wall \n";
			break;
		case 'S':
		case 's':
			cout << "You return to the South Hallway. \n";
			hall1SKev();
			break;
		case 'W':
		case 'w':
			cout << "There's a wall there. \n";
			break;
		case 'e':
		case 'E':
			cout << "Nothing but wall. \n";
			break;
		case 'G':
		case 'g':
			cout << "Boxes are empty so nothing to pick up \n ";
			break;
		case 'I':
		case 'i':
			cout << "You're carrying: \n";
			if (crowbar == 1)
				cout << "The crowbar \n";
			if (taser == 1)
				cout << "The taser \n";
			if (Knife == 1)
				cout << "The knife \n";
			if (code == 1)
				cout << "The code in the diary: '1CqM2MvB3EoR' \n";
			if (keyDang == 1)
				cout << "The First Key \n";
			if (key2 == 1)
				cout << "The Second Key \n";
			if (key3 == 1)
				cout << "The Third Key \n";
			if (Yes == 1)
				cout << "The alien object \n";
			if (pda == 1)
				cout << "The PDA \n";
			break;
		case 'p':
		case 'P':
			if (pda == 1)
			{
				cout << "You are in good health. \n";
				if (wobbly > 1)
					cout << wobbly << " minutes \n";
				else
					cout << wobbly << " minute remaining. Please hurry!\n";
				break;
			}
			else
				cout << "Did not recognize that command. Please try something else. \n";
			break;
		case 'M':
		case 'm':
			main();
		case 'Q':
		case 'q':
			exit(0);
		default:
			cout << "Did not recognize that command. Please try something. \n";
		}

	} while (cond != 1);
}

void rm3() //kevin

{
	char move;
	string pickup;
	cout << "You've walked into the third room. \n";
	cout << "It seems like somebody's bedroom. \n";

	do
	{
		cout << "What do you want to do? \n";
		cin >> move;
		switch (move)
		{
		case 'L':
		case 'l':
			cout << "After looking around, you notice a small cabinet in the corner. \n";
			cout << "There's a bed but it's pretty bare. \n";
			break;
		case 'N':
		case 'n':
			cout << "That's a wall there.\n";
			break;
		case 'S':
		case 's':
			cout << "You return to the South Hallway \n";
			hall1SKev();
			break;
		case 'W':
		case 'w':
			cout << "That is a wall \n";
			break;
		case 'e':
		case 'E':
			cout << "You're not a ghost. You cannot move through walls. \n";
			break;
		case 'G': //action key
		case 'g':
			cout << "What would you like to do? \n";
			cin.ignore();
			getline(cin, pickup);
			if (pickup == "cabinet" || pickup == "Cabinet")
			{
				cabinet = 1;
				cout << "There was nothing in the cabinet. Keep looking \n";

			}
			else
			{
				cout << "That item isn't in this room.";
			}
			break;
		case 'I':
		case 'i':
			cout << "You're carrying: \n";
			if (crowbar == 1)
				cout << "The crowbar \n";
			if (taser == 1)
				cout << "The taser \n";
			if (Knife == 1)
				cout << "The knife \n";
			if (code == 1)
				cout << "The code in the diary: '1CqM2MvB3EoR' \n";
			if (keyDang == 1)
				cout << "The First Key \n";
			if (key2 == 1)
				cout << "The Second Key \n";
			if (key3 == 1)
				cout << "The Third Key \n";
			if (Yes == 1)
				cout << "The alien object \n";
			if (pda == 1)
				cout << "The PDA \n";
			break;
		case 'p':
		case 'P':
			if (pda == 1)
			{
				cout << "You are in good health. \n";
				if (wobbly > 1)
					cout << wobbly << " minutes \n";
				else
					cout << wobbly << " minute remaining. Please hurry!\n";
				break;
			}
			else
				cout << "Did not recognize that command. Please try something else. \n";
			break;
		case 'M':
		case 'm':
			main();
		case 'Q':
		case 'q':
			exit(0);
		default:
			cout << "Did not recognize that command. Please try something. \n";
		}

	} while (cond != 1);

}


void rm4()
{
	char move;
	string pickup;
	cout << "This is the last room in the hallway. \n";

	do {
		cout << "What do you want to do? \n";
		cin >> move;
		switch (move)
		{
		case 'L':
		case 'l':
			cout << "You walk in and see multiple tanks of water harvesting humans inside them. \n";
			cout << "You also see somthing glimmering in the corner of the room and decide to take a look at it.\n";
			cout << "It's an unknown alien object you've never seen before.\n";
			break;
		case 'N':
		case 'n':
			cout << "There is an impression of a door but it's just a trick of the light. It's actually a wall. \n";
			break;
		case 'S':
		case 's':
			cout << "You return to the South Hallway. \n";
			hall1SKev();
			break;
		case 'W':
		case 'w':
			cout << "That's a wall. \n";
			break;
		case 'e':
		case 'E':
			cout << "Bumping into walls isn't healthy. \n";
			break;
		case 'G':
		case 'g':
			cout << "Would you like to pick up the unknown item? \n";
			cin.ignore(); //ignores other things that were typed before here
			getline(cin, pickup); //so this only accepts stuff after the line
			if (pickup == "Yes" || pickup == "yes") //two spellings in case the user doesn't want to use capital letters
			{
				Yes = 1;
				cout << "You've picked up the unknown object. It has been added to your inventory. \n";
			}
			else
				cout << "That's not here. \n";
			break;
		case 'I':
		case 'i':
			cout << "You're carrying: \n";
			if (crowbar == 1)
				cout << "The crowbar \n";
			if (taser == 1)
				cout << "The taser \n";
			if (Knife == 1)
				cout << "The knife \n";
			if (code == 1)
				cout << "The code in the diary: '1CqM2MvB3EoR' \n";
			if (keyDang == 1)
				cout << "The First Key \n";
			if (key2 == 1)
				cout << "The Second Key \n";
			if (key3 == 1)
				cout << "The Third Key \n";
			if (Yes == 1)
				cout << "The alien object \n";
			if (pda == 1)
				cout << "The PDA \n";
			break;
		case 'p':
		case 'P':
			if (pda == 1)
			{
				cout << "You are in good health. \n";
				if (wobbly > 1)
					cout << wobbly << " minutes \n";
				else
					cout << wobbly << " minute remaining. Please hurry!\n";
				break;
			}
			else
				cout << "Did not recognize that command. Please try something else. \n";
			break;
		case 'M':
		case 'm':
			main();
		case 'Q':
		case 'q':
			exit(0);
		default:
			cout << "Did not recognize that command. Please try something. \n";
		}

	} while (cond != 1);
}

void engineRm()
{
	char move;
	string pickup;
	cout << "Looks like you entered into the engine room.\n";
	cout << "There is a little light inside but no one is here.\n";

	do {
		cout << "What do you want to do? \n";
		cin >> move;
		switch (move)
		{
		case 'L':
		case 'l':
			cout << "OH wait! I found a key.\n";
			break;
		case 'N':
		case 'n':
			cout << "wall \n";
			break;
		case 'S':
		case 's':
			cout << "wall \n";
			break;
		case 'W':
		case 'w':
			cout << "hallway \n";
			hall1E();
			break;
		case 'e':
		case 'E':
			cout << "wall \n";
			break;
		case 'G':
		case 'g':
			cout << "Would you like to pick up the unknown item? \n";
			cin.ignore(); //ignores other things that were typed before here
			getline(cin, pickup); //so this only accepts stuff after the line
			if (pickup == "key" || pickup == "Key") //two spellings in case the user doesn't want to use capital letters
			{
				key2 = 1;
				cout << "You've picked up the key. It has been added to your inventory. \n";
			}
			else
				cout << "That's not here. \n";
			break;
		case 'I':
		case 'i':
			cout << "You're carrying: \n";
			if (crowbar == 1)
				cout << "The crowbar \n";
			if (taser == 1)
				cout << "The taser \n";
			if (Knife == 1)
				cout << "The knife \n";
			if (code == 1)
				cout << "The code in the diary: '1CqM2MvB3EoR' \n";
			if (keyDang == 1)
				cout << "The First Key \n";
			if (key2 == 1)
				cout << "The Second Key \n";
			if (key3 == 1)
				cout << "The Third Key \n";
			if (Yes == 1)
				cout << "The alien object \n";
			if (pda == 1)
				cout << "The PDA \n";
			break;
		case 'p':
		case 'P':
			if (pda == 1)
			{
				cout << "You are in good health. \n";
				if (wobbly > 1)
					cout << wobbly << " minutes \n";
				else
					cout << wobbly << " minute remaining. Please hurry!\n";
				break;
			}
			else
				cout << "Did not recognize that command. Please try something else. \n";
			break;
		case 'M':
		case 'm':
			main();
		case 'Q':
		case 'q':
			exit(0);
		default:
			cout << "Did not recognize that command. Please try something. \n";
		}

	} while (cond != 1);
}

void weaponsRm()
{
	char move;
	string pickup;
	cout << "  \n";


	do {
		cout << "What do you want to do? \n";
		cin >> move;
		switch (move)
		{
		case 'L':
		case 'l':
			cout << " \n";
			break;
		case 'N':
		case 'n':
			cout << "wall \n";
			break;
		case 'S':
		case 's':
			cout << "wall \n";
			break;
		case 'W':
		case 'w':
			cout << "bridge \n";
			bridge();
			break;
		case 'e':
		case 'E':
			cout << "hallway \n";
			hall1WAlex();
			break;
		case 'G':
		case 'g':
			cout << "What would you like to pick up? \n";
			cin.ignore(); //ignores other things that were typed before here
			getline(cin, pickup); //so this only accepts stuff after the line
			if (pickup == "taser" || pickup == "Taser") //two spellings in case the user doesn't want to use capital letters
			{
				taser = 1;
				cout << "You've picked up the taser. It has been added to your inventory. \n";
			}
			else
				cout << "That's not here. \n";
			break;
		case 'I':
		case 'i':
			cout << "You're carrying: \n";
			if (crowbar == 1)
				cout << "The crowbar \n";
			if (taser == 1)
				cout << "The taser \n";
			if (Knife == 1)
				cout << "The knife \n";
			if (code == 1)
				cout << "The code in the diary: '1CqM2MvB3EoR' \n";
			if (keyDang == 1)
				cout << "The First Key \n";
			if (key2 == 1)
				cout << "The Second Key \n";
			if (key3 == 1)
				cout << "The Third Key \n";
			if (Yes == 1)
				cout << "The alien object \n";
			if (pda == 1)
				cout << "The PDA \n";
			break;
		case 'p':
		case 'P':
			if (pda == 1)
			{
				cout << "You are in good health. \n";
				if (wobbly > 1)
					cout << wobbly << " minutes \n";
				else
					cout << wobbly << " minute remaining. Please hurry!\n";
				break;
			}
			else
				cout << "Did not recognize that command. Please try something else. \n";
			break;
		case 'M':
		case 'm':
			main();
		case 'Q':
		case 'q':
			exit(0);
		default:
			cout << "Did not recognize that command. Please try something. \n";
		}

	} while (cond != 1);
}

void commsRm()
{
	char move;
	string pickup;
	cout << "  \n";

	do {
		cout << "What do you want to do? \n";
		cin >> move;
		switch (move)
		{
		case 'L':
		case 'l':
			cout << "As you look around the communications room, you see a small vault to your left with a keypad. \n";
			break;
		case 'N':
		case 'n':
			cout << "wall \n";
			break;
		case 'S':
		case 's':
			cout << "wall \n";
			break;
		case 'W':
		case 'w':
		{cout << "bridge \n";
		if (keyDang == 1 && key2 == 1 && key3 == 1)
		{
			bridgeKeys();
		}
		else
		{
			bridge();
		}}
			break;
		case 'e':
		case 'E':
			cout << "hallway \n";
			hall1WAlex();
			break;
		case 'G':
		case 'g':
			cout << "Enter Pass Code: \n";
			cin >> passCode;
			if (passCode == 12345)
			{
				keyDang = 1;
				cout << "You opened the key vault and obtained a key. \n";
			}
			break;
		case 'I':
		case 'i':
			cout << "You're carrying: \n";
			if (crowbar == 1)
				cout << "The crowbar \n";
			if (taser == 1)
				cout << "The taser \n";
			if (Knife == 1)
				cout << "The knife \n";
			if (code == 1)
				cout << "The code in the diary: '1CqM2MvB3EoR' \n";
			if (keyDang == 1)
				cout << "The First Key \n";
			if (key2 == 1)
				cout << "The Second Key \n";
			if (key3 == 1)
				cout << "The Third Key \n";
			if (Yes == 1)
				cout << "The alien object \n";
			if (pda == 1)
				cout << "The PDA \n";
			break;
		case 'p':
		case 'P':
			if (pda == 1)
			{
				cout << "You are in good health. \n";
				if (wobbly > 1)
					cout << wobbly << " minutes \n";
				else
					cout << wobbly << " minute remaining. Please hurry!\n";
				break;
			}
			else
				cout << "Did not recognize that command. Please try something else. \n";
			break;
		case 'M':
		case 'm':
			main();
		case 'Q':
		case 'q':
			exit(0);
		default:
			cout << "Did not recognize that command. Please try something. \n";
		}

	} while (cond != 1);
}

void bridge()
{
	char move, move2;
	string pickup;

	cout << "You've reached the bridge of the ship. \n";
	if (cond3 == 0)
	{
		cout << "The blaring alarms continue in the background. \n";
	}
	do {
		cout << "What do you want to do? \n";
		cin >> move;
		switch (move)
		{
		case 'L':
		case 'l':
			cout << "There is a computer on in the center of the room. \n";
			cout << "There is also a pedestal next to it with something on top. \n";
			break;
		case 'N':
		case 'n':
			cout << "There are a bunch of screens on the walls that show where you are but surprisingly no doors you can walk through. \n";
			break;
		case 'S':
		case 's':
			cout << "That's an impressive view but it's probably not a good idea to walk out into open space. \n";
			break;
		case 'W':
		case 'w':
			cout << "There are screens showing the health of the ship and other seemingly important information on the ship. \n";
			break;
		case 'e':
		case 'E':
			cout << "There are 2 rooms in that direction.\n";
			do
			{
				cout << "The first room is the Communications Room and the other is the Weapons Room.\n";
				cin >> move2;
				switch (move2)
				{
				case 'C':
				case 'c':
					commsRm();
					break;
				case 'w':
				case 'W':
					weaponsRm();
					break;
				default:
					cout << "Didn't understand your command. \n";
				}
			} while (cond != 1);
			break;
		case 'G': //action key
		case 'g':
			cout << "What would you like to do? \n";
			cin.ignore();
			getline(cin, pickup);
			if (pickup == "computer" || pickup == "Computer")
			{
				computer = 1;
				cond3 = 1;
				cout << "When you touch the computer, the flashing lights stop flashing and change to a bright white, and the alarms turn off. \n";
				cout << "However, the screen displays a large moon directly ahead of the ship and the words: \n";
				cout << "Time to Collision: " << wobbly << " minutes. \n";
				cout << "Please enter captain's keys and prepare alternative route. \n";
				cout << "Now to look for the keys. \n";

			}
			else if (pickup == "pedestal" || pickup == "Pedestal")
			{
				cout << "There's a PDA on the pedestal. \n";
				cout << "You grab it and turn it on. \n";
				cout << "It scans and tells you about your health and important information about the ship. \n";
				cout << "Press 'P' to use the PDA.";
				pda = 1;

			}
			else
			{
				cout << "That item isn't in this room.";
			}
			break;
		case 'I':
		case 'i':
			cout << "You're carrying: \n";
			if (crowbar == 1)
				cout << "The crowbar \n";
			if (taser == 1)
				cout << "The taser \n";
			if (Knife == 1)
				cout << "The knife \n";
			if (code == 1)
				cout << "The code in the diary: '1CqM2MvB3EoR' \n";
			if (keyDang == 1)
				cout << "The First Key \n";
			if (key2 == 1)
				cout << "The Second Key \n";
			if (key3 == 1)
				cout << "The Third Key \n";
			if (Yes == 1)
				cout << "The alien object \n";
			if (pda == 1)
				cout << "The PDA \n";
			break;
		case 'p':
		case 'P':
			if (pda == 1)
			{
				cout << "You are in good health. \n";
				if (wobbly > 1)
					cout << wobbly << " minutes \n";
				else
					cout << wobbly << " minute remaining. Please hurry!\n";
				break;
			}
			else
				cout << "Did not recognize that command. Please try something else. \n";
			break;
		case 'M':
		case 'm':
			main();
		case 'Q':
		case 'q':
			exit(0);
		default:
			cout << "Did not recognize that command. Please try something. \n";
		}

	} while (cond != 1);
}

void bridgeKeys()
{
	char move, move2;
	string pickup; //variable to accept the item name
	cout << "You return to the bridge with all the keys \n";
	cin >> move;

		do {
			cout << "What do you want to do?\n";
			cin >> move;
			switch (move)
			{
			case 'L':
			case 'l':
				cout << " \n";
				break;
			case 'N':
			case 'n':
				cout << "Goes North \n";
				break;
			case 'S':
			case 's':
				cout << "South \n";
				break;
			case 'W':
			case 'w':
				cout << "West \n";
				break;
			case 'e':
			case 'E':
				cout << "There are 2 rooms in that direction.\n";
				do
				{
					cout << "The first room is the Communications Room and the other is the Weapons Room.\n";
					cin >> move2;
					switch (move2)
					{
					case 'C':
					case 'c':
						commsRm();
						break;
					case 'w':
					case 'W':
						weaponsRm();
						break;
					default:
						cout << "Didn't understand your command. \n";
					}
				} while (cond != 1);
				break;
			case 'G':
			case 'g':
				cout << "What would you like to pick up? \n";
				cin.ignore(); //ignores other things that were typed before here
				getline(cin, pickup); //so this only accepts stuff after the line
				if (pickup == "Item" || pickup == "item") //two spellings in case the user doesn't want to use capital letters
				{
					
					cout << "You've picked up the item. It has been added to your inventory. \n";
				}
				else
					cout << "That's not here. \n";
				break;
			case 'I':
			case 'i':
				cout << "You're carrying: \n";
				if (crowbar == 1)
					cout << "The crowbar \n";
				if (taser == 1)
					cout << "The taser \n";
				if (Knife == 1)
					cout << "The knife \n";
				if (code == 1)
					cout << "The code in the diary: '1CqM2MvB3EoR' \n";
				if (keyDang == 1)
					cout << "The First Key \n";
				if (key2 == 1)
					cout << "The Second Key \n";
				if (key3 == 1)
					cout << "The Third Key \n";
				if (Yes == 1)
					cout << "The alien object \n";
				if (pda == 1)
					cout << "The PDA \n";
				break;
			case 'p':
			case 'P':
				if (pda == 1)
				{
					cout << "You are in good health. \n";
					if (wobbly > 1)
						cout << wobbly << " minutes \n";
					else
						cout << wobbly << " minute remaining. Please hurry!\n";
					break;
				}
				else
					cout << "Did not recognize that command. Please try something else. \n";
				break;
			case 'M':
			case 'm':
				main();
			case 'Q':
			case 'q':
				exit(0);
			default:
				cout << "Did not recognize that command. Please try something. \n";
			}

		} while (cond != 1);
}

void endGame()
{
	char final;

	if (timeLoss == 1)
	{
		cout << "\nYou were not fast enough in finding the keys. \n";
		cout << "The ship crash-landed on a dark moon and subsequently exploded. \n";
		cout << "It was quite painful.\n \n";
		cout << "To return to the Main Menu, choose 'M'. Otherwise hit any other key to Quit. \n";
		cin >> final;

		switch (final)
		{
		case 'm':
		case 'M':
			cond = 0; cond2 = 0; cond3 = 0;
			crowbar = 0; taser = 0; Knife = 0;
			cabinet = 0; code = 0;
			keyDang = 0; key2 = 0; key3 = 0;
			passCode = 0;
			Yes = 0;
			computer = 0; pda = 0;
			timeLoss = 0;
			wobbly = 30;
			main();
		case 'q':
		case 'Q':
			exit(0);

		}
	}
}
