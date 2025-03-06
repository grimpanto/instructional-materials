using System;
using static System.Console;
using System.IO;

public class Program {
    public static void Main() {
        DriveInfo[] drives=DriveInfo.GetDrives();
        foreach (var drive in drives) {
            WriteLine(drive.Name);  // -> / or C:\
            WriteLine(drive.DriveFormat);  // -> ext or NTFS
            WriteLine(drive.DriveType);  // -> Fixed or Removable
            WriteLine(drive.RootDirectory);  // -> / or C:\
            WriteLine(drive.VolumeLabel);  // -> / or Windows
            WriteLine(drive.TotalFreeSpace);
            WriteLine(drive.AvailableFreeSpace);
            WriteLine(drive.TotalSize);
            WriteLine();
        }
    }
}
