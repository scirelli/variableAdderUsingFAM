#include <iostream.h>

void OutPut(int totTypeMem, int numberOftype, int size, char * type)
{
	
	cout<< "\n\nNumber of " << type << "= " << numberOftype 
		<< "\nTotal memory in bytes needed= " << totTypeMem
		<< "\nBytes per " << type << "= " << size << "\n";
	return;
}