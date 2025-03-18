/*
 * @copyright 2016 Günter Kolousek
 */

import java.io.BufferedWriter;
import java.io.OutputStreamWriter;
import java.io.IOException;

import java.net.Socket;
import java.net.ServerSocket;
import java.net.BindException;

import java.util.Date;

public class DaytimeServer {

   private Socket sock;

   public DaytimeServer(Socket sock_) {
      sock = sock_;
   }


   // just mimic the thread interface! (now it's not necessary
   // but who cares...)  in fact, it's intentional: so I can make a
   // real multi-threaded server almost without any effort
   public void run() {
      try {
         BufferedWriter out = new BufferedWriter(
               new OutputStreamWriter(sock.getOutputStream()));
         // protocol: send the date in any format
         out.write(new Date().toString());
         // protocol: followed by a newline
         out.newLine();
         out.flush();
      } catch (IOException e) {
         System.out.println(
               "an IO error occurred during writing time to client (" +
               e.getMessage() + ")"
         );
      } finally {
         // protocol: and close the connection
         try { sock.close(); } catch (IOException e) {}
      }
   }


   public void start() {
      run();
   }


   public static void main(String[] args) {
      if (args.length < 1) {
         usage();
      }

      int port = 0;
      try {
         port = Integer.parseInt(args[0]);
      } catch (NumberFormatException e) {
         usage();
      }

      ServerSocket srv_sock = null;

      // creating of the instance (as well as the port binding) is outside of the following while!
      try {
         srv_sock = new ServerSocket(port);
         // creating a server socket and, hence, binding the port possesses it's own error handler!
      } catch (BindException e) { // before IO Exception
         error("Server socket " + port + " already in use or not enough privileges to bind to it!");
      } catch (IOException e) {
         error("An IO exception occured during creating a server socket (" + e.getMessage() + ")");
      }

      while (true) {
         // the try...catch is inside the while!!!
         try {
            System.out.println("just before accept");
            Socket sock = srv_sock.accept();
            DaytimeServer server = new DaytimeServer(sock);
            server.start();
         } catch (IOException e) {
            System.out.println("An IO exception occured during waiting for client (" + e.getMessage() + ")");
            System.out.println("Now retrying...");
         }
      }
   }


   public static void usage() {
      System.out.println("Usage: java DaytimeServer port");
      System.exit(1);
   }


   public static void error(String error) {
      System.out.println(error);
      System.exit(2);
   }

}
