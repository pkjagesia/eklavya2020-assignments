#include <stdio.h>
#include <string.h>

int main()
{
   float sensor[4];
   char fname[20];
    int count=0,flag = 0;
	FILE *fp;
	printf("Enter name of file to be read: ");
	scanf("%s",fname);
	fp = fopen(fname,"r");

	while(!feof(fp))
    {
        fscanf(fp,"%f %f %f %f",sensor,sensor+1,sensor+2,sensor+3);
        while(sensor[0]>0.7 && sensor[0]<0.9 && sensor[3]>0.7 && sensor[3]<0.9)
        {
            flag+=1;
            fscanf(fp,"%f %f %f %f",sensor,sensor+1,sensor+2,sensor+3);

        }
        if (flag > 7)
            count+=1;
            flag = 0;

    }
    printf("number of nodes : %d",count);
    fclose(fp);
	return 0;
}

