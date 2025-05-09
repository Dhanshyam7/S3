/*this is a java program which prints the numbers inorder using two threads. oddthreads prints odd numbers and eventhread prints even numbers.*/

class common
{
        boolean val=true;
}

class oddthread extends Thread
{
        common c;
        oddthread(common c)
        {
                this.c=c;
        }
        public void run()
        {
                for(int i=1;i<10;i=i+2)
                {
                        while(c.val==false);
                        synchronized (c)
                        {
                            System.out.println(i);
                            c.val=false;
                        }
                }
        }
}
class eventhread extends Thread
{ 
        common c;
        eventhread(common c) 
        { 
                this.c=c;
        }
        public void run()
        { 
                for(int i=2;i<10;i=i+2)
                {
                    while(c.val==true);
                    synchronized(c)
                    {
                        System.out.println(i);
                        c.val=true;
                    }
                }
        }
}

public class Main
{
        public static void main(String args[])
        {
                common c= new common();
                oddthread o=new oddthread(c);
                eventhread e=new eventhread(c);
                o.start();
                e.start();
        }
}
