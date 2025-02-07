#include <iostream>
#include <unistd.h>

using namespace std;

/* color */

// bold color
#define BLACK "\e[1;30m";
#define RED "\e[1;31m";
#define GREEN "\e[1;32m";
#define YELLOW "\e[1;33m";
#define BLUE "\e[1;34m";
#define PURPLE "\e[1;35m";
#define CYAN  "\e[1;36m";
#define WHITE "\e[1;37m";

// Background
#define BRBLACK "\e[40m";
#define BRRED "\e[41m";
#define BRGREEN "\e[42m";
#define BRYELLOW "\e[43m";
#define BRBLUE "\e[44m";
#define BRPURPLE "\e[45m";
#define BRCYAN "\e[46m";
#define BRWHITE "\e[47m";

// reset color
#define RESET "\e[0m";

void banner() {
    system("clear");

    cout << CYAN;
    cout <<"_______________________________________________________________" << endl ;
    cout << RED;
    cout << R"(
    dMMMMb  dMMMMb  dMP dMP dMMMMMMP dMMMMMP
   dMP"dMP dMP.dMP dMP dMP    dMP   dMP
  dMMMMK" dMMMMK" dMP dMP    dMP   dMMMP
 dMP.aMF dMP"AMF dMP.aMP    dMP   dMP
dMMMMP" dMP dMP  VMMMP"    dMP   dMMMMMP           )" <<endl;
cout << BLUE;
     cout << R"(
    dMMMMb  .aMMMb  dMMMMb dMMMMMMP dMMMMMP dMMMMb
   dMP.dMP dMP"dMP dMP.dMP   dMP   dMP     dMP.dMP
  dMMMMP" dMP dMP dMMMMK"   dMP   dMMMP   dMMMMK"
 dMP     dMP.aMP dMP"AMF   dMP   dMP     dMP"AMF
dMP      VMMMP" dMP dMP   dMP   dMMMMMP dMP dMP)" <<endl;

    cout << GREEN;
    cout << "\nWilliam Steven (Anon404)" <<endl;
    cout << CYAN;                                                 cout<<"_______________________________________________________________\n" << endl << RESET;
}

int ftp(){
    banner();

    return 0;
}

int ssh(){
    banner();

    return 0;
}

int telnet(){
    banner();

    return 0;
}

int smtp(){
    banner();

    return 0;
}

int mysql(){
    banner();

    return 0;
}

int vnc(){
    banner();

    return 0;
}


int main() {

    banner();
    cout << BRGREEN;
    cout << WHITE;
    cout << "[+] Available  ports \n" <<endl <<RESET;

    cout << GREEN;
    cout << " 1) FTP : 20,21" <<endl;
    cout << " 2) SSH : 22" <<endl;
    cout << " 3) TELNET : 23" <<endl;
    cout << " 4) SMTP : 25" <<endl;
    cout << " 5) MySql : 3306" <<endl;
    cout << " 6) VNC : 5900" <<endl;
    cout << endl << RESET;

    cout << YELLOW;
    int port;
    cout << "[?] Choose port number : ";
    cin >> port ;

    system("sleep 0.5");
    if(port == 1 || port == 20 || port == 21) {
        cout << CYAN;
        cout << "\n[*] Owwh You want FTP port 👀👀" <<endl;
        system("sleep 1");
        ftp();
    } else if(port == 2 || port == 22) {
        cout << CYAN;
        cout << "\n[*] Owwh You want SSH port 👀👀" <<endl;
        system("sleep 1");
        ssh();
    } else if(port == 3 || port == 23) {
        cout << CYAN;
        cout << "\n[*] Owwh You want TELNET port 👀👀" <<endl;
        system("sleep 1");
        telnet();
    } else if(port == 4 || port == 25) {
        cout << CYAN;
        cout << "\n[*] Owwh You want SMTP port 👀👀" <<endl;
        system("sleep 1");
        smtp();
    } else if(port == 5 || port == 3306) {
        cout << CYAN;
        cout << "\n[*] Owwh You want MySql port 👀👀" <<endl;
        system("sleep 1");
        mysql();
    } else if(port == 6 || port == 5900) {
        cout << CYAN;
        cout << "\n[*] Owwh You want VNC port 👀👀" <<endl;
        system("sleep 1");
        vnc();
    } else {
        cout << RED;
        cout << "\n[!] Ops wrong option.......😕" <<endl;
        system("sleep 1 && exit 1");

    }

    return 0;
}
