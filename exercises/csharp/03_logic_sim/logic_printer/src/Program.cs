// @copyright 2018 Günter Kolousek

using System;
using static System.Console;

namespace logic_printer {

  namespace propositional {
    public static class Printer {
        public static void print_header1(string title) {
            WriteLine(" a | " + title);
            WriteLine("--------");
        }

        public static void print_header2(string title) {
            WriteLine(" a | b | " + title);
            WriteLine("---------------");
        }

        public static void print_table2(Func<bool, bool, bool> op) {
            for (int a=0; a < 2; ++a)
                for (int b=0; b < 2; ++b)
                    WriteLine($" {a} | {b} |   {Convert.ToInt32(op(Convert.ToBoolean(a), Convert.ToBoolean(b)))}");
        }

        public static void print_table1(Func<bool, bool> op) {
            for (int a=0; a < 2; ++a)
                WriteLine($" {a} |  {Convert.ToInt32(op(Convert.ToBoolean(a)))}");
        }

        public static void print_conj_table() {
            print_header2("a & b");
            print_table2((a, b) => logics.propositional.Operators.conj(a, b));
        }

        public static void print_disj_table() {
            print_header2("a | b");
            print_table2((a, b) => logics.propositional.Operators.disj(a, b));
        }

        public static void print_anti_table() {
            print_header2("a ^ b");
            print_table2((a, b) => logics.propositional.Operators.anti(a, b));
        }

        public static void print_neg_table() {
            print_header1("!a");
            print_table1((a) => logics.propositional.Operators.neg(a));
        }

        public static void print_imp_table() {
            print_header2("a -> b");
            print_table2((a, b) => logics.propositional.Operators.imp(a, b));
        }

        public static void print_equiv_table() {
            print_header2("a <-> b");
            print_table2((a, b) => logics.propositional.Operators.imp(a, b));
        }

        public static void print_all() {
            WriteLine("Propositional Logic");
            WriteLine("===================");
            WriteLine();
            print_conj_table();
            WriteLine();
            print_disj_table();
            WriteLine();
            print_anti_table();
            WriteLine();
            print_neg_table();
            WriteLine();
            print_imp_table();
            WriteLine();
            print_equiv_table();
            WriteLine();
        }
    }
  }

  namespace lukasiewicz3 {
    public static class Printer {
        public static void print_header1(string title) {
            WriteLine(" a | " + title);
            WriteLine("--------");
        }

        public static void print_header2(string title) {
            WriteLine(" a | b | " + title);
            WriteLine("---------------");
        }

        public static string to_string(bool? op) {
            return op.HasValue ? Convert.ToInt32(op).ToString() : "½";
        }

        public static void print_table2(Func<bool?, bool?, bool?> op) {
            bool?[] values={false, null, true};
            foreach (bool? a in values)
                foreach (bool? b in values)
                    WriteLine($" {to_string(a)} | {to_string(b)} |   {to_string(op(a, b))}");
        }

        public static void print_table1(Func<bool?, bool?> op) {
            bool?[] values={false, null, true};
            foreach (bool? a in values)
                WriteLine($" {to_string(a)} |  {to_string(op(a))}");
        }

        public static void print_conj_table() {
            print_header2("a & b");
            print_table2((a, b) => logics.lukasiewicz3.Operators.conj(a, b));
        }

        public static void print_disj_table() {
            print_header2("a | b");
            print_table2((a, b) => logics.lukasiewicz3.Operators.disj(a, b));
        }

        public static void print_anti_table() {
            print_header2("a ^ b");
            print_table2((a, b) => logics.lukasiewicz3.Operators.anti(a, b));
        }

        public static void print_neg_table() {
            print_header1("!a");
            print_table1((a) => logics.lukasiewicz3.Operators.neg(a));
        }

        public static void print_imp_table() {
            print_header2("a -> b");
            print_table2((a, b) => logics.lukasiewicz3.Operators.imp(a, b));
        }

        public static void print_equiv_table() {
            print_header2("a <-> b");
            print_table2((a, b) => logics.lukasiewicz3.Operators.equiv(a, b));
        }

        public static void print_all() {
            WriteLine("Lukasiewicz L3");
            WriteLine("===================");
            WriteLine();

            print_conj_table();
            WriteLine();
            print_disj_table();
            WriteLine();
            print_anti_table();
            WriteLine();
            print_neg_table();
            WriteLine();
            print_imp_table();
            WriteLine();
            print_equiv_table();
            WriteLine();
        }
    }
  }


    namespace lukasiewiczn {
    public static class Printer {
        public static void print_header1(string title) {
            WriteLine("   a   |  " + title);
            WriteLine("----------------");
        }

        public static void print_header2(string title) {
            WriteLine("   a   |   b   | " + title);
            WriteLine("------------------------");
        }

        public static void print_table2(Func<double, double, double> op) {
            double[] values={0, 1.0/3, 2.0/3, 1};
            foreach (double a in values)
                foreach (double b in values)
                    WriteLine($" {a:f} | {b:f} | {op(a, b):f}");
        }

        public static void print_table1(Func<double, double> op) {
            double[] values={0, 1.0/3, 2.0/3, 1};
            foreach (double a in values)
                WriteLine($" {a:f} | {op(a):f}");
        }

        public static void print_conj_table() {
            print_header2("a & b");
            print_table2((a, b) => logics.lukasiewiczn.Operators.conj(a, b));
        }

        public static void print_disj_table() {
            print_header2("a | b");
            print_table2((a, b) => logics.lukasiewiczn.Operators.disj(a, b));
        }

        public static void print_anti_table() {
            print_header2("a ^ b");
            print_table2((a, b) => logics.lukasiewiczn.Operators.anti(a, b));
        }

        public static void print_neg_table() {
            print_header1("!a");
            print_table1((a) => logics.lukasiewiczn.Operators.neg(a));
        }

        public static void print_imp_table() {
            print_header2("a -> b");
            print_table2((a, b) => logics.lukasiewiczn.Operators.imp(a, b));
        }

        public static void print_equiv_table() {
            print_header2("a <-> b");
            print_table2((a, b) => logics.lukasiewiczn.Operators.equiv(a, b));
        }

        public static void print_all() {
            WriteLine("Lukasiewicz L4");
            WriteLine("===================");
            WriteLine();

            print_conj_table();
            WriteLine();
            print_disj_table();
            WriteLine();
            print_anti_table();
            WriteLine();
            print_neg_table();
            WriteLine();
            print_imp_table();
            WriteLine();
            print_equiv_table();
            WriteLine();
        }
    }
  }

  class Program {
      static void Main(string[] args) {
          propositional.Printer.print_all();
          lukasiewicz3.Printer.print_all();
          lukasiewiczn.Printer.print_all();
      }
  }
}
