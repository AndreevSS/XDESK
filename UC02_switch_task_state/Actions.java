/*
 * LoadRunner Java script.
 * Description: Oracle Database Testing via JDBC
 */

import lrapi.lr;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.*;

public class Actions
{
    // Create global connection variable
    private Connection connection;

    // VUser Init
    public int init() throws ClassNotFoundException, SQLException {
        // Initialize DB connection
        //connection = null;
        try {
	    // Load Oracle JDBC Driver
            Class.forName("oracle.jdbc.driver.OracleDriver");
        //  Class.forName("com.mysql.jdbc.Driver");
        } catch (Exception ex) {
	    // If driver load is unsuccessful
	    lr.log_message("Database Driver not found");
	    lr.abort();
	}
	try {
	    // Specify the JDBC Connection String (jdbc:oracle:thin:@HOST:PORT:SID)jdbc:oracle:thin

		connection = DriverManager.getConnection("jdbc:oracle:thin:@192.168.14.53:1522:orcl","c##x5","c##x5");
		
	    lr.log_message("JDBC Connection Successful");
        } catch (SQLException e) {
        	e.printStackTrace();
	    // If Connection Failed
	    lr.log_message("Database Connection Failed, Please check your connection string");
	    lr.abort();
	}
	    return 0;
    } //end of init

    public int action() throws ClassNotFoundException, SQLException {

	// Database Query Example 1
	lr.start_transaction("Database_Query_1");
	database_query(
		"update ticket set state_id = 1 where state_id = -1");
	lr.end_transaction("Database_Query_1", lr.AUTO);

	// Database Query Example 2
	lr.start_transaction("Database_Query_2");
	database_query("insert into task (id, Ticket_id, state_id, header, priority_id, text, client_id, create_date, external_system, external_id, change_id, guid, contractor_id, solution_group_id, last_edit_date, engineer_id) select id, id, state_id, header, '3', text, applicant_id, '1511190000000', 'ASKO', 'TSK_1800000','IDC2D620524153zdzPWAoX9OFgW4UB', 'd830c5ee-9b77-4bd1-879a-0c4d2c282a67', '102', '9', last_edit_date, '103' from ticket where state_id = 1 and NOT EXISTS (SELECT * FROM task WHERE task.Ticket_id = ticket.id)");
    lr.end_transaction("Database_Query_2", lr.AUTO);

/*	// Database Query Example 3
	lr.start_transaction("Database_Query_3");
	database_query("select * from TABLE_3");
	lr.end_transaction("Database_Query_3", lr.AUTO);*/

	return 0;
    } //end of action

    public int end() throws Throwable {
	connection = null;
        return 0;
    } //end of end

    // Function: database_query
    // Argument: SQL Query String
    // Performs an SQL Query String, and returns pass or fail for the current transaction
    //
    public int database_query(String SQL_QUERY) {
       Statement stmt = null;
       ResultSet rset = null;

       try {
	   connection.setAutoCommit(true);
	   stmt = connection.createStatement();
	   rset = stmt.executeQuery(SQL_QUERY);
	   lr.set_transaction_status(lr.PASS);
	   // while (rset.next()) {				// Print the results of the query
	   //     lr.log_message(rset.getString(1));  		// Note: This should be used for debugging only,
	   // }							// as it slows down execution time
	   //lr.log_message("SQL Query Executed Successfully");
	   rset.close();
	} catch (SQLException e) {
	    // SQL Query has failed
	    lr.log_message("Caught Exception: " + e.getMessage());
	    lr.set_transaction_status(lr.FAIL);
	    return 1;
	}
	return 0;
    }
}