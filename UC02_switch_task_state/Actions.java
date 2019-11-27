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
    
    public int init() throws ClassNotFoundException, SQLException {
	
    // Initialize DB connection
        try {
            Class.forName("oracle.jdbc.driver.OracleDriver");
        } catch (Exception ex) {
	    	lr.log_message("Database Driver not found");
	  		lr.abort();
		}
		try {
        	connection = DriverManager.getConnection("jdbc:oracle:thin:@" + lr.eval_string("{HOST}") + ":" + lr.eval_string("{PORT}") + ":" + lr.eval_string("{SID}") ,lr.eval_string("{Login}") ,lr.eval_string("{Password}") );
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
    	
	database_query("update ticket set state_id = 1 where state_id = -1");

	database_query(
		"insert into task (id, Ticket_id, state_id, header, priority_id, text, client_id, create_date, external_system," +
		"external_id, change_id, guid, contractor_id, solution_group_id, last_edit_date, engineer_id) select id, id, state_id," +
		"header, '3', text, applicant_id, '1511190000000', 'ASKO', 'TSK_1800000','IDC2D620524153zdzPWAoX9OFgW4UB', 'd830c5ee-9b77-4bd1-879a-0c4d2c282a67',"+
		"'102', '9', last_edit_date, '103' from ticket where state_id = 1 and NOT EXISTS (SELECT * FROM task WHERE task.Ticket_id = ticket.id)");
	
	
	connection.commit();
	connection.close();

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
	   connection.setAutoCommit(false);
	   stmt = connection.createStatement();
	   rset = stmt.executeQuery(SQL_QUERY);
	   lr.set_transaction_status(lr.PASS);
	   rset.close();
	} catch (SQLException e) {
	    // SQL Query has failed
	    lr.log_message("Caught Exception: " + e.getMessage());
	    lr.set_transaction_status(lr.FAIL);
	    
	    connection.rollback();
	    connection.close();
	    
	    return 1;
	}
	return 0;
    }
}