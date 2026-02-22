#include <iostream>
#include <fstream>   // For file operations
#include <fcntl.h>   // File control definitions
#include <termios.h> // POSIX terminal control
#include <unistd.h>  // UNIX standard function definitions
#include <string.h>

int main()
{
    // 1. Open the Serial Port
    // Replace with your actual device path from: ls /dev/cu.*
    const char *portName = "/dev/cu.usbserial-AC00ISQH";
    int serial_port = open(portName, O_RDWR);

    if (serial_port < 0)
    {
        std::cerr << "Error: Could not open serial port." << std::endl;
        return 1;
    }

    // 2. Basic Configuration
    struct termios tty;
    tcgetattr(serial_port, &tty);
    cfsetispeed(&tty, B9600);        // Input speed
    cfsetospeed(&tty, B9600);        // Output speed
    tty.c_cflag |= (CLOCAL | CREAD); // Ignore modem lines, enable receiver
    tty.c_cflag |= CS8;              // 8-bit chars
    tcsetattr(serial_port, TCSANOW, &tty);

    // 3. Prepare the Log File
    std::ofstream logFile;
    logFile.open("serial_log.txt", std::ios::app); // Open in append mode

    if (!logFile.is_open())
    {
        std::cerr << "Error: Could not open log file." << std::endl;
        return 1;
    }

    std::cout << "Listening on " << portName << "... Press Ctrl+C to stop." << std::endl;

    // 4. Read and Write Loop
    char read_buf[256];

    while (true)
    {
        // Clear buffer
        memset(&read_buf, '\0', sizeof(read_buf));

        // Read from serial
        int num_bytes = read(serial_port, &read_buf, sizeof(read_buf) - 1);

        if (num_bytes > 0)
        {
            // Display to Console
            std::cout << "Received: " << read_buf << std::endl;

            // Write to .txt File
            logFile << read_buf;
            logFile.flush(); // Ensure data is written to disk immediately
        }
    }

    // Clean up (Note: while(true) loop makes this unreachable without a break)
    logFile.close();
    close(serial_port);
    return 0;
}