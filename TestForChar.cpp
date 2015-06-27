int TestForChar(int & index, char * program)
{
	bool test= true;
	int numberOfChar=0;
	
	index++; //move pointer to next char

	switch( program[index] )
	{
	case 'h' : index++;                           //is the next letter an 'n' ? if yes move pointer check next char
			   switch( program[index] )
			   {
			   case 'a' : index++;               //is the next letter a 't' ? if it is move pointer and check for a space
				          switch( program[index])
						  {
						  case 'r' : index++;
									 switch( program[index] )
									 {
									 case ' ' : index++;
											    while(test != false)
												{
													switch(program[index])
													{
													case ',' : numberOfChar+=1;
															   break;
										 
													case ';' : numberOfChar+=1;
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
									 break;
									 }
						  break;
						  }
			   break;
			   }
	break;
	}
	
	return numberOfChar;
}