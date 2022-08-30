#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int DECtoBIN(int n, int fix)
{
    int a[10], i;
    int firstn = n;
    for (i = 0; i < 8; i++)
    {
        a[i] = 0;
    }

    for (i = 0; n > 0; i++)
    {
        a[i] = n % 2;
        n = n / 2;
    }
    int start, bin = 0;
    start = 8 - (fix % 8);

    for (i = start - 1; i >= 0; i--)
    {
        bin = bin + a[i] * pow(2, i);
    }

    int ans;
    if (firstn == 0)
    {
        ans = 0;
    }
    else
    {
        ans = firstn - bin;
    }
    return ans;
}
void firstipfinder(int totalip, int ip1, int ip2, int ip3, int ip4, int ns, int type)
{
    float rip1m, rip1d;

    rip1d = (totalip / 256);
    rip1m = totalip % 256;
    ip3 = ip3 + rip1d;
    ip4 = ip4 + rip1m;
    if (ip3 > 255)
    {
        ip2 = ip2 + (ip3 / 256);
        ip3 = ip3 % 256;
    }
    if (ip2 > 255)
    {
        ip1 = ip1 + (ip2 / 256);
        ip2 = ip2 % 256;
    }
    printf("IP of first PC of Subnet (%d)  -> %d.%d.%d.%d\n", ns, ip1, ip2, ip3, ip4);
}

void lastipfinder(int totalip, int ip1, int ip2, int ip3, int ip4, int ns, int type)
{
    float rip1m, rip1d;

    rip1d = (totalip / 256);
    rip1m = totalip % 256;
    ip3 = ip3 + rip1d;
    ip4 = ip4 + rip1m;
    if (ip3 > 255)
    {
        ip2 = ip2 + (ip3 / 256);
        ip3 = ip3 % 256;
    }
    if (ip2 > 255)
    {
        ip1 = ip1 + (ip2 / 256);
        ip2 = ip2 % 256;
    }
    printf("IP of last PC of Subnet (%d)  -> %d.%d.%d.%d\n", ns, ip1, ip2, ip3, ip4);
}

int main()
{
    int ns, np;
    int ip1 = 0, ip2 = 0, ip3 = 0, ip4 = 0;

    printf("-------------------------------------------\n");
    printf("---------- IP address Calculator ----------\n");
    printf("-------------------------------------------\n");
    int subm[4], i = 0;
    int type;
start:
    printf("\nEnter your IP [Format: x.x.x.x/x]:\n");
    for (i = 0; i <= 4; i++)
    {
        scanf("%d", &subm[i]);

        if (subm[i] < 0 || subm[i] > 255)
        {
            printf("\nPlease enter a valid number");
            goto start;
        }
    }
    if (subm[4] < 0 || subm[4] > 32)
    {
        printf("\nPlease enter a valid number");
        goto start;
    }
    int netip;
    netip = pow(2, (32 - subm[4]));
    int totalip;

    if (subm[4] >= 0 && subm[4] < 8)
    {
        ip1 = DECtoBIN(subm[0], subm[4]);
        type = 1;
    }
    else if (subm[4] >= 8 && subm[4] < 16)
    {
        ip1 = subm[0];
        ip2 = DECtoBIN(subm[1], subm[4]);
        type = 12;
    }
    else if (subm[4] >= 16 && subm[4] < 24)
    {
        ip1 = subm[0];
        ip2 = subm[1];
        ip3 = DECtoBIN(subm[2], subm[4]);
        type = 123;
    }
    else if (subm[4] >= 24 && subm[4] < 32)
    {
        ip1 = subm[0];
        ip2 = subm[1];
        ip3 = subm[2];
        ip4 = DECtoBIN(subm[3], subm[4]);
        type = 1234;
    }
    else
    {
        ip1 = subm[0];
        ip2 = subm[1];
        ip3 = subm[2];
        ip4 = subm[3];
    }

ns:
    printf("\nEnter the no. of Subnets : ");
    scanf("%d", &ns);
    if (ns < 0)
    {
        printf("\nPlease enter a valid positive number");
        goto ns;
    }
np:
    printf("\nEnter the no. of PCs in each Subnet : ");
    scanf("%d", &np);
    if (np < 0)
    {
        printf("\nPlease enter a valid positive number");
        goto np;
    }
    int no = 1;
    int count;
    totalip = ns * np - 1;
    count = totalip;
    if (totalip > netip)
    {
        printf("\n############### OUT OF RANGE ###############");
        exit(0);
    }
    while (i < totalip)
    {
        count = i + np - 5;
        firstipfinder(count - np, ip1, ip2, ip3, ip4, no, type);
        lastipfinder(count - 1, ip1, ip2, ip3, ip4, no, type);
        printf("\n");
        i = i + np;
        no++;
    }

    printf("\nDo you want to continue ? [1.YES][2.NO]\nANS=>");
    int ans;
    scanf("%d", &ans);
    if (ans == 1)
    {
        system("cls");
        goto start;
    }
    else
    {
        exit(0);
    }
    return 0;
}