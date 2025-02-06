#include <QCoreApplication>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QDebug>

void initializeDatabase() {


    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("cam_database.db");


    if (!db.open()) {
        qDebug() << "Error: Unable to open database!";
        return;
    }

    QSqlQuery query;

    // Create Roles table
    QString createRolesTable = R"(
        CREATE TABLE IF NOT EXISTS Roles1 (
            role_id INTEGER PRIMARY KEY AUTOINCREMENT,
            role_name TEXT NOT NULL,
            permissions TEXT NOT NULL
        )
    )";
    if (!query.exec(createRolesTable)) {
        qDebug() << "Failed to create Roles table:" << query.lastError().text();
    }

    // Create Users table
    QString createUsersTable = R"(
        CREATE TABLE IF NOT EXISTS Users1 (
            user_id INTEGER PRIMARY KEY AUTOINCREMENT,
            username TEXT NOT NULL,
            password TEXT NOT NULL,
            role_id INTEGER NOT NULL,
            FOREIGN KEY(role_id) REFERENCES Roles(role_id)
        )
    )";
    if (!query.exec(createUsersTable)) {
        qDebug() << "Failed to create Users table:" << query.lastError().text();
    }
}


void addRole(const QString &roleName, const QString &permissions) {
    QSqlQuery query;
    query.prepare("INSERT INTO Roles1 (role_name, permissions) VALUES (:role_name, :permissions)");
    query.bindValue(":role_name", roleName);
    query.bindValue(":permissions", permissions);

    if (!query.exec()) {
        qDebug() << "Failed to add role:" << query.lastError().text();
    } else {
        qDebug() << "Role added successfully:" << roleName;
    }
}

void addUser(const QString &username, const QString &password, int roleId) {
    QSqlQuery query;
    query.prepare("INSERT INTO Users1 (username, password, role_id) VALUES (:username, :password, :role_id)");
    query.bindValue(":username", username);
    query.bindValue(":password", password);
    query.bindValue(":role_id", roleId);

    if (!query.exec()) {
        qDebug() << "Failed to add user:" << query.lastError().text();
    } else {
        qDebug() << "User added successfully:" << username;
    }
}

bool authenticateUser(const QString &username, const QString &password, QString &roleName) {
    QSqlQuery query;
    query.prepare(R"(
        SELECT Roles1.role_name
        FROM Users1
        INNER JOIN Roles1 ON Users1.role_id = Roles1.role_id
        WHERE Users1.username = :username AND Users1.password = :password
    )");
    query.bindValue(":username", username);
    query.bindValue(":password", password);

    if (!query.exec()) {
        qDebug() << "Authentication query failed:" << query.lastError().text();
        return false;
    }

    if (query.next()) {
        roleName = query.value("role_name").toString();
        qDebug() << "Authentication successful! Role:" << roleName;
        return true;
    } else {
        qDebug() << "Authentication failed: Invalid username or password.";
        return false;
    }
}

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    // Initialize the database
    initializeDatabase();


    // Add roles
    // addRole("Admin", "all_permissions");
    // addRole("Operator", "limited_permissions");
    // addRole("Viewer", "read_only");

    // // Add users
    // addUser("admin_user", "admin_password", 1);
    // addUser("operator_user", "operator_password", 2);
    // addUser("viewer_user", "viewer_password", 3);

    // Authentication test
    QString roleName;
    if (authenticateUser("admin_user", "admin_password", roleName)) {
        qDebug() << "Access granted! User role is:" << roleName;
    } else {
        qDebug() << "Access denied!";
    }

    return a.exec();
}
