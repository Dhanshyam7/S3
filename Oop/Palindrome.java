public class Palindrome
{
   public static void main(String args[])
   {
     int j,i;
     char str[]={'m','a','l','a','y','a','l','a','m','\0'};
     for (i=0,j=8;i<j;i++,j--)
     {
	if (str[i]!=str[j])
	   break;
     }
     if (i==j)
	System.out.println("pallindrome");
     else
	System.out.println("not pallindrome");
   }
}
