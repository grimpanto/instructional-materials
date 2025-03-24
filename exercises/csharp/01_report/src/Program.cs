// @copyright 2018 Günter Kolousek

namespace ko {

  using System;
  using System.IO;
  using System.Collections.Generic;
  using System.Linq;

  struct Config {
      public string filename;
      public bool sortit;
  }


  struct Record {
      public string product;
      public string salesclerk;
      public double price;
      public int quantity;
      public int month;
      public override string ToString() {
          return string.Format("{0},{1},{2},{3},{4}", product, salesclerk,
            price, quantity, month);
      }
  }


  public class Program {
      static void usage(string msg="") {
          Console.WriteLine(
            "usage: report [--help|-h|-s] [FILE]\n" +
            "Print a sales statistics report ordered by product and" +
              "salesclerk.\n\n" +
            "  --help|-h ... Help!\n" +
            "  -s ... sort it before producing the report\n" +
            "  FILE ... file name or - (stdin). If FILE is missing" +
              "read from stdin");
          if (msg != "")
              Console.WriteLine("\n" + msg);
          Environment.Exit(1);
      }


      static Config parse_argv(string[] args) {
          Config cfg = new Config();
          cfg.filename = "-";

          string state="S";

          foreach (string arg in args) {
              switch (state) {
                case "S":
                  if (arg == "-h" || arg == "--help")
                      usage();
                  else if (arg == "-s") {
                      cfg.sortit = true;
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
                      usage(string.Format("No more options allowed!\n" +
                          "Additional option was : '{0}'", arg));
                  cfg.filename = arg;
                  state = "P";
                  break;
                case "P":
                  usage(string.Format("No more options or parameters allowed!\n"+
                      "Additional argument was: '{0}'", arg));
                  break;
              }
          }
          return cfg;
      }


      static void process(Config cfg) {
          var records=new List<Record>();
          string[] lines;

          // input
          try {
              // Console.WriteLine(File.ReadAllText(cfg.filename));
              lines = File.ReadAllLines(cfg.filename);
              foreach (var line in lines) {
                  var items=line.Split(",");
                  // checking the size is missing... but who cares?
                  var rec=new Record();
                  rec.product = items[0];
                  rec.salesclerk = items[1];
                  rec.price = double.Parse(items[2]);
                  rec.quantity = int.Parse(items[3]);
                  rec.month = int.Parse(items[4]);
                  records.Add(rec);
              }
          } catch (FileNotFoundException) {
              Console.WriteLine(string.Format("File '{0}' not found!",
                  cfg.filename));
              Environment.Exit(2);
          }

          // processing
          if (cfg.sortit) {
              // sorting beforehand
              records.Sort((x, y) => x.salesclerk.CompareTo(y.salesclerk));
              records.Sort((x, y) => x.product.CompareTo(y.product));
              // backup the sorted records
              File.WriteAllLines(cfg.filename + ".bak",
                records.Select(i => i.ToString()));
          }

          control_break(records);
      }


      static private void control_break(List<Record> records) {
          // Programmvorbereitung
          Console.WriteLine(
            "### Umsatzstatistik nach Produkten und Verkäufern ###");
          Console.WriteLine(string.Format("{0,-20} {1,-16} {2,-6}", "Produkt",
              "Verkäufer", "Umsatzsumme"));
          IEnumerator<Record> rec_iter=records.GetEnumerator();
          double total_sales=0;
          bool rec_valid=rec_iter.MoveNext();
          while (rec_valid) {
              Record rec=rec_iter.Current;
              // Gruppenvorbereitung
              double product_sales = 0;
              Console.WriteLine();
              string curr_product = rec.product;
              while (rec_valid && curr_product == rec.product) {
                  // Untergruppenvorbereitung
                  double salesclerk_sales=0;
                  string curr_salesclerk = rec.salesclerk;
                  while (rec_valid && curr_product == rec.product &&
                    curr_salesclerk == rec.salesclerk) {
                      // Einzelsatzverarbeitung
                      salesclerk_sales += (rec.price * rec.quantity);
                      rec_valid = rec_iter.MoveNext();
                      rec = rec_iter.Current;
                  }
                  // Untergruppennachbearbeitung
                  Console.WriteLine(string.Format("{0,-20} {1,-16} {2,-6} *",
                      curr_product, curr_salesclerk, salesclerk_sales));
                  product_sales += salesclerk_sales;
              }
              // Gruppennachbereitung
              Console.WriteLine(string.Format("{0,-20} {1,-16} {2,-6} **",
                  curr_product, "", product_sales));
              total_sales += product_sales;
          }
          // Programmnachbereitung
          Console.WriteLine("\n{0,-20} {1,-16} {2,-6} ***", "Gesamtumsatz",
            "", total_sales);
      }

      static public int Main(string[] args) {
          Config cfg = parse_argv(args);

          process(cfg);

          return 1;
      }
  }
}
