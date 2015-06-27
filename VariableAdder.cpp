#include <iostream.h>

char * Get_Input(void);
void CheckForVariables(char *);
void Intro(void);

void main()
{
	int icontinue= 0;
	bool bcontinue= true;

	Intro();

	while(bcontinue)
	{
		CheckForVariables( Get_Input() );
		
		cout<< "\n\n\t\tWould you like to continue checking files?\n\n"
			<< "1. Yes\n"
			<< "2. No\n"
			<< "\nEnter choise-> ";
		cin >> icontinue;
		
		switch(icontinue)
		{
		case 1 : bcontinue= true; break;
		default : bcontinue= false;
		}
		
	}
	
	return;
}