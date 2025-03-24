using System;
using System.IO;
using System.Collections.Generic;
using System.Text;

namespace ko.elispy {
  struct Config {
      public string filename;
      public bool generate;
  }

  
  class Elispy {
      static void usage(string msg="") {
          Console.WriteLine(
            "usage: report [--help|-h|-g] [FILE]\n" +
            "Evaluate the elispy expressions of FILE otherwise the REPL will be started.\n\n" +
            "  --help|-h ... Help!\n" +
            "  -g ... generate C# code; only valid if FILE is provided\n" +
            "  FILE ... file name or - (stdin). If FILE is missing start the REPL");
          if (msg != "")
              Console.WriteLine("\n" + msg);
          Environment.Exit(1);
      }


      static Config parse_argv(string[] args) {
          Config cfg = new Config();
          cfg.filename = "";

          string state="S";
        
          foreach (string arg in args) {
              switch (state) {
                case "S":
                  if (arg == "-h" || arg == "--help")
                      usage();
                  else if (arg == "-g") {
                      cfg.generate = true;
                      state = "O";
                  } else if (arg != "-" && arg.StartsWith("-"))
                      usage(string.Format("Unknown option: '{0}'", arg));
                  else {
                      cfg.filename = arg;
                      state = "P";
                  }
                  break;
                case "O":
                  if (arg != "-" && arg.StartsWith("-"))
                      usage(string.Format("No more options allowed!\nAdditional option was : '{0}'", arg));
                  cfg.filename = arg;
                  state = "P";
                  break;
                case "P":
                  usage(string.Format("No more options or parameters allowed!\nAdditional argument was: '{0}'", arg));
                  break;
              }
          }
          if (cfg.generate && cfg.filename == "")
              usage(string.Format("No filename given but code generation requested!"));
          return cfg;
      }


      static void process(Config cfg) {
          //Console.WriteLine(cfg.filename);
          var lexer = new SexpsLexer();

          /*
          lexer.test();
          */

          var ctx=new Context();
          var parser=new SexpsParser(lexer, ctx);

          /*
          parser.test();
          */

          if (cfg.filename == "") {
              var interpreter=new SexpsInterpreter(parser);
              //interpreter.test();
              interpreter.repl();
              return;
          }

          string input=null;

          if (cfg.filename == "-") {
              input = Console.In.ReadToEnd();
          } else {
              try {
                  input = File.ReadAllText(cfg.filename);
              } catch (Exception e) {
                  usage(e.Message);
              }
          }

          try {
              List<Sexp> lst=parser.parse(input);
              if (cfg.generate) {
                  //throw new ArgumentException("NYI");
                  StreamWriter sw=null;
                  try {
                      if (cfg.filename == "-") {
                          sw = new StreamWriter(Console.OpenStandardOutput());
                          sw.AutoFlush = true;
                      } else {
                          sw = new StreamWriter(Path.GetFileNameWithoutExtension(cfg.filename) + ".cs");
                      }
                      var code=new StringBuilder();
                      var cg=new CSharpGenerator(code);
                      cg.start();
                      for (int i=0; i < lst.Count; ++i) {
                          cg.print_indentation();
                          lst[i].accept(cg);
                          code.Append(";\n");
                      }
                      cg.end();
                      sw.WriteLine(code);
                  } catch (Exception) {
                      throw;
                  } finally {
                      sw.Close();
                  }
              } else {                  
                  for (int i=0; i < lst.Count; ++i) {
                      Sexp res=lst[i].eval(ctx);
                      if (i == lst.Count - 1 && cfg.filename == "-")
                          Console.WriteLine(res);
                  }
              }
          } catch (Exception e) {
              Console.WriteLine(e.get_full_message());
          }
      }

      static int Main(string[] args) {
          Config cfg = parse_argv(args);

          process(cfg);
          return 1;
      }
  }
}
