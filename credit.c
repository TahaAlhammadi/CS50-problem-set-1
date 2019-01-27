#include<stdio.h>
#include<cs50.h>

int find_the_sum1(long cc_num);
int find_the_sum0(long cc_num);
int main(void)
{
    long cc_num;
    int i, sum0 , sum1;
    do     //prompt the user for a positive cc number and reprompt otherwise
    {
       cc_num = get_long("Write the credit card number,please :\n"); 
    }
    while (cc_num<0);
    
    sum0 = find_the_sum0(cc_num); 
    sum1 =find_the_sum1(cc_num);
    if((sum1+sum0)%10 == 0)      //decide the type of the cc number  
    {
        if ( (cc_num >= 340000000000000 && cc_num < 350000000000000) || (cc_num >= 370000000000000 && cc_num < 380000000000000) )
            printf("AMERICAN EXPRESS\n");
        else if (( cc_num >= 5100000000000000 && cc_num < 5600000000000000 ) || (cc_num >=2220000000000000 && cc_num <= 2229999999999999))
            printf("MASTERCARD\n");
        else if ( (cc_num >= 4000000000000 && cc_num < 5000000000000) || (cc_num >= 4000000000000000 && cc_num < 5000000000000000) )
            printf("VISA\n");
        else
            printf("INVALID\n");
    }
    else
    {
        printf("INVIALD\n");
    }
}

int find_the_sum0(long cc_num)    //declare a funcion whose purpose is to find the sum of digit starting from the second last digit
{
    long i;
    int t, zadd, tadd;
    for (i=cc_num/10 , zadd =0 , tadd =0 ; i>0 ; i/=100)
    {        
        if((2*(i%10)) >9 )  
        {
            for (t=2*(i%10) ; t>0 ; t/=10) //find the sum of more than one digit number after double it 
            {
                tadd +=(t%10);
            }

        } 
        else      //find the sum of one-digit numbers 
        {
            zadd +=(2*(i%10));
        }
    }
    tadd +=0;
    return (zadd + tadd);
}

int find_the_sum1(long cc_num)    //declare  a function whose purpose is to find the sum of numbers starting from the last digit with skiping a digit at a time
{
    long i;
    int tadd;
    for (i = cc_num , tadd=0 ;i>0 ; i/=100)
    {
        tadd += i%10;
    }
    return (tadd);
}
