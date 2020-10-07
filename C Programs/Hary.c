#include <stdio.h>
void main()
{
char base_digits[16] =
{'0', '1', '2', '3', '4', '5', '6', '7',
'8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
int converted_number[64];
int number_to_convert;
int next_digit, base, index=0;
printf("Decimal to other base conversion program \n");
printf("Enter a decimal number ");
scanf("%d",&number_to_convert);
printf("Enter desired base to convert: ");
scanf("%d",&base);
while (number_to_convert != 0)
{
converted_number[index] = number_to_convert % base;
number_to_convert = number_to_convert / base;
++index;
}
--index;
printf("\n\nConverted Number from base 10 to base %d= ",base);
for( ; index>=0; index--)
{
printf("%c", base_digits[converted_number[index]]);
}
printf("\n");
}
