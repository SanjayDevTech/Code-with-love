import java.net.Socket;

public class DiscoverHostSocket {
    public static void main(String[] args) {
         // Check localhost port 1 to 100
        Socket theSocket = null;
        String host = "localhost";
        for (int i =0; i <=5000; i++){
        try {
            theSocket = new Socket(host, i);
            System.out.println("There is a server on port " + i + " of " + host);    
        } catch (Exception e) {  
        } finally{
            try{
                theSocket.close();
            }catch(Exception e){

            }
        }
        }
    }
}