import java.io.*;
class doublylinkedlist
{
   class Node
   {
      private int data;
      private Node left;
      private Node right;

      Node(int data)
      {
    	this.data=data;
    	this.left=null;
    	this.right=null;
      }
   }
   private Node head=null;
   private Node tail=null;
   public void Insert(int data)
   {
      Node temp=new Node(data);
      if(head==null)
         head=tail=temp;
      else
      {
	 tail.right=temp;
	 temp.left=tail;
	 tail=temp;
      }
      System.out.println("inserted:"+ data);
   }
   public void Delete()
   {
      if(head==null)
         System.out.println("empty");
      else if (head==tail)
      {
          head=tail=null;
      }
      else
      { int data=head.data;
         head=head.right;
  	     head.left=null;
         System.out.println("deleted:"+ data);
      }
   }
   public void Display()
   {
      if(head==null)
         System.out.println("empty");
      else
      {
         Node ptr=head;
         while(ptr!=null)
         {  System.out.print(ptr.data +" ");
            ptr=ptr.right;
         }
	 System.out.println();
      }
   }
}

public class dl
{
   public static void main(String args[])
   {
      doublylinkedlist dl= new doublylinkedlist();
      BufferedReader rd= new BufferedReader(new InputStreamReader(System.in));
      int ch=0;
      try
      {
      while (ch!=4)
      {
         System.out.println("menu:\n1.insert\n2.delete\n3.display\n4.exit");
	 String c=rd.readLine();
	 ch=Integer.parseInt(c);
	 switch(ch)
	 {
	 case 1:System.out.println("enter element:");
	        String rc=rd.readLine();
	        int elt=Integer.parseInt(rc);
                dl.Insert(elt);
                break;
	 case 2:dl.Delete();break;
	 case 3:dl.Display();break;
	 case 4:break;
	 default: System.out.println("invalid choice");
	 }
      }
      }
      catch(Exception e)
      {System.out.println(e);}
   }
}

