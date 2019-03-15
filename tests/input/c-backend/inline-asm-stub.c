short int add(short int *n)
{
	asm("addw $1, %0" : "+m" (*n));
	return *n;
}
