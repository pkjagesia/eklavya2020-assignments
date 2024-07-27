#include<stdio.h>

 int sum_of_array(unsigned char a[])
{
        int hexa[4];
        int temp,sum=0,i=0;
        //Adding the first eight elements of the array
         for(int i=0;i<8;i++)
        {
            sum+=a[i];
        }

        //Converting from decimal to hexadecimal and storing in reverse order
        while(sum!=0)
        {
           temp = sum%16;
           hexa[i] = temp;
           i++;
            sum = sum/16;
        }

        unsigned char l = a[8] & 0x0F; //extracting the lower order nibble in byte 9
        unsigned char h = (a[8]>>4) & 0x0F;//extracting the higher order nibble in byte 9

        if(hexa[0]==l && hexa[1]==h) //comparing byte 9 with actual sum of elements
            return 0;
        else
            return -1;

}

void cal_distance(int a,int b,FILE *fd)
{
    int distance;
    distance = (b << 8) | a; //combining byte 3 and byte 4 with byte 3 being lower order byte
    fprintf(fd,"%d\n ",distance);
}

void cal_strength(int a,int b,FILE *fs)
{
    int strength;
    strength = (b << 8) | a; //combining byte 5 and byte 6 with byte 5 being lower order byte
    fprintf(fs,"%d\n ",strength);
}
int main()
{
    unsigned char buffer[10];
    int s1;
    char fname[20];
    FILE *fp,*fd,*fs;

    printf("Enter the name of the file to be read:");
    scanf("%s",fname);
    fp = fopen(fname,"rb");
    fd = fopen("distance.txt","a");
    fs = fopen("signal.txt","a");

    while(!feof(fp))

    {
        fread(buffer,sizeof(buffer),1,fp);

    s1 = sum_of_array(buffer);
    if (s1 == 0)
    {
         cal_distance(buffer[2],buffer[3],fd);
         cal_strength(buffer[4],buffer[5],fs);

    }
    else if (s1 == -1)
        continue;
    }

    return 0;
}
