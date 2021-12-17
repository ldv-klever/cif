void *func(void *p1, char *p2, char *p3)
{
  return ( void *) ( ( int ) ( p2 + ( unsigned int ) p1 ) - ( int ) p3 );
}
