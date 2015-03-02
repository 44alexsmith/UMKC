/*Class: CS 371
  Name: Alexeo Smith
  Assignment: HW #2
  Date: 2/28/2015
  Purpose:This tutorial shows how to create a Java DB application to handle 
  		  table in MySQL using JDBC driver. 
*/

package dbapp;

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.Statement;

import java.sql.*;
import com.mysql.jdbc.jdbc2.optional.MysqlDataSource;

public class DBApp {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try{
			//get db connection
			MysqlDataSource dataSource = new MysqlDataSource();
			dataSource.setServerName("localhost");
			dataSource.setUser("root");
			dataSource.setPassword("");
			dataSource.setDatabaseName("usd5b");
			Connection conn = dataSource.getConnection();
			Statement stmt = conn.createStatement();
			
			//execute query
			ResultSet rset = stmt.executeQuery("select * from student");
			
			//process results of the query
			while(rset.next()){
				System.out.println(rset.getInt("id")+ "," +
				rset.getString("lName")+", "+ rset.getString("fName"));
			}
			//Close connection
			stmt.close();
			conn.close();
		   
		  } catch(Exception e){
			  System.out.println(e);
		  }
		}
	}


