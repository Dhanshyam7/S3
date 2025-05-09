class Matrix
{   int mat[][];
    int row,col;
    Matrix(int r,int c, int[][] mat1)
    {
       this.mat= new int[r][c];
       this.row=r;
       this.col=c;
       for(int i=0;i<this.row;i++)
        {
          for (int j=0;j<this.col;j++)
          {
             this.mat[i][j]=mat1[i][j];
          }
          System.out.println("\n");
       }

    }
    Matrix(int r,int c)
    {
       this.mat= new int[r][c];
       this.row=r;
       this.col=c;
    }
    Matrix Multi(Matrix mat1)
    {
      int[][] mat3=new int[mat1.row][this.col];
       Matrix matrix3=new Matrix(mat1.row,this.col,mat3);
       for(int i=0;i<mat1.row;i++)
       {
          for (int j=0;j<this.col;j++)
          {  matrix3.mat[i][j]=0;
             for (int k=0;k<this.row;k++)
             {
                matrix3.mat[i][j]+=mat1.mat[i][k]*mat[k][j];
             }
          }
       }
       return matrix3;
    }
    void display()
      {
        for(int i=0;i<this.row;i++)
        {
          for (int j=0;j<this.col;j++)
          {
              System.out.print(this.mat[i][j]+" ");
          }
          System.out.println("\n");
       }
     }

}

public class MatrixMultiply
{
   public static void main(String args[])
   {
      Matrix matrix1=new Matrix(3,2);
      matrix1.mat=new int[][]{{1,2},{3,4},{5,6}};
      System.out.println("matrix 1");
      matrix1.display();
      Matrix matrix2=new Matrix(2,3);
      matrix2.mat=new int[][]{{1,2,3},{4,5,6}};
      System.out.println("matrix 2");
      matrix2.display();
      Matrix res=matrix2.Multi(matrix1);
      res.display();
   }
}




