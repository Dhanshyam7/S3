class Employee
{
   private String name;
   private int age;
   private String phno;
   private String address;
   private int sal;

   protected Employee(String n, int g, String p, String ad, int sa)
   {
      this.name = n;
      this.age = g;
      this.phno = p;
      this.address = ad;
      this.sal = sa;
   }

   protected void print_details()
   {
      System.out.println("Name:  "+this.name);
      System.out.println("Age:   "+this.age);
      System.out.println("Phone: "+this.phno);
      System.out.println("Address:"+this.address);
      this.print_sal();
   }
   private void print_sal()
   {
      System.out.println("salary:"+sal);
   }
}

class  Officer extends Employee
{
   String special;

   public Officer(String n, int g, String p, String ad, int sa,String s)
   {
      super(n,g,p,ad,sa);
      this.special = s;
   }
   public Officer(String n, int g, String p, String ad, int sa) //demonstrate overloading
   {
      super(n,g,p,ad,sa);
   }

   public void print_details()
   {
      super.print_details();
      System.out.println("Specialisation :"+special);
      System.out.println("\n");
   }
}
class Manager extends Employee
{
   String dept;

   public Manager(String n, int g, String p, String ad, int sa,String d)
   {
      super(n,g,p,ad,sa);
      this.dept = d;
   }
   public Manager(String n, int g, String p, String ad, int sa)  //demonstrate overloading
   {
      super(n,g,p,ad,sa);
   }
   public void print_details()
   {
      super.print_details();
      System.out.println("Department :"+dept);
      System.out.println("\n");
   }
}

public class display_employ
{
   public static void main (String[] args)
   {

      Officer of1 = new Officer("Arsha",20,"987654329","Chengannur",50000,"Sports");
      Manager mgr = new Manager("Devika",20,"5678903241","Pattambi",500000,"Dance");
      of1.print_details();
      mgr.print_details();
   }
}
