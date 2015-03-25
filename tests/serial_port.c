/*
 * References:
 *
 *   [1] http://ulisse.elettra.trieste.it/services/doc/serial/
 */

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <termios.h>
#include <unistd.h>

int main()
{
    int fd = open("/dev/ttyUSB0", O_RDWR | O_NOCTTY | O_NDELAY);

    if (fd == -1)
    {
        perror("Error while opening /dev/ttyUSB0");
    }
    else
    {
        printf("Opening /dev/ttyUSB0 successful!\n");
        //fcntl(fd, F_SETFL, 0); // ???
    }

    struct termios options;
    
    // Get the current options for the port.
    tcgetattr(fd, &options);

    // Set the baud rates to 115200.
    cfsetispeed(&options, B115200);
    cfsetospeed(&options, B115200);

    // Enable the receiver and set local mode.
    options.c_cflag |= (CLOCAL | CREAD);

    // Set to 'No parity (8N1)'
    options.c_cflag &= ~PARENB;
    options.c_cflag &= ~CSTOPB;
    options.c_cflag &= ~CSIZE;  // Mask the character size bits.
    options.c_cflag |= CS8;     // Select 8 data bits

    // Raw Input???
    options.c_cflag &= ~( ICANON | ECHO | ECHOE |ISIG );

    // Set Software Flow Control???
    options.c_iflag &= ~(IXON | IXOFF | IXANY );

    // Select Raw Output.
    options.c_oflag &= ~OPOST;

    // Set the new options for the port.
    tcsetattr(fd, TCSANOW, &options);

    ssize_t n_bytes_written = write(fd, "ATZ\r", 4);
    if (n_bytes_written < 0) {
        puts("write() of 4 bytes failed!");
    }

    // Do not wait for characters to become available while reading, but
    // immediately return.
    fcntl(fd, F_SETFL, FNDELAY);

    char buffer[10];
    char *bufptr;
    bufptr = buffer;
    ssize_t n_bytes_read = read(fd, bufptr, sizeof(buffer));
    printf("number of bytes read is %zd\n", n_bytes_read);

    int x;
    for (x = 0; x < 10 ; ++x)
    {
        printf("%d  ", buffer[x]);
    }
    printf("\n");
    close(fd);

    puts(buffer);

    return (0);
}
