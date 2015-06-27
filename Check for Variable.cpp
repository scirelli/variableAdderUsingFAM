//known bugs in this function: cout<< "int "; this will cause an extra addition of an integer
//as well as type casting when there is a space (int ) k=3.6;
//i think there is some other bug maybe with the fact that i index--; when i used a huge program where i counted 22 ints it counted 20 not sure why

#include <string.h>
#include <iostream.h>

int TestForIntegers(int &, char *);
int TestForBool(int &, char *);
int TestForChar(int &, char *);
int TestForFloat(int &, char *);
int TestForDouble(int &, char *);
void OutPut(int, int, int, char *);

void CheckForVariables(char * program)
{
	int index=0;
	int numberOfInteger=0, totIntMem=0;
	int numberOfBool=0, totBoolMem=0;
	int numberOfChar=0, totCharMem=0;
	int numberOfFloat=0, totFloatMem=0;
	int numberOfDouble=0, totDoubleMem=0;
	bool test= false;

	while( program[index] != NULL)
	{
		switch(program[index])
		{
		case '/' : index++;
				   switch( program[index] )
				   {
				   case '/' : index++;
					          while( program[index] != '\n')
							  {
									index++;
							  }
					          
							  break;
				   case '*' : index++;
							  while( (test != true) && (program[index] != NULL) )
							  {
								  switch( program[index] )
								  {
								  case '*' : index++;
									         switch( program[index] )
											 {
											 case '/' : index++;
												        test= true;
														break;
											 }
											 break;
								  }
								  index++;
							  }//end test while loop
				   }
				   index--; //had to decriment because while loop causes a skip over 1 extra char
				   break;
		case 'i' : numberOfInteger += TestForIntegers(index, program); break;
		case 'b' : numberOfBool+= TestForBool(index, program); break;
		case 'c' : numberOfChar+= TestForChar(index, program); break;
		case 'f' : numberOfFloat+= TestForFloat(index, program); break;
		case 'd' : numberOfDouble+= TestForDouble(index, program); break;
		}
		cout<<"Prosessing\n";
		index++;
	}
	
	totIntMem= numberOfInteger * sizeof(int);
	totBoolMem= numberOfBool * sizeof(bool);
	totCharMem= numberOfChar * sizeof(char);
	totFloatMem= numberOfFloat * sizeof(float);
	totDoubleMem= numberOfDouble * sizeof(double);
	
	OutPut(totBoolMem, numberOfBool, sizeof(bool), "bool");
	OutPut(totIntMem, numberOfInteger, sizeof(int), "int");
	OutPut(totCharMem, numberOfChar, sizeof(char), "char");
	OutPut(totDoubleMem, numberOfDouble, sizeof(double), "double");
	OutPut(totFloatMem, numberOfFloat, sizeof(float), "float");
	
	delete(program);

	return;
}