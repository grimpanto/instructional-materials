
using System;

class Program {    
    static void Main() {
        //             rows x columns
        int[,] mat=new int[3,3];
        mat[0,0] = 1;
        mat[0,1] = 2;
        mat[0,2] = 3;
        Console.WriteLine(mat[0,0]);  // -> 1
        Console.WriteLine(mat[1,1]);  // -> 0
        Console.WriteLine(mat.Length);  // -> 9
        int[,] mat2={
            {1, 2, 3},
            {4, 5, 6}
        };
        Console.WriteLine(mat2.Rank);  // -> 2
        Console.WriteLine(mat2.GetLength(0));  // -> 3
        Console.WriteLine(mat2.GetLength(1));  // -> 3
    }
}
