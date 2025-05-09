abstract class Shape
{
   abstract protected void numberOfSides();
   abstract protected void area();
   protected void finalize()
   {
      System.out.println("\nFINALIZED\n");
   }

}

class Triangle extends Shape
{  private float a,b;
   Triangle(float a,float b)
   {  super();
      this.a=a;
      this.b=b;
   }
   protected void numberOfSides()
   {
      System.out.println("number of sides of triangle is 3 \n");
   }
   protected void area()
   {
      System.out.println("area of triangle:"+ (b*a)/2);
   }
   protected void finalize()
   {
      System.out.println("\nFINALIZED\n");
   }


}
class Rectangle extends Shape
{  private float a,b;
   Rectangle(float a,float b)
   {  super();
      this.a=a;
      this.b=b;
   }

   protected void numberOfSides()
   {
      System.out.println("number of sides of rectangle is 4 \n");
   }
   protected void area()
   {
      System.out.println("area of rectangle:"+ ((b*a)));
   }


   protected void finalize()
   {
      System.out.println("\nFINALIZED\n");
   }

}
class Hexagon extends Shape
{  private float a;
   Hexagon(float a)
   {  super();
      this.a=a;
   }

   protected void numberOfSides()
   {
      System.out.println("number of sides of hexagon is 6 \n");
   }
   protected void area()
   {
      System.out.println("area of hexagon:"+ (3*1.5*a*a/2));
   }

   protected void finalize()
   {
      System.out.println("\nFINALIZED\n");
   }

}
public class ShapeMain
{
   public static void main(String args[])
   {
      Shape tri= new Triangle(2,3);
      tri.numberOfSides();
      tri.area();
      Rectangle rect= new Rectangle(3,4);
      rect.numberOfSides();
      rect.area();
      Hexagon hex= new Hexagon(5);
      hex.numberOfSides();
      hex.area();
   }
}
