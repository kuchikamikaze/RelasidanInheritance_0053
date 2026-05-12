#include <iostream>
#include <string>
using namespace std;

// pembuatan class user
class User {

protected:
    // member variable
    static int globalId;
    int id;
    string nama;
    string email;

public:
    // constructor
    User(string pNama, string pEmail)
        : nama(pNama), email(pEmail) {

        id = generateId();
    }

    // function generate id
    int generateId() {
        return ++globalId;
    }

    // getter
    int getId() {
        return id;
    }

    string getNama() {
        return nama;
    }

    string getEmail() {
        return email;
    }
};

// inisialisasi static variable
int User::globalId = 0;

// pembuatan class member
class Member : public User {

private:
    bool status;

public:
    // constructor
    Member(string pNama, string pEmail, bool pStatus)
        : User(pNama, pEmail), status(pStatus) {}

    // function show profile
    void showProfile() {

        cout << "===== PROFILE MEMBER =====" << endl;
        cout << "ID     : " << id << endl;
        cout << "Nama   : " << nama << endl;
        cout << "Email  : " << email << endl;
        cout << "Status : ";

        if (status == true) {
            cout << "Aktif" << endl;
        } else {
            cout << "Nonaktif" << endl;
        }

        cout << endl;
    }

    // getter status
    bool getStatus() {
        return status;
    }

    // setter status
    void setStatus(bool pStatus) {
        status = pStatus;
    }
};

// pembuatan class admin
class Admin : public User {

public:
    // constructor
    Admin(string pNama, string pEmail)
        : User(pNama, pEmail) {}

    // function show all member
    void showAllMember(Member member1, Member member2) {

        cout << "===== DATA MEMBER =====\n" << endl;

        member1.showProfile();
        member2.showProfile();
    }

    // function toggle activation member
    void toggleActivationMember(Member &memberObj) {

        if (memberObj.getStatus() == true) {

            memberObj.setStatus(false);

            cout << memberObj.getNama()
                << " berhasil dinonaktifkan\n" << endl;

        } else {

            memberObj.setStatus(true);

            cout << memberObj.getNama()
                << " berhasil diaktifkan\n" << endl;
        }
    }
};

int main() {

    // membuat object member
    Member member1("Andi", "andi@gmail.com", true);
    Member member2("Budi", "budi@gmail.com", false);

    // membuat object admin
    Admin admin1("Admin Utama", "admin@gmail.com");

    // menampilkan semua member
    admin1.showAllMember(member1, member2);

    // mengubah status member
    admin1.toggleActivationMember(member2);

    // menampilkan profile setelah status diubah
    member2.showProfile();

    return 0;
}