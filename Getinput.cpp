//#include <iostream.h>
#include <fstream.h>
#include <stdio.h>
#include <string.h>
#define FLUSH while (cin.get() != '\n')

char * Get_Input()
{
	int Menu(void);
	
	fstream infile;
	char filename[81];

	switch(Menu())
	{
	case 1 : infile.open("c:\\mydocu~1\\visual~1\\variab~2\\code.txt", ios::in); 
			 strcpy(filename,"c:\\mydocu~1\\visual~1\\variab~2\\code.txt");
			 if(infile.fail())                                      //test to see if file is there
				cout<< "Input file dose not exist";	
			 break;                                              //opens file for reading
	
	case 2 : cout<< "Enter file name-> ";                            //allows user to enter path
		     cin.getline(filename, 81, '\n'); 
			 infile.open(filename, ios::in);
			 if(infile.fail())                                      //test to see if file is there
				cout<< "Input file dose not exist";
			 break;
	default : cout<<"That is not an option.  Using default, option 1"; 
			  infile.open ("c:\\mydocu~1\\visual~1\\variab~2\\code.txt", ios::in);
	}	
	
	int i=0;                     //keeps track of # of chars in file
	char * j= new char [3];                     //arbitrery variable just there to hold a char, so pointer can more
	
	while(!infile.eof())        //counts # of chars in file
	{
		infile.getline(j, 2, NULL);
		i++;
		cout<<"Number of chars= " << i << "\n";
	}
		
	//infile &seekg(streampos, seek_dir=ios::beg);
	infile.close();                  //not sure how to reset file pointer so i closed
	infile.open(filename, ios::in);  // and reopened the file

	char * input= new char [i];               //creates array of chars to store file's contents
	char * k = new char[3];           //ok the reason that this string has to be as big as the main on is because the way i take the input using infile>> it reads only chars and stops at spaces, so if there are no spaces in the program the first string is the whole program
	strcpy(input, " ");               //needed to have something to concatinate to
	
	while(!infile.eof())             //gets in all chars in the file and stores it
	{
		infile.getline(k, 2, NULL);
		strcat(input, k);
		cout<<"reading\n";
	}
	
	infile.close();          //closes file
	return input;
}

int Menu()
{
	int choice=0;

	cout<< "\t\tChoose and option \n\n1) Use default path \n2) Enter your own path";
	cout<< "\n(note: path example a:\\[filename] this is the path to your .txt file) \n\nOption-> ";
	cin>> choice;
	FLUSH;
	return choice;
}