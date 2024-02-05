

int rabbit(int n)
{
    if (n <= 2)
        return 1;
    else // n > 2, so n - 1 > 0 and n - 2 > 0
        return rabbit(n-1) + rabbit(n - 2);
}   // end rabbit