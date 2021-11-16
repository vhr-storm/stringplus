#ifndef S21_ERRNO_H
#define S21_ERRNO_H

#include <stdio.h>

#define EPERM 1
#define ENOENT 2
#define ESRCH 3
#define EINTR 4
#define EIO 5
#define ENXIO 6
#define E2BIG 7
#define ENOEXEC 8
#define EBADF 9
#define ECHILD 10
#define EDEADLK 11
#define ENOMEM 12
#define EACCES 13
#define EFAULT 14
#define ENOTBLK 15
#define EBUSY 16
#define EEXIST 17
#define EXDEV 18
#define ENODEV 19
#define ENOTDIR 20
#define EISDIR 21
#define EINVAL 22
#define ENFILE 23
#define EMFILE 24
#define ENOTTY 25
#define ETXTBSY 26
#define EFBIG 27
#define ENOSPC 28
#define ESPIPE 29
#define EROFS 30
#define EMLINK 31
#define EPIPE 32
#define EDOM 33
#define ERANGE 34
#define EAGAIN 35
#define EINPROGRESS 36
#define EALREADY 37
#define ENOTSOCK 38
#define EDESTADDRREQ 39
#define EMSGSIZE 40
#define EPROTOTYPE 41
#define ENOPROTOOPT 42
#define EPROTONOSUPPORT 43
#define ESOCKTNOSUPPORT 44
#define ENOTSUP 45
#define EPFNOSUPPORT 46
#define EAFNOSUPPORT 47
#define EADDRINUSE 48
#define EADDRNOTAVAIL 49
#define ENETDOWN 50
#define ENETUNREACH 51
#define ENETRESET 52
#define ECONNABORTED 53
#define ECONNRESET 54
#define ENOBUFS 55
#define EISCONN 56
#define ENOTCONN 57
#define ESHUTDOWN 58
#define ETOOMANYREFS 59
#define ETIMEDOUT 60
#define ECONNREFUSED 61
#define ELOOP 62
#define ENAMETOOLONG 63
#define EHOSTDOWN 64
#define EHOSTUNREACH 65
#define ENOTEMPTY 66
#define EPROCLIM 67
#define EUSERS 68
#define EDQUOT 69
#define ESTALE 70
#define EREMOTE 71
#define EBADRPC 72
#define ERPCMISMATCH 73
#define EPROGUNAVAIL 74
#define EPROGMISMATCH 75
#define EPROCUNAVAIL 76
#define ENOLCK 77
#define ENOSYS 78
#define EFTYPE 79
#define EAUTH 80
#define ENEEDAUTH 81
#define EPWROFF 82
#define EDEVERR 83
#define EOVERFLOW 84
#define EBADEXEC 85
#define EBADARCH 86
#define ESHLIBVERS 87
#define EBADMACHO 88
#define ECANCELED 89
#define EIDRM 90
#define ENOMSG 91
#define EILSEQ 92
#define ENOATTR 93
#define EBADMSG 94
#define EMULTIHOP 95
#define ENOLINK 97
#define ENOSTR 99
#define EPROTO 100
#define ETIME 101
#define EOPNOTSUPP 102
#define ENOPOLICY 103
#define ENOTRECOVERABLE 104
#define EOWNERDEAD 105
#define EQFULL 106
#define ELAST 107

#define MACROLST                                                   \
  errlist[1] = "Operation not permitted";                          \
  errlist[2] = "No such file or directory";                        \
  errlist[3] = "No such process";                                  \
  errlist[4] = "Interrupted system call";                          \
  errlist[5] = "Input/output error";                               \
  errlist[6] = "Device not configured";                            \
  errlist[7] = "Argument list too long";                           \
  errlist[8] = "Exec format error";                                \
  errlist[9] = "Bad file descriptor";                              \
  errlist[10] = "No child processes";                              \
  errlist[11] = "Resource deadlock avoided";                       \
  errlist[12] = "Cannot allocate memory";                          \
  errlist[13] = "Permission denied";                               \
  errlist[14] = "Bad address";                                     \
  errlist[15] = "Block device required";                           \
  errlist[16] = "Device / Resource busy";                          \
  errlist[17] = "File exists";                                     \
  errlist[18] = "Cross-device link";                               \
  errlist[19] = "Operation not supported by device";               \
  errlist[20] = "Not a directory";                                 \
  errlist[21] = "Is a directory";                                  \
  errlist[22] = "Invalid argument";                                \
  errlist[23] = "Too many open files in system";                   \
  errlist[24] = "Too many open files";                             \
  errlist[25] = "Inappropriate ioctl for device";                  \
  errlist[26] = "Text file busy";                                  \
  errlist[27] = "File too large";                                  \
  errlist[28] = "No space left on device";                         \
  errlist[29] = "Illegal seek";                                    \
  errlist[30] = "Read-only file system";                           \
  errlist[31] = "Too many links";                                  \
  errlist[32] = "Broken pipe";                                     \
  errlist[33] = "Numerical argument out of domain";                \
  errlist[34] = "Result too large";                                \
  errlist[35] = "Resource temporarily unavailable";                \
  errlist[36] = "Operation now in progress";                       \
  errlist[37] = "Operation already in progress";                   \
  errlist[38] = "Socket operation on non-socket";                  \
  errlist[39] = "Destination address required";                    \
  errlist[40] = "Message too long";                                \
  errlist[41] = "Protocol wrong type for socket";                  \
  errlist[42] = "Protocol not available";                          \
  errlist[43] = "Protocol not supported";                          \
  errlist[44] = "Socket type not supported";                       \
  errlist[45] = "Operation not supported";                         \
  errlist[46] = "Protocol family not supported";                   \
  errlist[47] = "Address family not supported by protocol family"; \
  errlist[48] = "Address already in use";                          \
  errlist[49] = "Can't assign requested address";                  \
  errlist[50] = "Network is down";                                 \
  errlist[51] = "Network is unreachable";                          \
  errlist[52] = "Network dropped connection on reset";             \
  errlist[53] = "Software caused connection abort";                \
  errlist[54] = "Connection reset by peer";                        \
  errlist[55] = "No buffer space available";                       \
  errlist[56] = "Socket is already connected";                     \
  errlist[57] = "Socket is not connected";                         \
  errlist[58] = "Can't send after socket shutdown";                \
  errlist[59] = "Too many references: can't splice";               \
  errlist[60] = "Operation timed out";                             \
  errlist[61] = "Connection refused";                              \
  errlist[62] = "Too many levels of symbolic links";               \
  errlist[63] = "File name too long";                              \
  errlist[64] = "Host is down";                                    \
  errlist[65] = "No route to host";                                \
  errlist[66] = "Directory not empty";                             \
  errlist[67] = "Too many processes";                              \
  errlist[68] = "Too many users";                                  \
  errlist[69] = "Disc quota exceeded";                             \
  errlist[70] = "Stale NFS file handle";                           \
  errlist[71] = "Too many levels of remote in path";               \
  errlist[72] = "RPC struct is bad";                               \
  errlist[73] = "RPC version wrong";                               \
  errlist[74] = "RPC prog. not avail";                             \
  errlist[75] = "Program version wrong";                           \
  errlist[76] = "Bad procedure for program";                       \
  errlist[77] = "No locks available";                              \
  errlist[78] = "Function not implemented";                        \
  errlist[79] = "Inappropriate file type or format";               \
  errlist[80] = "Authentication error";                            \
  errlist[81] = "Need authenticator";                              \
  errlist[82] = "Device power is off";                             \
  errlist[83] = "Device error, e.g. paper out";                    \
  errlist[84] = "Value too large to be stored in data type";       \
  errlist[85] = "Bad executable";                                  \
  errlist[86] = "Bad CPU type in executable";                      \
  errlist[87] = "Shared library version mismatch";                 \
  errlist[88] = "Malformed Macho file";                            \
  errlist[89] = "Operation canceled";                              \
  errlist[90] = "Identifier removed";                              \
  errlist[91] = "No message of desired type";                      \
  errlist[92] = "Illegal byte sequence";                           \
  errlist[93] = "Attribute not found";                             \
  errlist[94] = "Bad message";                                     \
  errlist[95] = "Reserved";                                        \
  errlist[96] = "No message available on STREAM";                  \
  errlist[97] = "Reserved";                                        \
  errlist[98] = "No STREAM resources";                             \
  errlist[99] = "Not a STREAM";                                    \
  errlist[100] = "Protocol error";                                 \
  errlist[101] = "STREAM ioctl timeout";                           \
  errlist[102] = "Operation not supported on socket";              \
  errlist[103] = "No such policy registered";                      \
  errlist[104] = "State not recoverable";                          \
  errlist[105] = "Previous owner died";                            \
  errlist[106] = "Interface output queue is full";                 \
  errlist[107] = "Must be equal largest errno";

#endif