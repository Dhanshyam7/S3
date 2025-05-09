/*Write a Java program that implements a multi-threaded program which has three threads.
First thread generates a random integer every 1 second. If the value is even, second
thread computes the square of the number and prints. If the value is odd the third thread
will print the value of cube of the number.*/

import java.util.Random; 
class randomno extends Thread 
{ 
   Random r=new Random(); 
   boolean etrack,otrack; 
   int num; 
   public void run() 
   { 
        for(int i=0;i<20;i++) 
        { 
            num=r.nextInt(100); 
            if(num%2==0) 
            { 
                etrack=true; 
                otrack=false; 
            } 
            else{ 
                otrack=true; 
                etrack=false;
            } 
           try 
           { 
               Thread.sleep(1000); 
           } 
           catch(Exception e) 
           {}
        }
   } 
} 
class even extends Thread 
{ 
    randomno r; 
    public even(randomno r) 
    { 
        this.r=r; 
    } 
    public void run() 
    { 
        for(int i =0;i<20;i++) 
        { 
          int n=r.num; 
          if(r.etrack==true)
          { 
              System.out.println(n+ " = "+Math.pow(n,2)); 
          }
          r.etrack=false;
          try 
          { 
              Thread.sleep(1000); 
               
          } 
          catch(Exception e) 
          { 
          } 
           
        } 
    } 
} 
class odd extends Thread 
{ 
    randomno r; 
   public odd(randomno r) 
    { 
        this.r=r; 
    } 
    public void run() 
    { 
        for(int i=0;i<20;i++) 
        { 
            int n=r.num; 
            if(r.otrack==true) 
            { 
                System.out.println(n+ " = "+Math.pow(n,3)); 
            } 
             r.otrack=false;
            try 
            { 
                Thread.sleep(1000); 
            } 
            catch(Exception e) 
            {} 
        } 
    } 
     
} 
class Main { 
    public static void main(String[] args) { 
         randomno r=new randomno(); 
         odd o=new odd(r); 
         even e=new even(r); 
         r.start(); 
         o.start(); 
         e.start(); 
    } 
}