#include<stdio.h>
void direction(char);
void check_right_straight(float value[],FILE *fp)
{
        int count=0;
        while(value[0]<0.4 && value[1]>0.7 && value[2]>0.7 && value[3]>0.7 && value[4]>0.7)
        {
           count+=1;
           fscanf(fp,"%f %f %f %f %f",value,value+1,value+2,value+3,value+4);
        }

        if(count >= 70)
        {
                printf("\nSTRAIGHT ---- RIGHT + STRAIGHT ---- ");
                direction('S');
        }

}

void check_left_straight(float value[],FILE *fp)
{
        int count=0;
        while(value[0]>0.7 && value[1]>0.7 && value[2]>0.7 && value[3]<0.4 && value[4]>0.7)
        {
           count+=1;
           fscanf(fp,"%f %f %f %f %f",value,value+1,value+2,value+3,value+4);
        }

        if(count >= 70)
        {
                printf("\nLEFT ---- LEFT + STRAIGHT ---- ");
                direction('L');
        }

}

void check_right_only(float value[],FILE *fp)
{
        int count=0;
        while(value[0]<0.4 && value[1]>0.7 && value[2]>0.7 && value[3]>0.7 && value[4]<0.4)
        {
           count+=1;
           fscanf(fp,"%f %f %f %f %f",value,value+1,value+2,value+3,value+4);
        }

        if(count >= 70)
        {
                printf("\nRIGHT TURN ---- ONLY RIGHT ---- ");
                direction('R');
        }

}

void check_left_only(float value[],FILE *fp)
{
        int count=0;
        while(value[0]>0.7 && value[1]>0.7 && value[2]>0.7 && value[3]<0.4 && value[4]<0.4)
        {
           count+=1;
           fscanf(fp,"%f %f %f %f %f",value,value+1,value+2,value+3,value+4);
        }

        if(count >= 70)
        {
                printf("\nLEFT TURN ---- ONLY LEFT ---- ");
                direction('L');
        }

}

void plus(float value[],FILE *fp)
{
        int count=0;
        while(value[0]>0.7 && value[1]>0.7 && value[2]>0.7 && value[3]>0.7 && value[4]>0.7)
        {
           count+=1;
           fscanf(fp,"%f %f %f %f %f",value,value+1,value+2,value+3,value+4);
        }

        if(count >= 70)
        {
                printf("\nLEFT TURN ---- PLUS ---- ");
                direction('L');
        }

}

void Shape_T(float value[],FILE *fp)
{
        int count=0;
        while(value[0]>0.7 && value[1]>0.7 && value[2]>0.7 && value[3]>0.7 && value[4]<0.4)
        {
           count+=1;
           fscanf(fp,"%f %f %f %f %f",value,value+1,value+2,value+3,value+4);
        }

        if(count >= 70)
        {
                printf("\nLEFT TURN ---- T ---- ");
                direction('L');
        }

}



void Dead_end(float value[],FILE *fp)
{
        int count=0;
        while(value[0]<0.4 && value[1]<0.4 && value[2]<0.4 && value[3]<0.4 && value[4]<0.4)
        {
           count+=1;
           fscanf(fp,"%f %f %f %f %f",value,value+1,value+2,value+3,value+4);
        }

        if(count >= 25)
        {
                printf("\nSTOP ---- END ---- ");
                direction('S');
        }

}

void direction(char ch)
{
    char current_direction[4][6] = {"NORTH","EAST","SOUTH","WEST"};
    static int i = 0;

    if (ch == 'S')
        printf("%s",current_direction[i]);
    else if (ch == 'R')
        {
            i++;
            if(i == 4)
            {
                i = 0;
                printf("%s",current_direction[i]);
            }
            else
                printf("%s",current_direction[i]);
        }
        else if (ch == 'L')
        {
            i--;
            if (i == -1)
            {
                i = 3;
                printf("%s",current_direction[i]);
            }
            else
                printf("%s",current_direction[i]);
        }
}

int main()
{
    FILE *fp;
    float value[5];
    char fname[20];
    int n = 0;

    printf("Enter the name of the file to be read:");
    scanf("%s",fname);
    fp = fopen(fname,"r");
    n = fscanf(fp,"%f %f %f %f %f",value,value+1,value+2,value+3,value+4);
    while(n == 5)
    {


         if (value[0]<0.4 && value[1]>0.7 && value[2]>0.7 && value[3]>0.7 && value[4]>0.7)
            check_right_straight(value,fp);
        else if (value[0]>0.7 && value[1]>0.7 && value[2]>0.7 && value[3]<0.4 && value[4]>0.7)
            check_left_straight(value,fp);
        else if (value[0]<0.4 && value[1]>0.7 && value[2]>0.7 && value[3]>0.7 && value[4]<0.4)
            check_right_only(value,fp);
        else if (value[0]>0.7 && value[1]>0.7 && value[2]>0.7 && value[3]<0.4 && value[4]<0.4)
            check_left_only(value,fp);
        else if (value[0]>0.7 && value[1]>0.7 && value[2]>0.7 && value[3]>0.7 && value[4]>0.7)
            plus(value,fp);
        else if (value[0]>0.7 && value[1]>0.7 && value[2]>0.7 && value[3]>0.7 && value[4]<0.4)
            Shape_T(value,fp);
        else if (value[0]<0.4 && value[1]<0.4 && value[2]<0.4 && value[3]<0.4 && value[4]<0.4)
            Dead_end(value,fp);
         n = fscanf(fp,"%f %f %f %f %f",value,value+1,value+2,value+3,value+4);
    }

    fclose(fp);
    return 0;
}



