int main()
{
    int z;
    int a;
    int b;
    float c;
    int[3][4][5] arr;
    z = 0;
    if (!true)
    {
        a = 1;
    }
    else
    {
        b = 2;
    }
    c = 3.0;
    while (a < 10)
    {
        a = a + 1;
        b = a / 2 - 1 * 3;
        if (b >= 0 && a < 3)
        {
            arr[a][b][0] = (a + 2) * 2;
        }
    }
    a = 100;
}