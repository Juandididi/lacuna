#include <stdlib.h>
#include <stdio.h>

void main ()
{
    float x0, y0, x1, y1, xp, yp, aqi, humper, temper, aqier, meteff;
    char op;
    
    
do
{
    printf ("MENU \n\n\n");
    printf ("A. Humidity Efficiency Interpolation \n");
    printf ("B. Temperature Efficiency Interpolation \n");
    printf ("C. AQI Efficiency Coefficient \n");
    printf ("D. Meteorological Efficiency Coefficient \n");
    printf ("Q. EXIT \n\n");
    printf ("CHOOSE AN OPTION: ");
    scanf ("%c", &op);
    
    switch (op)
    {
        case 'A':
        case 'a':
            printf("Enter first point (x0,y0):\n");
            scanf("%f%f",&x0,&y0);
            printf("Enter second point (x1,y1):\n");
            scanf("%f%f",&x1,&y1);
            printf("Enter interpolation point: ");
            scanf("%f", &xp);
            
            humper = y0 + ((y1-y0)/(x1-x0)) * (xp - x0);
            printf("Your Humidity Efficiency Percentage at %0.3f is %0.3f", xp, humper);
        
        break;
        
        case 'B':
        case 'b':
            printf("Enter first point (x0,y0):\n");
            scanf("%f%f",&x0,&y0);
            printf("Enter second point (x1,y1):\n");
            scanf("%f%f",&x1,&y1);
            printf("Enter interpolation point: ");
            scan("%f", &xp);
            
            temper = y0 + ((y1-y0)/(x1-x0)) * (xp - x0);
            printf("Your Temperature Efficiency Percentage at %0.3f is %0.3f", xp, temper);
        break;
        
        case 'C':
        case 'c':
            printf ("Give me today's AQI value: ");
            scanf ("%f", &aqi);
            
            if (aqi <= 25)
            {
                aqier=1;
            }
            
            else if (aqi > 25 && aqi <= 30)
            {
                aqier=0.9;
            }
            
            else if (aqi > 30 && aqi <= 35)
            {
                aqier=0.8;
            }
            
            else if (aqi > 35 && aqi <= 45)
            {
                aqier=0.75;
            }
            
            else if (aqi > 45 && aqi <= 50)
            {
                aqier=0.7;
            }
            
            printf ("Your AQI Efficiency Coefficient is: %f", aqier);
        break;
        
        case 'D':
        case 'd':
            printf ("Calculating your crop meteorological efficiency coefficient... \n\n");
            humper=humper/100;
            temper=temper/100;
            meteff=(humper+temper+aqier)/3;
            printf ("Your metereological efficiency is: %f", meteff);
        break;
    }
    
    
} while (op != 'Q' || op != 'q');
    
    
system ("PAUSE");    
}
