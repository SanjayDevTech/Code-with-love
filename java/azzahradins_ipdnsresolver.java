import java.net.Inet4Address;
import java.net.InetAddress;
import java.net.UnknownHostException;
import java.util.Scanner;

public class ipdnsresolver {
    private static String dns = "";
    private static String ipAddress = "";
    private static String binaryIp = "";

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Input DNS / IP : ");
        boolean isValidAddress = ipValid(sc.nextLine());
        if(isValidAddress){
            IpToDns(ipAddress);
            IpToBinary(ipAddress);
        }else{
            DnsToIp(dns);
            IpToBinary(ipAddress);
        }
        System.out.println("Created by : Azzahra Dinda S");
    }
    
    private static void IpToDns(String ipAddress) {
        try{
            InetAddress inetAddress = InetAddress.getByName(ipAddress);
            dns = inetAddress.getHostName();
            System.out.println("DNS Hostname : " + dns);
        }catch(UnknownHostException ex){
            System.out.println("Host tidak ditemukan");
        }
        
    }
    
    private static void DnsToIp(String dns) {
        try {
            InetAddress inet1 = InetAddress.getByName(dns);
            ipAddress = inet1.getHostAddress();
            System.out.println("IP Address : " + ipAddress);
        } catch (Exception e) {
            System.out.println("Periksa kembali koneksi anda!");
        }
    }

    private static void IpToBinary(String ipAddress) {
        String[] ipArray = ipAddress.split("\\.");
        for(String ip: ipArray){
            // setiap ip nya ubah dulu jadi biner
            String binary = Integer.toBinaryString(Integer.valueOf(ip));
            String bit = "00000000";
            binary = bit.substring(binary.length())+binary;
            // kalau ip address yang akhir cocok dengan ip yang sudah dipecah
            if(ip.equals(ipArray[3])){
                binaryIp += binary;
            }else{
                binaryIp += binary.concat(".");
            }
        }
        System.out.println("IP Binary : " + binaryIp);
    }

    private static boolean ipValid(String input) {
        try {
            InetAddress inetAddress = InetAddress.getByName(input);
            if(inetAddress.getHostAddress().equals(input) && 
                    inetAddress instanceof Inet4Address){
                ipAddress = input;
                return true;
            }else{
                dns = input;
                return false;
            }
	}
	catch (UnknownHostException ex) {
            return false;
        }
    }
}