#include <sys/wait.h>
#include <unistd.h>
#include <fstream>
#include <iostream>

void catFile(const char* filename) {
    // 创建管道
    int pipefd[2];
    if (pipe(pipefd) == -1) {
        std::cerr << "无法创建管道" << std::endl;
        return;
    }

    // 创建子进程
    pid_t pid = fork();
    if (pid == -1) {
        std::cerr << "无法创建子进程" << std::endl;
        close(pipefd[0]);
        close(pipefd[1]);
        return;
    }

    if (pid == 0) {
        // 子进程读取管道数据并写入标准输出
        close(pipefd[1]);  // 关闭写端

        const int buffer_size = 4096;
        char buffer[buffer_size];

        ssize_t bytes_read = 0;
        while ((bytes_read = read(pipefd[0], buffer, buffer_size)) > 0) {
            ssize_t bytes_written = write(STDOUT_FILENO, buffer, bytes_read);
            if (bytes_written == -1) {
                std::cerr << "写入标准输出时发生错误" << std::endl;
                close(pipefd[0]);
                return;
            }
        }

        close(pipefd[0]);  // 关闭读端
        _exit(0);
    } else {
        // 父进程从文件中读取数据并写入管道
        close(pipefd[0]);  // 关闭读端

        std::ifstream file(filename, std::ios::binary);
        if (!file) {
            std::cerr << "无法打开文件: " << filename << std::endl;
            close(pipefd[1]);
            return;
        }

        const int buffer_size = 4096;
        char buffer[buffer_size];

        while (file) {
            file.read(buffer, buffer_size);
            ssize_t bytes_read = file.gcount();
            if (bytes_read > 0) {
                ssize_t bytes_written = write(pipefd[1], buffer, bytes_read);
                if (bytes_written == -1) {
                    std::cerr << "写入管道时发生错误" << std::endl;
                    close(pipefd[1]);
                    return;
                }
            }
        }

        file.close();
        close(pipefd[1]);  // 关闭写端

        waitpid(pid, nullptr, 0);  // 等待子进程结束
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "用法: " << argv[0] << " 文件名" << std::endl;
        return 1;
    }

    const char* filename = argv[1];
    catFile(filename);

    return 0;
}
