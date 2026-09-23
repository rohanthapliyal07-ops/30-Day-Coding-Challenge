#include<stdio.h>
int main(){
int phy,chem,math,eng,cs,tmarks;
float avg,per;
printf("Enter Physics Marks");
scanf("%d",&phy);
printf("Enter Chemistry Marks");
scanf("%d",&chem);
printf("Enter Mathematics Marks");
scanf("%d",&math);
printf("Enter English Marks");
scanf("%d",&eng);
printf("Enter Computer Science Marks");
scanf("%d",&cs);
tmarks=(phy+chem+math+eng+cs);
avg=tmarks/5;
per=(tmarks/500.0)*100;
printf("%f",per);
printf("Total Marks Obtained By The Student : %d \n",tmarks);
printf("Average Marks Obtained By The Student : %f \n",avg);
printf("Percentage Obtained By The Student : %f \n",per);
return 0;
}
