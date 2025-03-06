
import java.util.logging.*;

public class Test {

   public static void main(String[] args) {

	   /*
	   Logger log = Logger.getLogger("");
	   Logger log1 = Logger.getLogger("com");
	   Logger log2 = Logger.getLogger("com.uberdev");
	   Logger log3 = Logger.getLogger("com.uberdev.db");

	   //log.addHandler(new ConsoleHandler());
	   //log1.addHandler(new ConsoleHandler());
       //log2.addHandler(new ConsoleHandler());
	   //log3.addHandler(new ConsoleHandler());
	   
	   log2.setLevel(Level.WARNING);
       
	   log1.info("hallo log1");  // wird geloggt
	   log2.info("hallo log2");  // NICHT geloggt (auch nicht an log1 weiter)
	   log3.info("hallo log3");  // NICHT geloggt (erbt von log2)


	   log2.setFilter(new Filter() {
			   public boolean isLoggable(LogRecord rec) {
				   return false; }
				   });
		   
	   //log2.severe("severe log2");  // NICHT geloggt (auch nicht an log1 weiter)
	   
	   //log3.setUseParentHandlers(true);
	   log3.setLevel(Level.INFO);
	   log3.info("hallo hallo log3");  // wird jetzt geloggt!

	   Object[] handlers = log.getHandlers();
	   System.out.println(handlers.length);
	   
	   // log3.warning("warning");
	   */

	   Logger log1 = Logger.getLogger("com.ueberdev");
	   Logger log2 = Logger.getLogger("com.ueberdev.db");
	   log1.setFilter(new Filter() {
			   public boolean isLoggable(LogRecord rec) {
				   return false; }
		   });
	   log2.setFilter(new Filter() {
			   public boolean isLoggable(LogRecord rec) {
				   return true; }
		   });
	   log1.info("hallo log1");  // verschwindet im Nirvana
	   log2.info("hallo log2");  // log2, dann log1, dann root-Logger!
   }
}