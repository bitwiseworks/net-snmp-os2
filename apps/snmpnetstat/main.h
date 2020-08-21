
#ifndef MAXHOSTNAMELEN
#define MAXHOSTNAMELEN	64
#endif

extern  netsnmp_session *ss;
NETSNMP_IMPORT
int netsnmp_query_get(    netsnmp_variable_list *list,
                          netsnmp_session       *session);
NETSNMP_IMPORT
int netsnmp_query_getnext(netsnmp_variable_list *list,
                          netsnmp_session       *session);
NETSNMP_IMPORT
int netsnmp_query_walk(   netsnmp_variable_list *list,
                          netsnmp_session       *session);

#ifndef AF_INET6
#define AF_INET6	10
#endif

#ifndef NI_MAXHOST
#define NI_MAXHOST      1025
#endif

#ifdef __OS2__
struct in6_addr {
        u_int8_t s6_addr[16];
};

struct sockaddr_in6 {
        u_char  sin6_len;
        u_char  sin6_family;
        u_short sin6_port;
        u_int   sin6_flowinfo;
        struct  in6_addr sin6_addr;
};
#endif