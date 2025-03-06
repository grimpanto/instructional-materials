using System;

class Program {
    static int sum(params int[] nums) {
        int acc=0;
        foreach (var n in nums) {
            acc += n;
        }
        return acc;
    }
    static void Main() {
        Console.WriteLine(sum(1, 2, 3));
    }
}
