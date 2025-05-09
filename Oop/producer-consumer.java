//producer consumer problem
class Q
{
    int n;
    Boolean val=true;
    synchronized void put(int n)
    {
        while(!val)
            try
            {
                wait();
            }
            catch (InterruptedException e) {}
        val=false;
        this.n=n;
        System.out.println("put"+n);
        notify();
    }
    synchronized void get()
    {
         while(val)
            try
            {
                wait();
            }
            catch (InterruptedException e) {}
        val=true;
        System.out.println("get"+n);
        notify();
    }
}
class Producer implements Runnable
{   Q q;
    Producer(Q q)
    {
        this.q=q;
        new Thread(this).start();
    }
    
    public void run()
    {
        int i=0;
        while(true)
            q.put(i++);
    }
}
class Consumer implements Runnable
{
    Q q;
    Consumer(Q q)
    {
        this.q=q;
        new Thread(this).start();
    }
    
    public void run()
    {
        while(true)
            q.get();
    }
}
public class Main
{
    public static void main(String[] args)
    {
        Q q=new Q();
        new Producer(q);
        new Consumer(q);
    }
}
