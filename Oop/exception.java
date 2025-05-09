import java.util.*;
import java.io.*;
class GradeException  extends Exception
{
    public   GradeException(String message)
    {
        super(message);
    }
}
class Student
{
    String name;
    double grade;

   public Student(String name,double grade)throws GradeException
   {
      if(grade<0||grade>100)
      {
          throw new GradeException("Grade must be between 0 and 100 ");
      }
      this.name=name;
      this.grade=grade;
  }
  public void displayinfo()
  {
     System.out.println("Name:"+name+",Grade:"+grade);
  }
}

public class exception
{
    public static void main(String args[])
    {
        try
        {
            Student student=new Student("gokul",150);

            student.displayinfo(); 
        }
        catch(GradeException e)
        {
           System.out.println("InvalidGradeException caught:"+e.getMessage());
        }
        catch(Exception e)
        {
           System.out.println("General Exception caught:"+e.getMessage());
        }
        finally
        {
            System.out.println("all cleared");
        }
    }
}
