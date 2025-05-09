//raising custom exceptions
class EvenException extends Exception
{
    public String toString()
    {
        return "Even found";
    }
}
class OddException extends Exception
{
    public String toString()
    {
        return "Odd found";
    }
}

class ExceptionDemo
{
    void demo(int a) throws EvenException ,OddException
    {
        if (a%2==0)
            throw new EvenException();
        else
            throw new OddException();
    }
}

public class main
{
    public static void main(String args[])
    {
    ExceptionDemo ex=new ExceptionDemo();
    for (int i=0;i<10;i++)
    {
        try
        {
           ex.demo(i);
        }
        catch (EvenException e)
        {
            System.out.println(e);
        }
        catch (OddException e)
        {
            System.out.println(e);
        }
        }
    }
}