using System;
using static System.Console;
using System.IO;

public class RessourceHolder : IDisposable {
    private bool disposed=false; 
    public void Dispose() {
        Dispose(true);
        GC.SuppressFinalize(this);
    }
    protected virtual void Dispose(bool disposing) {
        if (!disposed) {
            if (disposing) {
                WriteLine("cleanup managed objects");
            }
            WriteLine("unmanaged objects: set large fields to null");
            disposed = true;
        } }
    ~RessourceHolder() {
        Dispose (false);
    } }


public class Program {
    public static void Main() {
        using (var rh=new RessourceHolder()) {}
    }
}
