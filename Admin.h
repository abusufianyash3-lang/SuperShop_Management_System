  #ifndef ADMIN_H
  #define ADMIN_H
 
  typedef struct {
char username[50]; 
char password[50]; 
 } Admin;
 
 unsigned int adminLogin(const Admin* admin);
  #endif // ADMIN_H
