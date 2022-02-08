#include <iostream>
#include <vector>
#include <array>
#include "item.h"
#include "game.h"
//#include <mysql/mysql.h>
//#include "mysql_connection.h"
//#include <cppconn/driver.h>
//#include <cppconn/exception.h>
//#include <cppconn/resultset.h>
//#include <cppconn/statement.h>

std::vector<Item> getGameItems() {
    std::vector<Item> gameItems = {
            {1, "rock",     {3, 4}, {2, 5}},
            {2, "paper",    {1, 5}, {3, 4}},
            {3, "scissors", {2, 4}, {1, 5}},
            {4, "lizard",   {2, 5}, {1, 3}},
            {5, "Spock",    {3, 1}, {2, 4}}
    };

    return gameItems;
}

//int testdb();

int main() {

    Game game = Game(getGameItems());

    game.start();

    return 0;
}
//
//struct connection_details
//{
//    const char *server, *user, *password, *database;
//};
//
//MYSQL* mysql_connection_setup(struct connection_details mysql_details){
//    MYSQL* connection = mysql_init(NULL); // mysql instance
//
////connect database
//    if(!mysql_real_connect(connection, mysql_details.server, mysql_details.user, mysql_details.password, mysql_details.database, 0, NULL, 0)){
//        std::cout << "Connection Error: " << mysql_error(connection) << std::endl;
//        exit(1);
//    }
//
//    return connection;
//}
//
//
//MYSQL_RES* mysql_perform_query(MYSQL *connection, const char *sql_query){
//    //send query to db
//    if(mysql_query(connection, sql_query)){
//        std::cout << "MySQL Query Error: " << mysql_error(connection) << std::endl;
//        exit(1);
//    }
//
//    return mysql_use_result(connection);
//}
//
//int test_db()
//{
//    MYSQL *con;	// the connection
//    MYSQL_RES *res;	// the results
//    MYSQL_ROW row;	// the result rows (array)
//
//    struct connection_details mysqlD;
//    mysqlD.server = "localhost";  // where the mysql database is
//    mysqlD.user = "username"; // user
//    mysqlD.password = "password"; // the password for the database
//    mysqlD.database = "mydatabase";	// the databse
//
//    // connect to the mysql database
//    con = mysql_connection_setup(mysqlD);
//
//    // get the results from executing commands
//    res = mysql_perform_query(con, "select * from tblUsers;");
//
//    std::cout << ("Database Output:\n") << std::endl;
//
//    while ((row = mysql_fetch_row(res)) != NULL){
//        // the below row[] parameters may change depending on the size of the table and your objective
//        std::cout << row[0] << " | " << row[1] << " | " << row[2] << " | " << row[3] << " | " << row[4] << std::endl << std::endl;
//    }
//
//    // clean up the database result
//    mysql_free_result(res);
//
//    // close database connection
//    mysql_close(con);
//
//    return 0;
//}
//
//int testdb()
//{
//    std::cout << std::endl;
//    std::cout << "Running 'SELECT 'Hello World!' << AS _message'..." << std::endl;
//
//    try {
//        sql::Driver *driver;
//        sql::Connection *con;
//        sql::Statement *stmt;
//        sql::ResultSet *res;
//
//        /* Create a connection */
//        driver = get_driver_instance();
//        con = driver->connect("tcp://127.0.0.1:3306", "root", "admin");
//        /* Connect to the MySQL test database */
//        con->setSchema("test");
//
//        stmt = con->createStatement();
//        res = stmt->executeQuery("SELECT 'Hello World!' AS _message");
//        while (res->next()) {
//            std::cout << "\t... MySQL replies: ";
//            /* Access column data by alias or column name */
//            std::cout << res->getString("_message") << std::endl;
//            std::cout << "\t... MySQL says it again: ";
//            /* Access column data by numeric offset, 1 is the first column */
//            std::cout << res->getString(1) << std::endl;
//        }
//        delete res;
//        delete stmt;
//        delete con;
//
//    } catch (sql::SQLException &e) {
//        std::cout << "# ERR: SQLException in " << __FILE__;
//        std::cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << std::endl;
//        std::cout << "# ERR: " << e.what();
//        std::cout << " (MySQL error code: " << e.getErrorCode();
//        std::cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;
//    }
//
//    std::cout << std::endl;
//
//    return EXIT_SUCCESS;
//}