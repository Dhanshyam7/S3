public class sort
{
   public static void main(String args[])
   {
     int arr[]={2,5,6,8,3,4,9};
     srch s=new srch();
     s.search(arr,7,8);

   }
}

class srch
{
   void search(int arr[],int len,int key)
   {//sorting array
     for(int i=1;i<len;i++)
     { 
         for(int j=0;j<len-i;j++)
         { 
            if(arr[j]>arr[j+1])
            { 
               int temp=arr[j];
               arr[j]=arr[j+1];
               arr[j+1]=temp;
            }
         }
      }
      System.out.println("printing sorted array");
      for(int i=0;i<len;i++)
      {
         System.out.print(arr[i]+ " ");
      }
      System.out.println();
      //searching
      int mid,high=len,low=0;
      while(high>low)
      {
         mid=(low+high)/2;
	 if (arr[mid]==key)
	 {
	    System.out.println("item found at index "+mid);
	    return;
         }
	 else if (key >arr[mid])
	 {
	    low=mid+1;
         }
         else if (key <arr[mid])
         {
            high=mid-1;
         }
      }
      System.out.println("item not found");
   }
}

