#include "database.h"
using namespace ::mysqlx;

void printRow(Row row){
    std::cout << row[1] << std::endl;
};

int main() {
    Session mySession(SessionOption::HOST, "localhost",
                      SessionOption::PORT, 33060,
                      SessionOption::USER, "root",
                      SessionOption::PWD, "admin");

    Schema myDb = mySession.getSchema("rps_db");

    mySession.sql("USE rps_db").execute();
    auto MyResult = mySession.sql("SELECT * FROM items").execute();

    auto rowList = MyResult.fetchAll();

    std::for_each(rowList.begin(), rowList.end(), printRow);
    return 0;
}
