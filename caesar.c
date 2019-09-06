#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char Wrap(char ch,int k);

int main(int argc, string argv[])
{
    if(argc != 2)
    {
        printf("Usage: ./caesar key \n");
        return 1;
    }
    
    int l = strlen(argv[1]);
    
    for(int i = 0; i < l;i++)
    {
        if(isdigit(argv[1][i]) == 0)
        {
            printf("Usage: ./caesar key \n");
            return 1;
        }
    }
     
    int k = atoi(argv[1]);
    
    string code = get_string("plaintext: ");
    
    int len = strlen(code);
    
    for (int j=0 ; j < len ;j++)
    {
        
        code[j] = Wrap(code[j],k);
    }  
           
    printf ("ciphertext: %s\n", code);
}

char Wrap (char ch,int k)
{
    if (isupper(ch))
    {         
        ch = ch - 65;   
        if (ch + k > 25 )  
        {      
            ch = 0 + (ch + k)%26;
        } else   
        {       
            ch = ch + k;     
        }
             
        ch = ch + 65 ;
        return ch;
           
    } 
    if (islower(ch))
    {
        ch = ch - 97;   
        if (ch + k > 25 )  
        {      
            ch = 0 + (ch + k)%26;
        } else   
        {       
            ch = ch + k;     
        }
             
        ch = ch + 97 ;
        return ch;
    }
    return ch;
}
