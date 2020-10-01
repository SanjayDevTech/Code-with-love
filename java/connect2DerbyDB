import java.sql.*;  

public class HandleDBExample {  
    public static void main(String args[]) throws Exception {  
        try {  
            Class.forName("org.apache.derby.jdbc.ClientDriver");  
            Connection connect = DriverManager.getConnection("jdbc:derby://localhost:1527/testdb" + System.currentTimeMillis() + ";create=true");  
            Statement stmt = connect.createStatement();  

            System.out.println("Database info: " + connect.getMetaData().getURL() + " " + connect.getMetaData().getDatabaseProductName());  

            String query = "CREATE TABLE EmployeeData( "  
            + "Id INT NOT NULL GENERATED ALWAYS AS IDENTITY, "  
            + "Name VARCHAR(255), "  
            + "Salary INT NOT NULL, "  
            + "Location VARCHAR(255), "  
            + "PRIMARY KEY (Id))";  

            stmt.execute(query);  
            System.out.println("Table created");  

            query = "INSERT INTO EmployeeData("  
            + "Name, Salary, Location) VALUES "  
            + "('Amit', 30000, 'Hyderabad'), "  
            + "('Kalyan', 40000, 'Vishakhapatnam'), "  
            + "('Renuka', 50000, 'Delhi'), "  
            + "('Archana', 15000, 'Mumbai'), "  
            + "('Trupthi', 45000, 'Kochin'), "  
            + "('Suchatra', 33000, 'Pune'), "  
            + "('Rahul', 39000, 'Lucknow'), "  
            + "('Trupthi', 45000, 'Kochin')";  

            stmt.execute(query);  
            System.out.println("Values inserted");  

            ResultSet rs = stmt.executeQuery("Select * from EmployeeData");  
            System.out.println("Contents of the table EmployeeData table:");  
            while(rs.next()) {  
                  System.out.print("ID: "+rs.getInt("ID")+", ");  
                  System.out.print("Name: "+rs.getString("Name")+", ");  
                  System.out.print("Salary: "+rs.getInt("Salary")+", ");  
                  System.out.print("Location: "+rs.getString("Location"));  
                  System.out.println();  
           }  
           connect.close();  
      } catch (Exception e) {  
            throw e;  
      }  
    }  
}
