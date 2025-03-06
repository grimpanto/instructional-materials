using System;

public class Test {
    public static void Main() {
        StrBox b = new StrBox(); b[0] = "abc";
        Console.WriteLine(b[0]);
    }
}

public class StrBox {
    private string[] box = new string[5];     
    public string this[int idx] {
        get {
            return (0 <= idx && idx <= box.Length) ? 
              box[idx] : null;
        }
        set {
            box[idx] = (0 <= idx && idx <= box.Length) ?
              value : null;
        }
    }
}
