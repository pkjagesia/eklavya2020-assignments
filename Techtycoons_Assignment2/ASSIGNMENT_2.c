#include <stdio.h>
void final_direction(int,int);

void check_turns(FILE* fp)
{
    int nodes=0,i=0,j=0,k=0,turn=0,left_turn=0,right_turn=0;
    float sensor[4];

    while(!feof(fp))
    {
        fscanf(fp,"%f %f %f %f",sensor,sensor+1,sensor+2,sensor+3);

        //Checking for nodes
        while((sensor[0]>0.7 && sensor[0]<1) && (sensor[1]>0.7 && sensor[1]<1) && (sensor[2]>0.7 && sensor[2]<1) && (sensor[3]>0.7 && sensor[3]<1))
        {
          i+=1;
          fscanf(fp,"%f %f %f %f",sensor,sensor+1,sensor+2,sensor+3);

        }

         if (i > 7)
         {
            nodes+=1;
            //If a node is followed by a turn,then read those lines without incrementing the turns.

            while(sensor[0]>0.7 && sensor[0]<1 && sensor[1]>0.7 && sensor[1]<1 && sensor[2]>0.7 && sensor[2]<1 && sensor[3]>0 && sensor[3]<0.4)
            {
              k+=1;
              fscanf(fp,"%f %f %f %f",sensor,sensor+1,sensor+2,sensor+3);

            }

             while(sensor[0]>0 && sensor[0]<0.4 && sensor[1]>0.7 && sensor[1]<1 && sensor[2]>0.7 && sensor[2]<1 && sensor[3]>0.7 && sensor[3]<1)
             {
                k+=1;
                fscanf(fp,"%f %f %f %f",sensor,sensor+1,sensor+2,sensor+3);

             }
                k = 0;
          }

                i = 0;



        //Checking for left turns
          while(sensor[0]>0.7 && sensor[0]<1 && sensor[1]>0.7 && sensor[1]<1 && sensor[2]>0.7 && sensor[2]<1 && sensor[3]>0 && sensor[3]<0.4)
           {
                i+=1;
                fscanf(fp,"%f %f %f %f",sensor,sensor+1,sensor+2,sensor+3);
           }

        //If turn is followed by a node, then don't consider the turn but increase the number of nodes
           while(sensor[0]>0.7 && sensor[0]<1 && sensor[1]>0.7 && sensor[1]<1 && sensor[2]>0.7 && sensor[2]<1 && sensor[3]>0.7 && sensor[3]<1)
           {
                j+=1;
                fscanf(fp,"%f %f %f %f",sensor,sensor+1,sensor+2,sensor+3);


            }

            if (i>7 && j<2)
            {
                turn+=1;
                left_turn+=1;
            }
            else if(j>7)
                nodes+=1;

            i = 0;
            j = 0;


        //Checking for right turns
            while(sensor[0]>0 && sensor[0]<0.4 && sensor[1]>0.7 && sensor[1]<1 && sensor[2]>0.7 && sensor[2]<1 && sensor[3]>0.7 && sensor[3]<1)
            {
                i+=1;
                fscanf(fp,"%f %f %f %f",sensor,sensor+1,sensor+2,sensor+3);

            }

        //If turn is followed by a node, then don't consider the turn but increase the number of nodes
            while(sensor[0]>0.7 && sensor[0]<1 && sensor[1]>0.7 && sensor[1]<1 && sensor[2]>0.7 && sensor[2]<1 && sensor[3]>0.7 && sensor[3]<1)
            {
                j+=1;
                fscanf(fp,"%f %f %f %f",sensor,sensor+1,sensor+2,sensor+3);

            }
            if (i>7 && j<3)
            {
              turn+=1;
              right_turn+=1;
            }
            else if (j>7)
                nodes+=1;

           i = 0;
           j = 0;

    }

     printf("number of nodes: %d \n",nodes);
     printf("number of turns: %d ",turn);
     final_direction(left_turn,right_turn);

}

void final_direction(int l, int r)
{
    int final_angle,n=-2;
    final_angle = (l * 90)+ (r*(-90));

    while(n<3)
    {
        if (final_angle == (0 + (360*n)))
            printf("\nfinal direction: NORTH");
        else if (final_angle == (90 + (360*n)))
            printf("\nfinal direction: WEST");
        else if (final_angle == (180 + (360*n)))
             printf("\nfinal direction: SOUTH");
        else if (final_angle == (270 + (360*n)))
            printf("\nfinal direction: EAST");
        n++;
    }
}
int main()
{

    char fname[20];
	FILE *fp;
	printf("Enter name of file to be read: ");
	scanf("%s",fname);
	fp = fopen(fname,"r");
	check_turns(fp);
    fclose(fp);
	return 0;
}

