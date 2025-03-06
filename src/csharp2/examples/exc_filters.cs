using System;
using static System.Console;

public class Program {
    public static void Main() {
        try {
            InvalidOperationException e=new InvalidOperationException();
            e.Data["reason"] = "full";
            throw e;
        } catch (InvalidOperationException e) when ((string)e.Data["reason"] == "empty") {
            WriteLine("Tank leer");
            } catch (InvalidOperationException e) when ((string)e.Data["reason"] == "full") {
            WriteLine("Tank voll");                
        } catch {
            WriteLine("ungültiger Zustand");
        }
    }
}
