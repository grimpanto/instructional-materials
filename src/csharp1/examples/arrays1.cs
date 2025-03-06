
using System;

class Program {    
    static void Main() {
        int[] arr;
        arr = new int[3];
        int[] arr2=new int[]{1,2,3};
        int[] arr3={4,5,6};
        Console.WriteLine(arr[0]); // -> 0
        foreach (var elem in arr2) {
            Console.Write(elem + " ");
        }
        Console.WriteLine("\n" + arr.Length); // -> 3
    }
}
