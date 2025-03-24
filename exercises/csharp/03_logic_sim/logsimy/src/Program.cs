// @copyright 2018 Günter Kolousek

using System;

namespace logsimy {
  //using gates.propositional;
  //using variables;
  using circuits;
  class Program {
      static void Main(string[] args) {
          /*
          variables.Variable p2=new variables.Variable();
          variables.Utilities.enable_logging(p2, "p2: ");
          variables.Variable p1=new variables.Variable();
          //p1.connect(p2);
          variables.Utilities.connect(p1, p2);

          p1.value = true;
          p2.reset();
          //Console.WriteLine(p1.value);

          variables.Variable p3=new variables.Variable();
          p3.notify += ((v, reason) => Console.WriteLine(v.value));
          p2.notify += ((v, reason) => p3.value = v.value);
          p1.value = true;
          */
          //TestCircuits.and3();
          //TestCircuits.and_or();
          TestCircuits.flip_flop();
      }
  }
}
