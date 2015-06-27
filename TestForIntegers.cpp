#include <string.h>


int TestForIntegers(int & index, char * program)
{
	bool test= true;
	int numberOfIntegers=0;
	
	index++; //move pointer to next char

	switch( program[index] )
	{
	case 'n' : index++;                           //is the next letter an 'n' ? if yes move pointer check next char
			   switch( program[index] )
			   {
			   case 't' : index++;               //is the next letter a 't' ? if it is move pointer and check for a space
				          switch( program[index] )
						  {
						  case ' ' : index++;
							         while(test != false)
									 {
										 switch(program[index])
										 {
										 case ',' : numberOfIntegers+=1;
											        break;
										 
										 case ';' : numberOfIntegers+=1;
													test= false;
													break;
										 
										 case '(' : index++;
												    while( program[index] != ')' )
													{
														index++;
													}
													test= false;
													break;
										 }
										 index++;
									 }//end while
						  						  
						  }//end ' ' switch
						  
						  break; //break for t
			   }//end t swtch
			   break;//break for n
	}
	
	return numberOfIntegers;
}

//610-659-0689