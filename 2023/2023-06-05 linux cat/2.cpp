#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fstream>
#include <iostream>

void catFile(const char* filename) {
    // 打开文件
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        std::cerr << "无法打开文件: " << filename << std::endl;
        return;
    }

    // 获取文件大小
    struct stat file_stat {};
    if (fstat(fd, &file_stat) == -1) {
        std::cerr << "无法获取文件大小: " << filename << std::endl;
        close(fd);
        return;
    }
    off_t file_size = file_stat.st_size;

    // 将文件映射到内存
    void* file_data = mmap(nullptr, file_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (file_data == MAP_FAILED) {
        std::cerr << "无法将文件映射到内存: " << filename << std::endl;
        close(fd);
        return;
    }

    // 将映射的内存输出到标准输出
    ssize_t bytes_written = write(STDOUT_FILENO, file_data, file_size);
    if (bytes_written == -1) {
        std::cerr << "写入标准输出时发生错误" << std::endl;
    }

    // 清理资源
    munmap(file_data, file_size);
    close(fd);
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
