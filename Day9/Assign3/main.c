#include <stdio.h>
#include "circle.h"
#include "rectangle.h"
#include "square.h"
int area;

int main()
{

   area=area_circle(2);

   printf("area : %d\n", area);


   int area1=area_rectangle(2,3);

   printf("area1 : %d\n", area1);
   
   int area2=area_square(3);

   printf("area2 : %d\n", area2);

   return 0;
}
