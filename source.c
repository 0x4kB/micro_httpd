typedef long jmp_buf[8];
typedef unsigned int ml_size_t;
typedef int ml_off_t;
typedef unsigned int uint32_t;
typedef unsigned char uint8_t;
typedef unsigned long size_t;
typedef int bool;
inline void __attribute__((noreturn,always_inline))__ABORT(){
 __asm__("xor %esp,%esp\nxor %ebp,%ebp\nret");
 __builtin_unreachable();
}
typedef struct _text_match { char *pos; int len; } text_match;
typedef int FILE;
typedef union { FILE *F; int i, fd;} mfl_union;
typedef struct { int quot; int rem; } div_t;
typedef struct { long int quot; long int rem; } ldiv_t;
typedef struct { unsigned int quot; unsigned int rem; } uidiv_t;
typedef struct { unsigned long int quot; unsigned long int rem; } uldiv_t;
typedef void (*sighandler_t)(int);
typedef void (functionp)(void);
typedef struct {
  int tz_minuteswest;
  int tz_dsttime;
} timezone;
typedef long time_t;
typedef long suseconds_t;
typedef unsigned useconds_t;
struct timeval { time_t tv_sec; suseconds_t tv_usec; };
struct itimerval {
  struct timeval it_interval;
  struct timeval it_value;
};
typedef unsigned long size_t;
typedef unsigned char uchar;
typedef int wchar_t;
typedef long double double_t;
typedef float float_t;
typedef struct { long long __ll; long double __ld; } max_align_t;
typedef struct { union { int __i[14]; volatile int __vi[14]; unsigned long __s[7]; } __u; } pthread_attr_t;
typedef struct { union { int __i[10]; volatile int __vi[10]; volatile void *volatile __p[5]; } __u; } pthread_mutex_t;
typedef struct { union { int __i[10]; volatile int __vi[10]; volatile void *volatile __p[5]; } __u; } mtx_t;
typedef struct { union { int __i[12]; volatile int __vi[12]; void *__p[6]; } __u; } pthread_cond_t;
typedef struct { union { int __i[12]; volatile int __vi[12]; void *__p[6]; } __u; } cnd_t;
typedef struct { union { int __i[14]; volatile int __vi[14]; void *__p[7]; } __u; } pthread_rwlock_t;
typedef struct { union { int __i[8]; volatile int __vi[8]; void *__p[4]; } __u; } pthread_barrier_t;
typedef unsigned long uintptr_t;
typedef long ssize_t;
typedef long intptr_t;
typedef long regoff_t;
typedef long register_t;
typedef signed char int8_t;
typedef signed short int16_t;
typedef signed int int32_t;
typedef signed long int64_t;
typedef signed long intmax_t;
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long uint64_t;
typedef unsigned long u_int64_t;
typedef unsigned long uintmax_t;
typedef unsigned mode_t;
typedef unsigned long nlink_t;
typedef long off_t;
typedef unsigned long ino_t;
typedef unsigned long dev_t;
typedef long blksize_t;
typedef long blkcnt_t;
typedef unsigned long fsblkcnt_t;
typedef unsigned long fsfilcnt_t;
typedef unsigned wint_t;
typedef unsigned long wctype_t;
typedef void * timer_t;
typedef int clockid_t;
typedef long clock_t;
struct timespec { time_t tv_sec; long tv_nsec; };
typedef int pid_t;
typedef unsigned id_t;
typedef unsigned uid_t;
typedef unsigned gid_t;
typedef int key_t;
typedef struct __mbstate_t { unsigned __opaque1, __opaque2; } mbstate_t;
typedef struct __locale_struct * locale_t;
struct iovec { void *iov_base; size_t iov_len; };
typedef unsigned socklen_t;
typedef unsigned short sa_family_t;
struct winsize {
 unsigned short ws_row;
 unsigned short ws_col;
 unsigned short ws_xpixel;
 unsigned short ws_ypixel;
};
struct stat {
  dev_t st_dev;
  ino_t st_ino;
  nlink_t st_nlink;
  mode_t st_mode;
  uid_t st_uid;
  gid_t st_gid;
  unsigned int __pad0;
  dev_t st_rdev;
  off_t st_size;
  blksize_t st_blksize;
  blkcnt_t st_blocks;
  struct timespec st_atim;
  struct timespec st_mtim;
  struct timespec st_ctim;
  long __unused[3];
};
struct sockaddr {
 sa_family_t sa_family;
 char sa_data[14];
};
typedef unsigned char u_int8_t;
typedef unsigned short u_int16_t;
typedef unsigned u_int32_t;
typedef char *caddr_t;
typedef unsigned char u_char;
typedef unsigned short u_short, ushort;
typedef unsigned u_int, uint;
typedef unsigned long u_long, ulong;
typedef long long quad_t;
typedef unsigned long long u_quad_t;
int isalnum_l(int, locale_t);
int isalpha_l(int, locale_t);
int isblank_l(int, locale_t);
int iscntrl_l(int, locale_t);
int isdigit_l(int, locale_t);
int isgraph_l(int, locale_t);
int islower_l(int, locale_t);
int isprint_l(int, locale_t);
int ispunct_l(int, locale_t);
int isspace_l(int, locale_t);
int isupper_l(int, locale_t);
int isxdigit_l(int, locale_t);
int tolower_l(int, locale_t);
int toupper_l(int, locale_t);
typedef int8_t int_fast8_t;
typedef int64_t int_fast64_t;
typedef int8_t int_least8_t;
typedef int16_t int_least16_t;
typedef int32_t int_least32_t;
typedef int64_t int_least64_t;
typedef uint8_t uint_fast8_t;
typedef uint64_t uint_fast64_t;
typedef uint8_t uint_least8_t;
typedef uint16_t uint_least16_t;
typedef uint32_t uint_least32_t;
typedef uint64_t uint_least64_t;
struct itimerspec {
 struct timespec it_interval;
 struct timespec it_value;
};
struct timex {
 int modes;
 long offset;
 long freq;
 long maxerror;
 long esterror;
 int status;
 long constant;
 long precision;
 long tolerance;
 struct timeval time;
 long tick;
 long ppsfreq;
 long jitter;
 int shift;
 long stabil;
 long jitcnt;
 long calcnt;
 long errcnt;
 long stbcnt;
 int tai;
};
struct inotify_event {
 int wd;
 uint32_t mask, cookie, len;
 char name[];
};
struct statx_timestamp{
  int64_t tv_sec;
  uint32_t tv_nsec;
  int32_t __statx_timestamp_pad1[1];
};
struct statx{
  uint32_t stx_mask;
  uint32_t stx_blksize;
  uint64_t stx_attributes;
  uint32_t stx_nlink;
  uint32_t stx_uid;
  uint32_t stx_gid;
  uint16_t stx_mode;
  uint16_t __statx_pad1[1];
  uint64_t stx_ino;
  uint64_t stx_size;
  uint64_t stx_blocks;
  uint64_t stx_attributes_mask;
  struct statx_timestamp stx_atime;
  struct statx_timestamp stx_btime;
  struct statx_timestamp stx_ctime;
  struct statx_timestamp stx_mtime;
  uint32_t stx_rdev_major;
  uint32_t stx_rdev_minor;
  uint32_t stx_dev_major;
  uint32_t stx_dev_minor;
  uint64_t __statx_pad2[14];
};
typedef long long __kernel_long_t;
typedef unsigned long __kernel_ulong_t;
typedef int sig_atomic_t;
typedef void (*__sighandler_t) (int);
typedef __sighandler_t sig_t;
typedef unsigned long __u64;
typedef unsigned int __u32;
typedef signed long __s64;
typedef signed int __s32;
typedef unsigned short __u16;
typedef signed short __s16;
struct fsxattr {
 uint32_t fsx_xflags;
 uint32_t fsx_extsize;
 uint32_t fsx_nextents;
 uint32_t fsx_projid;
 uint32_t fsx_cowextsize;
 unsigned char fsx_pad[8];
};
struct prctl_mm_map {
 uint64_t start_code;
 uint64_t end_code;
 uint64_t start_data;
 uint64_t end_data;
 uint64_t start_brk;
 uint64_t brk;
 uint64_t start_stack;
 uint64_t arg_start;
 uint64_t arg_end;
 uint64_t env_start;
 uint64_t env_end;
 uint64_t *auxv;
 uint32_t auxv_size;
 uint32_t exe_fd;
};
typedef long __band_t;
typedef union sigval {
  int sival_int;
  void *sival_ptr;
} sigval_t;
typedef struct siginfo {
  int32_t si_signo;
  int32_t si_errno;
  int32_t si_code;
  union {
    char __pad[128 - 2*sizeof(int) - sizeof(long)];
    struct {
      pid_t _pid;
      uid_t _uid;
    } _kill;
    struct {
      uint32_t _timer1;
      uint32_t _timer2;
    } _timer;
    struct {
      pid_t _pid;
      uid_t _uid;
      sigval_t _sigval;
    } _rt;
    struct {
      pid_t _pid;
      uid_t _uid;
      int32_t _status;
      clock_t _utime;
      clock_t _stime;
    } _sigchld;
    struct {
      void *_addr;
    } _sigfault;
    struct {
      __band_t _band;
      int32_t _fd;
    } _sigpoll;
  } _sifields;
} siginfo_t;
typedef struct __sigset_t { unsigned long sig; } sigset_t;
struct sigaction {
  void (*sa_handler)(int);
  unsigned long sa_flags;
  void (*restorer)(void);
  sigset_t sa_mask;
};
struct tms
  {
    clock_t tms_utime;
    clock_t tms_stime;
    clock_t tms_cutime;
    clock_t tms_cstime;
  };
struct oldold_utsname {
        char sysname[9];
        char nodename[9];
        char release[9];
        char version[9];
        char machine[9];
};
struct old_utsname {
        char sysname[65];
        char nodename[65];
        char release[65];
        char version[65];
        char machine[65];
};
struct new_utsname {
        char sysname[64 + 1];
        char nodename[64 + 1];
        char release[64 + 1];
        char version[64 + 1];
        char machine[64 + 1];
        char domainname[64 + 1];
};
struct rusage {
 struct timeval ru_utime;
 struct timeval ru_stime;
 __kernel_long_t ru_maxrss;
 __kernel_long_t ru_ixrss;
 __kernel_long_t ru_idrss;
 __kernel_long_t ru_isrss;
 __kernel_long_t ru_minflt;
 __kernel_long_t ru_majflt;
 __kernel_long_t ru_nswap;
 __kernel_long_t ru_inblock;
 __kernel_long_t ru_oublock;
 __kernel_long_t ru_msgsnd;
 __kernel_long_t ru_msgrcv;
 __kernel_long_t ru_nsignals;
 __kernel_long_t ru_nvcsw;
 __kernel_long_t ru_nivcsw;
};
struct rlimit {
 __kernel_ulong_t rlim_cur;
 __kernel_ulong_t rlim_max;
};
typedef unsigned long rlim_t;
struct rlimit64 {
 __u64 rlim_cur;
 __u64 rlim_max;
};
enum fsconfig_command {
 FSCONFIG_SET_FLAG = 0,
 FSCONFIG_SET_STRING = 1,
 FSCONFIG_SET_BINARY = 2,
 FSCONFIG_SET_PATH = 3,
 FSCONFIG_SET_PATH_EMPTY = 4,
 FSCONFIG_SET_FD = 5,
 FSCONFIG_CMD_CREATE = 6,
 FSCONFIG_CMD_RECONFIGURE = 7,
};
struct seccomp_data {
 int nr;
 __u32 arch;
 __u64 instruction_pointer;
 __u64 args[6];
};
struct seccomp_notif_sizes {
 __u16 seccomp_notif;
 __u16 seccomp_notif_resp;
 __u16 seccomp_data;
};
struct seccomp_notif {
 __u64 id;
 __u32 pid;
 __u32 flags;
 struct seccomp_data data;
};
struct seccomp_notif_resp {
 __u64 id;
 __s64 val;
 __s32 error;
 __u32 flags;
};
typedef struct __user_cap_header_struct {
 uint32_t version;
 int pid;
} *cap_user_header_t;
typedef struct __user_cap_data_struct {
        uint32_t effective;
        uint32_t permitted;
        uint32_t inheritable;
} *cap_user_data_t;
typedef int cap_value_t;
struct vfs_cap_data {
 uint32_t magic_etc; struct { uint32_t permitted; uint32_t inheritable; } data[2];
};
struct vfs_ns_cap_data {
 uint32_t magic_etc; struct { uint32_t permitted; uint32_t inheritable; } data[2];
 uint32_t rootid;
};
typedef enum {
    CAP_EFFECTIVE = 0,
    CAP_PERMITTED = 1,
    CAP_INHERITABLE = 2
} cap_flag_t;
struct udiv_t { unsigned int quot, rem; };
typedef struct _fmt_t {
  signed char __attribute__((may_alias)) base;
  signed char __attribute__((may_alias)) padding;
  signed char __attribute__((may_alias)) pad;
  signed char __attribute__((may_alias)) group;
  signed char __attribute__((may_alias)) groupsep;
  signed char __attribute__((may_alias)) flags;
  signed char __attribute__((may_alias)) strpadding;
  signed char __attribute__((may_alias)) strpad;
 } fmt_t;
typedef struct __attribute__((packed))_fmt_set {
  char base;
  char padding;
  char pad;
  char group;
  char groupsep;
  char flags;
  char strpadding;
  char strpad;
 } fmt_set;
typedef union {
 fmt_set *set;
 struct {
  char base;
  char padding;
  char pad;
  char group;
  char groupsep;
  char flags;
  char strpadding;
  char strpad;
 };
} fmt_setunion;
struct __dirstream{
 off_t tell;
 int fd;
 int buf_pos;
 int buf_end;
 int align;
 char buf[0];
};
typedef struct __dirstream DIR;
struct dirent {
 ino_t d_ino;
 off_t d_off;
 unsigned short d_reclen;
 char d_name[];
};
static void __ERR(int errnum, const char* func );
typedef int errno_t;
extern int errno;
typedef unsigned long fd_mask;
typedef struct {
 unsigned int fds_bits[1024 / 32 ];
 unsigned short highestbit;
} fd_set;
typedef struct {char c;} __guarded_memory;
typedef __builtin_va_list va_list;
typedef unsigned int index_t;
typedef unsigned int brk_data_t;
typedef unsigned int sbrk_data_t;
struct ml_malloc_area{
 void *pos;
 unsigned short int size;
 unsigned short int free;
 unsigned short int freegaps;
 unsigned short int largestfree;
};
struct ml_malloc_def;
struct ml_malloc_freearray{
  unsigned int pos;
  unsigned int largestfree;
  unsigned int data[0];
  unsigned int size;
  unsigned int freegaps;
  unsigned int _data[];
};
struct ml_malloc_def{
 struct ml_malloc_area *area;
 struct ml_malloc_freestorage* free;
 void* (*find_free)(struct ml_malloc_def*,int size);
 int (*resize_area)(struct ml_malloc_area*,int size);
 int (*check_area)(struct ml_malloc_area*);
 const int movposfactor;
 const int typesize;
 const int btval,btfree,btprevfree,bttop;
};
typedef struct ml_malloc_area ml_malloc_area_t;
struct udphdr {
 uint16_t uh_sport;
 uint16_t uh_dport;
 uint16_t uh_ulen;
 uint16_t uh_sum;
};
enum {
 TCP_NLA_PAD,
 TCP_NLA_BUSY,
 TCP_NLA_RWND_LIMITED,
 TCP_NLA_SNDBUF_LIMITED,
 TCP_NLA_DATA_SEGS_OUT,
 TCP_NLA_TOTAL_RETRANS,
 TCP_NLA_PACING_RATE,
 TCP_NLA_DELIVERY_RATE,
 TCP_NLA_SND_CWND,
 TCP_NLA_REORDERING,
 TCP_NLA_MIN_RTT,
 TCP_NLA_RECUR_RETRANS,
 TCP_NLA_DELIVERY_RATE_APP_LMT,
 TCP_NLA_SNDQ_SIZE,
 TCP_NLA_CA_STATE,
 TCP_NLA_SND_SSTHRESH,
 TCP_NLA_DELIVERED,
 TCP_NLA_DELIVERED_CE,
};
typedef uint16_t in_port_t;
typedef uint32_t in_addr_t;
struct in_addr { in_addr_t s_addr; };
struct in6_addr {
 union {
  uint8_t __s6_addr[16];
  uint16_t __s6_addr16[8];
  uint32_t __s6_addr32[4];
 } __in6_union;
};
struct timestamp {
 uint8_t len;
 uint8_t ptr;
 unsigned int flags:4;
 unsigned int overflow:4;
 uint32_t data[9];
};
struct iphdr {
 unsigned int ihl:4;
 unsigned int version:4;
 uint8_t tos;
 uint16_t tot_len;
 uint16_t id;
 uint16_t frag_off;
 uint8_t ttl;
 uint8_t protocol;
 uint16_t check;
 uint32_t saddr;
 uint32_t daddr;
};
struct ethhdr {
 uint8_t h_dest[6];
 uint8_t h_source[6];
 uint16_t h_proto;
};
struct ip {
 unsigned int ip_hl:4;
 unsigned int ip_v:4;
 uint8_t ip_tos;
 uint16_t ip_len;
 uint16_t ip_id;
 uint16_t ip_off;
 uint8_t ip_ttl;
 uint8_t ip_p;
 uint16_t ip_sum;
 struct in_addr ip_src, ip_dst;
};
struct ip_timestamp {
 uint8_t ipt_code;
 uint8_t ipt_len;
 uint8_t ipt_ptr;
 unsigned int ipt_flg:4;
 unsigned int ipt_oflw:4;
 uint32_t data[9];
};
struct linger {
 int l_onoff;
 int l_linger;
};
struct sockaddr_in {
 unsigned short sin_family;
 uint16_t sin_port;
 struct in_addr sin_addr;
 uint8_t sin_zero[8];
};
struct addrinfo {
 int ai_flags;
 int ai_family;
 int ai_socktype;
 int ai_protocol;
 socklen_t ai_addrlen;
 struct sockaddr *ai_addr;
 char *ai_canonname;
 struct addrinfo *ai_next;
};
struct ifmap {
 unsigned long mem_start;
 unsigned long mem_end;
 uint16_t base_addr;
 unsigned char irq;
 unsigned char dma;
 unsigned char port;
};
struct sockaddr_storage {
 sa_family_t ss_family;
 uint32_t __ss_align;
 char __ss_padding[(128 - (2 * sizeof (uint32_t ))) ];
};
struct netent {
 char *n_name;
 char **n_aliases;
 int n_addrtype;
 uint32_t n_net;
};
struct hostent {
 char *h_name;
 char **h_aliases;
 int h_addrtype;
 int h_length;
 char **h_addr_list;
};
struct ether_addr {
 uint8_t ether_addr_octet[6];
};
struct ether_header {
 uint8_t ether_dhost[6];
 uint8_t ether_shost[6];
 uint16_t ether_type;
};
struct ifreq {
 union
 {
  char ifrn_name[16];
 } ifr_ifrn;
 union {
  struct sockaddr ifru_addr;
  struct sockaddr ifru_dstaddr;
  struct sockaddr ifru_broadaddr;
  struct sockaddr ifru_netmask;
  struct sockaddr ifru_hwaddr;
  int16_t ifru_flags;
  int32_t ifru_ivalue;
  int32_t ifru_mtu;
  struct ifmap ifru_map;
  char ifru_slave[16];
  char ifru_newname[16];
  char* ifru_data;
 } ifr_ifru;
};
struct sockaddr_ll {
 unsigned short sll_family, sll_protocol;
 int sll_ifindex;
 unsigned short sll_hatype;
 unsigned char sll_pkttype, sll_halen;
 unsigned char sll_addr[8];
};
struct packet_mreq {
 int mr_ifindex;
 unsigned short int mr_type, mr_alen;
 unsigned char mr_address[8];
};
struct rtentry {
 unsigned long int rt_pad1;
 struct sockaddr rt_dst;
 struct sockaddr rt_gateway;
 struct sockaddr rt_genmask;
 unsigned short int rt_flags;
 short int rt_pad2;
 unsigned long int rt_pad3;
 unsigned char rt_tos;
 unsigned char rt_class;
 short int rt_pad4[sizeof(long)/2-1];
 short int rt_metric;
 char *rt_dev;
 unsigned long int rt_mtu;
 unsigned long int rt_window;
 unsigned short int rt_irtt;
};
struct in6_rtmsg {
 struct in6_addr rtmsg_dst;
 struct in6_addr rtmsg_src;
 struct in6_addr rtmsg_gateway;
 uint32_t rtmsg_type;
 uint16_t rtmsg_dst_len;
 uint16_t rtmsg_src_len;
 uint32_t rtmsg_metric;
 unsigned long int rtmsg_info;
 uint32_t rtmsg_flags;
 int rtmsg_ifindex;
};
static inline void __attribute__((noreturn,always_inline))exit(int ret){
 __asm__("jmp __exit"::"D"(ret));
 __builtin_unreachable();
}
struct tm {
 int tm_sec;
 int tm_min;
 int tm_hour;
 int tm_mday;
 int tm_mon;
 int tm_year;
 int tm_wday;
 int tm_yday;
 int tm_isdst;
 long __tm_gmtoff;
 const char *__tm_zone;
};
typedef struct {
 int tm_sec;
 int tm_min;
 int tm_hour;
 int tm_mday;
 int tm_mon;
 int tm_year;
 int tm_wday;
 int tm_yday;
 int tm_isdst;
} tm;
typedef struct {
  time_t actime;
  time_t modtime;
} utimbuf;
extern void volatile __attribute__((naked,noipa,cold,no_instrument_function)) opt_fence(void*p,...);
__asm__(".global opt_fence\nopt_fence:\nretq");
struct stat;
struct timeval;
struct timezone;
typedef unsigned long u64;
typedef unsigned int u32;
typedef long aio_context_t;
typedef long key_serial_t;
typedef long loff_t;
typedef long qid_t;
typedef long mqd_t;
typedef long stack_t;
typedef long umode_t;
typedef long semun_u;
struct sockaddr;
struct iovcc;
struct rusage;
struct file_handle;
struct utimbuf;
struct sched_attr;
struct sched_param;
struct itimerspec;
struct kexec_segment;
struct task_struct;
struct msghdr;
struct iocb;
struct io_event;
struct linux_dirent64;
struct pt_regs;
struct perf_event_attr;
struct __sysctl_args;
struct timex;
struct msgbuf;
struct pollfd;
struct getcpu_cache;
struct bpf_attr;
struct shmid_ds;
struct epoll_event;
struct mq_attr;
struct poll_fd;
struct mq_attr;
struct sembuf;
struct statfs;
struct sysinfo;
struct rlimit;
struct ustat;
struct itimerval;
struct linux_dirent;
struct robust_list_head;
struct sigevent;
struct siginfo;
struct bpf_attr;
struct msqid_ds;
struct rlimit64;
struct sigaction;
struct mmsghdr;
struct msqid_ds;
;
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wint-conversion"
static inline int volatile __attribute__((always_inline)) fork( ){ int sysret; __asm__ volatile ("syscall" : "=a" (sysret) : "a" ( ((57 | 0 ) | 0 ) ) : "memory","rcx", "r11", "cc" ); ; return(sysret); }
static inline int volatile __attribute__((always_inline)) socket( int a1, int a2, int a3 ){ int sysret; __asm__ volatile ("syscall" : "=a" (sysret) : "a" ( ((41 | 0 ) | 0 ) ) , "D" (a1) , "S" (a2) , "d" (a3) : "memory","rcx", "r11", "cc" ); ; return(sysret); }
static inline int volatile sendfile( int a1, int a2, off_t *a3, size_t a4 ){ int sysret; __asm__ volatile ("mov %5,%%r10\n syscall" : "=a" (sysret) : "a" ( ((40 | 0 ) | 0 ) ),"D"(a1),"S"(a2),"d"(a3), "g"((uint64_t)(a4)) : "memory","rcx", "r11", "cc", "r10" ); ; return(sysret); }
static inline int volatile setsockopt( int a1, int a2, int a3, const void *a4, int a5 ){ int sysret; __asm__ volatile ("mov %5,%%r10\nmov %6,%%r8\nsyscall" : "=a" (sysret) : "a" ( ((54 | 0 ) | 0 ) ),"D"(a1),"S"(a2),"d"(a3), "g"((uint64_t)(a4)), "g"((uint64_t)(a5)) : "memory","rcx", "r11", "cc", "r8","r10" ); ; return(sysret); }
static inline int volatile __attribute__((always_inline)) stat( const char* a1, struct stat* a2 ){ int sysret; __asm__ volatile ("syscall" : "=a" (sysret) : "a" ( ((4 | 0 ) | 0 ) ) , "D" (a1) , "S" (a2) : "memory","rcx", "r11", "cc" ); ; return(sysret); }
static inline int volatile __attribute__((always_inline)) dup( int a1 ){ int sysret; __asm__ volatile ("syscall" : "=a" (sysret) : "a" ( ((32 | 0 ) | 0 ) ) , "D" (a1) : "memory","rcx", "r11", "cc" ); ; return(sysret); }
static inline int volatile __attribute__((always_inline)) close( int a1 ){ int sysret; __asm__ volatile ("syscall" : "=a" (sysret) : "a" ( ((3 | 0 ) | 0 ) ) , "D" (a1) : "memory","rcx", "r11", "cc" ); ; return(sysret); }
static inline int volatile __attribute__((always_inline)) write( int a1, const void *a2, int a3 ){ int sysret; __asm__ volatile ("syscall" : "=a" (sysret) : "a" ( ((1 | 0 ) | 0 ) ) , "D" (a1) , "S" (a2) , "d" (a3) : "memory","rcx", "r11", "cc" ); ; return(sysret); }
static inline int volatile __attribute__((always_inline)) listen( int a1, int a2 ){ int sysret; __asm__ volatile ("syscall" : "=a" (sysret) : "a" ( ((50 | 0 ) | 0 ) ) , "D" (a1) , "S" (a2) : "memory","rcx", "r11", "cc" ); ; return(sysret); }
static inline int volatile __attribute__((always_inline)) nanosleep( struct timespec *a1, struct timespec *a2 ){ int sysret; __asm__ volatile ("syscall" : "=a" (sysret) : "a" ( ((35 | 0 ) | 0 ) ) , "D" (a1) , "S" (a2) : "memory","rcx", "r11", "cc" ); ; return(sysret); }
static inline int volatile __attribute__((always_inline)) accept( int a1, struct sockaddr *a2, socklen_t *a3 ){ int sysret; __asm__ volatile ("syscall" : "=a" (sysret) : "a" ( ((43 | 0 ) | 0 ) ) , "D" (a1) , "S" (a2) , "d" (a3) : "memory","rcx", "r11", "cc" ); ; return(sysret); }
static inline int volatile __attribute__((always_inline)) execve( const char *a1, char* const* a2, char* const* a3 ){ int sysret; __asm__ volatile ("syscall" : "=a" (sysret) : "a" ( ((59 | 0 ) | 0 ) ) , "D" (a1) , "S" (a2) , "d" (a3) : "memory","rcx", "r11", "cc" ); ; return(sysret); }
static inline int volatile __attribute__((always_inline)) read( int a1, void *a2, int a3 ){ int sysret; __asm__ volatile ("syscall" : "=a" (sysret) : "a" ( ((0 | 0 ) | 0 ) ) , "D" (a1) , "S" (a2) , "d" (a3) : "memory","rcx", "r11", "cc" ); ; return(sysret); }
static inline int volatile __attribute__((always_inline)) bind( int a1, struct sockaddr *a2, int a3 ){ int sysret; __asm__ volatile ("syscall" : "=a" (sysret) : "a" ( ((49 | 0 ) | 0 ) ) , "D" (a1) , "S" (a2) , "d" (a3) : "memory","rcx", "r11", "cc" ); ; return(sysret); }
#pragma GCC diagnostic pop
unsigned int volatile msleep(uint seconds, uint useconds);
static int _strcasecmp(const char*c1,const char*c2,int len);
static char* strtok_r(char *s, const char *delim, char **last);
static char *strcpy(char *dest, const char *src);
static void* memcpy( void*d, const void *s, ml_size_t n );
static ml_size_t strlen(const char*str);
static int _dprints(int fd, unsigned long int __ml_valist[]);
static int volatile _open( const char *file, int flags, int mode );
static int strcmp(const char*s1,const char*s2);
static char *stpcpy(char *dest, const char *src);
unsigned int volatile usleep(unsigned int useconds);
static int strncasecmp(const char*c1,const char*c2,int len);
extern void __attribute__((naked,noreturn,no_instrument_function,used))_start();
__asm__ (".global _start\n_start:\n xorl %ebp, %ebp\n	popq %rdi\n	movq %rsp,%rsi\n	movq %rdi,%rax\n	leaq  8(%rsi,%rdi,8),%rdx\n"
 "call main\n"
 "movq %rax, %rdi\n"
 ".global __exit\n"
 "__exit:\n"
 "movq $60, %rax\n"
 "syscall\n"
 "xor %esp,%esp\nret"
 );
static int _dprints(int fd, unsigned long int __ml_valist[]){
  int ret = 0;
  const char *msg;
  unsigned long int* args;
  args=__ml_valist+1; unsigned long int* __ml_vacopy_args=args-1;
  for ( int a = ((ml_size_t)*__ml_vacopy_args ); a>0; a-- ){
   msg=({ if ( ((args - __ml_vacopy_args) > *__ml_vacopy_args) ) { write(2,"\033[1;31m" "count ML_VA_ARG" "\n" "\033[0;37;40m",sizeof("\033[1;31m" "count ML_VA_ARG" "\n" "\033[0;37;40m")-1);if((((long)22!=-404)?(22!=0):(((long)"not enough arguments in ML_VA_LIST for ML_VA_ARG"!=-404)?(unsigned long int)"not enough arguments in ML_VA_LIST for ML_VA_ARG":0))) exit((((long)22!=-404)?(22!=0):(((long)"not enough arguments in ML_VA_LIST for ML_VA_ARG"!=-404)?(unsigned long int)"not enough arguments in ML_VA_LIST for ML_VA_ARG":0))); }; ((char*)*args++); });
   int i = write(fd,msg,strlen(msg));
   if ( i<0 )
    return(i);
   ret += i;
  }
  return(ret);
}
static int strcmp(const char*s1,const char*s2){
 char a;
 __asm__ volatile (R"(
	1:
	   lodsb (%%rsi),%%al
		subb (%%rdi),%%al
		jnz 6f
		inc %%rdi
		testb $0xff,-1(%%rdi)
		jnz 1b
6:
		neg %%al
	)" : "=a"(a),"+D"(s1),"+S"(s2) :: "cc" );
 return((int)a);
}
static int _strcasecmp(const char*c1,const char*c2,int len){
  int a = 0;
  while ( (c1[a] != 0) && (c2[a]!=0 ) && a != len ){
    if ( c1[a] != c2[a] ){
      if ( ((c1[a])|0x20) > ((c2[a])|0x20) )
        return(1);
      if ( ((c1[a])|0x20) < ((c2[a])|0x20) )
        return(-1);
    }
    a++;
  }
  if ( (c1[a] == 0 ) && ( c2[a] == 0 ) )
    return(0);
  return (1);
}
static int strcasecmp(const char*c1,const char*c2){
  return( _strcasecmp(c1,c2,-1) );
}
static int strncasecmp(const char*c1,const char*c2,int len){
  if ( len <=0 )
    return(-1);
  return(_strcasecmp(c1,c2,len) );
}
static int volatile _open( const char *file, int flags, int mode ){
  int ret;
  __asm__ volatile ("syscall" : "=a" (ret) : "a" ( (2 | 0 ) ) , "D" ((unsigned long int)file), "S" (flags), "d" (mode) : "memory","rcx", "r11", "cc" );
  return(ret);
}
unsigned int volatile usleep(unsigned int useconds){
  struct timespec ts;
  ts.tv_nsec = (long)(((long)useconds*1000) % 1000000000 );
  ts.tv_sec = 0;
  if( useconds >= 1000000 )
    ts.tv_sec = ((long)useconds/1000000);
  return( nanosleep(&ts, &ts) );
}
unsigned int volatile msleep(uint seconds, uint useconds){
  struct timespec ts;
  ts.tv_nsec = (long)((long)useconds*1000 % 1000000000 );
  ts.tv_sec = seconds;
  if( useconds >= 1000000 )
    ts.tv_sec += ((long)useconds/1000000);
  return( nanosleep(&ts, &ts) );
}
static void* memcpy( void*d, const void *s, ml_size_t n ){
 char *dest = d;
 __asm__ volatile("rep movsb" :
   "+c"(n),"+S"(s), "+D"(dest) :: "memory","cc" );
 return(d);
}
static char *strcpy(char *dest, const char *src){
 char *d = dest;
 while((*d=*src)){
  src++;d++;
 }
 return(dest);
}
static char* strtok_r(char *s, const char *delim, char **last){
 const char *spanp;
 int c, sc;
 char *tok;
 if (s == 0 && (s = *last) == 0)
  return (0);
cont:
 c = *s++;
 for (spanp = delim; (sc = *spanp++) != 0;) {
  if (c == sc)
   goto cont;
 }
 if (c == 0) {
  *last = 0;
  return (0);
 }
 tok = s - 1;
 while(1){
  c = *s++;
  spanp = delim;
  do {
   if ((sc = *spanp++) == c) {
    if (c == 0)
     s = 0;
    else
     s[-1] = '\0';
    *last = s;
    return (tok);
   }
  } while (sc != 0);
 }
}
static char *stpcpy(char *dest, const char *src){
 while ( (*dest=*src) ){
  dest++;
  src++;
 }
 *dest = 0;
 return(dest);
}
static ml_size_t strlen(const char*str){
 if ( !str )
  return(0);
 ml_size_t a;
 __asm__ volatile( R"(
	xor %%ecx, %%ecx
	dec %%ecx
	#xor %%eax,%%eax	
	repne scasb	
	neg %%ecx	
	sub $2,%%ecx
 )" : "=c"(a), "+D"(str): "a"(0) :"cc");
 return (a);
}
__asm__(".MARK_MICROSERVER:");
void __attribute__((noreturn)) err( int err, const char* msg ){
 ({ unsigned long int VAARGS[4 +1] = {(unsigned long int) 4 , (unsigned long int) "ERROR: " , (unsigned long int) msg , (unsigned long int) "\n" , (unsigned long int) 0 }; _dprints(2,VAARGS); });
 exit(({ int _r = err; if ( _r<0 ) _r=-_r; _r; }));
}
const char* mimeclass_str =
        "application\0audio\0image\0video\0text";
const char * const mimetypes_str[] ={
 "application/octet-stream", "application/msword", "application/octet-stream", "application/pdf", "application/x-javascript", "application/xml", "application/zip", "application/gz", "application/tar", "audio/mpeg3", "image/bmp", "image/gif", "image/ico", "image/jpeg", "image/png", "image/tiff", "text/css", "text/html", "text/markdown", "text/plain", "text/x-c", "video/avi", "video/mpeg",
};
const char * const mimetypes_ext[] ={
 "\n""\e", "\n"".doc", "\n"".bin\t.rar", "\n"".pdf", "\n"".js", "\n"".xml", "\n"".zip", "\n"".gz", "\n"".tar", "\n"".mp3", "\n"".bmp", "\n"".gif", "\n"".ico", "\n"".jpeg\t.jpg", "\n"".png", "\n"".tiff", "\n"".css", "\n"".html\t.shtml\t.htm\t.php", "\n"".markdown\t.md", "\n""README\t.nfo\t.txt", "\n"".c\t.h", "\n"".avi", "\n"".mpeg\t.mpg",
};
static int getmimetype(const char* path){
 const char *pend = path + strlen(path) - 1;
 int type = 0;
 for ( const char *const *m = mimetypes_ext; m - mimetypes_ext < sizeof(mimetypes_ext)/sizeof(char*); m++ ){
  const char *p, *pext=(*m+(strlen(*m)));
  do {
   p = pend;
   pext--;
   while ( *p && (((*p)|0x20)==*pext) ){
    p--,pext--;
   }
   if ( *pext <= '\n' ){
    return( m - mimetypes_ext );
   }
   while ( *pext> '\n' ){
    pext--;
   }
  }
  while ( *pext != '\n' );
 }
 return(({ enum { UNKNOWN,unknown=UNKNOWN, msword,application_msword=msword, octet_stream,application_octet_stream=octet_stream, pdf,application_pdf=pdf, javascript,application_x_javascript=javascript, xml,application_xml=xml, zip,application_zip=zip, gz,image_gz=gz, tar,image_tar=tar, mp3,audio_mpeg3=mp3, bmp,image_bmp=bmp, gif,image_gif=gif, ico,image_ico=ico, jpeg,image_jpeg=jpeg, png,image_png=png, tiff,image_tiff=tiff, css,text_css=css, html,text_html=html, markdown,text_markdown=markdown, plain,text_plain=plain, c,text_x_c=c, avi,video_avi=avi, mpg,video_mpeg=mpg, ENDENUM }; unknown; }));
}
static void sendheader( char*status, char*title, int mimetype ){
 ({ unsigned long int VAARGS[9 +1] = {(unsigned long int) 9 , (unsigned long int) "HTTP/1.0 " , (unsigned long int) status , (unsigned long int) " " , (unsigned long int) title , (unsigned long int) "\r\n" "Connection: close\r\n" "Allow: GET\r\n" "Content-Type: " , (unsigned long int) mimetypes_str[mimetype] , (unsigned long int) "\r\n\r\n" , (unsigned long int) 0 , (unsigned long int) 0 }; _dprints(1,VAARGS); });
}
static void send_htmlhead(const char* status, const char* title ){
 ({ unsigned long int VAARGS[11 +1] = {(unsigned long int) 11 , (unsigned long int) "<html>\n<head><title>" , (unsigned long int) status , (unsigned long int) ": " , (unsigned long int) title , (unsigned long int) "</title></head>\n<body>\n<h3>" , (unsigned long int) status , (unsigned long int) ": " , (unsigned long int) title , (unsigned long int) "</h3>\n" , (unsigned long int) 0 , (unsigned long int) 0 }; _dprints(1,VAARGS); });
}
static void send_error( char*status, char*title ){
 ({ unsigned long int VAARGS[5 +1] = {(unsigned long int) 5 , (unsigned long int) status , (unsigned long int) ": " , (unsigned long int) title , (unsigned long int) "\n" , (unsigned long int) 0 }; _dprints(2,VAARGS); });
 sendheader( status, title, ({ enum { UNKNOWN,unknown=UNKNOWN, msword,application_msword=msword, octet_stream,application_octet_stream=octet_stream, pdf,application_pdf=pdf, javascript,application_x_javascript=javascript, xml,application_xml=xml, zip,application_zip=zip, gz,image_gz=gz, tar,image_tar=tar, mp3,audio_mpeg3=mp3, bmp,image_bmp=bmp, gif,image_gif=gif, ico,image_ico=ico, jpeg,image_jpeg=jpeg, png,image_png=png, tiff,image_tiff=tiff, css,text_css=css, html,text_html=html, markdown,text_markdown=markdown, plain,text_plain=plain, c,text_x_c=c, avi,video_avi=avi, mpg,video_mpeg=mpg, ENDENUM }; html; }) );
 send_htmlhead(status,title);
 write(1,"</body></html>\n",sizeof("</body></html>\n")-1);
 exit(0);
}
static void __attribute__((noreturn))http_handler( int rfd, char *buf, char *pos ){
 int r;
 do {
  r= read(rfd, pos, (4000 -(pos-buf)) );
 } while ( ({ int _r = r; if ( _r<0 ) _r=-_r; _r; }) == 4 || ({ int _r = r; if ( _r<0 ) _r=-_r; _r; }) == 11 );
 if ( r<0 || r == (4000 -(pos-buf)) )
   send_error("400", "Bad");
 char *p;
 char* method = strtok_r( pos, " \t\n\r", &p );
 char* path = strtok_r( 0, " \t\n\r", &p );
 char* prot = strtok_r( 0, " \t\n\r", &p );
 if ( strcmp( "GET", method ) )
  send_error("405","Unsupported" );
 if ( prot-path > 4096 - (pos-buf) )
  send_error("400","Bad Request");
 if ( path[0] != '/' )
  send_error("400","Bad Path");
 for ( char *c = path; *c; c++ )
  if ( *c=='.' && *(c+1) == '.' )
   send_error("400","Bad Path ..");
 char *pend = stpcpy( pos, path );
 path = buf+4;
 ({ unsigned long int VAARGS[4 +1] = {(unsigned long int) 4 , (unsigned long int) "Access: " , (unsigned long int) path , (unsigned long int) "\n" , (unsigned long int) 0 }; _dprints(2,VAARGS); });
 struct stat st;
 if ( stat( path, &st ) != 0 ){
  send_error("404","Not found");
 }
 int mimetype = getmimetype(path);
 char *args[] = { "sh", "-c", buf, 0 };
 int ffd = 0;
 if ( (((st.st_mode) & 0170000) == 0040000) ){
  mimetype = ({ enum { UNKNOWN,unknown=UNKNOWN, msword,application_msword=msword, octet_stream,application_octet_stream=octet_stream, pdf,application_pdf=pdf, javascript,application_x_javascript=javascript, xml,application_xml=xml, zip,application_zip=zip, gz,image_gz=gz, tar,image_tar=tar, mp3,audio_mpeg3=mp3, bmp,image_bmp=bmp, gif,image_gif=gif, ico,image_ico=ico, jpeg,image_jpeg=jpeg, png,image_png=png, tiff,image_tiff=tiff, css,text_css=css, html,text_html=html, markdown,text_markdown=markdown, plain,text_plain=plain, c,text_x_c=c, avi,video_avi=avi, mpg,video_mpeg=mpg, ENDENUM }; html; });
 } else
  if ( mimetype == ({ enum { UNKNOWN,unknown=UNKNOWN, msword,application_msword=msword, octet_stream,application_octet_stream=octet_stream, pdf,application_pdf=pdf, javascript,application_x_javascript=javascript, xml,application_xml=xml, zip,application_zip=zip, gz,image_gz=gz, tar,image_tar=tar, mp3,audio_mpeg3=mp3, bmp,image_bmp=bmp, gif,image_gif=gif, ico,image_ico=ico, jpeg,image_jpeg=jpeg, png,image_png=png, tiff,image_tiff=tiff, css,text_css=css, html,text_html=html, markdown,text_markdown=markdown, plain,text_plain=plain, c,text_x_c=c, avi,video_avi=avi, mpg,video_mpeg=mpg, ENDENUM }; markdown; }) ){
  *(uint*)buf = *(uint*)"cat ";
  strcpy( pend, " | lowdown -s" );
  mimetype = ({ enum { UNKNOWN,unknown=UNKNOWN, msword,application_msword=msword, octet_stream,application_octet_stream=octet_stream, pdf,application_pdf=pdf, javascript,application_x_javascript=javascript, xml,application_xml=xml, zip,application_zip=zip, gz,image_gz=gz, tar,image_tar=tar, mp3,audio_mpeg3=mp3, bmp,image_bmp=bmp, gif,image_gif=gif, ico,image_ico=ico, jpeg,image_jpeg=jpeg, png,image_png=png, tiff,image_tiff=tiff, css,text_css=css, html,text_html=html, markdown,text_markdown=markdown, plain,text_plain=plain, c,text_x_c=c, avi,video_avi=avi, mpg,video_mpeg=mpg, ENDENUM }; html; });
 } else {
  ffd = _open(path,00000000, ((((00000000)&00000100)==00000100)&&((+0)==0))?0644:(+0));
  if ( ffd<=0 )
   send_error("423", "Not accessible" );
 }
 sendheader( "200", "Ok", mimetype );
 if ( (((st.st_mode) & 0170000) == 0040000) ){
  int plen = pend-pos;
  send_htmlhead( "Directory index", pos );
  if (plen>1) ({ unsigned long int VAARGS[5 +1] = {(unsigned long int) 5 , (unsigned long int) "<a href=\"" , (unsigned long int) pos , (unsigned long int) "/..\">Parent .. &uarr;</a><br/>\n" , (unsigned long int) 0 , (unsigned long int) 0 }; _dprints(1,VAARGS); });
  *(uint*)buf = *(uint*)"ls  ";
  char *p = pend;
  pend = stpcpy(pend, " | sed -E 's;(.*);<a href=\\\"");
  memcpy(pend, pos+1, plen-1 );
  strcpy(pend+plen-1, "/\\1\\\">\\1</a><br/>;';"
    "echo '</body></html>'");
 }
 if ( ffd == 0 ){
  execve( "/bin/sh", args, 0 );
 } else {
  sendfile(1, ffd, 0, st.st_size );
 }
 exit(0);
}
int __attribute__((used))main(int argc, char **argv, char **env){
 if ( argc != 2 || argv[1][0] == '-' ){
  write(2,"Usage: microserve pathname\n",sizeof("Usage: microserve pathname\n")-1);
  exit(1);
 }
 char _buf[4000 +4];
 char *buf = _buf + 4;
 char *pos = stpcpy( buf, argv[1] );
 int rfd;
 socklen_t addrlen;
 struct sockaddr_in address;
 int sockfd;
 if ((sockfd = socket(2, 1, 0)) <= 0){
  err(sockfd,"socket creation");
 }
 int port = 4000;
 address.sin_family = 2;
 address.sin_addr.s_addr = ((in_addr_t) 0x00000000);
 address.sin_port = 0xa00f;
 int r;
 ulong l = 1;
 if ( (r =setsockopt(sockfd, 1, 2, &l, sizeof(l))) < 0){
  err(r,"socket options" );
 }
 if ( (r=bind(sockfd, (struct sockaddr *) &address, sizeof(address))) != 0){
  err(r,"binding socket" );
 }
 ({ unsigned long int VAARGS[4 +1] = {(unsigned long int) 4 , (unsigned long int) "serve at port 4000, root: " , (unsigned long int) buf , (unsigned long int) "\n" , (unsigned long int) 0 }; _dprints(2,VAARGS); });
 int retr = 0;
 while (1) {
  if ( (r=listen(sockfd, 10)) < 0) {
   { write(2,"WARN: " "listen" "\n",sizeof("WARN: " "listen" "\n")-1); };
   if ( ++retr > 10 )
    err(14,"abort");
   usleep(100);
   continue;
  }
  retr=0;
  if ((rfd = accept(sockfd, (struct sockaddr *) &address, &addrlen)) < 0){
   { write(2,"WARN: " "accept" "\n",sizeof("WARN: " "accept" "\n")-1); };
   continue;
  }
  write(2,"Connect\n",sizeof("Connect\n")-1);
  int pid = fork();
  if (pid < 0){
   { write(2,"WARN: " "fork" "\n",sizeof("WARN: " "fork" "\n")-1); };
  }
  if (pid == 0){
   close(sockfd);
   close(1);
   dup(rfd);
   http_handler(rfd,_buf, pos);
  }
  else {
   close(rfd);
  }
 }
 __builtin_unreachable();
}
