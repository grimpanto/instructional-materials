// @copyright 2018 Günter Kolousek

namespace ko {
  using System;
  using System.Linq;
  using System.Diagnostics;

  static class Utility {
      public static bool In<T>(this T item, params T[] list) {
          return list.Contains(item);
      }

      public static string get_full_message(this Exception ex) {
          return ex.InnerException == null
            ? ex.Message
            : ex.Message + " --> " + ex.InnerException.get_full_message();
      }

      public static string shell_exec(string cmd) {
          // replace " in cmd by \"
          var escaped_args = cmd.Replace("\"", "\\\"");

          var process = new Process() {
              StartInfo = new ProcessStartInfo {
                  FileName = "/bin/bash",
                  Arguments = $"-c \"{escaped_args}\"",
                  RedirectStandardOutput = true,
                  UseShellExecute = false,  // false on dotnet core anyway
                  CreateNoWindow = true
              }
          };

          process.Start();
          string result = process.StandardOutput.ReadToEnd();
          process.WaitForExit();

          if (process.ExitCode != 0)
              throw new InvalidOperationException($"Process exited with {process.ExitCode}");

          return result;
      }
  }
}
