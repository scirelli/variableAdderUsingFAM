int TestForBool(int & index, char * program)
{
	bool test= true;
	int numberOfBool=0;
	
	index++; //move pointer to next char

	switch( program[index] )
	{
	case 'o' : index++;                           //is the next letter an 'n' ? if yes move pointer check next char
			   switch( program[index] )
			   {
			   case 'o' : index++;
				          switch( program[index] )
						  {
						  case 'l' : index++;
							         switch( program[index] )
									 {
									 case ' ' : index++;
										        while(test != false)
												{
													switch(program[index])
													{
													case ',' : numberOfBool+=1;
															   break;
										 
													case ';' : numberOfBool+=1;
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
						  break;
						  }
			   break;
			   }
	break;
	}

	return numberOfBool;
}
