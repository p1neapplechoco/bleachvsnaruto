#include "settings.h"
#include "game.h"
#include "menu.h"
#include "sfx.h"
#include "d2data.h"
#include "graphic.h"


bool music = true;
bool sound = true;

int Setting() {
	system("cls");
	int OldMode = _setmode(_fileno(stdout), _O_WTEXT);
	int _pos_x = D2_X_SETTING + 9;
	for (int i = 0; i < D2_SETTINGS_1.size() - 1 - i; i += 2) {
		gotoxy(_pos_x + i, D2_Y_SETTING - 10);
		wcout << D2_SETTINGS_1[i] << D2_SETTINGS_1[i + 1];
		gotoxy(_pos_x + i, D2_Y_SETTING - 9);
		wcout << D2_SETTINGS_2[i] << D2_SETTINGS_2[i + 1];
		gotoxy(_pos_x + i, D2_Y_SETTING - 8);
		wcout << D2_SETTINGS_3[i] << D2_SETTINGS_3[i + 1];
		gotoxy(_pos_x + i, D2_Y_SETTING - 7);
		wcout << D2_SETTINGS_4[i] << D2_SETTINGS_4[i + 1];
		gotoxy(_pos_x + i, D2_Y_SETTING - 6);
		wcout << D2_SETTINGS_5[i] << D2_SETTINGS_5[i + 1];
		gotoxy(_pos_x + i, D2_Y_SETTING - 5);
		wcout << D2_SETTINGS_6[i] << D2_SETTINGS_6[i + 1];

		gotoxy(_pos_x + int(D2_SETTINGS_1.size()) - i - 2, D2_Y_SETTING - 10);
		wcout << D2_SETTINGS_1[D2_SETTINGS_1.size() - 2 - i] << D2_SETTINGS_1[D2_SETTINGS_1.size() - 1 - i];
		gotoxy(_pos_x + int(D2_SETTINGS_1.size()) - i - 2, D2_Y_SETTING - 9);
		wcout << D2_SETTINGS_2[D2_SETTINGS_1.size() - 2 - i] << D2_SETTINGS_2[D2_SETTINGS_1.size() - 1 - i];
		gotoxy(_pos_x + int(D2_SETTINGS_1.size()) - i - 2, D2_Y_SETTING - 8);
		wcout << D2_SETTINGS_3[D2_SETTINGS_1.size() - 2 - i] << D2_SETTINGS_3[D2_SETTINGS_1.size() - 1 - i];
		gotoxy(_pos_x + int(D2_SETTINGS_1.size()) - i - 2, D2_Y_SETTING - 7);
		wcout << D2_SETTINGS_4[D2_SETTINGS_1.size() - 2 - i] << D2_SETTINGS_4[D2_SETTINGS_1.size() - 1 - i];
		gotoxy(_pos_x + int(D2_SETTINGS_1.size()) - i - 2, D2_Y_SETTING - 6);
		wcout << D2_SETTINGS_5[D2_SETTINGS_1.size() - 2 - i] << D2_SETTINGS_5[D2_SETTINGS_1.size() - 1 - i];
		gotoxy(_pos_x + int(D2_SETTINGS_1.size()) - i - 2, D2_Y_SETTING - 5);
		wcout << D2_SETTINGS_6[D2_SETTINGS_1.size() - 2 - i] << D2_SETTINGS_6[D2_SETTINGS_1.size() - 1 - i];

		
	}

	int CurrentMode = _setmode(_fileno(stdout), OldMode);
	gotoxy(D2_X_SETTING + 24, D2_Y_SETTING + 17);
	cout << "Press Esc to return Menu";

	for (int i = 0; i < 82; i += 2) {
		gotoxy(D2_X_SETTING + i, D2_Y_SETTING);
		cout << D2_LOWER_FRAME << D2_LOWER_FRAME;
		gotoxy(D2_X_SETTING + 80 - i, D2_Y_SETTING + 19);
		cout << D2_UPPER_FRAME << D2_UPPER_FRAME;
		
	}

	for (int i = 1; i < 19; i += 2) {
		gotoxy(D2_X_SETTING + 81, D2_Y_SETTING + i);
		cout << D2_VERTICAL_FRAME;
		gotoxy(D2_X_SETTING + 81, D2_Y_SETTING + i + 1);
		cout << D2_VERTICAL_FRAME;
		gotoxy(D2_X_SETTING, D2_Y_SETTING + 19 - i);
		cout << D2_VERTICAL_FRAME;
		gotoxy(D2_X_SETTING, D2_Y_SETTING + 19 - i - 1);
		cout << D2_VERTICAL_FRAME;
		
	}

	gotoxy(D2_X_SETTING + 18, D2_Y_SETTING + 5); //D2 X Setting = 46, D2y=15
	printf("Music:");
	gotoxy(D2_X_SETTING + 18, D2_Y_SETTING + 13);
	printf("Sound:");
	string options[] = { "        ON         ", "        OFF        ", "        ON         ", "        OFF        " };
	int counter = 1;
	char key;

	for (int i = 0;;)
	{

		gotoxy(76, 19);

		cout << options[0];

		gotoxy(76, 21);
		cout << options[1];

		gotoxy(76, 27);
		cout << options[2];

		gotoxy(76, 29);
		cout << options[3];



		key = _getch();

		if ((key == 72 || key == 'w') && (counter >= 2 && counter <= 4))
		{

			counter--;
		}
		if ((key == 80 || key == 's') && (counter >= 1 && counter <= 3))
		{

			counter++;
		}
		if (key == '\r')
		{
			switch (counter) {
			case 1:
				music = true;
				backgroundmusic();
				break;
			case 2:
				music = false;
				backgroundmusic();
				break;
			case 3:
				sound = true;
				break;
			case 4:
				sound = false;
			default:
				break;
			}
		}

		if (key == 27) {
			Loading();
			return counter;
		}

		options[0] = "        ON         ";
		options[1] = "        OFF        ";
		options[2] = "        ON         ";
		options[3] = "        OFF        ";


		if (counter == 1)
		{

			select1();
			options[0] = "     >> ON  <<      ";

		}
		if (counter == 2)
		{

			select1();
			options[1] = "    >>  OFF  <<     ";

		}
		if (counter == 3)
		{

			select1();
			options[2] = "     >> ON  <<      ";

		}
		if (counter == 4)
		{

			select1();
			options[3] = "    >>  OFF  <<     ";

		}
	}
}



void select() {
	(sound) ? PlaySound(TEXT("Sounds//select.wav"), NULL, SND_FILENAME | SND_ASYNC) : PlaySound(TEXT("Sounds//silent.wav"), NULL, SND_FILENAME | SND_ASYNC);
}

void backgroundmusic() {
	(music) ? mciSendString(L"play \"sounds//backgroundmusic.mp3\" repeat", NULL, 0, 0) : mciSendString(L"pause \"sounds//backgroundmusic.mp3\"", NULL, 0, 0);
}

void goXO() {
	(sound) ? PlaySound(TEXT("Sounds//goXO.wav"), NULL, SND_FILENAME | SND_ASYNC) : PlaySound(TEXT("Sounds//silent.wav"), NULL, SND_FILENAME | SND_ASYNC);
}

void enterXO() {
	(sound) ? PlaySound(TEXT("Sounds//enterXO.wav"), NULL, SND_FILENAME | SND_ASYNC) : PlaySound(TEXT("Sounds//silent.wav"), NULL, SND_FILENAME | SND_ASYNC);
}

void select1() {
	(sound) ? PlaySound(TEXT("Sounds//select1.wav"), NULL, SND_FILENAME | SND_ASYNC) : PlaySound(TEXT("Sounds//silent.wav"), NULL, SND_FILENAME | SND_ASYNC);
}

void winsound() {
	(sound) ? PlaySound(TEXT("Sounds//win.wav"), NULL, SND_FILENAME | SND_ASYNC) : PlaySound(TEXT("Sounds//silent.wav"), NULL, SND_FILENAME | SND_ASYNC);
}