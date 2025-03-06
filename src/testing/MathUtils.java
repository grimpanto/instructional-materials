import java.util.logging.*;
import java.io.*;
     
public class MathUtils {
    public static void main(String argv[]) throws IOException {
        Handler fh = new FileHandler("%t/all.log");  // tmp dir
		fh = new ConsoleHandler();
        Logger logger = Logger.getLogger("at.ac.htlwrn.math");
		Logger.getLogger("").addHandler(fh);
		logger.addHandler(fh);
        logger.setLevel(Level.FINEST);
		System.out.println(logger.getLevel());
        logger.fine("calculating prime numbers: start");
        try {
            //PrimesCalculator.calculate();
        } catch (Exception e) {
            logger.log(Level.WARNING,
					   "calculating prime numbers: failed", e);
        }
        logger.fine("calculating prime numbers: done");
    }
}