unsigned int setbits(unsigned int x, int p, int n, unsigned int y)
{
    return (x & ~(~(~0 << n)  << (p + 1 - n))) | (y &   ~(~0 << n)) << (p + 1 - n);
}
