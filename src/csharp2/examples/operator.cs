using System;

public struct Complex {
    public double real;  public double imag;
    public Complex(double real, double imag) {
        this.real = real; this.imag = imag;
    }
    public static Complex operator+(Complex op1, Complex op2) {
        return new Complex(op1.real + op2.real,
          op1.imag + op2.imag);
    }
}

public class Test {
    public static void Main() {
        Complex c1 = new Complex(3, 0);
        Complex c2 = new Complex(1, 1);
        Complex c = c1 + c2;
        Console.WriteLine(c.real + " " + c.imag);
    }
}
