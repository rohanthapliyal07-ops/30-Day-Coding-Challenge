#include<stdio.h>
int main() {
float fuel_price,mileage,dist,fuel_req,fuel_cost;
printf("Enter the Distance To be Travelled During the Trip : ");
scanf("%f",&dist);
printf("Enter the Mileage of The Car to be used during the trip : ");
scanf("%f",&mileage);
printf("Enter the Fuel Cost Per Litre : ");
scanf("%f",&fuel_price);
fuel_req=dist/mileage;
fuel_cost=fuel_req*fuel_price;
printf("The Total Fuel required For the Trip is : %.2fL\n",fuel_req);
printf("The Total Cost Of Travelling is : ₹%.2f \n",fuel_cost);
return 0;
}
