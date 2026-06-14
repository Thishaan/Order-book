#include<netinet/in.h> 
#include<sys/socket.h>
#include <netdb.h>

/**
 * 
 * an abstractino
 * 
 * 
 * 
 */


class Connection{




    Connection() =  default;


    inline int establishConnection(){


        int clientSocket = socket(AF_INET, SOCK_STREAM, 0);

        sockaddr_in serverAddress;
        serverAddress.sin_family = AF_INET;
        serverAddress.sin_port = htons(8080);
        serverAddress.sin_addr.s_addr = INADDR_ANY;
        
        if(bind()){



            return -1;
        }

    }


    inline void accept(){


    }


     
};